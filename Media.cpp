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
    : MediaFile()
    , muiMediaId(0)
{ }

Media::Media(const unsigned uiMediaId)
    : MediaFile()
    , muiMediaId(uiMediaId)
{ }

Media::Media(const QString &sName)
    : MediaFile()
    , muiMediaId(0), msName(sName)
{ }

Media::Media(const QList<Artist> &lstArtists)
    : MediaFile()
    , muiMediaId(0), mLstArtists(lstArtists)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName)
    : MediaFile()
    , muiMediaId(uiMediaId), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QDate &dtRelease)
    : MediaFile()
    , muiMediaId(uiMediaId), mDtRelease(dtRelease)
{ }

Media::Media(const unsigned uiMediaId, const unsigned uiReleaseYear)
    : MediaFile()
    , muiMediaId(uiMediaId), mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1))
{ }

Media::Media(const unsigned uiMediaId, const QList<Artist> &lstArtists)
    : MediaFile()
    , muiMediaId(uiMediaId), mLstArtists(lstArtists)
{ }

Media::Media(const QString &sName, const QDate &dtRelease)
    : MediaFile()
    , muiMediaId(0), mDtRelease(dtRelease), msName(sName)
{ }

Media::Media(const QString &sName, const unsigned uiReleaseYear)
    : MediaFile()
    , muiMediaId(0), mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1)), msName(sName)
{ }

Media::Media(const QString &sName, const QString &sFilePath)
    : MediaFile(sFilePath)
    , muiMediaId(0), msName(sName)
{ }

Media::Media(const QString &sName, const QList<Artist> &lstArtists)
    : MediaFile()
    , muiMediaId(0), mLstArtists(lstArtists), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease)
    : MediaFile()
    , muiMediaId(uiMediaId), mDtRelease(dtRelease), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear)
    : MediaFile()
    , muiMediaId(uiMediaId), mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1)), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const QString &sFilePath)
    : MediaFile(sFilePath)
    , muiMediaId(uiMediaId), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const QList<Artist> &lstArtists)
    : MediaFile()
    , muiMediaId(uiMediaId), mLstArtists(lstArtists), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : MediaFile()
    , muiMediaId(uiMediaId), mDtRelease(dtRelease), mLstArtists(lstArtists), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : MediaFile()
    , muiMediaId(uiMediaId), mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1)), mLstArtists(lstArtists), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : MediaFile(sFilePath)
    , muiMediaId(uiMediaId), mDtRelease(dtRelease), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : MediaFile(sFilePath)
    , muiMediaId(uiMediaId), mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1)), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> lstArtists)
    : MediaFile(sFilePath)
    , muiMediaId(uiMediaId), mDtRelease(dtRelease), mLstArtists(lstArtists), msName(sName)
{ }

Media::Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> lstArtists)
    : MediaFile(sFilePath)
    , muiMediaId(uiMediaId), mDtRelease(QDate(static_cast<int>(uiReleaseYear), 1, 1)), mLstArtists(lstArtists), msName(sName)
{ }

Media::Media(const Media &refCopy)
    : MediaFile(refCopy)
    , muiMediaId(refCopy.getMediaId())
    , mDtRelease(refCopy.getReleaseDate())
    , mLstArtists(refCopy.getArtists())
    , msName(refCopy.getName())
{ }

Media::~Media()
{ }

void Media::addArtist(const Artist &refArtist)
{
    getArtistsInternal().append(refArtist);

    setChanged();
    notifyObservers("Artists");
}

const QList<Artist> Media::getArtists() const
{
    return(getArtistsInternal());
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

    setChanged();
    notifyObservers("Artists");
}

void Media::setMediaId(const unsigned uiMediaId)
{
    muiMediaId = uiMediaId;

    setChanged();
    notifyObservers("MediaId");
}

void Media::setName(const QString &sName)
{
    msName = sName;

    setChanged();
    notifyObservers("Name");
}

void Media::setReleaseDate(const QDate &dtRelease)
{
    mDtRelease = dtRelease;

    setChanged();
    notifyObservers("ReleaseDate");
}

void Media::setReleaseDate(const unsigned uiReleaseYear)
{
    mDtRelease = QDate(static_cast<int>(uiReleaseYear), 1, 1);

    setChanged();
    notifyObservers("ReleaseDate");
}

Media &Media::operator=(const Media &refCopy)
{
    MediaFile::operator=(refCopy);

    setMediaId(refCopy.getMediaId());
    setName(refCopy.getName());
    setFilePath(refCopy.getFilePath());
    setReleaseDate(refCopy.getReleaseDate());
    setArtists(refCopy.getArtists());

    return(*this);
}

bool Media::operator==(const Media &refOther) const
{
    return  (   MediaFile::operator==(refOther)
            &&  (getMediaId() == refOther.getMediaId())
            &&  (getName() == refOther.getName())
            &&  (getFilePath() == refOther.getFilePath())
            &&  (getReleaseDate() == refOther.getReleaseDate())
            &&  (getArtists() == refOther.getArtists()));
}

bool Media::operator!=(const Media &refOther) const
{
    return(!operator==(refOther));
}
