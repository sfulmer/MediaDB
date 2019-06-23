#include "RoleType.h"

using namespace net::draconia::mediadb::dbo;

RoleType::RoleType()
    : muiRoleTypeId(0)
{ }

RoleType::RoleType(const unsigned uiRoleTypeId)
    : muiRoleTypeId(uiRoleTypeId)
{ }

RoleType::RoleType(const QString &sRoleType)
    : muiRoleTypeId(0), msRoleType(sRoleType)
{ }

RoleType::RoleType(const unsigned uiRoleTypeId, const QString &sRoleType)
    : muiRoleTypeId(uiRoleTypeId), msRoleType(sRoleType)
{ }

RoleType::RoleType(const RoleType &refCopy)
    : muiRoleTypeId(refCopy.getRoleTypeId()), msRoleType(refCopy.getRoleType())
{ }

RoleType::~RoleType()
{ }

unsigned RoleType::getRoleTypeId() const
{
    return(muiRoleTypeId);
}

QString RoleType::getRoleType() const
{
    return(msRoleType);
}

void RoleType::setRoleTypeId(const unsigned uiRoleTypeId)
{
    muiRoleTypeId = uiRoleTypeId;

    setChanged(true);
    notifyObservers();
}

void RoleType::setRoleType(const QString &sRoleType)
{
    msRoleType = sRoleType;

    setChanged(true);
    notifyObservers();
}

RoleType &RoleType::operator=(const RoleType &refOther)
{
    setRoleTypeId(refOther.getRoleTypeId());
    setRoleType(refOther.getRoleType());

    return(*this);
}

bool RoleType::operator==(const RoleType &refOther) const
{
    return  (   (getRoleTypeId() == refOther.getRoleTypeId())
            &&  (getRoleType() == refOther.getRoleType()));
}

bool RoleType::operator!=(const RoleType &refOther) const
{
    return(!operator==(refOther));
}
