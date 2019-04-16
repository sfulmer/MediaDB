#pragma once

#include "BeanFactory.h"
#include<QList>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlRecord>
#include "TableUtils.h"

using namespace net::draconia;

namespace net
{
    namespace draconia
    {
        namespace dao
        {
            template<typename T>
            class AbstractDAO
            {
                QSqlDatabase *mPtrDatasource;
                TableUtils *mPtrTableUtils;
            protected:
                void closeConnection()
                {
                    if(getDatabase().isOpen())
                        getDatabase().close();
                }
                virtual T createObjectFromResults(const QSqlRecord &refRecord) = 0;
                virtual QList<T> createObjectListFromResults(const QSqlQuery &refQuery) = 0;
                virtual bool createTable() const = 0;
                virtual QSqlDatabase &getDatabase() const
                {
                    return(*mPtrDatasource);
                }
                virtual QString getQueriedColumnsForSelect() const = 0;
                TableUtils &getTableUtils()
                {
                    if(mPtrTableUtils == nullptr)
                        mPtrTableUtils = new TableUtils(getDatabase());

                    return(*mPtrTableUtils);
                }
                virtual T &insert(const T &refToSave) const = 0;
                virtual bool isTableExists() const = 0;
                virtual void removeTable() = 0;
                virtual T &update(const T &refToSave) const = 0;
            public:
                AbstractDAO(const QSqlDatabase &refDatasource = BeanFactory::getInstance().getDatabase())
                    : mPtrDatasource(&const_cast<QSqlDatabase &>(refDatasource))
                { }
                virtual ~AbstractDAO()
                {
                    if(mPtrTableUtils != nullptr)
                        {
                        delete mPtrTableUtils;

                        mPtrTableUtils = nullptr;
                        }
                }
            };
        }
    }
}
