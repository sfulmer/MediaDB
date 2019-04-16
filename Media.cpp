#include "DBO.h"

using namespace net::draconia::dbo;

QList<Artist> &Media::getArtistsInternal() const
{
    return(const_cast<QList<Artist> &>(mLstArtists));
}

void Media::setArtists(const QList<Artist> &lstArtists)
{
    mLstArtists.clear();
    mLstArtists.append(lstArtists);
}

Media::Media()
    : Observable()
    , muiMediaId(0)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease)
    : Observable()
    , muiMediaId(uiMediaId)
    , mDtRelease(dtRelease)
    , msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear)
    : Observable()
    , muiMediaId(uiMediaId)
    , mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1))
    , msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Observable()
    , muiMediaId(uiMediaId)
    , mDtRelease(dtRelease)
    , msFilePath(sFilePath), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Observable()
    , muiMediaId(uiMediaId)
    , mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1))
    , msFilePath(sFilePath), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Observable()
    , muiMediaId(uiMediaId)
    , mDtRelease(dtRelease)
    , msName(sName)
{
    setArtists(lstArtists);
}

Media::Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Observable()
    , muiMediaId(uiMediaId)
    , mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1))
    , msName(sName)
{
    setArtists(lstArtists);
}

Media::Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Observable()
    , muiMediaId(uiMediaId)
    , mDtRelease(dtRelease)
    , msFilePath(sFilePath), msName(sName)
{
    setArtists(lstArtists);
}

Media::Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Observable()
    , muiMediaId(uiMediaId)
    , mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1))
    , msFilePath(sFilePath), msName(sName)
{
    setArtists(lstArtists);
}

Media::Media(const Media &refCopy)
    : Observable()
    , muiMediaId(refCopy.getMediaId())
    , mDtRelease(refCopy.getReleaseDate())
    , msFilePath(refCopy.getFilePath())
    , msName(refCopy.getName())
{
    setArtists(refCopy.getArtists());
}

Media::~Media()
{ }


void Media::addArtist(const Artist &refArtist)
{
    getArtistsInternal().append(refArtist);

    setChanged();
    notifyObservers();
}

const QList<Artist> &Media::getArtists() const
{
    return(getArtistsInternal());
}

QString &Media::getFilePath() const
{
    return(const_cast<QString &>(msFilePath));
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

    setChanged();
    notifyObservers();
}

void Media::removeArtist(const unsigned uiIndex)
{
    getArtistsInternal().removeAt(static_cast<int>(uiIndex));

    setChanged();
    notifyObservers();
}

void Media::setFilePath(const QString &sFilePath)
{
    msFilePath = sFilePath;

    setChanged();
    notifyObservers();
}

void Media::setMediaId(const unsigned uiMediaId)
{
    muiMediaId = uiMediaId;

    setChanged();
    notifyObservers();
}

void Media::setName(const QString &sName)
{
    msName = sName;

    setChanged();
    notifyObservers();
}

void Media::setReleaseDate(const QDate &dtRelease)
{
    mDtRelease = dtRelease;

    setChanged();
    notifyObservers();
}

void Media::setReleaseDate(const unsigned uiReleaseYear)
{
    mDtRelease = QDate(static_cast<int>(uiReleaseYear), 1, 1);

    setChanged();
    notifyObservers();
}

bool Media::operator==(const Media &refOther) const
{
    return  (     (getMediaId() == refOther.getMediaId())
            &&    (getName() == refOther.getName())
            &&    (getReleaseDate() == refOther.getReleaseDate())
            &&    (getFilePath() == refOther.getFilePath())
            &&    (getArtists() == refOther.getArtists()));
}

NoMedia::NoMedia()
    : Media()
{ }

NoMedia::NoMedia(const NoMedia &refCopy)
    : Media(refCopy)
{ }

NoMedia::~NoMedia()
{ }
