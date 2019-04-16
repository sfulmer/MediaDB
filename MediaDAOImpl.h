#pragma once

#include "BeanFactory.h"
#include "MediaDAO.h"
#include<QSharedPointer>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlRecord>
#include "TableUtils.h"

namespace net
{
    namespace draconia
    {
        namespace dao
        {
            class MediaDAOImpl : public MediaDAO
            {
                QSqlDatabase *mPtrDatasource;
                TableUtils *mPtrTableUtils;

                const static QString TableName;
            protected:
                void closeConnection();
                virtual QSharedPointer<Media> createObjectFromResults(const QSqlRecord &refRecord);
                virtual bool createTable() const;
                virtual QSqlDatabase &getDatabase() const;
                virtual QString getQueriedColumnsForSelect() const;
                TableUtils &getTableUtils();
                virtual Media &insert(const Media &refToSave) const;
                virtual bool isTableExists() const;
                virtual void removeTable();
                virtual Media &update(const Media &refToSave) const;
            public:
                MediaDAOImpl(const QSqlDatabase &refDatasource = BeanFactory::getInstance().getDatabase());
                virtual ~MediaDAOImpl();

                virtual QSharedPointer<Media> getById(const unsigned uiMediaId) const;
                virtual bool remove(const Media &refMedia) const;
                virtual Media &save(const Media &refToSave) const;
            };
        }
    }
}
