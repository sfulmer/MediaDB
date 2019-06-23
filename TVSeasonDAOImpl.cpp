#include "BeanFactory.h"
#include "MediaDAOImpl.h"
#include<QtSql/QSqlField>
#include "RoleDAOImpl.h"
#include "TVEpisodeDAOImpl.h"
#include "TVSeasonDAOImpl.h"
#include "TVSeriesDAOImpl.h"

using namespace net::draconia::mediadb::dao;

using net::draconia::mediadb::BeanFactory;

const QString TVSeasonDAOImpl::TableName("TVSeasons");

TVSeason TVSeasonDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    TVSeries objTVSeries = getTVSeriesDAO().getById(refRecord.field("TVSeriesId").value().toUInt());
    TVSeason objTVSeason = TVSeason(    objTVSeries
                                   ,    refRecord.field("TVSeasonId").value().toUInt()
                                   ,    refRecord.field("SeasonNumber").value().toUInt()
                                   ,    refRecord.field("Comments").value().toString());

    for(TVEpisode objTVEpisode : getTVEpisodeDAO().listBySeason(objTVSeason))
        objTVSeason.addEpisode(objTVEpisode);

    return(objTVSeason);
}

MediaDAO &TVSeasonDAOImpl::getMediaDAO() const
{
    return(mRefMediaDAO);
}

QString TVSeasonDAOImpl::getPrimaryKey() const
{
    return("TVSeasonId");
}

QString TVSeasonDAOImpl::getQueriedColumnsForSelect() const
{
    return("TVSeriesId, SeasonNumber, Comments");
}

RoleDAO &TVSeasonDAOImpl::getRoleDAO() const
{
    return(mRefRoleDAO);
}

QString TVSeasonDAOImpl::getTableName() const
{
    return(TableName);
}

TVEpisodeDAO &TVSeasonDAOImpl::getTVEpisodeDAO() const
{
    return(mRefTVEpisodeDAO);
}

TVSeriesDAO &TVSeasonDAOImpl::getTVSeriesDAO() const
{
    return(mRefTVSeriesDAO);
}

TVSeason &TVSeasonDAOImpl::insert(const TVSeason &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into " + getTableName() + "(" + getQueriedColumnsForSelect() + ") values(?, ?, ?);");

    objQuery.bindValue(1, refToSave.getSeries().getTVSeriesId());
    objQuery.bindValue(2, refToSave.getNumber());
    objQuery.bindValue(3, refToSave.getComments());

    if(objQuery.exec())
        const_cast<TVSeason &>(refToSave).setSeasonId(objQuery.lastInsertId().toUInt());

    return(const_cast<TVSeason &>(refToSave));
}

TVSeason &TVSeasonDAOImpl::update(const TVSeason &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("update " + getTableName() + " set TVSeriesId = ?, SeasonNumber = ?, Comments = ? where " + getPrimaryKey() + " = ?;");

    objQuery.bindValue(1, refToSave.getSeries().getTVSeriesId());
    objQuery.bindValue(2, refToSave.getNumber());
    objQuery.bindValue(3, refToSave.getComments());
    objQuery.bindValue(4, refToSave.getSeasonId());

    objQuery.exec();

    return(const_cast<TVSeason &>(refToSave));
}

TVSeasonDAOImpl::TVSeasonDAOImpl(const QSqlDatabase &refDatabase)
    : AbstractDAO<TVSeason>(refDatabase)
    , mRefMediaDAO(BeanFactory::getInstance().getMediaDAO())
    , mRefRoleDAO(BeanFactory::getInstance().getRoleDAO())
    , mRefTVEpisodeDAO(BeanFactory::getInstance().getTVEpisodeDAO())
    , mRefTVSeriesDAO(BeanFactory::getInstance().getTVSeriesDAO())
{ }

TVSeasonDAOImpl::~TVSeasonDAOImpl()
{ }

bool TVSeasonDAOImpl::createTable() const
{
    if(!isTableExists())
        {
        QSqlQuery objQuery(getDatabase());

        objQuery.prepare("create table " + getTableName() + "(" + getPrimaryKey() + " int not null auto_increment primary key, TVSeriesId int not null, SeasonNumber int not null, Comments varchar(32000) not null default ' ', foreign key(TVSeriesId) references TVSeries(TVSeriesId));");

        static_cast<TVSeriesDAOImpl &>(getTVSeriesDAO()).createTable();

        return(objQuery.exec());
        }
    else
        return(true);
}

