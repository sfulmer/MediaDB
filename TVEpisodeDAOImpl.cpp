#include "MediaDAOImpl.h"
#include<QtSql/QSqlField>
#include "RoleDAOImpl.h"
#include "TVEpisodeDAOImpl.h"
#include "TVSeasonDAOImpl.h"

using namespace net::draconia::mediadb::dao;

using net::draconia::mediadb::dbo::Media;

const QString TVEpisodeDAOImpl::TableName("TVEpisodes");

TVEpisode TVEpisodeDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    Media objMedia = getMediaDAO().getById(refRecord.field("MediaId").value().toUInt());
    TVSeason objTVSeason = getTVSeasonDAO().getById(refRecord.field("TVSeasonId").value().toUInt());

    return(TVEpisode(   objTVSeason
                    ,   objMedia.getMediaId()
                    ,   refRecord.field("TVEpisodeId").value().toUInt()
                    ,   refRecord.field("EpisodeNumber").value().toUInt()
                    ,   objMedia.getName()
                    ,   objMedia.getReleaseDate()
                    ,   objMedia.getFilePath()
                    ,   objMedia.getArtists()
                    ,   refRecord.field("Comments").value().toString()));
}

MediaDAO &TVEpisodeDAOImpl::getMediaDAO() const
{
    return(mRefMediaDAO);
}

QString TVEpisodeDAOImpl::getPrimaryKey() const
{
    return("TVEpisodeId");
}

QString TVEpisodeDAOImpl::getQueriedColumnsForSelect() const
{
    return("MediaId, EpisodeNumber, TVSeasonId, Comments");
}

RoleDAO &TVEpisodeDAOImpl::getRoleDAO() const
{
    return(mRefRoleDAO);
}

QString TVEpisodeDAOImpl::getTableName() const
{
    return(TableName);
}

TVSeasonDAO &TVEpisodeDAOImpl::getTVSeasonDAO() const
{
    return(mRefTVSeasonDAO);
}

TVEpisode &TVEpisodeDAOImpl::insert(const TVEpisode &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into " + getTableName() + " (" + getQueriedColumnsForSelect() + ") values(?, ?, ?, ?);");

    getMediaDAO().save(refToSave);
    getTVSeasonDAO().save(refToSave.getSeason());

    objQuery.bindValue(1, refToSave.getMediaId());
    objQuery.bindValue(2, refToSave.getNumber());
    objQuery.bindValue(3, refToSave.getSeason().getSeasonId());
    objQuery.bindValue(4, refToSave.getComments());

    if(objQuery.exec())
        const_cast<TVEpisode &>(refToSave).setTVEpisodeId(objQuery.lastInsertId().toUInt());

    return(const_cast<TVEpisode &>(refToSave));
}

TVEpisode &TVEpisodeDAOImpl::update(const TVEpisode &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("update " + getTableName() + " set MediaId = ?, EpisodeNumber = ?, TVSeasonId = ?, Comments = ? where " + getPrimaryKey() + " = ;");

    getMediaDAO().save(refToSave);
    getTVSeasonDAO().save(refToSave.getSeason());

    objQuery.bindValue(1, refToSave.getMediaId());
    objQuery.bindValue(2, refToSave.getNumber());
    objQuery.bindValue(3, refToSave.getSeason().getSeasonId());
    objQuery.bindValue(4, refToSave.getComments());
    objQuery.bindValue(5, refToSave.getTVEpisodeId());

    objQuery.exec();

    return(const_cast<TVEpisode &>(refToSave));
}

TVEpisodeDAOImpl::TVEpisodeDAOImpl(const QSqlDatabase &refDatabase)
    : AbstractDAO<TVEpisode>(refDatabase)
    , mRefMediaDAO(BeanFactory::getInstance().getMediaDAO())
    , mRefRoleDAO(BeanFactory::getInstance().getRoleDAO())
    , mRefTVSeasonDAO(BeanFactory::getInstance().getTVSeasonDAO())
{ }

TVEpisodeDAOImpl::~TVEpisodeDAOImpl()
{ }

bool TVEpisodeDAOImpl::createTable() const
{
    if(!isTableExists())
        {
        QSqlQuery objQuery(getDatabase());

        objQuery.prepare("create table " + getTableName() + "(" + getPrimaryKey() + " int not null auto_increment primary key, MediaId int not null, EpisodeNumber int not null, TVSeasonId int not null, Comments varchar(32000) not null default ' ', foreign key(MediaId) references Media(MediaId));");

        return(objQuery.exec());
        }
    else
        return(true);
}

TVEpisode TVEpisodeDAOImpl::getById(const unsigned uiId) const
{
    static_cast<TVSeasonDAOImpl &>(getTVSeasonDAO()).createTable();

    return(AbstractDAO<TVEpisode>::getById(uiId));
}

