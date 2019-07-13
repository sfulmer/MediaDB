#pragma once

#include "AbstractDAO.h"
#include "BeanFactory.h"
#include "CollectionDAO.h"

using net::draconia::mediadb::BeanFactory;

using net::draconia::mediadb::dbo::Collection;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                extern template class AbstractDAO<Collection>;

                class CollectionDAOImpl : public AbstractDAO<Collection>, public CollectionDAO
                {
                protected:
                    virtual Collection createObjectFromResults(const QSqlRecord &refRecord);
                    virtual Collection &insert(const Collection &refToSave) const;
                    virtual bool isTableExists() const;
                    virtual void removeTable();
                    virtual Collection &update(const Collection &refToSave) const;
                public:
                    CollectionDAOImpl(const QSqlDatabase &refDatasource = BeanFactory::getInstance().getDatabase());
                    virtual ~CollectionDAOImpl();

                    virtual bool createTable() const;
                    virtual Collection getById(const unsigned uiCollectionId) const;
                    virtual Collection getByName(const QString &sName) const;
                    virtual QList<Collection> list() const;
                    virtual QList<Collection> listByPartialName(const QString &sPartialName) const;
                    virtual bool remove(const Collection &refToRemove) const;
                    virtual Collection &save(const Collection &refToSave) const;
                };
            }
        }
    }
}
