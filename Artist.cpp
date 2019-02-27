#include "Artist.h"

using namespace net::draconia;

QList<Media> &Artist::getRolesInternal() const
{
    return(const_cast<QList<Media> &>(mLstRoles));
}

void Artist::setRoles(const QList<Media> &lstRoles)
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

Artist::Artist(const unsigned uiArtistId, const QString &sName)
    : muiArtistId(uiArtistId), msName(sName)
{ }

Artist::Artist(const unsigned uiArtistId, const QString &sName, const QList<Media> &lstRoles)
    : muiArtistId(uiArtistId)
    , msName(sName)
{
    setRoles(lstRoles);
}

Artist::Artist(const Artist &refCopy)
    : muiArtistId(refCopy.getArtistId())
    , msName(refCopy.getName())
{
    setRoles(refCopy.getRoles());
}

Artist::~Artist()
{ }

void Artist::addRole(const Media &refMedia)
{
    getRolesInternal().append(refMedia);
}

unsigned Artist::getArtistId() const
{
    return(muiArtistId);
}

QString &Artist::getName() const
{
    return(const_cast<QString &>(msName));
}

const QList<Media> &Artist::getRoles() const
{
    return(getRolesInternal());
}

bool Artist::removeRole(const Media &refMedia)
{
    return(getRolesInternal().removeOne(refMedia));
}

void Artist::removeRole(const unsigned uiIndex)
{
    getRolesInternal().removeAt(static_cast<int>(uiIndex));
}

void Artist::setArtistId(const unsigned uiArtistId)
{
    muiArtistId = uiArtistId;
}

void Artist::setName(const QString &sName)
{
    msName = sName;
}
