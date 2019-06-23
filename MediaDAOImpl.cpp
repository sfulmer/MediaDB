#include "Artist.h"
#include "ArtistDAOImpl.h"
#include "MediaDAOImpl.h"
#include<QtSql/QSqlField>
#include "RoleDAOImpl.h"

using namespace net::draconia::mediadb::dao;
using net::draconia::mediadb::dbo::Artist;

const QString MediaDAOImpl::TableName("Media");

Media MediaDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    Media objMedia;

    objMedia.setMediaId(refRecord.field("MediaId").value().toUInt());
    objMedia.setName(refRecord.field("Name").value().toString());
    objMedia.setReleaseDate(refRecord.field("ReleaseDate").value().toDate());
    objMedia.setFilePath(refRecord.field("FilePath").value().toString());

    for(Artist objArtist : getArtistDAO().listByMedia(objMedia))
        objMedia.addArtist(objArtist);

    return(objMedia);
}

ArtistDAO &MediaDAOImpl::getArtistDAO() const
{
    return(mRefArtistDAO);
}

QString MediaDAOImpl::getPrimaryKey() const
{
    return("MediaId");
}

QString MediaDAOImpl::getQueriedColumnsForSelect() const
{
    return("Name, ReleaseDate, FilePath");
}

RoleDAO &MediaDAOImpl::getRoleDAO() const
{
    return(mRefRoleDAO);
}

QString MediaDAOImpl::getTableName() const
{
    return(TableName);
}

Media &MediaDAOImpl::insert(const Media &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into " + TableName + "(" + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + ") values(?, ?, ?, ?);");

    objQuery.bindValue(1, refToSave.getMediaId());
    objQuery.bindValue(2, refToSave.getName());
    objQuery.bindValue(3, refToSave.getReleaseDate());
    objQuery.bindValue(4, refToSave.getFilePath());

    if(objQuery.exec())
        const_cast<Media &>(refToSave).setMediaId(objQuery.lastInsertId().toUInt());

    return(const_cast<Media &>(refToSave));
}

Media &MediaDAOImpl::update(const Media &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("update " + TableName + "set Name = ?, ReleaseDate = ?, FilePath = ? where " + getPrimaryKey() + " = ?;");

    objQuery.bindValue(1, refToSave.getName());
    objQuery.bindValue(2, refToSave.getReleaseDate());
    objQuery.bindValue(3, refToSave.getFilePath());
    objQuery.bindValue(4, refToSave.getMediaId());

    objQuery.exec();

    return(const_cast<Media &>(refToSave));
}

MediaDAOImpl::MediaDAOImpl(const QSqlDatabase &refDatasource)
    : AbstractDAO<Media>(refDatasource)
    , mRefArtistDAO(BeanFactory::getInstance().getArtistDAO())
    , mRefRoleDAO(BeanFactory::getInstance().getRoleDAO())
{ }

bool MediaDAOImpl::createTable() const
{
    if(!isTableExists())
        {
        QSqlQuery objQuery(getDatabase());

        objQuery.prepare("create table " + TableName + "(MediaId int not null auto_increment primary key, Name varchar(255) not null, ReleaseDate date not null, FilePath varchar(255) not null, unique key(Name, ReleaseDate));");

        return(objQuery.exec());
        }
    else
        return(true);
}

Media MediaDAOImpl::getById(const unsigned uiMediaId) const
{
    return(AbstractDAO<Media>::getById(uiMediaId));
}

Media MediaDAOImpl::getByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " where Name = ? and ReleaseDate between ? and ?;");

    objQuery.bindValue(1, sName);
    objQuery.bindValue(2, QDate(static_cast<int>(uiReleaseYear), 1, 1));
    objQuery.bindValue(3, QDate(static_cast<int>(uiReleaseYear + 1), 1, 1));

    if(objQuery.exec())
        return(const_cast<MediaDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(Media());
}

QList<Media> MediaDAOImpl::list() const
{
    return(AbstractDAO<Media>::list());
}

QList<Media> MediaDAOImpl::listByArtist(const Artist &refArtist) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Roles on Roles.MediaId = Media.MediaId inner join Artists on Roles.ArtistId = Artist.ArtistId and Artist.ArtistId = ?;");

    reinterpret_cast<ArtistDAOImpl &>(getArtistDAO()).createTable();
    reinterpret_cast<RoleDAOImpl &>(getRoleDAO()).createTable();

    objQuery.bindValue(1, refArtist.getArtistId());

    if(objQuery.exec())
        return(const_cast<MediaDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Media>());
}

QList<Media> MediaDAOImpl::listByArtistAndName(const Artist &refArtist, const QString &sName) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Artists on Artists.MediaId = Media.MediaId and Artist.ArtistId = ? where Media.Name = ?;");

    reinterpret_cast<ArtistDAOImpl &>(getArtistDAO()).createTable();
    reinterpret_cast<RoleDAOImpl &>(getRoleDAO()).createTable();

    objQuery.bindValue(1, refArtist.getArtistId());
    objQuery.bindValue(2, sName);

    if(objQuery.exec())
        return(const_cast<MediaDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Media>());
}

