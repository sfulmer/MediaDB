#include "BeanFactory.h"
#include "MediaDAOImpl.h"
#include<QtSql/QSqlField>
#include "RoleDAOImpl.h"
#include "TVEpisodeDAOImpl.h"
#include "TVSeasonDAOImpl.h"
#include "TVSeriesDAOImpl.h"

using namespace net::draconia::mediadb::dao;

using net::draconia::mediadb::BeanFactory;

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

RoleDAO &TVSeasonDAOImpl::getRoleDAO() const
{
    return(mRefRoleDAO);
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

    objQuery.prepare("insert into TVSeasons (TVSeriesId, SeasonNumber, Comments) values(?, ?, ?);");

    objQuery.bindValue(1, refToSave.getSeries().getTVSeriesId());
    objQuery.bindValue(2, refToSave.getNumber());
    objQuery.bindValue(3, refToSave.getComments());

    if(objQuery.exec())
        const_cast<TVSeason &>(refToSave).setSeasonId(objQuery.lastInsertId().toUInt());

    return(const_cast<TVSeason &>(refToSave));
}

bool TVSeasonDAOImpl::isTableExists() const
{
    return(const_cast<TVSeasonDAOImpl &>(*this).getTableUtils().isTableExists("TVSeasons"));
}

void TVSeasonDAOImpl::removeTable()
{
    getTableUtils().removeTable("TVSeasons");
}

TVSeason &TVSeasonDAOImpl::update(const TVSeason &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("update TVSeasons set TVSeriesId = ?, SeasonNumber = ?, Comments = ? where TVSeasonId = ?;");

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

        objQuery.prepare("create table TVSeasons (TVSeasonId int not null auto_increment primary key, TVSeriesId int not null, SeasonNumber int not null, Comments varchar(32000) not null default ' ', foreign key(TVSeriesId) references TVSeries(TVSeriesId));");

        static_cast<TVSeriesDAOImpl &>(getTVSeriesDAO()).createTable();

        return(objQuery.exec());
        }
    else
        return(true);
}

TVSeason TVSeasonDAOImpl::getById(const unsigned uiTVSeasonId) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select TVSeasonId, TVSeriesId, SeasonNumber, Comments from TVSeasons where TVSeasonId = ?;");

    objQuery.bindValue(1, uiTVSeasonId);

    if(objQuery.exec())
        return(const_cast<TVSeasonDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(TVSeason());
}

TVSeason TVSeasonDAOImpl::getByTVSeriesAndNumber(const TVSeries &refTVSeries, const unsigned uiNumber) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select TVSeasonId, TVSeriesId, SeasonNumber, Comments from TVSeasons where TVSeriesId = ? and SeasonNumber = ?;");

    objQuery.bindValue(1, refTVSeries.getTVSeriesId());
    objQuery.bindValue(2, uiNumber);

    if(objQuery.exec())
        return(const_cast<TVSeasonDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(TVSeason());
}

QList<TVSeason> TVSeasonDAOImpl::list() const
{
   if(!isTableExists())
       createTable();

   QSqlQuery objQuery(getDatabase());

   objQuery.prepare("select TVSeasonId, TVSeriesId, SeasonNumber, Comments from TVSeasons;");

   if(objQuery.exec())
       return(const_cast<TVSeasonDAOImpl &>(*this).createObjectListFromResults(objQuery));
   else
       return(QList<TVSeason>());
}

QList<TVSeason> TVSeasonDAOImpl::listByArtist(const Artist &refArtist) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select TVSeasonId, TVSeriesId, SeasonNumber, Comments from TVSeasons inner join TVEpisodes on TVEpisodes.TVSeasonId = TVSeasons.TVSeasonId inner join Media on TVEpisodes.MediaId = Media.MediaId inner join Roles on Roles.MediaId = Media.MediaId and Roles.ArtistId = ?;");

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

    objQuery.prepare("select TVSeasonId, TVSeriesId, SeasonNumber, Comments from TVSeasons where TVSeriesId = ?;");

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

    objQuery.prepare("select TVSeasonId, TVSeriesId, SeasonNumber, Comments from TVSeasons inner join TVEpisodes on TVEpisodes.TVSeasonId = TVSeasons.TVSeasonId inner join Media on TVEpisodes.MediaId = Media.MediaId inner join Roles on Roles.MediaId = Media.MediaId and Roles.ArtistId = ? where TVSeriesId = ?;");

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

    objQuery.prepare("select TVSeasonId, TVSeriesId, SeasonNumber, Comments from TVSeasons inner join TVEpisodes on TVEpisodes.TVSeasonId = TVSeasons.TVSeasonId inner join Media on TVEpisodes.MediaId = Media.MediaId and Media.Name = ? where TVSeriesId = ?;");

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

    objQuery.prepare("select TVSeasonId, TVSeriesId, SeasonNumber, Comments from TVSeasons where Comments like ?;");

    objQuery.bindValue(1, "%" + sWord + "%");

    if(objQuery.exec())
        return(const_cast<TVSeasonDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVSeason>());
}

bool TVSeasonDAOImpl::remove(const TVSeason &refToRemove) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("delete from TVSeasons where TVSeasonId = ?;");

    objQuery.bindValue(1, refToRemove.getSeasonId());

    return(objQuery.exec());
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
