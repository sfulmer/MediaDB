#include "Artist.h"

using namespace net::draconia::mediadb::dbo;

QList<Role> &Artist::getRolesInternal() const
{
    return(const_cast<QList<Role> &>(mLstRoles));
}

void Artist::setRoles(const QList<Role> &lstRoles)
{
    getRolesInternal().clear();
    getRolesInternal().append(lstRoles);
}

Artist::Artist()
    : muiArtistId(0)
{ }

Artist::Artist(const unsigned uiArtistId)
    : muiArtistId(uiArtistId)
{ }

Artist::Artist(const QString &sName)
    : muiArtistId(0), msName(sName)
{ }

Artist::Artist(const QString &sName, const QList<Role> &lstRoles)
    : muiArtistId(0), msName(sName), mLstRoles(lstRoles)
{ }

Artist::Artist(const unsigned uiArtistId, const QString &sName)
    : muiArtistId(uiArtistId), msName(sName)
{ }

Artist::Artist(const unsigned uiArtistId, const QString &sName, const QList<Role> &lstRoles)
    : muiArtistId(uiArtistId), msName(sName), mLstRoles(lstRoles)
{ }

Artist::Artist(const Artist &refCopy)
    : muiArtistId(refCopy.getArtistId())
    , msName(refCopy.getName())
    , mLstRoles(refCopy.getRoles())
{ }

Artist::~Artist()
{ }

void Artist::addRole(const Role &refRole)
{
    getRolesInternal().append(refRole);

    setChanged(true);
    notifyObservers();
}

unsigned Artist::getArtistId() const
{
    return(muiArtistId);
}

QString &Artist::getName() const
{
    return(const_cast<QString &>(msName));
}

const QList<Role> &Artist::getRoles() const
{
    return(getRolesInternal());
}

bool Artist::removeRole(const Role &refRole)
{
    bool bRetVal = getRolesInternal().removeOne(refRole);

    setChanged(true);
    notifyObservers();

    return(bRetVal);
}

void Artist::removeRole(const unsigned uiIndex)
{
    removeRole(getRolesInternal()[static_cast<int>(uiIndex)]);

}

void Artist::setArtistId(const unsigned uiArtistId)
{
    muiArtistId = uiArtistId;

    setChanged(true);
    notifyObservers();
}

void Artist::setName(const QString &sName)
{
    msName = sName;

    setChanged(true);
    notifyObservers();
}

Artist &Artist::operator=(const Artist &refOther)
{
    setArtistId(refOther.getArtistId());
    setName(refOther.getName());
    setRoles(refOther.getRoles());

    return(*this);
}

bool Artist::operator==(const Artist &refOther) const
{
    return  (   (getArtistId() == refOther.getArtistId())
            &&  (getName() == refOther.getName())
            &&  (getRoles() == refOther.getRoles()));
}

bool Artist::operator!=(const Artist &refOther) const
{
    return(!operator==(refOther));
}