TVEpisode TVEpisodeDAOImpl::getBySeasonAndEpisodeNumber(const TVSeason &refSeason, const unsigned uiEpisodeNumber) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " where TVSeasonId = ? and EpisodeNumber = ?;");

    static_cast<TVSeasonDAOImpl &>(getTVSeasonDAO()).createTable();

    objQuery.bindValue(1, refSeason.getSeasonId());
    objQuery.bindValue(2, uiEpisodeNumber);

    if(objQuery.exec())
        return(const_cast<TVEpisodeDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(TVEpisode());
}

TVEpisode TVEpisodeDAOImpl::getBySeasonAndName(const TVSeason &refSeason, const QString &sName) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Media on " + getTableName() + ".MediaId = Media.MediaId and Media.Name = ? where TVSeasonId = ? and EpisodeNumber = ?;");

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<TVSeasonDAOImpl &>(getTVSeasonDAO()).createTable();

    objQuery.bindValue(1, sName);
    objQuery.bindValue(2, refSeason.getSeasonId());

    if(objQuery.exec())
        return(const_cast<TVEpisodeDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(TVEpisode());
}

QList<TVEpisode> TVEpisodeDAOImpl::list() const
{
    static_cast<TVSeasonDAOImpl &>(getTVSeasonDAO()).createTable();

    return(AbstractDAO<TVEpisode>::list());
}

QList<TVEpisode> TVEpisodeDAOImpl::listByArtist(const Artist &refArtist) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Media on " + getTableName() + ".MediaId = Media.MediaId inner join Roles on Roles.MediaId = Media.MediaId and Roles.ArtistId = ?;");

    static_cast<RoleDAOImpl &>(getRoleDAO()).createTable();
    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<TVSeasonDAOImpl &>(getTVSeasonDAO()).createTable();

    objQuery.bindValue(1, refArtist.getArtistId());

    if(objQuery.exec())
        return(const_cast<TVEpisodeDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVEpisode>());
}

QList<TVEpisode> TVEpisodeDAOImpl::listByName(const QString &sName) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Media on " + getTableName() + ".MediaId = Media.MediaId and Media.Name = ?;");

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<TVSeasonDAOImpl &>(getTVSeasonDAO()).createTable();

    objQuery.bindValue(1, sName);

    if(objQuery.exec())
        return(const_cast<TVEpisodeDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVEpisode>());
}

QList<TVEpisode> TVEpisodeDAOImpl::listByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Media on " + getTableName() + ".MediaId = Media.MediaId inner join Roles on Roles.MediaId = Media.MediaId and Roles.ArtistId = ? and Media.ReleaseDate between ? and ?;");

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<TVSeasonDAOImpl &>(getTVSeasonDAO()).createTable();

    objQuery.bindValue(1, sName);
    objQuery.bindValue(2, QDate(static_cast<int>(uiReleaseYear), 1, 1));
    objQuery.bindValue(3, QDate(static_cast<int>(uiReleaseYear) + 1, 1, 1));

    if(objQuery.exec())
        return(const_cast<TVEpisodeDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVEpisode>());
}

QList<TVEpisode> TVEpisodeDAOImpl::listBySeason(const TVSeason &refSeason) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " where TVSeasonId = ?;");

    static_cast<TVSeasonDAOImpl &>(getTVSeasonDAO()).createTable();

    objQuery.bindValue(1, refSeason.getSeasonId());

    if(objQuery.exec())
        return(const_cast<TVEpisodeDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVEpisode>());
}

QList<TVEpisode> TVEpisodeDAOImpl::listBySeasonAndArtist(const TVSeason &refSeason, const Artist &refArtist) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Media on " + getTableName() + ".MediaId = Media.MediaId inner join Roles on Roles.MediaId = Media.Mediaid and Roles.ArtistId = ? where TVSeasonId = ?;");

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<RoleDAOImpl &>(getRoleDAO()).createTable();
    static_cast<TVSeasonDAOImpl &>(getTVSeasonDAO()).createTable();

    objQuery.bindValue(1, refArtist.getArtistId());
    objQuery.bindValue(2, refSeason.getSeasonId());

    if(objQuery.exec())
        return(const_cast<TVEpisodeDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVEpisode>());
}

QList<TVEpisode> TVEpisodeDAOImpl::listByWordInComments(const QString &sWord) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " where Comments like ?;");

    static_cast<TVSeasonDAOImpl &>(getTVSeasonDAO()).createTable();

    objQuery.bindValue(1, "%" + sWord + "%");

    if(objQuery.exec())
        return(const_cast<TVEpisodeDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVEpisode>());
}

bool TVEpisodeDAOImpl::remove(const TVEpisode &refToRemove) const
{
    return(AbstractDAO<TVEpisode>::remove(refToRemove.getTVEpisodeId()));
}

TVEpisode &TVEpisodeDAOImpl::save(const TVEpisode &refToSave) const
{
    if(!isTableExists())
        createTable();

    if(refToSave.getTVEpisodeId() > 0)
        return(update(refToSave));
    else
        return(insert(refToSave));
}
