#include "TVSeason.h"
#include "TVEpisode.h"

using namespace net::draconia::mediadb::dbo;

TVEpisode::TVEpisode()
    : Media()
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(nullptr)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason)
    : Media()
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId)
    : Media(uiMediaId)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const QString &sName)
    : Media(sName)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const QList<Artist> &lstArtists)
    : Media(lstArtists)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName)
    : Media(uiMediaId, sName)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QDate &dtRelease)
    : Media(uiMediaId, dtRelease)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiReleaseYear)
    : Media(uiMediaId, uiReleaseYear)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QList<Artist> &lstArtists)
    : Media(uiMediaId, lstArtists)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const QString &sName, const QDate &dtRelease)
    : Media(sName, dtRelease)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const QString &sName, const unsigned uiReleaseYear)
    : Media(sName, uiReleaseYear)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const QString &sName, const QString &sFilePath)
    : Media(sName, sFilePath)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const QString &sName, const QList<Artist> &lstArtists)
    : Media(sName, lstArtists)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QString &sFilePath)
    : Media(uiMediaId, sName, sFilePath)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, lstArtists)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QString &sFilePath)
    : Media(uiMediaId, sName, sFilePath)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QString &sFilePath)
    : Media(uiMediaId, sName, sFilePath)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, lstArtists)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, lstArtists)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiNumber(0), muiTVEpisodeId(0)
    , msComments(sComments)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiNumber(0), muiTVEpisodeId(0)
    , msComments(sComments)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiNumber(0), muiTVEpisodeId(0)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QList<Artist> lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiNumber(0), muiTVEpisodeId(0)
    , msComments(sComments)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QList<Artist> lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiNumber(0), muiTVEpisodeId(0)
    , msComments(sComments)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QList<Artist> lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QList<Artist> lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QList<Artist> lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QList<Artist> lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mPtrTVSeason(&refTVSeason)
{ }

TVEpisode::TVEpisode(const TVEpisode &refCopy)
    : Media(refCopy)
    , muiNumber(refCopy.getNumber())
    , muiTVEpisodeId(refCopy.getTVEpisodeId())
    , msComments(refCopy.getComments())
    , mPtrTVSeason(refCopy.mPtrTVSeason)
{ }

TVEpisode::~TVEpisode()
{
    mPtrTVSeason.reset(nullptr);
}

QString TVEpisode::getComments() const
{
    return(msComments);
}

unsigned TVEpisode::getNumber() const
{
    return(muiNumber);
}

TVSeason TVEpisode::getSeason() const
{
    if(mPtrTVSeason.isNull())
        return(TVSeason());
    else
        return(*mPtrTVSeason);
}

unsigned TVEpisode::getTVEpisodeId() const
{
    return(muiTVEpisodeId);
}

void TVEpisode::setComments(const QString &sComments)
{
    msComments = sComments;

    setChanged(true);
    notifyObservers();
}

void TVEpisode::setNumber(const unsigned uiNumber)
{
    muiNumber = uiNumber;

    setChanged(true);
    notifyObservers();
}

void TVEpisode::setTVEpisodeId(const unsigned uiTVEpisodeId)
{
    muiTVEpisodeId = uiTVEpisodeId;

    setChanged(true);
    notifyObservers();
}

TVEpisode &TVEpisode::operator=(const TVEpisode &refCopy)
{
    MediaFile::operator=(refCopy);

    setComments(refCopy.getComments());
    setNumber(refCopy.getNumber());
    setTVEpisodeId(refCopy.getTVEpisodeId());

    return(*this);
}

bool TVEpisode::operator==(const TVEpisode &refOther) const
{
    return  (   MediaFile::operator==(refOther)
            &&  (getComments() == refOther.getComments())
            &&  (getNumber() == refOther.getNumber())
            &&  (getTVEpisodeId() == refOther.getTVEpisodeId()));
}

bool TVEpisode::operator!=(const TVEpisode &refOther) const
{
    return(!operator==(refOther));
}
