#include "ArtistDAOImpl.h"
#include "MediaDAOImpl.h"
#include<QtSql/QSqlField>
#include "RoleDAOImpl.h"
#include "TVSeriesDAOImpl.h"
#include "TVSpecialDAOImpl.h"

using namespace net::draconia::mediadb::dao;

const QString TVSpecialDAOImpl::TableName("TVSpecials");

TVSpecial TVSpecialDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    Media objMedia = getMediaDAO().getById(refRecord.field("MediaId").value().toUInt());
    TVSeries objTVSeries = getTVSeriesDAO().getById(refRecord.field("TVSeriesId").value().toUInt());

    return(TVSpecial(   objTVSeries
                    ,   objMedia.getMediaId()
                    ,   refRecord.field("TVSpecialId").value().toUInt()
                    ,   objMedia.getName()
                    ,   objMedia.getReleaseDate()
                    ,   objMedia.getFilePath()
                    ,   objMedia.getArtists()
                    ,   refRecord.field("Comments").value().toString()));
}

ArtistDAO &TVSpecialDAOImpl::getArtistDAO() const
{
    return(mRefArtistDAO);
}

MediaDAO &TVSpecialDAOImpl::getMediaDAO() const
{
    return(mRefMediaDAO);
}

QString TVSpecialDAOImpl::getPrimaryKey() const
{
    return("TVSpecialId");
}

QString TVSpecialDAOImpl::getQueriedColumnsForSelect() const
{
    return("MediaId, TVSeriesId, Comments");
}

RoleDAO &TVSpecialDAOImpl::getRoleDAO() const
{
    return(mRefRoleDAO);
}

QString TVSpecialDAOImpl::getTableName() const
{
    return(TableName);
}

TVSeriesDAO &TVSpecialDAOImpl::getTVSeriesDAO() const
{
    return(mRefTVSeriesDAO);
}

TVSpecial &TVSpecialDAOImpl::insert(const TVSpecial &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into " + getTableName() + " (" + getQueriedColumnsForSelect() + ") values(?, ?, ?);");

    objQuery.bindValue(1, refToSave.getMediaId());
    objQuery.bindValue(2, refToSave.getSeries().getTVSeriesId());
    objQuery.bindValue(3, refToSave.getComments());

    if(objQuery.exec())
        const_cast<TVSpecial &>(refToSave).setTVSpecialId(objQuery.lastInsertId().toUInt());

    return(const_cast<TVSpecial &>(refToSave));
}

TVSpecial &TVSpecialDAOImpl::update(const TVSpecial &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("update " + getTableName() + " set MediaId = ?, TVSeriesId = ?, Comments = ? where TVSpecialId = ?;");

    objQuery.bindValue(1, refToSave.getMediaId());
    objQuery.bindValue(2, refToSave.getSeries().getTVSeriesId());
    objQuery.bindValue(3, refToSave.getComments());
    objQuery.bindValue(4, refToSave.getTVSpecialId());

    objQuery.exec();

    return(const_cast<TVSpecial &>(refToSave));
}

TVSpecialDAOImpl::TVSpecialDAOImpl(const QSqlDatabase &refDatabase)
    : AbstractDAO<TVSpecial>(refDatabase)
    , mRefArtistDAO(BeanFactory::getInstance().getArtistDAO())
    , mRefMediaDAO(BeanFactory::getInstance().getMediaDAO())
    , mRefRoleDAO(BeanFactory::getInstance().getRoleDAO())
    , mRefTVSeriesDAO(BeanFactory::getInstance().getTVSeriesDAO())
{ }

TVSpecialDAOImpl::~TVSpecialDAOImpl()
{ }

