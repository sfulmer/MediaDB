#include "CollectionDAOImpl.h"
#include<QSqlField>

using namespace net::draconia::mediadb::dao;

Collection CollectionDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    return(Collection(  refRecord.field("CollectionId").value().toUInt()
                     ,  refRecord.field("Name").value().toString()));
}

Collection &CollectionDAOImpl::insert(const Collection &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into Collections (Name) values(?);");

    objQuery.bindValue(1, refToSave.getName());

    if(objQuery.exec())
        const_cast<Collection &>(refToSave).setCollectionId(objQuery.lastInsertId().toUInt());

    return(const_cast<Collection &>(refToSave));
}

bool CollectionDAOImpl::isTableExists() const
{
    return(const_cast<CollectionDAOImpl &>(*this).getTableUtils().isTableExists("Collections"));
}

void CollectionDAOImpl::removeTable()
{
    getTableUtils().removeTable("Collections");
}

Collection &CollectionDAOImpl::update(const Collection &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("update Collections set Name = ? where CollectionId = ?;");

    objQuery.bindValue(1, refToSave.getName());
    objQuery.bindValue(2, refToSave.getCollectionId());

    objQuery.exec();

    return(const_cast<Collection &>(refToSave));
}

CollectionDAOImpl::CollectionDAOImpl(const QSqlDatabase &refDatasource)
    : AbstractDAO<Collection>(refDatasource)
{ }

CollectionDAOImpl::~CollectionDAOImpl()
{ }

bool CollectionDAOImpl::createTable() const
{
    if(!isTableExists())
        {
        QSqlQuery objQuery(getDatabase());

        objQuery.prepare("create table Collections (CollectionId int not null auto_increment primary key, Name varchar(255) not null);");

        return(objQuery.exec());
        }
    else
        return(true);
}

Collection CollectionDAOImpl::getById(const unsigned uiCollectionId) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select CollectionId, Name from Collections where CollectionId = ?;");

    objQuery.bindValue(1, uiCollectionId);

    if(objQuery.exec())
        return(const_cast<CollectionDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(Collection());
}

Collection CollectionDAOImpl::getByName(const QString &sName) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select CollectionId, Name from Collections where Name = ?;");

    objQuery.bindValue(1, sName);

    if(objQuery.exec())
        return(const_cast<CollectionDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(Collection());
}

QList<Collection> CollectionDAOImpl::list() const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select CollectionId, Name from Collections;");

    if(objQuery.exec())
        return(const_cast<CollectionDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Collection>());
}

QList<Collection> CollectionDAOImpl::listByPartialName(const QString &sPartialName) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select CollectionId, Name from Collections where Name like ?;");

    objQuery.bindValue(1, "%" + sPartialName + "%");

    if(objQuery.exec())
        return(const_cast<CollectionDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Collection>());
}

bool CollectionDAOImpl::remove(const Collection &refToRemove) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("delete from Collections where CollectionId = ?;");

    objQuery.bindValue(1, refToRemove.getCollectionId());

    return(objQuery.exec());
}

Collection &CollectionDAOImpl::save(const Collection &refToSave) const
{
    if(!isTableExists())
        createTable();

    if(refToSave.getCollectionId() > 0)
        return(update(refToSave));
    else
        return(insert(refToSave));
}
