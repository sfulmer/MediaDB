#include "Artist.h"
#include "Media.h"
#include "Role.h"

using namespace net::draconia::mediadb::dbo;

Role::Role()
    : muiRoleId(0), mPtrArtist(nullptr), mPtrMedia(nullptr), mPtrRoleType(nullptr)
{ }

Role::Role(const unsigned uiRoleId)
    : muiRoleId(uiRoleId), mPtrArtist(nullptr), mPtrMedia(nullptr), mPtrRoleType(nullptr)
{ }

Role::Role(const Artist &refArtist)
    : muiRoleId(0), mPtrArtist(const_cast<Artist *>(&refArtist)), mPtrMedia(nullptr), mPtrRoleType(nullptr)
{ }

Role::Role(const Media &refMedia)
    : muiRoleId(0), mPtrArtist(nullptr), mPtrMedia(const_cast<Media *>(&refMedia)), mPtrRoleType(nullptr)
{ }

Role::Role(const RoleType &refRoleType)
    : muiRoleId(0), mPtrArtist(nullptr), mPtrMedia(nullptr), mPtrRoleType(const_cast<RoleType *>(&refRoleType))
{ }

Role::Role(const QString &sName)
    : muiRoleId(0), mPtrArtist(nullptr), mPtrMedia(nullptr)
    , mPtrRoleType(nullptr), msName(sName)
{ }

Role::Role(const unsigned uiRoleId, const Artist &refArtist)
    : muiRoleId(uiRoleId), mPtrArtist(const_cast<Artist *>(&refArtist))
    , mPtrMedia(nullptr), mPtrRoleType(nullptr)
{ }

Role::Role(const unsigned uiRoleId, const Media &refMedia)
    : muiRoleId(uiRoleId), mPtrArtist(nullptr)
    , mPtrMedia(const_cast<Media *>(&refMedia))
    , mPtrRoleType(nullptr)
{ }

Role::Role(const unsigned uiRoleId, const RoleType &refRoleType)
    : muiRoleId(uiRoleId), mPtrArtist(nullptr)
    , mPtrMedia(nullptr)
    , mPtrRoleType(const_cast<RoleType *>(&refRoleType))
{ }

Role::Role(const unsigned uiRoleId, const QString &sName)
    : muiRoleId(uiRoleId), mPtrArtist(nullptr)
    , mPtrMedia(nullptr), mPtrRoleType(nullptr)
    , msName(sName)
{ }

Role::Role(const Artist &refArtist, const Media &refMedia)
    : muiRoleId(0), mPtrArtist(const_cast<Artist *>(&refArtist))
    , mPtrMedia(const_cast<Media *>(&refMedia)), mPtrRoleType(nullptr)
{ }

Role::Role(const Artist &refArtist, const RoleType &refRoleType)
    : muiRoleId(0), mPtrArtist(const_cast<Artist *>(&refArtist))
    , mPtrMedia(nullptr), mPtrRoleType(const_cast<RoleType *>(&refRoleType))
{ }

Role::Role(const Artist &refArtist, const QString &sName)
    : muiRoleId(0), mPtrArtist(const_cast<Artist *>(&refArtist))
    , mPtrMedia(nullptr), mPtrRoleType(nullptr), msName(sName)
{ }

Role::Role(const Media &refMedia, const RoleType &refRoleType)
    : muiRoleId(0), mPtrArtist(nullptr)
    , mPtrMedia(const_cast<Media *>(&refMedia))
    , mPtrRoleType(const_cast<RoleType *>(&refRoleType))
{ }

Role::Role(const Media &refMedia, const QString &sName)
    : muiRoleId(0), mPtrArtist(nullptr)
    , mPtrMedia(const_cast<Media *>(&refMedia)), mPtrRoleType(nullptr)
    , msName(sName)
{ }

Role::Role(const RoleType &refRoleType, const QString &sName)
    : muiRoleId(0), mPtrArtist(nullptr)
    , mPtrMedia(nullptr), mPtrRoleType(const_cast<RoleType *>(&refRoleType))
    , msName(sName)
{ }

Role::Role(const unsigned uiRoleId, const Artist &refArtist, const Media &refMedia)
    : muiRoleId(uiRoleId), mPtrArtist(const_cast<Artist *>(&refArtist))
    , mPtrMedia(const_cast<Media *>(&refMedia))
    , mPtrRoleType(nullptr)
{ }

Role::Role(const unsigned uiRoleId, const Artist &refArtist, const RoleType &refRoleType)
    : muiRoleId(uiRoleId), mPtrArtist(const_cast<Artist *>(&refArtist))
    , mPtrMedia(nullptr), mPtrRoleType(const_cast<RoleType *>(&refRoleType))
{ }

Role::Role(const unsigned uiRoleId, const Artist &refArtist, const QString &sName)
    : muiRoleId(uiRoleId), mPtrArtist(const_cast<Artist *>(&refArtist))
    , mPtrMedia(nullptr), mPtrRoleType(nullptr), msName(sName)
{ }

Role::Role(const unsigned uiRoleId, const Media &refMedia, const RoleType &refRoleType)
    : muiRoleId(uiRoleId), mPtrArtist(nullptr)
    , mPtrMedia(const_cast<Media *>(&refMedia))
    , mPtrRoleType(const_cast<RoleType *>(&refRoleType))
{ }

Role::Role(const unsigned uiRoleId, const Media &refMedia, const QString &sName)
    : muiRoleId(uiRoleId), mPtrArtist(nullptr)
    , mPtrMedia(const_cast<Media *>(&refMedia))
    , mPtrRoleType(nullptr), msName(sName)
{ }

