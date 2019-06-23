#include "ArtistDAOImpl.h"
#include "MediaDAOImpl.h"
#include "MovieDAOImpl.h"
#include "MovieViewingDAOImpl.h"
#include<QtSql/QSqlField>
#include<QVariant>
#include "RoleDAOImpl.h"

using namespace net::draconia::mediadb::dao;

using net::draconia::mediadb::dbo::Media;
using net::draconia::mediadb::dbo::Movie;

const QString MovieDAOImpl::TableName("Movies");

Movie MovieDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    Media objMedia = getMediaDAO().getById(refRecord.field("MediaId").value().toUInt());
    Movie objMovie = Movie  (   objMedia.getMediaId()
                            ,   refRecord.field("MovieId").value().toUInt()
                            ,   objMedia.getName()
                            ,   objMedia.getReleaseDate()
                            ,   objMedia.getFilePath()
                            ,   objMedia.getArtists()
                            ,   refRecord.field("Comments").value().toString());

    for(MovieViewing objViewing : getMovieViewingDAO().listByMovie(objMovie))
        objMovie.addViewing(objViewing);

    return(objMovie);
}

ArtistDAO &MovieDAOImpl::getArtistDAO() const
{
    return(mRefArtistDAO);
}

MediaDAO &MovieDAOImpl::getMediaDAO() const
{
    return(mRefMediaDAO);
}

MovieViewingDAO &MovieDAOImpl::getMovieViewingDAO() const
{
    return(mRefMovieViewingDAO);
}

QString MovieDAOImpl::getPrimaryKey() const
{
    return("MovieId");
}

QString MovieDAOImpl::getQueriedColumnsForSelect() const
{
    return("MediaId, Comments");
}

RoleDAO &MovieDAOImpl::getRoleDAO() const
{
    return(mRefRoleDAO);
}

QString MovieDAOImpl::getTableName() const
{
    return(TableName);
}

Movie &MovieDAOImpl::insert(const Movie &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into " + getTableName() + "(" + getQueriedColumnsForSelect() + ") values(?, ?);");

    objQuery.bindValue(1, refToSave.getMediaId());
    objQuery.bindValue(2, refToSave.getComments());

    if(objQuery.exec())
        const_cast<Movie &>(refToSave).setMovieId(objQuery.lastInsertId().toUInt());

    for(MovieViewing objViewing : refToSave.getViewings())
        getMovieViewingDAO().save(objViewing);

    return(const_cast<Movie &>(refToSave));
}

Movie &MovieDAOImpl::update(const Movie &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("update " + getTableName() + "set MediaId = ?, Comments = ? where MovieId = ?;");

    objQuery.bindValue(1, refToSave.getMediaId());
    objQuery.bindValue(2, refToSave.getComments());
    objQuery.bindValue(3, refToSave.getMovieId());

    for(MovieViewing objViewing : refToSave.getViewings())
        getMovieViewingDAO().save(objViewing);

    objQuery.exec();

    return(const_cast<Movie &>(refToSave));
}

MovieDAOImpl::MovieDAOImpl(const QSqlDatabase &refDatabase)
    : AbstractDAO<Movie>(refDatabase)
    , mRefArtistDAO(BeanFactory::getInstance().getArtistDAO())
    , mRefMediaDAO(BeanFactory::getInstance().getMediaDAO())
    , mRefMovieViewingDAO(BeanFactory::getInstance().getMovieViewingDAO())
    , mRefRoleDAO(BeanFactory::getInstance().getRoleDAO())
{ }

MovieDAOImpl::~MovieDAOImpl()
{ }

bool MovieDAOImpl::createTable() const
{
    if(!isTableExists())
        {
        QSqlQuery objQuery(getDatabase());

        static_cast<MovieViewingDAOImpl &>(getMovieViewingDAO()).createTable();

        objQuery.prepare("create table " + getTableName() + "(" + getPrimaryKey() + " int not null auto_increment primary key, MediaId int not null, Comments varchar(32000) not null default ' ', foreign key(MediaId) references Media(MediaId));");

        return(objQuery.exec());
        }
    else
        return(true);
}

Movie MovieDAOImpl::getById(const unsigned uiMovieId) const
{
    return(AbstractDAO<Movie>::getById(uiMovieId));
}

Movie MovieDAOImpl::getByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Media on Movies.MediaId = Media.MediaId and Media.Name = ? and Media.ReleaseDate between ? and ?;");

    objQuery.bindValue(1, sName);
    objQuery.bindValue(2, QDate(static_cast<int>(uiReleaseYear), 1, 1));
    objQuery.bindValue(3, QDate(static_cast<int>(uiReleaseYear) + 1, 1, 1));

    if(objQuery.exec())
        return(const_cast<MovieDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(Movie());
}

QList<Movie> MovieDAOImpl::list() const
{
    return(AbstractDAO<Movie>::list());
}

QList<Movie> MovieDAOImpl::listByArtist(const Artist &refArtist) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    static_cast<ArtistDAOImpl &>(getArtistDAO()).createTable();
    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<RoleDAOImpl &>(getRoleDAO()).createTable();

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Media on Movies.MediaId = Media.MediaId inner join Roles on Roles.MediaId = Media.MediaId inner join Artists on Roles.ArtistId = Artists.ArtistId and Artists.ArtistId = ?;");

    objQuery.bindValue(1, refArtist.getArtistId());

    if(objQuery.exec())
        return(const_cast<MovieDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Movie>());
}

