#include "TVSeason.h"
#include "TVSeries.h"

using namespace net::draconia::mediadb::dbo;

QList<TVEpisode> &TVSeason::getEpisodesInternal() const
{
    return(const_cast<QList<TVEpisode> &>(mLstEpisodes));
}

void TVSeason::setEpisodes(const QList<TVEpisode> &lstEpisodes)
{
    getEpisodesInternal().clear();
    getEpisodesInternal().append(lstEpisodes);

    setChanged(true);
    notifyObservers();
}

TVSeason::TVSeason()
    : muiSeasonId(0), muiNumber(0), mPtrTVSeries(nullptr)
{ }

TVSeason::TVSeason(TVSeries &refTVSeries)
    : muiSeasonId(0), muiNumber(0), mPtrTVSeries(&refTVSeries)
{ }

TVSeason::TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId)
    : muiSeasonId(uiSeasonId), muiNumber(0), mPtrTVSeries(&refTVSeries)
{ }

TVSeason::TVSeason(TVSeries &refTVSeries, const QString &sComments)
    : muiSeasonId(0), muiNumber(0), msComments(sComments), mPtrTVSeries(&refTVSeries)
{ }

TVSeason::TVSeason(TVSeries &refTVSeries, const QList<TVEpisode> &lstEpisodes)
    : muiSeasonId(0), muiNumber(0), mLstEpisodes(lstEpisodes), mPtrTVSeries(&refTVSeries)
{ }

TVSeason::TVSeason(TVSeries &refTVSeries, const QString &sComments, const QList<TVEpisode> &lstEpisodes)
    : muiSeasonId(0), muiNumber(0), mLstEpisodes(lstEpisodes), msComments(sComments), mPtrTVSeries(&refTVSeries)
{ }

TVSeason::TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const unsigned uiNumber)
    : muiSeasonId(uiSeasonId), muiNumber(uiNumber), mPtrTVSeries(&refTVSeries)
{ }

TVSeason::TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const QString &sComments)
    : muiSeasonId(uiSeasonId), muiNumber(0), msComments(sComments), mPtrTVSeries(&refTVSeries)
{ }

TVSeason::TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const QList<TVEpisode> &lstEpisodes)
    : muiSeasonId(uiSeasonId), muiNumber(0), mLstEpisodes(lstEpisodes), mPtrTVSeries(&refTVSeries)
{ }

TVSeason::TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const unsigned uiNumber, const QString &sComments)
    : muiSeasonId(uiSeasonId), muiNumber(uiNumber), msComments(sComments), mPtrTVSeries(&refTVSeries)
{ }

TVSeason::TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const unsigned uiNumber, const QList<TVEpisode> &lstEpisodes)
    : muiSeasonId(uiSeasonId), muiNumber(uiNumber), mLstEpisodes(lstEpisodes), mPtrTVSeries(&refTVSeries)
{ }

TVSeason::TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const unsigned uiNumber, const QString &sComments, const QList<TVEpisode> &lstEpisodes)
    : muiSeasonId(uiSeasonId), muiNumber(uiNumber), mLstEpisodes(lstEpisodes), msComments(sComments), mPtrTVSeries(&refTVSeries)
{ }

TVSeason::TVSeason(const TVSeason &refCopy)
    : muiSeasonId(refCopy.getSeasonId()), muiNumber(refCopy.getNumber()), mLstEpisodes(refCopy.getEpisodes()), msComments(refCopy.getComments()), mPtrTVSeries(refCopy.mPtrTVSeries)
{ }

TVSeason::~TVSeason()
{
    mPtrTVSeries.reset(nullptr);
}

void TVSeason::addEpisode(const TVEpisode &refEpisode)
{
    getEpisodesInternal().append(refEpisode);

    setChanged(true);
    notifyObservers();
}

QString TVSeason::getComments() const
{
    return(msComments);
}

const QList<TVEpisode> TVSeason::getEpisodes() const
{
    return(getEpisodesInternal());
}

unsigned TVSeason::getNumber() const
{
    return(muiNumber);
}

unsigned TVSeason::getSeasonId() const
{
    return(muiSeasonId);
}

TVSeries TVSeason::getSeries() const
{
    if(mPtrTVSeries.isNull())
        return(TVSeries());
    else
        return(*mPtrTVSeries);
}

bool TVSeason::removeEpisode(const TVEpisode &refEpisode)
{
    bool bRetVal = getEpisodesInternal().removeOne(refEpisode);

    setChanged(true);
    notifyObservers();

    return(bRetVal);
}

void TVSeason::removeEpisode(const unsigned uiIndex)
{
    getEpisodesInternal().removeAt(static_cast<int>(uiIndex));

    setChanged(true);
    notifyObservers();
}

void TVSeason::setComments(const QString &sComments)
{
    msComments = sComments;

    setChanged(true);
    notifyObservers();
}

void TVSeason::setNumber(const unsigned uiNUmber)
{
    muiNumber = uiNUmber;

    setChanged(true);
    notifyObservers();
}

void TVSeason::setSeasonId(const unsigned uiSeasonId)
{
    muiSeasonId = uiSeasonId;

    setChanged(true);
    notifyObservers();
}

void TVSeason::setSeries(const TVSeries &refSeries)
{
    mPtrTVSeries.reset(const_cast<TVSeries *>(&refSeries));
}

TVSeason &TVSeason::operator=(const TVSeason &refCopy)
{
    Observable::operator=(refCopy);
    setComments(refCopy.getComments());
    setEpisodes(refCopy.getEpisodes());
    setNumber(refCopy.getNumber());
    setSeasonId(refCopy.getSeasonId());

    if(refCopy.getSeries() != TVSeries())
        setSeries(refCopy.getSeries());

    return(*this);
}

bool TVSeason::operator==(const TVSeason &refOther) const
{
    return  (   (getComments() == refOther.getComments())
            &&  (getEpisodes() == refOther.getEpisodes())
            &&  (getNumber() == refOther.getNumber())
            &&  (getSeasonId() == refOther.getSeasonId())
            &&  (getSeries() == refOther.getSeries()));
}


bool TVSeason::operator!=(const TVSeason &refOther) const
{
    return(!operator==(refOther));
}
