#include "Album.h"

using namespace net::draconia::mediadb::dbo;

QList<Song> &Album::getSongsInternal() const
{
    return(const_cast<QList<Song> &>(mLstSongs));
}

void Album::setSongs(const QList<Song> &lstSongs)
{
    getSongsInternal().clear();
    getSongsInternal().append(lstSongs);

    setChanged(true);
    notifyObservers();
}

Album::Album()
    : muiAlbumId(0)
{ }

Album::Album(const unsigned uiAlbumId)
    : muiAlbumId(uiAlbumId)
{ }

Album::Album(const QString &sName)
    : msName(sName), muiAlbumId(0)
{ }

Album::Album(const QList<Song> &lstSongs)
    : mLstSongs(lstSongs), muiAlbumId(0)
{ }

Album::Album(const unsigned uiAlbumId, const QString &sName)
    : msName(sName), muiAlbumId(uiAlbumId)
{ }

Album::Album(const unsigned uiAlbumId, const QList<Song> &lstSongs)
    : mLstSongs(lstSongs), muiAlbumId(uiAlbumId)
{ }

Album::Album(const QString &sName, const QList<Song> &lstSongs)
    : mLstSongs(lstSongs), msName(sName), muiAlbumId(0)
{ }

Album::Album(const unsigned uiAlbumId, const QString &sName, const QList<Song> &lstSongs)
    : mLstSongs(lstSongs), msName(sName), muiAlbumId(uiAlbumId)
{ }

Album::Album(const Album &refCopy)
    : mLstSongs(refCopy.getSongs()), msName(refCopy.getName()), muiAlbumId(refCopy.getAlbumId())
{ }

Album::~Album()
{ }

void Album::addSong(const Song &refSong)
{
    getSongsInternal().append(refSong);

    setChanged(true);
    notifyObservers();
}

unsigned Album::getAlbumId() const
{
    return(muiAlbumId);
}

QString Album::getName() const
{
    return(msName);
}

const QList<Song> Album::getSongs() const
{
    return(getSongsInternal());
}

bool Album::removeSong(const Song &refSong)
{
    bool bRetVal = getSongsInternal().removeOne(refSong);

    setChanged(true);
    notifyObservers();

    return(bRetVal);
}

void Album::removeSong(const unsigned uiIndex)
{
    getSongsInternal().removeAt(static_cast<int>(uiIndex));

    setChanged(true);
    notifyObservers();
}

void Album::setAlbumId(const unsigned uiAlbumId)
{
    muiAlbumId = uiAlbumId;

    setChanged(true);
    notifyObservers();
}

void Album::setName(const QString &sName)
{
    msName = sName;

    setChanged(true);
    notifyObservers();
}

Album &Album::operator=(const Album &refCopy)
{
    setAlbumId(refCopy.getAlbumId());
    setName(refCopy.getName());
    setSongs(refCopy.getSongs());

    return(*this);
}

bool Album::operator==(const Album &refOther) const
{
    return  (   (getAlbumId() == refOther.getAlbumId())
            &&  (getName() == refOther.getName())
            &&  (getSongs() == refOther.getSongs()));
}

bool Album::operator!=(const Album &refOther) const
{
    return(!operator==(refOther));
}