bool TVSpecialDAOImpl::createTable() const
{
    if(!isTableExists())
        {
        QSqlQuery objQuery(getDatabase());

        objQuery.prepare("create table " + getTableName() + "(" + getPrimaryKey() + " int not null auto_increment primary key, MediaId int not null, TVSeriesId int not null, Comments varchar(32000) not null default ' ', foreign key(MediaId) references Media(MediaId), foreign key (TVSeriesId) references TVSeries(TVSeriesId));");

        return(objQuery.exec());
        }
    else
        return(true);
}

TVSpecial TVSpecialDAOImpl::getById(const unsigned uiId) const
{
    return(AbstractDAO<TVSpecial>::getById(uiId));
}

TVSpecial TVSpecialDAOImpl::getByNameAndreleaseYear(const QString &sName, const unsigned uiReleaseYear) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Media on " + getTableName() + ".MediaId = Media.MediaId and Media.Name = ? and Media.ReleaseDate between ? and ?;");

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();

    objQuery.bindValue(1, sName);
    objQuery.bindValue(2, QDate(static_cast<int>(uiReleaseYear), 1, 1));
    objQuery.bindValue(3, QDate(static_cast<int>(uiReleaseYear) + 1, 1, 1));

    if(objQuery.exec())
        return(const_cast<TVSpecialDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(TVSpecial());
}

QList<TVSpecial> TVSpecialDAOImpl::list() const
{
    return(AbstractDAO<TVSpecial>::list());
}

QList<TVSpecial> TVSpecialDAOImpl::listByArtist(const Artist &refArtist) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Media on " + getTableName() + ".MediaId = Media.MediaId inner join Roles on Roles.MediaId = Media.MediaId and Roles.ArtistId = ?;");

    static_cast<RoleDAOImpl &>(getRoleDAO()).createTable();
    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();

    objQuery.bindValue(1, refArtist.getArtistId());

    if(objQuery.exec())
        return(const_cast<TVSpecialDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVSpecial>());
}

QList<TVSpecial> TVSpecialDAOImpl::listByArtistAndSeries(const Artist &refArtist, const TVSeries &refTVSeries) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Media on " + getTableName() + ".MediaId = Media.MediaId inner join Roles on Roles.MediaId = Media.MediaId and Roles.ArtistId = ? where TVSeriesId = ?;");

    static_cast<RoleDAOImpl &>(getRoleDAO()).createTable();
    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();

    objQuery.bindValue(1, refArtist.getArtistId());
    objQuery.bindValue(2, refTVSeries.getTVSeriesId());

    if(objQuery.exec())
        return(const_cast<TVSpecialDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVSpecial>());
}

QList<TVSpecial> TVSpecialDAOImpl::listByName(const QString &sName) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Media on " + getTableName() + ".MediaId = Media.MediaId and Media.Name = ?;");

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();

    objQuery.bindValue(1, sName);

    if(objQuery.exec())
        return(const_cast<TVSpecialDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVSpecial>());
}

QList<TVSpecial> TVSpecialDAOImpl::listByTVSeries(const TVSeries &refTVSeries) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " where TVSeriesId = ?;");

    objQuery.bindValue(1, refTVSeries.getTVSeriesId());

    if(objQuery.exec())
        return(const_cast<TVSpecialDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVSpecial>());
}

QList<TVSpecial> TVSpecialDAOImpl::listByWordInComment(const QString &sWord) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " where Comments like ?;");

    objQuery.bindValue(1, "%" + sWord + "%");

    if(objQuery.exec())
        return(const_cast<TVSpecialDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<TVSpecial>());
}

bool TVSpecialDAOImpl::remove(const TVSpecial &refToRemove) const
{
    if(!isTableExists())
        createTable();

    return(AbstractDAO<TVSpecial>::remove(refToRemove.getTVSpecialId()));
}

TVSpecial &TVSpecialDAOImpl::save(const TVSpecial &refToSave) const
{
    if(!isTableExists())
        createTable();

    if(refToSave.getTVSpecialId() > 0)
        return(update(refToSave));
    else
        return(insert(refToSave));
}
