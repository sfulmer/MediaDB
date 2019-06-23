#include "TVSeries.h"
#include "TVSpecial.h"

using namespace net::draconia::mediadb::dbo;

TVSpecial::TVSpecial()
    : Media(), muiTVSpecialId(0), mPtrTVSeries(nullptr)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries)
    : Media(), muiTVSpecialId(0), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease), muiTVSpecialId(0), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear), muiTVSpecialId(0), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease), muiTVSpecialId(uiTVSpecialId), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear), muiTVSpecialId(uiTVSpecialId), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath), muiTVSpecialId(0), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), muiTVSpecialId(0), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath), muiTVSpecialId(uiTVSpecialId), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), muiTVSpecialId(uiTVSpecialId), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath), msComments(sComments), muiTVSpecialId(0), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), msComments(sComments), muiTVSpecialId(0), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath), msComments(sComments), muiTVSpecialId(uiTVSpecialId), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), msComments(sComments), muiTVSpecialId(uiTVSpecialId), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists), muiTVSpecialId(0), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), muiTVSpecialId(0), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists), muiTVSpecialId(uiTVSpecialId), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), muiTVSpecialId(uiTVSpecialId), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists), msComments(sComments), muiTVSpecialId(0), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), msComments(sComments), muiTVSpecialId(0), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists), msComments(sComments), muiTVSpecialId(uiTVSpecialId), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), msComments(sComments), muiTVSpecialId(uiTVSpecialId), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), muiTVSpecialId(0), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), muiTVSpecialId(0), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), muiTVSpecialId(uiTVSpecialId), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), muiTVSpecialId(uiTVSpecialId), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), msComments(sComments), muiTVSpecialId(0), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), msComments(sComments), muiTVSpecialId(0), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), msComments(sComments), muiTVSpecialId(uiTVSpecialId), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), msComments(sComments), muiTVSpecialId(uiTVSpecialId), mPtrTVSeries(&refTVSeries)
{ }

TVSpecial::TVSpecial(const TVSpecial &refCopy)
    : Media(refCopy), msComments(refCopy.getComments()), muiTVSpecialId(refCopy.getTVSpecialId()), mPtrTVSeries(refCopy.mPtrTVSeries)
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
    Media::operator=(refCopy);

    setComments(refCopy.getComments());
    setTVSpecialId(refCopy.getTVSpecialId());

    if(refCopy.mPtrTVSeries.isNull())
        mPtrTVSeries.reset(nullptr);
    else
        mPtrTVSeries.swap(const_cast<TVSpecial &>(refCopy).mPtrTVSeries);

    return(*this);
}

bool TVSpecial::operator==(const TVSpecial &refOther) const
{
    return  (   Media::operator==(refOther)
            &&  (getComments() == refOther.getComments())
            &&  (getSeries() == refOther.getSeries())
            &&  (getTVSpecialId() == refOther.getTVSpecialId()));
}

bool TVSpecial::operator!=(const TVSpecial &refOther) const
{
    return(!operator==(refOther));
}
