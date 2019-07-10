#include<QtSql/QSqlField>
#include "TVSeasonDAOImpl.h"
#include "TVSeriesDAOImpl.h"
#include "TVSpecialDAOImpl.h"

using namespace net::draconia::mediadb::dao;

using net::draconia::mediadb::dbo::TVSeries;
using net::draconia::mediadb::dbo::TVSpecial;

TVSeries TVSeriesDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    TVSeries objSeries = TVSeries   (    refRecord.field("TVSeriesId").value().toUInt()
                                    ,    refRecord.field("Name").value().toString()
                                    ,    refRecord.field("Comments").value().toString());

    for(TVSeason objSeason : getTVSeasonDAO().listByTVSeries(objSeries))
        objSeries.addSeason(objSeason);

    for(TVSpecial objSpecial : getTVSpecialDAO().listByTVSeries(objSeries))
        objSeries.addSpecial(objSpecial);

    return(objSeries);
}

TVSeasonDAO &TVSeriesDAOImpl::getTVSeasonDAO() const
{
    return(mRefTVSeasonDAO);
}

TVSpecialDAO &TVSeriesDAOImpl::getTVSpecialDAO() const
{
    return(mRefTVSpecialDAO);
}

TVSeries &TVSeriesDAOImpl::insert(const TVSeries &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into TVSeries (Name, Comments) values(?, ?);");

    objQuery.bindValue(1, refToSave.getName());
    objQuery.bindValue(2, refToSave.getComments());

    if(objQuery.exec())
        const_cast<TVSeries &>(refToSave).setTVSeriesId(objQuery.lastInsertId().toUInt());

    return(const_cast<TVSeries &>(refToSave));
}

bool TVSeriesDAOImpl::isTableExists() const
{
    return(const_cast<TVSeriesDAOImpl &>(*this).getTableUtils().isTableExists("TVSeries"));
}

void TVSeriesDAOImpl::removeTable()
{
    getTableUtils().removeTable("TVSeries");
}

TVSeries &TVSeriesDAOImpl::update(const TVSeries &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("upate TVSeries set Name = ?, Comments = ? where TVSeriesId = ?;");

    objQuery.bindValue(1, refToSave.getName());
    objQuery.bindValue(2, refToSave.getComments());
    objQuery.bindValue(3, refToSave.getTVSeriesId());

    objQuery.exec();

    return(const_cast<TVSeries &>(refToSave));
}

TVSeriesDAOImpl::TVSeriesDAOImpl(const QSqlDatabase &refDatabase)
    : AbstractDAO<TVSeries>(refDatabase)
    , mRefTVSeasonDAO(BeanFactory::getInstance().getTVSeasonDAO())
    , mRefTVSpecialDAO(BeanFactory::getInstance().getTVSpecialDAO())
{ }

TVSeriesDAOImpl::~TVSeriesDAOImpl()
{ }

bool TVSeriesDAOImpl::createTable() const
{
    if(!isTableExists())
        {
        QSqlQuery objQuery(getDatabase());

        objQuery.prepare("create table TVSeries(TVSeriesId int not null auto_increment primary key, Name varchar(255) not null, Comments varchar(32000) not null default ' ');");

        return(objQuery.exec());
        }
    else
        return(true);
}

TVSeries TVSeriesDAOImpl::getById(const unsigned uiId) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select TVSeriesId, Name, Comments from TVSeries where TvSeriesId = ?;");

    objQuery.bindValue(1, uiId);

    if(objQuery.exec())
        return(const_cast<TVSeriesDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(TVSeries());
}

QList<TVSeries> TVSeriesDAOImpl::list() const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select TVSeriesId, Name, Comments from TVSeries;");

    if(objQuery.exec())
        return(const_cast<TVSeriesDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVSeries>());
}

QList<TVSeries> TVSeriesDAOImpl::listByName(const QString &sName) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select TVSeriesId, Name, Comments from TVSeries where Name = ?;");

    objQuery.bindValue(1, sName);

    if(objQuery.exec())
        return(const_cast<TVSeriesDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVSeries>());
}

QList<TVSeries> TVSeriesDAOImpl::listByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const
{
    if(!isTableExists())
        createTable();

    QDate dtReleased(static_cast<int>(uiReleaseYear), 1, 1)
        , dtReleasedPlusOneYear = dtReleased.addYears(1);
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select distinct TVSeries.TVSeriesId TVSeriesId, TVSeries.Name Name, TVSeries.Comments Comments from TVSeries inner join TVSeasons on TVSeries.TVSeriesId = TVSeasons.TVSeriesId inner join TVEpisodes on TVEpisodes.TVSeasonId = TVSeasons.TVSeasonId inner join Media m1 on TVEpisodes.MediaId = m1.MediaId and m1.ReleaseDate between ? and ? inner join TVSpecials on TVSpecials.TVSeriesId = TVSeries.TVSeriesId inner join Media m2 on TVSpecials.MediaId = m2.MediaId and m2.ReleaseDate between ? and ? where TVSeries.Name = ?;");

    objQuery.bindValue(1, dtReleased);
    objQuery.bindValue(2, dtReleasedPlusOneYear);
    objQuery.bindValue(3, dtReleased);
    objQuery.bindValue(4, dtReleasedPlusOneYear);
    objQuery.bindValue(5, sName);

    if(objQuery.exec())
        return(const_cast<TVSeriesDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVSeries>());
}

QList<TVSeries> TVSeriesDAOImpl::listByReleaseYear(const unsigned uiReleaseYear) const
{
    if(!isTableExists())
        createTable();

    QDate   dtReleased(static_cast<int>(uiReleaseYear), 1, 1)
        ,   dtReleasedPlusOneYear = dtReleased.addYears(1);

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select distinct TVSeries.TVSeriesId TVSeriesId, TVSeries.Name Name, TVSeries.Comments Comments from TVSeries inner join TVSeasons on TVSeasons.TVSeriesId = TVSeries.TVSeriesId inner join TVEpisodes on TVEpisodes.TVSeasonId = TVSeasons.TVSeasonId inner join Media m1 on TVEpisodes.MediaId = m1.MediaId and m1.ReleaseDate between ? and ? inner join TVSpecials on TVSpecials.TVSeriesId = TVSeries.TVSeriesId inner join Media m2 on TVSpecials.MediaId = m2.MediaId and m2.ReleaseDate between ? and ?;");

    objQuery.bindValue(1, dtReleased);
    objQuery.bindValue(2, dtReleasedPlusOneYear);objQuery.bindValue(1, dtReleased);
    objQuery.bindValue(3, dtReleased);
    objQuery.bindValue(4, dtReleasedPlusOneYear);

    if(objQuery.exec())
        return(const_cast<TVSeriesDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVSeries>());
}

QList<TVSeries> TVSeriesDAOImpl::listByWordInComment(const QString &sWord) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select TVSeriesId, Name, Comments from TVSeries where Comments like ?;");

    objQuery.bindValue(1, "%" + sWord + "%");

    if(objQuery.exec())
        return(const_cast<TVSeriesDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVSeries>());
}

bool TVSeriesDAOImpl::remove(const TVSeries &refToRemove) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("delete from TVSeries where TVSeriesId = ?;");

    objQuery.bindValue(1, refToRemove.getTVSeriesId());

    return(objQuery.exec());
}

TVSeries &TVSeriesDAOImpl::save(const TVSeries &refToSave) const
{
    if(!isTableExists())
        createTable();

    if(refToSave.getTVSeriesId() > 0)
        return(update(refToSave));
    else
        return(insert(refToSave));
}
