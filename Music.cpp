#include "DBO.h"

using namespace net::draconia::dbo;

Single::Single()
    : Media()
    , muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease)
    , muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear)
    , muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease)
    , muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear)
    , muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , msComments(sComments)
    , muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , msComments(sComments)
    , muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , msComments(sComments)
    , muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , msComments(sComments)
    , muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , msComments(sComments)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , msComments(sComments)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , msComments(sComments)
    , muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , msComments(sComments)
    , muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , msComments(sComments)
    , muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , msComments(sComments)
    , muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , msComments(sComments)
    , muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , msComments(sComments)
    , muiSingleId(uiSingleId)
{ }

Single::Single(const Single &refCopy)
    : Media(refCopy.getMediaId(), refCopy.getName(), refCopy.getReleaseDate(), refCopy.getFilePath(), refCopy.getArtists())
    , msComments(refCopy.getComments())
    , muiSingleId(refCopy.getSingleId())
{ }

Single::~Single()
{ }

QString &Single::getComments() const
{
    return(const_cast<QString &>(msComments));
}

unsigned Single::getSingleId() const
{
    return(muiSingleId);
}

void Single::setComments(const QString &sComments)
{
    msComments = sComments;

    setChanged();
    notifyObservers();
}

void Single::setSingleId(const unsigned uiSingleId)
{
    muiSingleId = uiSingleId;

    setChanged();
    notifyObservers();
}

Song::Song(Album &refAlbum)
    : Single()
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease)
    : Single(uiMediaId, sName, dtRelease)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear)
    : Single(uiMediaId, sName, uiReleaseYear)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease)
    : Single(uiMediaId, uiSingleId, sName, dtRelease)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease)
    : Single(uiMediaId, uiSingleId, sName, dtRelease)
    , mRefAlbum(refAlbum)
    , muiSongId(uiSongId)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear)
    , mRefAlbum(refAlbum)
    , muiSongId(uiSongId)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Single(uiMediaId, sName, dtRelease, sFilePath)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Single(uiMediaId, sName, uiReleaseYear, sFilePath)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, sFilePath)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, sFilePath)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, sFilePath)
    , mRefAlbum(refAlbum)
    , muiSongId(uiSongId)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, sFilePath)
    , mRefAlbum(refAlbum)
    , muiSongId(uiSongId)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Single(uiMediaId, sName, dtRelease, sFilePath, sComments)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Single(uiMediaId, sName, uiReleaseYear, sFilePath, sComments)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, sFilePath, sComments)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, sFilePath, sComments)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, sFilePath, sComments)
    , mRefAlbum(refAlbum)
    , muiSongId(uiSongId)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, sFilePath, sComments)
    , mRefAlbum(refAlbum)
    , muiSongId(uiSongId)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Single(uiMediaId, sName, dtRelease, lstArtists)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Single(uiMediaId, sName, uiReleaseYear, lstArtists)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, lstArtists)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, lstArtists)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, lstArtists)
    , mRefAlbum(refAlbum)
    , muiSongId(uiSongId)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, lstArtists)
    , mRefAlbum(refAlbum)
    , muiSongId(uiSongId)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, sName, dtRelease, lstArtists, sComments)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, sName, uiReleaseYear, lstArtists, sComments)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, lstArtists, sComments)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, lstArtists, sComments)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, lstArtists, sComments)
    , mRefAlbum(refAlbum)
    , muiSongId(uiSongId)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, lstArtists, sComments)
    , mRefAlbum(refAlbum)
    , muiSongId(uiSongId)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Single(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Single(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, sFilePath, lstArtists)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, sFilePath, lstArtists)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, sFilePath, lstArtists)
    , mRefAlbum(refAlbum)
    , muiSongId(uiSongId)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, sFilePath, lstArtists)
    , mRefAlbum(refAlbum)
    , muiSongId(uiSongId)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, sName, dtRelease, sFilePath, lstArtists, sComments)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists, sComments)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, sFilePath, lstArtists, sComments)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, sFilePath, lstArtists, sComments)
    , mRefAlbum(refAlbum)
    , muiSongId(0)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, dtRelease, sFilePath, lstArtists, sComments)
    , mRefAlbum(refAlbum)
    , muiSongId(uiSongId)
{
    getAlbum().addSong(*this);
}

