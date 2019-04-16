#include<QtSql/QSqlQuery>
#include<QVariant>
#include "TableUtils.h"

using namespace net::draconia::dao;

QSqlDatabase &TableUtils::getDatasource() const
{
    return(*const_cast<QSqlDatabase *>(mPtrDatasource));
}

TableUtils::TableUtils(const QSqlDatabase &dbDatasource)
    : mPtrDatasource(&const_cast<QSqlDatabase &>(dbDatasource))
{ }

TableUtils::~TableUtils()
{
    mPtrDatasource = nullptr;
}

bool TableUtils::isTableExists(const QString &sTableName) const
{
    QSqlQuery objQuery(getDatasource());

    objQuery.prepare("SELECT name FROM sqlite_master WHERE type = 'table' AND name = :tablename;");
    objQuery.bindValue(":tablename", sTableName.toStdString().c_str());

    if(objQuery.exec())
        return(objQuery.size() > 0);
    else
        return(false);
}

bool TableUtils::removeTable(const QString &sTableName) const
{
    QSqlQuery objQuery(getDatasource());

    objQuery.prepare("drop table :tablename;");
    objQuery.bindValue(":tablename", sTableName.toStdString().c_str());

    return(objQuery.exec());
}
