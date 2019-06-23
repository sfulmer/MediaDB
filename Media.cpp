#include "Media.h"

using namespace net::draconia::mediadb::dbo;

QList<Artist> &Media::getArtistsInternal() const
{
    return(const_cast<QList<Artist> &>(mLstArtists));
}

void Media::setArtists(const QList<Artist> lstArtists)
{
    mLstArtists.clear();
    mLstArtists.append(lstArtists);
}

Media::Media()
    : muiMediaId(0)
{ }

Media::Media(const unsigned uiMediaId)
    : muiMediaId(uiMediaId)
{ }

Media::Media(const QString &sName)
    : muiMediaId(0), msName(sName)
{ }

Media::Media(const QList<Artist> &lstArtists)
    : muiMediaId(0), mLstArtists(lstArtists)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName)
    : muiMediaId(uiMediaId), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QDate &dtRelease)
    : muiMediaId(uiMediaId), mDtRelease(dtRelease)
{ }

Media::Media(const unsigned uiMediaId, const unsigned uiReleaseYear)
    : muiMediaId(uiMediaId), mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1))
{ }

Media::Media(const unsigned uiMediaId, const QList<Artist> &lstArtists)
    : muiMediaId(uiMediaId), mLstArtists(lstArtists)
{ }

Media::Media(const QString &sName, const QDate &dtRelease)
    : muiMediaId(0), mDtRelease(dtRelease), msName(sName)
{ }

Media::Media(const QString &sName, const unsigned uiReleaseYear)
    : muiMediaId(0), mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1)), msName(sName)
{ }

Media::Media(const QString &sName, const QString &sFilePath)
    : muiMediaId(0), msFilePath(sFilePath), msName(sName)
{ }


Media::Media(const QString &sName, const QList<Artist> &lstArtists)
    : muiMediaId(0), mLstArtists(lstArtists), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease)
    : muiMediaId(uiMediaId), mDtRelease(dtRelease), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear)
    : muiMediaId(uiMediaId), mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1)), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const QString &sFilePath)
    : muiMediaId(uiMediaId), msFilePath(sFilePath), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const QList<Artist> &lstArtists)
    : muiMediaId(uiMediaId), mLstArtists(lstArtists), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : muiMediaId(uiMediaId), mDtRelease(dtRelease), mLstArtists(lstArtists), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : muiMediaId(uiMediaId), mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1)), mLstArtists(lstArtists), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : muiMediaId(uiMediaId), mDtRelease(dtRelease), msFilePath(sFilePath), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : muiMediaId(uiMediaId), mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1)), msFilePath(sFilePath), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> lstArtists)
    : muiMediaId(uiMediaId), mDtRelease(dtRelease), mLstArtists(lstArtists), msFilePath(sFilePath), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> lstArtists)
    : muiMediaId(uiMediaId), mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1)), mLstArtists(lstArtists), msFilePath(sFilePath), msName(sName)
{ }

Media::Media(const Media &refCopy)
    : muiMediaId(refCopy.getMediaId())
    , mDtRelease(refCopy.getReleaseDate())
    , mLstArtists(refCopy.getArtists())
    , msFilePath(refCopy.getFilePath())
    , msName(refCopy.getName())
{ }

Media::~Media()
{ }

void Media::addArtist(const Artist &refArtist)
{
    getArtistsInternal().append(refArtist);

    setChanged(true);
    notifyObservers();
}

const QList<Artist> Media::getArtists() const
{
    return(getArtistsInternal());
}

QString Media::getFilePath() const
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

void Media::removeArtist(const Artist &refArtist)
{
    getArtistsInternal().removeOne(refArtist);

    setChanged(true);
    notifyObservers();
}

void Media::setFilePath(const QString &sFilePath)
{
    msFilePath = sFilePath;

    setChanged(true);
    notifyObservers();
}

void Media::setMediaId(const unsigned uiMediaId)
{
    muiMediaId = uiMediaId;

    setChanged(true);
    notifyObservers();
}

void Media::setName(const QString &sName)
{
    msName = sName;

    setChanged(true);
    notifyObservers();
}

void Media::setReleaseDate(const QDate &dtRelease)
{
    mDtRelease = dtRelease;

    setChanged(true);
    notifyObservers();
}

void Media::setReleaseDate(const unsigned uiReleaseYear)
{
    mDtRelease = QDate(static_cast<int>(uiReleaseYear), 1, 1);

    setChanged(true);
    notifyObservers();
}

Media &Media::operator=(const Media &refCopy)
{
    setMediaId(refCopy.getMediaId());
    setName(refCopy.getName());
    setFilePath(refCopy.getFilePath());
    setReleaseDate(refCopy.getReleaseDate());
    setArtists(refCopy.getArtists());

    return(*this);
}

bool Media::operator==(const Media &refOther) const
{
    return  (   (getMediaId() == refOther.getMediaId())
            &&  (getName() == refOther.getName())
            &&  (getFilePath() == refOther.getFilePath())
            &&  (getReleaseDate() == refOther.getReleaseDate())
            &&  (getArtists() == refOther.getArtists()));
}

bool Media::operator!=(const Media &refOther) const
{
    return(!operator==(refOther));
}