Song::Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Single(uiMediaId, uiSingleId, sName, uiReleaseYear, sFilePath, lstArtists, sComments)
    , mRefAlbum(refAlbum)
    , muiSongId(uiSongId)
{
    getAlbum().addSong(*this);
}

Song::Song(const Song &refCopy)
    : Single(refCopy.getMediaId(), refCopy.getSingleId(), refCopy.getName(), refCopy.getReleaseDate(), refCopy.getFilePath(), refCopy.getArtists(), refCopy.getComments())
    , mRefAlbum(refCopy.getAlbum())
    , muiSongId(refCopy.getSongId())
{
    getAlbum().addSong(*this);
}

Song::~Song()
{
    getAlbum().removeSong(*this);
}

Album &Song::getAlbum() const
{
    return(mRefAlbum);
}

unsigned Song::getSongId() const
{
    return(muiSongId);
}

void Song::setSongId(const unsigned uiSongId)
{
    muiSongId = uiSongId;

    setChanged();
    notifyObservers();
}

Song &Song::operator=(const Song &refOther)
{
    Single::operator=(refOther);

    setSongId(refOther.getSongId());

    setChanged();
    notifyObservers();

    return(*this);
}

QList<Song> &Album::getSongsInternal() const
{
    return(const_cast<QList<Song> &>(mLstSongs));
}

void Album::setSongs(const QList<Song> &lstSongs)
{
    mLstSongs.clear();
    mLstSongs.append(lstSongs);

    setChanged();
    notifyObservers();
}

Album::Album()
    : Observable()
    , muiAlbumId(0)
{ }

Album::Album(const unsigned uiAlbumId)
    : Observable()
    , muiAlbumId(uiAlbumId)
{ }

Album::Album(const QString &sName)
    : Observable()
    , msName(sName)
    , muiAlbumId(0)
{ }

Album::Album(const QList<Song> &lstSongs)
    : Observable()
    , muiAlbumId(0)
{
    setSongs(lstSongs);
}

Album::Album(const unsigned uiAlbumId, const QString &sName)
    : Observable()
    , msName(sName)
    , muiAlbumId(uiAlbumId)
{ }

Album::Album(const unsigned uiAlbumId, const QList<Song> &lstSongs)
    : Observable()
    , muiAlbumId(uiAlbumId)
{
    setSongs(lstSongs);
}

Album::Album(const QString &sName, const QList<Song> &lstSongs)
    : Observable()
    , msName(sName)
{
    setSongs(lstSongs);
}

Album::Album(const unsigned uiAlbumId, const QString &sName, const QList<Song> &lstSongs)
    : Observable()
    , msName(sName)
    , muiAlbumId(uiAlbumId)
{
    setSongs(lstSongs);
}

Album::Album(const Album &refCopy)
    : Observable()
    , msName(refCopy.getName())
    , muiAlbumId(refCopy.getAlbumId())
{
    setSongs(refCopy.getSongs());
}

Album::~Album()
{ }

void Album::addSong(const Song &refSong)
{
    getSongsInternal().append(refSong);

    setChanged();
    notifyObservers();
}

unsigned Album::getAlbumId() const
{
    return(muiAlbumId);
}

QString &Album::getName() const
{
    return(const_cast<QString &>(msName));
}

const QList<Song> Album::getSongs() const
{
    return(getSongsInternal());
}

bool Album::removeSong(const Song &refSong)
{
    bool bReturnValue = getSongsInternal().removeOne(refSong);

    setChanged();
    notifyObservers();

    return(bReturnValue);
}

void Album::removeSong(const unsigned uiIndex)
{
    getSongsInternal().removeAt(static_cast<int>(uiIndex));

    setChanged();
    notifyObservers();
}

void Album::setAlbumId(const unsigned uiAlbumId)
{
    muiAlbumId = uiAlbumId;

    setChanged();
    notifyObservers();
}

void Album::setName(const QString &sName)
{
    msName = sName;

    setChanged();
    notifyObservers();
}
