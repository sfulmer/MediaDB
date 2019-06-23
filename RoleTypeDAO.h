#pragma once

#include "RoleType.h"

using net::draconia::mediadb::dbo::RoleType;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                class RoleTypeDAO
                {
                public:
                    virtual ~RoleTypeDAO();

                    virtual RoleType getById(const unsigned uiRoleTypeId) const = 0;
                    virtual QList<RoleType> list() const = 0;
                    virtual bool remove(const RoleType &refToRemove) const = 0;
                    virtual RoleType &save(const RoleType &refToSave) const = 0;
                };
            }
        }
    }
}