TVSeason TVSeasonDAOImpl::getById(const unsigned uiTVSeasonId) const
{
    return(AbstractDAO<TVSeason>::getById(uiTVSeasonId));
}

TVSeason TVSeasonDAOImpl::getByTVSeriesAndNumber(const TVSeries &refTVSeries, const unsigned uiNumber) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " where TVSeriesId = ? and SeasonNumber = ?;");

    objQuery.bindValue(1, refTVSeries.getTVSeriesId());
    objQuery.bindValue(2, uiNumber);

    if(objQuery.exec())
        return(const_cast<TVSeasonDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(TVSeason());
}

QList<TVSeason> TVSeasonDAOImpl::list() const
{
    return(AbstractDAO<TVSeason>::list());
}

QList<TVSeason> TVSeasonDAOImpl::listByArtist(const Artist &refArtist) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select distinct " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join TVEpisodes on TVEpisodes.TVSeasonId = TVSeasons.TVSeasonId inner join Media on TVEpisodes.MediaId = Media.MediaId inner join Roles on Roles.MediaId = Media.MediaId and Roles.ArtistId = ?;");

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<RoleDAOImpl &>(getRoleDAO()).createTable();
    static_cast<TVEpisodeDAOImpl &>(getTVEpisodeDAO()).createTable();

    objQuery.bindValue(1, refArtist.getArtistId());

    if(objQuery.exec())
        return(const_cast<TVSeasonDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVSeason>());
}

QList<TVSeason> TVSeasonDAOImpl::listByTVSeries(const TVSeries &refTVSeries) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select distinct " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " where TVSeriesId = ?;");

    objQuery.bindValue(1, refTVSeries.getTVSeriesId());

    if(objQuery.exec())
        return(const_cast<TVSeasonDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVSeason>());
}

QList<TVSeason> TVSeasonDAOImpl::listByTVSeriesAndArtist(const TVSeries &refTVSeries, const Artist &refArtist) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select distinct " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join TVEpisodes on TVEpisodes.TVSeasonId = TVSeasons.TVSeasonId inner join Media on TVEpisodes.MediaId = Media.MediaId inner join Roles on Roles.MediaId = Media.MediaId and Roles.ArtistId = ? where TVSeriesId = ?;");

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<RoleDAOImpl &>(getRoleDAO()).createTable();
    static_cast<TVEpisodeDAOImpl &>(getTVEpisodeDAO()).createTable();

    objQuery.bindValue(1, refArtist.getArtistId());
    objQuery.bindValue(2, refTVSeries.getTVSeriesId());

    if(objQuery.exec())
        return(const_cast<TVSeasonDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVSeason>());
}

QList<TVSeason> TVSeasonDAOImpl::listByTVSeriesAndEpisodeName(const TVSeries &refTVSeries, const QString &sName) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select distinct " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join TVEpisodes on TVEpisodes.TVSeasonId = TVSeasons.TVSeasonId inner join Media on TVEpisodes.MediaId = Media.MediaId and Media.Name = ? where TVSeriesId = ?;");

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<TVEpisodeDAOImpl &>(getTVEpisodeDAO()).createTable();

    objQuery.bindValue(1, sName);
    objQuery.bindValue(2, refTVSeries.getTVSeriesId());

    if(objQuery.exec())
        return(const_cast<TVSeasonDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVSeason>());
}

QList<TVSeason> TVSeasonDAOImpl::listByWordInComments(const QString &sWord) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select distinct " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " where Comments like ?;");

    objQuery.bindValue(1, "%" + sWord + "%");

    if(objQuery.exec())
        return(const_cast<TVSeasonDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVSeason>());
}

bool TVSeasonDAOImpl::remove(const TVSeason &refToRemove) const
{
    return(AbstractDAO<TVSeason>::remove(refToRemove.getSeasonId()));
}

TVSeason &TVSeasonDAOImpl::save(const TVSeason &refToSave) const
{
    if(!isTableExists())
        createTable();

    if(refToSave.getSeasonId() > 0)
        return(update(refToSave));
    else
        return(insert(refToSave));
}
