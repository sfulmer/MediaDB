#pragma once

#include "BeanFactory.h"
#include<QtSql/QSqlDatabase>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                class TableUtils
                {
                    QSqlDatabase *mPtrDatasource;
                protected:
                    QSqlDatabase &getDatasource() const;
                public:
                    TableUtils(const QSqlDatabase &dbDatasource = BeanFactory::getInstance().getDatabase());
                    ~TableUtils();

                    bool isTableExists(const QString &sTableName) const;
                    bool removeTable(const QString &sTableName) const;
                };
            }
        }
    }
}
