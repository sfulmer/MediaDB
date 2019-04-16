#include "MediaDAOImpl.h"
#include<QtSql/QSqlField>
#include<QtSql/QSqlQuery>

using namespace net::draconia::dao;

const QString MediaDAOImpl::TableName("Media");

void MediaDAOImpl::closeConnection()
{
    if(getDatabase().isOpen())
        getDatabase().close();
}

QSharedPointer<Media> MediaDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    QSharedPointer<Media> ptrMedia(new NoMedia());

    ptrMedia->setMediaId(refRecord.field("MediaId").value().toUInt());
    ptrMedia->setName(refRecord.field("Name").value().toString());
    ptrMedia->setReleaseDate(refRecord.field("ReleaseDate").value().toDate());
    ptrMedia->setFilePath(refRecord.field("FilePath").value().toString());

    return(ptrMedia);
}

bool MediaDAOImpl::createTable() const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("create table " + TableName + "(MediaId int not null auto_increment primary key, Name varchar(255) not null, ReleaseDate date not null, FilePath varchar(255) not null, unique key(Name, ReleaseDate));");

    return(objQuery.exec());
}

QSqlDatabase &MediaDAOImpl::getDatabase() const
{
    return(*mPtrDatasource);
}

QString MediaDAOImpl::getQueriedColumnsForSelect() const
{
    return("MediaId, Name, ReleaseDate, FilePath");
}

TableUtils &MediaDAOImpl::getTableUtils()
{
    if(mPtrTableUtils == nullptr)
        mPtrTableUtils = new TableUtils(getDatabase());

    return(*mPtrTableUtils);
}

Media &MediaDAOImpl::insert(const Media &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into " + TableName + "(" + getQueriedColumnsForSelect() + ") values(?, ?, ?, ?);");

    objQuery.bindValue(1, refToSave.getMediaId());
    objQuery.bindValue(2, refToSave.getName());
    objQuery.bindValue(3, refToSave.getReleaseDate());
    objQuery.bindValue(4, refToSave.getFilePath());

    if(objQuery.exec())
        const_cast<Media &>(refToSave).setMediaId(objQuery.lastInsertId().toUInt());

    return(const_cast<Media &>(refToSave));
}

bool MediaDAOImpl::isTableExists() const
{
    return(const_cast<MediaDAOImpl &>(*this).getTableUtils().isTableExists(TableName));
}

void MediaDAOImpl::removeTable()
{
    getTableUtils().removeTable(TableName);
}

Media &MediaDAOImpl::update(const Media &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("update " + TableName + "set Name = ?, ReleaseDate = ?, FilePath = ? where MediaId = ?;");

    objQuery.bindValue(1, refToSave.getName());
    objQuery.bindValue(2, refToSave.getReleaseDate());
    objQuery.bindValue(3, refToSave.getFilePath());
    objQuery.bindValue(4, refToSave.getMediaId());

    objQuery.exec();

    return(const_cast<Media &>(refToSave));
}

MediaDAOImpl::MediaDAOImpl(const QSqlDatabase &refDatasource)
    : mPtrDatasource(&const_cast<QSqlDatabase &>(refDatasource))
    , mPtrTableUtils(nullptr)
{ }

MediaDAOImpl::~MediaDAOImpl()
{
    if(mPtrTableUtils != nullptr)
        {
        delete mPtrTableUtils;

        mPtrTableUtils = nullptr;
        }
}

QSharedPointer<Media> MediaDAOImpl::getById(const unsigned uiMediaId) const
{
    QSqlQuery objQuery(getDatabase());

    if(!isTableExists())
        createTable();

    objQuery.prepare("select " + getQueriedColumnsForSelect() + " from " + TableName + " where MediaId = ?;");

    objQuery.bindValue(1, uiMediaId);

    if(objQuery.exec())
        return(const_cast<MediaDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(QSharedPointer<Media>());
}

bool MediaDAOImpl::remove(const Media &refMedia) const
{
    QSqlQuery objQuery(getDatabase());

    if(!isTableExists())
        createTable();

    objQuery.prepare("delete from " + TableName + " where MediaId = ?;");

    objQuery.bindValue(1, refMedia.getMediaId());

    return(objQuery.exec());
}

Media &MediaDAOImpl::save(const Media &refToSave) const
{
    if(!isTableExists())
        createTable();

    if(refToSave.getMediaId() <= 0)
        return(insert(refToSave));
    else
        return(update(refToSave));
}
