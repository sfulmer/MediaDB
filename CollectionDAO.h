#pragma once

#include "Collection.h"

using net::draconia::mediadb::dbo::Collection;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                class CollectionDAO
                {
                public:
                    virtual ~CollectionDAO();

                    virtual Collection getById(const unsigned uiCollectionId) const = 0;
                    virtual Collection getByName(const QString &sName) const = 0;
                    virtual QList<Collection> list() const = 0;
                    virtual QList<Collection> listByPartialName(const QString &sPartialName) const = 0;
                    virtual bool remove(const Collection &refToRemove) const = 0;
                    virtual Collection &save(const Collection &refToSave) const = 0;
                };
            }
        }
    }
}
