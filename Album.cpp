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

    setChanged();
    notifyObservers("Songs");
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

Album::Album(const QString &sName, const QDate dtRelease)
    : mDtRelease(dtRelease), msName(sName)
    , muiAlbumId(0)
{ }

Album::Album(const QString &sName, const unsigned uiReleaseYear)
    : mDtRelease(static_cast<int>(uiReleaseYear), 1, 1), msName(sName)
    , muiAlbumId(0)
{ }

Album::Album(const QString &sName, const QList<Song> &lstSongs)
    : mLstSongs(lstSongs), msName(sName), muiAlbumId(0)
{ }

Album::Album(const QString &sName, const QString &sComments)
    : msComments(sComments), msName(sName)
    , muiAlbumId(0)
{ }

Album::Album(const QString &sName, const QDate dtRelease, const QString &sComments)
    : mDtRelease(dtRelease)
    , msComments(sComments)
    , msName(sName)
    , muiAlbumId(0)
{ }

Album::Album(const QString &sName, const unsigned uiReleaseYear, const QString &sComments)
    : mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1))
    , msComments(sComments)
    , msName(sName)
    , muiAlbumId(0)
{ }

Album::Album(const unsigned uiAlbumId, const QString &sName, const QDate dtRelease)
    : mDtRelease(dtRelease), msName(sName)
    , muiAlbumId(uiAlbumId)
{ }

Album::Album(const unsigned uiAlbumId, const QString &sName, const unsigned uiReleaseYear)
    : mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1)), msName(sName)
    , muiAlbumId(uiAlbumId)
{ }

Album::Album(const unsigned uiAlbumId, const QString &sName, const QList<Song> &lstSongs)
    : mLstSongs(lstSongs)
    , msName(sName)
    , muiAlbumId(uiAlbumId)
{ }

Album::Album(const unsigned uiAlbumId, const QString &sName, const QString &sComments)
    : msComments(sComments), msName(sName)
    , muiAlbumId(uiAlbumId)
{ }

Album::Album(const unsigned uiAlbumId, const QString &sName, const QDate dtRelease, const QString &sComments)
    : mDtRelease(dtRelease)
    , msComments(sComments)
    , msName(sName)
    , muiAlbumId(uiAlbumId)
{ }

Album::Album(const unsigned uiAlbumId, const QString &sName, const unsigned uiReleaseYear, const QString &sComments)
    : mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1))
    , msComments(sComments)
    , msName(sName)
    , muiAlbumId(uiAlbumId)
{ }

Album::Album(const unsigned uiAlbumId, const QString &sName, const unsigned uiReleaseYear, const QList<Song> &lstSongs)
    : mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1))
    , mLstSongs(lstSongs)
    , msName(sName)
    , muiAlbumId(uiAlbumId)
{ }

Album::Album(const unsigned uiAlbumId, const QString &sName, const QDate dtRelease, const QList<Song> &lstSongs, const QString &sComments)
    : mDtRelease(dtRelease)
    , mLstSongs(lstSongs)
    , msComments(sComments)
    , msName(sName)
    , muiAlbumId(uiAlbumId)
{ }

Album::Album(const unsigned uiAlbumId, const QString &sName, const unsigned uiReleaseYear, const QList<Song> &lstSongs, const QString &sComments)
    : mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1))
    , mLstSongs(lstSongs)
    , msComments(sComments)
    , msName(sName)
    , muiAlbumId(uiAlbumId)
{ }

Album::Album(const Album &refCopy)
    : mDtRelease(refCopy.getReleaseDate())
    , mLstSongs(refCopy.getSongs())
    , msComments(refCopy.getComments())
    , msName(refCopy.getName())
    , muiAlbumId(refCopy.getAlbumId())
{ }

Album::~Album()
{ }

void Album::addSong(const Song &refSong)
{
    getSongsInternal().append(refSong);

    setChanged();
    notifyObservers("Songs");
}

unsigned Album::getAlbumId() const
{
    return(muiAlbumId);
}

QString Album::getComments() const
{
    return(msComments);
}

QString Album::getName() const
{
    return(msName);
}

QDate Album::getReleaseDate() const
{
    return(mDtRelease);
}

const QList<Song> Album::getSongs() const
{
    return(getSongsInternal());
}

bool Album::removeSong(const Song &refSong)
{
    bool bRetVal = getSongsInternal().removeOne(refSong);

    setChanged();
    notifyObservers("Songs");

    return(bRetVal);
}

void Album::removeSong(const unsigned uiIndex)
{
    getSongsInternal().removeAt(static_cast<int>(uiIndex));

    setChanged();
    notifyObservers("Songs");
}

void Album::setAlbumId(const unsigned uiAlbumId)
{
    muiAlbumId = uiAlbumId;

    setChanged();
    notifyObservers("AlbumId");
}

void Album::setComments(const QString &sComments)
{
    msComments = sComments;

    setChanged();
    notifyObservers("Comments");
}

void Album::setName(const QString &sName)
{
    msName = sName;

    setChanged();
    notifyObservers("Name");
}

void Album::setReleaseDate(const QDate &dtRelease)
{
    mDtRelease = dtRelease;

    setChanged();
    notifyObservers("ReleaseDate");
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
