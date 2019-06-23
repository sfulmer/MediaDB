#include<QtSql/QSqlField>
#include<QVariant>
#include "RoleTypeDAOImpl.h"

using namespace net::draconia::mediadb::dao;

const QString RoleTypeDAOImpl::TableName("RoleTypes");

RoleType RoleTypeDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    return(RoleType (   refRecord.field("RoleTypeId").value().toUInt()
                    ,   refRecord.field("RoleType").value().toString()));
}

QString RoleTypeDAOImpl::getPrimaryKey() const
{
    return("RoleTypeId");
}

QString RoleTypeDAOImpl::getQueriedColumnsForSelect() const
{
    return("RoleType");
}

QString RoleTypeDAOImpl::getTableName() const
{
    return(TableName);
}

RoleType &RoleTypeDAOImpl::insert(const RoleType &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into " + getTableName() + "(" + getQueriedColumnsForSelect() + ") values (?);");

    objQuery.bindValue(1, refToSave.getRoleType());

    if(objQuery.exec())
        const_cast<RoleType &>(refToSave).setRoleTypeId(objQuery.lastInsertId().toUInt());

    return(const_cast<RoleType &>(refToSave));
}

RoleType &RoleTypeDAOImpl::update(const RoleType &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("update " + getTableName() + "set " + getQueriedColumnsForSelect() + " = ? where " + getPrimaryKey() + " = ?;");

    objQuery.bindValue(1, refToSave.getRoleType());
    objQuery.bindValue(2, refToSave.getRoleTypeId());

    objQuery.exec();

    return(const_cast<RoleType &>(refToSave));
}

RoleTypeDAOImpl::RoleTypeDAOImpl(const QSqlDatabase &refDatabase)
    : AbstractDAO<RoleType>(refDatabase)
{ }

RoleTypeDAOImpl::~RoleTypeDAOImpl()
{ }

bool RoleTypeDAOImpl::createTable() const
{
    if(!isTableExists())
        {
        QSqlQuery objQuery(getDatabase());

        objQuery.prepare("create table " + getTableName() + " (" + getPrimaryKey() + " int not null auto_increment primary key, " + getQueriedColumnsForSelect() + " varchar(100) not null default ' ');");

        return(objQuery.exec());
        }
    else
        return(true);
}

RoleType RoleTypeDAOImpl::getById(const unsigned uiRoleTypeId) const
{
    return(AbstractDAO<RoleType>::getById(uiRoleTypeId));
}

QList<RoleType> RoleTypeDAOImpl::list() const
{
    return(AbstractDAO<RoleType>::list());
}

bool RoleTypeDAOImpl::remove(const RoleType &refToRemove) const
{
    return(AbstractDAO<RoleType>::remove(refToRemove.getRoleTypeId()));
}

RoleType &RoleTypeDAOImpl::save(const RoleType &refToSave) const
{
    if(refToSave.getRoleTypeId() > 0)
        return(update(refToSave));
    else
        return(insert(refToSave));
}
