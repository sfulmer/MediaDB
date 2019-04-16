#include "DBO.h"

using namespace net::draconia::dbo;

RoleType::RoleType()
    : Observable()
    , muiRoleTypeId(0)
{ }

RoleType::RoleType(const unsigned uiRoleTypeId)
    : Observable()
    , muiRoleTypeId(uiRoleTypeId)
{ }

RoleType::RoleType(const QString &sRoleType)
    : Observable()
    , muiRoleTypeId(0)
    , msRoleType(sRoleType)
{ }

RoleType::RoleType(const unsigned uiRoleTypeId, const QString &sRoleType)
    : Observable()
    , muiRoleTypeId(uiRoleTypeId)
    , msRoleType(sRoleType)
{ }

RoleType::RoleType(const RoleType &refCopy)
    : Observable()
    , muiRoleTypeId(refCopy.getRoleTypeId())
    , msRoleType(refCopy.getRoleType())
{ }

RoleType::~RoleType()
{ }

unsigned RoleType::getRoleTypeId() const
{
    return(muiRoleTypeId);
}

QString &RoleType::getRoleType() const
{
    return(const_cast<QString &>(msRoleType));
}

void RoleType::setRoleTypeId(const unsigned uiRoleTypeId)
{
    muiRoleTypeId = uiRoleTypeId;

    setChanged();
    notifyObservers();
}

void RoleType::setRoleType(const QString &sRoleType)
{
    msRoleType = sRoleType;

    setChanged();
    notifyObservers();
}

RoleType &RoleType::operator=(const RoleType &refOther)
{
    muiRoleTypeId = refOther.getRoleTypeId();
    msRoleType = refOther.getRoleType();

    setChanged();
    notifyObservers();

    return(*this);
}

bool RoleType::operator==(const RoleType &refOther) const
{
    return  (   (getRoleTypeId() == refOther.getRoleTypeId())
            &&  (getRoleType() == refOther.getRoleType()));
}

Role::Role()
    : Observable()
    , muiRoleId(0)
    , mPtrMedia(nullptr)
{ }

Role::Role(const unsigned uiRoleId)
    : Observable()
    , muiRoleId(uiRoleId)
    , mPtrMedia(nullptr)
{ }

Role::Role(const Media &refMedia)
    : Observable()
    , muiRoleId(0)
    , mPtrMedia(&const_cast<Media &>(refMedia))
{ }

Role::Role(const RoleType &refRoleType)
    : Observable()
    , muiRoleId(0)
    , mPtrMedia(nullptr)
    , mObjRoleType(refRoleType)
{ }

Role::Role(const unsigned uiRoleId, const Media &refMedia)
    : Observable()
    , muiRoleId(uiRoleId)
    , mPtrMedia(&const_cast<Media &>(refMedia))
{ }

Role::Role(const unsigned uiRoleId, const RoleType &refRoleType)
    : Observable()
    , muiRoleId(uiRoleId)
    , mPtrMedia(nullptr)
    , mObjRoleType(refRoleType)
{ }

Role::Role(const unsigned uiRoleId, const Media &refMedia, const RoleType &refRoleType)
    : Observable()
    , muiRoleId(uiRoleId)
    , mPtrMedia(&const_cast<Media &>(refMedia))
    , mObjRoleType(refRoleType)
{ }

Role::Role(const Role &refCopy)
    : Observable()
    , muiRoleId(refCopy.getRoleId())
    , mPtrMedia(&(refCopy.getMedia()))
    , mObjRoleType(refCopy.getRoleType())
{ }

Role::~Role()
{
    mPtrMedia = nullptr;
}

Media &Role::getMedia() const
{
    if(mPtrMedia == nullptr)
        return(const_cast<NoMedia &>(mObjNoMedia));
    else
        return(*mPtrMedia);
}

unsigned Role::getRoleId() const
{
    return(muiRoleId);
}

RoleType &Role::getRoleType() const
{
    return(const_cast<RoleType &>(mObjRoleType));
}

void Role::setMedia(const Media &refMedia)
{
    mPtrMedia = &const_cast<Media &>(refMedia);

    setChanged();
    notifyObservers();
}

void Role::setRoleId(const unsigned uiRoleId)
{
    muiRoleId = uiRoleId;

    setChanged();
    notifyObservers();
}

void Role::setRoleType(const RoleType &refRoleType)
{
    mObjRoleType = refRoleType;

    setChanged();
    notifyObservers();
}

bool Role::operator==(const Role &refOther) const
{
    if  (   (getMedia() == mObjNoMedia)
        &&  (refOther.getMedia() == mObjNoMedia))
        return  (   (getRoleId() == refOther.getRoleId())
                &&  (getRoleType() == refOther.getRoleType()));
    else
        return  (   (getMedia() == refOther.getMedia())
                &&  (getRoleId() == refOther.getRoleId())
                &&  (getRoleType() == refOther.getRoleType()));
}