Role::Role(const unsigned uiRoleId, const RoleType &refRoleType, const QString &sName)
    : muiRoleId(uiRoleId), mPtrArtist(nullptr), mPtrMedia(nullptr)
    , mPtrRoleType(const_cast<RoleType *>(&refRoleType))
    , msName(sName)
{ }

Role::Role(const Artist &refArtist, const Media &refMedia, const QString &sName)
    : muiRoleId(0), mPtrArtist(const_cast<Artist *>(&refArtist))
    , mPtrMedia(const_cast<Media *>(&refMedia)), mPtrRoleType(nullptr)
    , msName(sName)
{ }

Role::Role(const Artist &refArtist, const RoleType &refRoleType, const QString &sName)
    : muiRoleId(0), mPtrArtist(const_cast<Artist *>(&refArtist))
    , mPtrMedia(nullptr), mPtrRoleType(const_cast<RoleType *>(&refRoleType))
    , msName(sName)
{ }

Role::Role(const Media &refMedia, const RoleType &refRoleType, const QString &sName)
    : muiRoleId(0), mPtrArtist(nullptr)
    , mPtrMedia(const_cast<Media *>(&refMedia))
    , mPtrRoleType(const_cast<RoleType *>(&refRoleType))
    , msName(sName)
{ }

Role::Role(const unsigned uiRoleId, const Artist &refArtist, const Media &refMedia, const QString &sName)
    : muiRoleId(uiRoleId), mPtrArtist(const_cast<Artist *>(&refArtist))
    , mPtrMedia(const_cast<Media *>(&refMedia))
    , mPtrRoleType(nullptr), msName(sName)
{ }

Role::Role(const unsigned uiRoleId, const Artist &refArtist, const RoleType &refRoleType, const QString &sName)
    : muiRoleId(uiRoleId), mPtrArtist(const_cast<Artist *>(&refArtist))
    , mPtrMedia(nullptr), mPtrRoleType(const_cast<RoleType *>(&refRoleType))
    , msName(sName)
{ }

Role::Role(const unsigned uiRoleId, const Media &refMedia, const RoleType &refRoleType, const QString &sName)
    : muiRoleId(uiRoleId), mPtrArtist(nullptr)
    , mPtrMedia(const_cast<Media *>(&refMedia))
    , mPtrRoleType(const_cast<RoleType *>(&refRoleType)), msName(sName)
{ }

Role::Role(const Artist &refArtist, const Media &refMedia, const RoleType &refRoleType, const QString &sName)
    : muiRoleId(0), mPtrArtist(const_cast<Artist *>(&refArtist))
    , mPtrMedia(const_cast<Media *>(&refMedia))
    , mPtrRoleType(const_cast<RoleType *>(&refRoleType))
    , msName(sName)
{ }

Role::Role(const unsigned uiRoleId, const Artist &refArtist, const Media &refMedia, const RoleType &refRoleType, const QString &sName)
    : muiRoleId(uiRoleId), mPtrArtist(const_cast<Artist *>(&refArtist))
    , mPtrMedia(const_cast<Media *>(&refMedia))
    , mPtrRoleType(const_cast<RoleType *>(&refRoleType))
    , msName(sName)
{ }

Role::Role(const Role &refCopy)
    : muiRoleId(refCopy.getRoleId())
    , mPtrArtist(refCopy.mPtrArtist)
    , mPtrMedia(refCopy.mPtrMedia)
    , mPtrRoleType(refCopy.mPtrRoleType)
    , msName(refCopy.getName())
{ }

Role::~Role()
{
    mPtrArtist.reset(nullptr);
    mPtrMedia.reset(nullptr);
}

Artist Role::getArtist() const
{
    if(mPtrArtist.isNull())
        return(Artist());
    else
        return(*mPtrArtist);
}

Media Role::getMedia() const
{
    if(mPtrMedia.isNull())
        return(Media());
    else
        return(*mPtrMedia);
}

QString Role::getName() const
{
    return(msName);
}

unsigned Role::getRoleId() const
{
    return(muiRoleId);
}

RoleType Role::getRoleType() const
{
    if(mPtrRoleType.isNull())
        return(RoleType());
    else
        return(*mPtrRoleType);
}

void Role::setArtist(const Artist &refArtist)
{
    mPtrArtist.reset(const_cast<Artist *>(&refArtist));

    setChanged();
    notifyObservers("Artist");
}

void Role::setMedia(const Media &refMedia)
{
    mPtrMedia.reset(const_cast<Media *>(&refMedia));

    setChanged();
    notifyObservers("Media");
}

void Role::setName(const QString &sName)
{
    msName = sName;

    setChanged();
    notifyObservers("Name");
}

void Role::setRoleId(const unsigned uiRoleId)
{
    muiRoleId = uiRoleId;

    setChanged();
    notifyObservers("RoleId");
}

void Role::setRoleType(const RoleType &refRoleType)
{
    mPtrRoleType.reset(const_cast<RoleType *>(&refRoleType));

    setChanged();
    notifyObservers("RoleType");
}

Role &Role::operator=(const Role &refCopy)
{
    setRoleId(refCopy.getRoleId());
    setName(refCopy.getName());
    setArtist(refCopy.getArtist());
    setMedia(refCopy.getMedia());
    setRoleType(refCopy.getRoleType());

    return(*this);
}

bool Role::operator==(const Role &refOther) const
{
    return  (   (getRoleId() == refOther.getRoleId())
            &&  (getName() == refOther.getName())
            &&  (getArtist() == refOther.getArtist())
            &&  (getMedia() == refOther.getMedia())
            &&  (getRoleType() == refOther.getRoleType()));
}

bool Role::operator!=(const Role &refOther) const
{
    return(!operator==(refOther));
}