QList<Movie> MovieDAOImpl::listByArtistAndName(const Artist &refArtist, const QString &sName) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    static_cast<ArtistDAOImpl &>(getArtistDAO()).createTable();
    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<RoleDAOImpl &>(getRoleDAO()).createTable();

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Media on Movies.MediaId = Media.MediaId and Media.Name = ? inner join Roles on Roles.MediaId = Media.MediaId inner join Artists on Roles.ArtistId = Artists.ArtistId and Artists.ArtistId = ?;");

    objQuery.bindValue(1, sName);
    objQuery.bindValue(2, refArtist.getArtistId());

    if(objQuery.exec())
        return(const_cast<MovieDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Movie>());
}

QList<Movie> MovieDAOImpl::listByArtistNameAndReleaseYear(const Artist &refArtist, const QString &sName, const unsigned uiReleaseYear) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    static_cast<ArtistDAOImpl &>(getArtistDAO()).createTable();
    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<RoleDAOImpl &>(getRoleDAO()).createTable();

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Media on Movies.MediaId = Media.MediaId and Media.Name = ? and Media.ReleaseDate between ? and ? inner join Roles on Roles.MediaId = Media.MediaId inner join Artists on Roles.ArtistId = Artists.ArtistId and Artists.ArtistId = ?;");

    objQuery.bindValue(1, sName);
    objQuery.bindValue(2, QDate(static_cast<int>(uiReleaseYear), 1, 1));
    objQuery.bindValue(3, QDate(static_cast<int>(uiReleaseYear) + 1, 1, 1));
    objQuery.bindValue(4, refArtist.getArtistId());

    if(objQuery.exec())
        return(const_cast<MovieDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Movie>());
}

QList<Movie> MovieDAOImpl::listByArtistNameReleaseYearAndRoleType(const Artist &refArtist, const QString &sName, const unsigned uiReleaseYear, const RoleType &refRoleType) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    static_cast<ArtistDAOImpl &>(getArtistDAO()).createTable();
    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<RoleDAOImpl &>(getRoleDAO()).createTable();

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Media on Movies.MediaId = Media.MediaId and Media.Name = ? and Media.ReleaseDate between ? and ? inner join Roles on Roles.MediaId = Media.MediaId and Roles.RoleTypeId = ? inner join Artists on Roles.ArtistId = Artists.ArtistId and Artists.ArtistId = ?;");

    objQuery.bindValue(1, sName);
    objQuery.bindValue(2, QDate(static_cast<int>(uiReleaseYear), 1, 1));
    objQuery.bindValue(3, QDate(static_cast<int>(uiReleaseYear) + 1, 1, 1));
    objQuery.bindValue(4, refRoleType.getRoleTypeId());
    objQuery.bindValue(5, refArtist.getArtistId());

    if(objQuery.exec())
        return(const_cast<MovieDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Movie>());
}

QList<Movie> MovieDAOImpl::listByArtistNameAndRoleType(const Artist &refArtist, const QString &sName, const RoleType &refRoleType) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    static_cast<ArtistDAOImpl &>(getArtistDAO()).createTable();
    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<RoleDAOImpl &>(getRoleDAO()).createTable();

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Media on Movies.MediaId = Media.MediaId and Media.Name = ? inner join Roles on Roles.MediaId = Media.MediaId and Roles.RoleTypeId = ? inner join Artists on Roles.ArtistId = Artists.ArtistId and Artists.ArtistId = ?;");

    objQuery.bindValue(1, sName);
    objQuery.bindValue(2, refRoleType.getRoleTypeId());
    objQuery.bindValue(3, refArtist.getArtistId());

    if(objQuery.exec())
        return(const_cast<MovieDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Movie>());
}

QList<Movie> MovieDAOImpl::listByArtistAndRoleType(const Artist &refArtist, const RoleType &refRoleType) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    static_cast<ArtistDAOImpl &>(getArtistDAO()).createTable();
    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<RoleDAOImpl &>(getRoleDAO()).createTable();

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Media on Movies.MediaId = Media.MediaId inner join Roles on Roles.MediaId = Media.MediaId and Roles.RoleTypeId = ? inner join Artists on Roles.ArtistId = Artists.ArtistId and Artists.ArtistId = ?;");

    objQuery.bindValue(1, refRoleType.getRoleTypeId());
    objQuery.bindValue(2, refArtist.getArtistId());

    if(objQuery.exec())
        return(const_cast<MovieDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Movie>());
}

QList<Movie> MovieDAOImpl::listByName(const QString &sName) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Media on Movies.MediaId = Media.MediaId and Media.Name = ?;");

    objQuery.bindValue(1, sName);

    if(objQuery.exec())
        return(const_cast<MovieDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Movie>());
}

QList<Movie> MovieDAOImpl::listByReleaseYear(const unsigned uiReleaseYear) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Media on Movies.MediaId = Media.MediaId and Media.ReleaseDate between ? and ?;");

    objQuery.bindValue(1, QDate(static_cast<int>(uiReleaseYear), 1, 1));
    objQuery.bindValue(2, QDate(static_cast<int>(uiReleaseYear) + 1, 1, 1));

    if(objQuery.exec())
        return(const_cast<MovieDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Movie>());
}

QList<Movie> MovieDAOImpl::listByWordInComments(const QString &sWord) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " where Comments like ?;");

    objQuery.bindValue(1, "%" + sWord + "%");

    if(objQuery.exec())
        return(const_cast<MovieDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Movie>());
}

bool MovieDAOImpl::remove(const Movie &refToRemove) const
{
    return(AbstractDAO<Movie>::remove(refToRemove.getMovieId()));
}

Movie &MovieDAOImpl::save(const Movie &refToSave) const
{
    if(!isTableExists())
        createTable();

    if(refToSave.getMovieId() > 0)
        return(update(refToSave));
    else
        return(insert(refToSave));
}
