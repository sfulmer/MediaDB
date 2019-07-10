#include "TVSeries.h"
#include "TVSpecial.h"

using namespace net::draconia::mediadb::dbo;

TVSpecial::TVSpecial()
    : Media()
    , muiTVSpecialId(0)
    , mPtrTVSeries(nullptr)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries)
    : Media()
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId)
    : Media(uiMediaId)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const QString &sName)
    : Media(sName)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const QList<Artist> &lstArtists)
    : Media(lstArtists)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName)
    : Media(uiMediaId, sName)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QDate &dtRelease)
    : Media(uiMediaId, dtRelease)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiReleaseYear)
    : Media(uiMediaId, uiReleaseYear)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QList<Artist> &lstArtists)
    : Media(uiMediaId, lstArtists)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName)
    : Media(uiMediaId, sName)
    , muiTVSpecialId(uiTVSpecialId)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QDate &dtRelease)
    : Media(uiMediaId, dtRelease)
    , muiTVSpecialId(uiTVSpecialId)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const unsigned uiReleaseYear)
    : Media(uiMediaId, uiReleaseYear)
    , muiTVSpecialId(uiTVSpecialId)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QList<Artist> &lstArtists)
    : Media(uiMediaId, lstArtists)
    , muiTVSpecialId(uiTVSpecialId)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const QString &sName, const QDate &dtRelease)
    : Media(sName, dtRelease)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const QString &sName, const unsigned uiReleaseYear)
    : Media(sName, uiReleaseYear)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const QString &sName, const QString &sFilePath)
    : Media(sName, sFilePath)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const QString &sName, const QList<Artist> &lstArtists)
    : Media(sName, lstArtists)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QString &sFilePath)
    : Media(uiMediaId, sName, sFilePath)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, lstArtists)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease)
    , muiTVSpecialId(uiTVSpecialId)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear)
    , muiTVSpecialId(uiTVSpecialId)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QString &sFilePath)
    : Media(uiMediaId, sName, sFilePath)
    , muiTVSpecialId(uiTVSpecialId)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, lstArtists)
    , muiTVSpecialId(uiTVSpecialId)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiTVSpecialId(uiTVSpecialId)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiTVSpecialId(uiTVSpecialId)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiTVSpecialId(uiTVSpecialId)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiTVSpecialId(uiTVSpecialId)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiTVSpecialId(uiTVSpecialId)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiTVSpecialId(uiTVSpecialId)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , msComments(sComments)
    , muiTVSpecialId(uiTVSpecialId)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , msComments(sComments)
    , muiTVSpecialId(uiTVSpecialId)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , msComments(sComments)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , msComments(sComments)
    , muiTVSpecialId(0)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , msComments(sComments)
    , muiTVSpecialId(uiTVSpecialId)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , msComments(sComments)
    , muiTVSpecialId(uiTVSpecialId)
    , mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(const TVSpecial &refCopy)
    : Media(refCopy)
    , msComments(refCopy.getComments())
    , muiTVSpecialId(refCopy.getTVSpecialId())
    , mPtrTVSeries(refCopy.mPtrTVSeries)
{ }

TVSpecial::~TVSpecial()
{
    mPtrTVSeries.reset(nullptr);
}

QString TVSpecial::getComments() const
{
    return(msComments);
}

TVSeries TVSpecial::getSeries() const
{
    if(mPtrTVSeries.isNull())
        return(TVSeries());
    else
        return(*mPtrTVSeries);
}

unsigned TVSpecial::getTVSpecialId() const
{
    return(muiTVSpecialId);
}

void TVSpecial::setComments(const QString &sComments)
{
    msComments = sComments;

    setChanged(true);
    notifyObservers();
}

void TVSpecial::setSeries(const TVSeries &refSeries)
{
    mPtrTVSeries.reset(const_cast<TVSeries *>(&refSeries));

    setChanged(true);
    notifyObservers();
}

void TVSpecial::setTVSpecialId(const unsigned uiTVSpecialId)
{
    muiTVSpecialId = uiTVSpecialId;

    setChanged(true);
    notifyObservers();
}

TVSpecial &TVSpecial::operator=(const TVSpecial &refCopy)
{
    MediaFile::operator=(refCopy);

    setComments(refCopy.getComments());
    setName(refCopy.getName());
    setTVSpecialId(refCopy.getTVSpecialId());

    if(refCopy.mPtrTVSeries.isNull())
        mPtrTVSeries.reset(nullptr);
    else
        mPtrTVSeries.swap(const_cast<TVSpecial &>(refCopy).mPtrTVSeries);

    return(*this);
}

bool TVSpecial::operator==(const TVSpecial &refOther) const
{
    return  (   MediaFile::operator==(refOther)
            &&  (getComments() == refOther.getComments())
            &&  (getName() == refOther.getName())
            &&  (getSeries() == refOther.getSeries())
            &&  (getTVSpecialId() == refOther.getTVSpecialId()));
}

bool TVSpecial::operator!=(const TVSpecial &refOther) const
{
    return(!operator==(refOther));
}
