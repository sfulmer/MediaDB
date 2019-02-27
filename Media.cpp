#include "Media.h"

using namespace net::draconia;

QList<Artist> Media::getArtistsInternal() const
{
    return(mLstArtists);
}

void Media::setArtists(const QList<Artist> &lstArtists)
{
    mLstArtists.clear();
    mLstArtists.append(lstArtists);
}

Media::Media()
    : muiMediaId(0)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease)
    : muiMediaId(uiMediaId)
    , mDtRelease(dtRelease)
    , msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear)
    : muiMediaId(uiMediaId)
    , mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1))
    , msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : muiMediaId(uiMediaId)
    , mDtRelease(dtRelease)
    , msFilePath(sFilePath), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : muiMediaId(uiMediaId)
    , mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1))
    , msFilePath(sFilePath), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : muiMediaId(uiMediaId)
    , mDtRelease(dtRelease)
    , msName(sName)
{
    setArtists(lstArtists);
}

Media::Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : muiMediaId(uiMediaId)
    , mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1))
    , msName(sName)
{
    setArtists(lstArtists);
}

Media::Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : muiMediaId(uiMediaId)
    , mDtRelease(dtRelease)
    , msFilePath(sFilePath), msName(sName)
{
    setArtists(lstArtists);
}

Media::Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : muiMediaId(uiMediaId)
    , mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1))
    , msFilePath(sFilePath), msName(sName)
{
    setArtists(lstArtists);
}

Media::Media(const Media &refCopy)
    : muiMediaId(refCopy.getMediaId())
    , mDtRelease(refCopy.getReleaseDate())
    , msFilePath(refCopy.getFilePath())
    , msName(refCopy.getName())
{
    setArtists(refCopy.getArtists());
}


void Media::addArtist(const Artist &refArtist)
{
    getArtistsInternal().append(refArtist);
}

const QList<Artist> Media::getArtists() const
{
    return(getArtistsInternal());
}

QString &Media::getFilePath() const
{
    return(msFilePath);
}

unsigned Media::getMediaId() const
{
    return(muiMediaId);
}

QString Media::getName() const
{
    return(msName);
}

QDate Media::getReleaseDate() const
{
    return(mDtRelease);
}

bool Media::removeArtist(const Artist &refArtist)
{
    return(getArtistsInternal().removeOne(refArtist));
}

void Media::removeArtist(const unsigned uiIndex)
{
    getArtistsInternal().removeAt(uiIndex);
}

void Media::setFilePath(const QString &sFilePath)
{
    msFilePath = sFilePath;
}

void Media::setMediaId(const unsigned uiMediaId)
{
    muiMediaId = uiMediaId;
}

void Media::setName(const QString &sName)
{
    msName = sName;
}

void Media::setReleaseDate(const QDate &dtRelease)
{
    mDtRelease = dtRelease;
}

void Media::setReleaseDate(const unsigned uiReleaseYear)
{
    mDtRelease = QDate(static_cast<int>(uiReleaseYear), 1, 1);
}
