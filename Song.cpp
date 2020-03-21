#include "Album.h"
#include "Song.h"

using namespace net::draconia::mediadb::dbo;

Song::Song()
    : mPtrAlbum(nullptr), muiSongId(0)
{ }

Song::Song(Album &refAlbum)
    : mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease)
    :   Single(uiMediaId, sName, dtRelease), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear)
    : Single(uiMediaId, sName, uiReleaseYear), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease)
    : Single(uiMediaId, uiSingleId, sName, dtRelease), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease)
    : Single(uiMediaId, uiSingleId, sName, dtRelease), mPtrAlbum(&refAlbum), muiSongId(uiSongId)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear), mPtrAlbum(&refAlbum), muiSongId(uiSongId)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Single(uiMediaId, sName, dtRelease, sFilePath), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Single(uiMediaId, sName, uiReleaseYear, sFilePath), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, sFilePath), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, sFilePath), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, sFilePath), mPtrAlbum(&refAlbum), muiSongId(uiSongId)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, sFilePath), mPtrAlbum(&refAlbum), muiSongId(uiSongId)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Single(uiMediaId, sName, dtRelease, sFilePath, sComments), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Single(uiMediaId, sName, uiReleaseYear, sFilePath, sComments), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, sFilePath, sComments), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, sFilePath, sComments), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, sFilePath, sComments), mPtrAlbum(&refAlbum), muiSongId(uiSongId)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, sFilePath, sComments), mPtrAlbum(&refAlbum), muiSongId(uiSongId)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Single(uiMediaId, sName, dtRelease, lstArtists), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Single(uiMediaId, sName, uiReleaseYear, lstArtists), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, lstArtists), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, lstArtists), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, lstArtists), mPtrAlbum(&refAlbum), muiSongId(uiSongId)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, lstArtists), mPtrAlbum(&refAlbum), muiSongId(uiSongId)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, sName, dtRelease, lstArtists, sComments), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, sName, uiReleaseYear, lstArtists, sComments), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, lstArtists, sComments), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, lstArtists, sComments), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, lstArtists, sComments), mPtrAlbum(&refAlbum), muiSongId(uiSongId)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, lstArtists, sComments), mPtrAlbum(&refAlbum), muiSongId(uiSongId)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Single(uiMediaId, sName, dtRelease, sFilePath, lstArtists), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Single(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, sFilePath, lstArtists), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, sFilePath, lstArtists), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, sFilePath, lstArtists), mPtrAlbum(&refAlbum), muiSongId(uiSongId)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, sFilePath, lstArtists), mPtrAlbum(&refAlbum), muiSongId(uiSongId)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, sName, dtRelease, sFilePath, lstArtists, sComments), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists, sComments), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, sFilePath, lstArtists, sComments), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, sFilePath, lstArtists, sComments), mPtrAlbum(&refAlbum), muiSongId(0)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, sFilePath, lstArtists, sComments), mPtrAlbum(&refAlbum), muiSongId(uiSongId)
{ }

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, sFilePath, lstArtists, sComments), mPtrAlbum(&refAlbum), muiSongId(uiSongId)
{ }

Song::Song(const Song &refCopy)
    : Single(refCopy), mPtrAlbum(refCopy.mPtrAlbum), muiSongId(refCopy.getSongId())
{ }

Song::~Song()
{
    mPtrAlbum.reset(nullptr);
}

Album Song::getAlbum() const
{
    if(mPtrAlbum.isNull())
        return(Album());
    else
        return(*mPtrAlbum);
}

unsigned Song::getSongId() const
{
    return(muiSongId);
}

void Song::setAlbum(const Album &refAlbum)
{
    mPtrAlbum.reset(const_cast<Album *>(&refAlbum));

    setChanged();
    notifyObservers("ALbum");
}

void Song::setSongId(const unsigned uiSongId)
{
    muiSongId = uiSongId;

    setChanged();
    notifyObservers("SongId");
}

Song &Song::operator=(const Song &refOther)
{
    Single::operator=(refOther);
    setAlbum(*refOther.mPtrAlbum);
    setSongId(refOther.getSongId());

    return(*this);
}

bool Song::operator==(const Song &refOther) const
{
    return  (   Single::operator==(refOther)
            &&  (getAlbum() == refOther.getAlbum())
            &&  (getSongId() == refOther.getSongId()));
}

bool Song::operator!=(const Song &refOther) const
{
    return(!operator==(refOther));
}
