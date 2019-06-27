#pragma once

#include<QList>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlRecord>
#include "TableUtils.h"

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                template<typename T>
                class AbstractDAO
                {
                    QSqlDatabase *mPtrDatasource;
                    TableUtils *mPtrTableUtils;
                protected:
                    void closeConnection();
                    virtual T createObjectFromResults(const QSqlRecord &refRecord) = 0;
                    QList<T> createObjectListFromResults(const QSqlQuery &refQuery);
                    QSqlDatabase &getDatabase() const;
                    TableUtils &getTableUtils();
                    virtual T &insert(const T &refToSave) const = 0;
                    virtual bool isTableExists() const = 0;
                    virtual void removeTable() = 0;
                    virtual T &update(const T &refToSave) const = 0;
                public:
                    AbstractDAO(const QSqlDatabase &refDatasource = BeanFactory::getInstance().getDatabase());
                    virtual ~AbstractDAO();
                    virtual bool createTable() const = 0;
                };
            }
        }
    }
}
