#pragma once

#include "Observable.h"
#include<Qstring>

using net::draconia::util::Observable;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dbo
            {
                class RoleType : public Observable
                {
                    unsigned muiRoleTypeId;
                    QString msRoleType;
                public:
                    RoleType();
                    RoleType(const unsigned uiRoleTypeId);
                    RoleType(const QString &sRoleType);
                    RoleType(const unsigned uiRoleTypeId, const QString &sRoleType);
                    RoleType(const RoleType &refCopy);
                    ~RoleType();

                    unsigned getRoleTypeId() const;
                    QString getRoleType() const;
                    void setRoleTypeId(const unsigned uiRoleTypeId);
                    void setRoleType(const QString &sRoleType);

                    RoleType &operator=(const RoleType &refOther);
                    bool operator==(const RoleType &refOther) const;
                    bool operator!=(const RoleType &refOther) const;
                };
            }
        }
    }
}