QList<Media> MediaDAOImpl::listByArtistNameAndReleaseYear(const Artist &refArtist, const QString &sName, const unsigned uiReleaseYear) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Artists on Artists.MediaId = Media.MediaId and Artist.ArtistId = ? where Media.Name = ? and Media.ReleaseDate between ? and ?;");

    reinterpret_cast<ArtistDAOImpl &>(getArtistDAO()).createTable();
    reinterpret_cast<RoleDAOImpl &>(getRoleDAO()).createTable();

    objQuery.bindValue(1, refArtist.getArtistId());
    objQuery.bindValue(2, sName);
    objQuery.bindValue(3, QDate(static_cast<int>(uiReleaseYear), 1, 1));
    objQuery.bindValue(4, QDate(static_cast<int>(uiReleaseYear + 1), 1, 1));

    if(objQuery.exec())
        return(const_cast<MediaDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Media>());
}

QList<Media> MediaDAOImpl::listByArtistNameReleaseYearAndRoleType(const Artist &refArtist, const QString &sName, const unsigned uiReleaseYear, const RoleType &refRoleType) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Artists on Artists.MediaId = Media.MediaId and Artist.ArtistId = ? inner join Role on Role.ArtistId = Artist.ArtistId and Role.RoleTypeId = ? where Media.Name = ? and Media.ReleaseDate between ? and ?;");

    reinterpret_cast<ArtistDAOImpl &>(getArtistDAO()).createTable();
    reinterpret_cast<RoleDAOImpl &>(getRoleDAO()).createTable();

    objQuery.bindValue(1, refArtist.getArtistId());
    objQuery.bindValue(2, refRoleType.getRoleTypeId());
    objQuery.bindValue(3, sName);
    objQuery.bindValue(4, QDate(static_cast<int>(uiReleaseYear), 1, 1));
    objQuery.bindValue(5, QDate(static_cast<int>(uiReleaseYear + 1), 1, 1));

    if(objQuery.exec())
        return(const_cast<MediaDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Media>());
}

QList<Media> MediaDAOImpl::listByArtistNameAndRoleType(const Artist &refArtist, const QString &sName, const RoleType &refRoleType) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Artists on Artists.MediaId = Media.MediaId and Artist.ArtistId = ? inner join Role on Role.ArtistId = Artist.ArtistId and Role.RoleTypeId = ? where Media.Name = ?;");

    reinterpret_cast<ArtistDAOImpl &>(getArtistDAO()).createTable();
    reinterpret_cast<RoleDAOImpl &>(getRoleDAO()).createTable();

    objQuery.bindValue(1, refArtist.getArtistId());
    objQuery.bindValue(2, refRoleType.getRoleTypeId());
    objQuery.bindValue(3, sName);

    if(objQuery.exec())
        return(const_cast<MediaDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Media>());
}

QList<Media> MediaDAOImpl::listByArtistAndRoleType(const Artist &refArtist, const RoleType &refRoleType) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Artists on Artists.MediaId = Media.MediaId and Artist.ArtistId = ? inner join Role on Artist.RoleId = Role.RoleId and Role.RoleTypeId = ?;");

    reinterpret_cast<ArtistDAOImpl &>(getArtistDAO()).createTable();
    reinterpret_cast<RoleDAOImpl &>(getRoleDAO()).createTable();

    objQuery.bindValue(1, refArtist.getArtistId());
    objQuery.bindValue(2, refRoleType.getRoleTypeId());

    if(objQuery.exec())
        return(const_cast<MediaDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Media>());
}

QList<Media> MediaDAOImpl::listByName(const QString &sName) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " where Name = ?;");

    objQuery.bindValue(1, sName);

    if(objQuery.exec())
        return(const_cast<MediaDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Media>());
}

QList<Media> MediaDAOImpl::listByReleaseYear(const unsigned uiReleaseYear) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " where ReleaseDate between ? and ?;");

    objQuery.bindValue(1, QDate(static_cast<int>(uiReleaseYear), 1, 1));
    objQuery.bindValue(2, QDate(static_cast<int>(uiReleaseYear + 1), 1, 1));

    if(objQuery.exec())
        return(const_cast<MediaDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Media>());
}

bool MediaDAOImpl::remove(const Media &refMedia) const
{
    return(AbstractDAO<Media>::remove(refMedia.getMediaId()));
}

Media &MediaDAOImpl::save(const Media &refToSave) const
{
    if(!isTableExists())
        createTable();

    if(refToSave.getMediaId() > 0)
        return(update(refToSave));
    else
        return(insert(refToSave));
}
