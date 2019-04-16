#pragma once

#include "BeanFactory.h"
#include<QString>
#include<QtSql/QSqlDatabase>

namespace net
{
    namespace draconia
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
