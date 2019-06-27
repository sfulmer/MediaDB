#include<QtSql/QSqlField>
#include<QVariant>
#include "RoleTypeDAOImpl.h"

using namespace net::draconia::mediadb::dao;

RoleType RoleTypeDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    return(RoleType (   refRecord.field("RoleTypeId").value().toUInt()
                    ,   refRecord.field("RoleType").value().toString()));
}

RoleType &RoleTypeDAOImpl::insert(const RoleType &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into RoleTypes(RoleType) values(?);");

    objQuery.bindValue(1, refToSave.getRoleType());

    if(objQuery.exec())
        const_cast<RoleType &>(refToSave).setRoleTypeId(objQuery.lastInsertId().toUInt());

    return(const_cast<RoleType &>(refToSave));
}

bool RoleTypeDAOImpl::isTableExists() const
{
    return(const_cast<RoleTypeDAOImpl &>(*this).getTableUtils().isTableExists("RoleTypes"));
}

void RoleTypeDAOImpl::removeTable()
{
    getTableUtils().removeTable("RoleTypes");
}

RoleType &RoleTypeDAOImpl::update(const RoleType &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("update RoleTypes set RoleType = ? where RoleTypeId = ?;");

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

        objQuery.prepare("create table RoleTypes(RoleTypeId int not null auto_increment primary key, RoleType varchar(100) not null);");

        return(objQuery.exec());
        }
    else
        return(true);
}

RoleType RoleTypeDAOImpl::getById(const unsigned uiRoleTypeId) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select RoleTypeId, RoleType from RoleTypes where RoleTypeId = ?;");

    objQuery.bindValue(1, uiRoleTypeId);

    if(objQuery.exec())
        return(const_cast<RoleTypeDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(RoleType());
}

QList<RoleType> RoleTypeDAOImpl::list() const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select RoleTypeId, RoleType from RoleTypes;");

    if(objQuery.exec())
        return(const_cast<RoleTypeDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<RoleType>());
}

bool RoleTypeDAOImpl::remove(const RoleType &refToRemove) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("delete from RoleTypes where RoleTypeId = ?;");

    objQuery.bindValue(1, refToRemove.getRoleTypeId());

    return(objQuery.exec());
}

RoleType &RoleTypeDAOImpl::save(const RoleType &refToSave) const
{
    if(refToSave.getRoleTypeId() > 0)
        return(update(refToSave));
    else
        return(insert(refToSave));
}
