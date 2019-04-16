#include "DBO.h"

using namespace net::draconia::dbo;

QList<Role> &Artist::getRolesInternal() const
{
    return(const_cast<QList<Role> &>(mLstRoles));
}

void Artist::setRoles(const QList<Role> &lstRoles)
{
    getRolesInternal().clear();
    getRolesInternal().append(lstRoles);

    setChanged();
    notifyObservers();
}

Artist::Artist()
    : Observable()
    , muiArtistId(0)
{ }

Artist::Artist(const unsigned uiArtistId)
    : Observable()
    , muiArtistId(uiArtistId)
{ }

Artist::Artist(const QString &sName)
    : Observable()
    , muiArtistId(0), msName(sName)
{ }

Artist::Artist(const unsigned uiArtistId, const QString &sName)
    : Observable()
    , muiArtistId(uiArtistId), msName(sName)
{ }

Artist::Artist(const unsigned uiArtistId, const QString &sName, const QList<Role> &lstRoles)
    : Observable()
    , muiArtistId(uiArtistId)
    , msName(sName)
{
    setRoles(lstRoles);
}

Artist::Artist(const Artist &refCopy)
    : Observable()
    , muiArtistId(refCopy.getArtistId())
    , msName(refCopy.getName())
{
    setRoles(refCopy.getRoles());
}

Artist::~Artist()
{ }

void Artist::addRole(const Role &refRole)
{
    getRolesInternal().append(refRole);

    setChanged();
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
    bool bReturnValue = getRolesInternal().removeOne(refRole);

    setChanged();
    notifyObservers();

    return(bReturnValue);
}

void Artist::removeRole(const unsigned uiIndex)
{
    getRolesInternal().removeAt(static_cast<int>(uiIndex));

    setChanged();
    notifyObservers();
}

void Artist::setArtistId(const unsigned uiArtistId)
{
    muiArtistId = uiArtistId;

    setChanged();
    notifyObservers();
}

void Artist::setName(const QString &sName)
{
    msName = sName;

    setChanged();
    notifyObservers();
}

bool Artist::operator==(const Artist &refOther) const
{
    return(  (getArtistId() == refOther.getArtistId())
          && (getName() == refOther.getName())
          && (getRoles() == refOther.getRoles()));
}
