#include "TVSeries.h"

using namespace net::draconia::mediadb::dbo;

QList<TVSeason> TVSeries::getSeasonsInternal() const
{
    return(const_cast<QList<TVSeason> &>(mLstSeasons));
}

QList<TVSpecial> TVSeries::getSpecialsInternal() const
{
    return(const_cast<QList<TVSpecial> &>(mLstSpecials));
}

void TVSeries::setSeasons(const QList<TVSeason> &lstSeasons)
{
    getSeasonsInternal().clear();
    getSeasonsInternal().append(lstSeasons);

    setChanged();
    notifyObservers("Seasons");
}

void TVSeries::setSpecials(const QList<TVSpecial> &lstSpecials)
{
    getSpecialsInternal().clear();
    getSpecialsInternal().append(lstSpecials);

    setChanged();
    notifyObservers("Specials");
}

TVSeries::TVSeries()
    : muiTVSeriesId(0)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId)
    : muiTVSeriesId(uiTVSeriesId)
{ }

TVSeries::TVSeries(const QString &sName)
    : muiTVSeriesId(0)
    , msName(sName)
{ }

TVSeries::TVSeries(const QList<TVSeason> &lstSeasons)
    : muiTVSeriesId(0)
    , mLstSeasons(lstSeasons)
{ }

TVSeries::TVSeries(const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(0)
    , mLstSpecials(lstSpecials)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName)
    : muiTVSeriesId(uiTVSeriesId)
    , msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QList<TVSeason> &lstSeasons)
    : muiTVSeriesId(uiTVSeriesId)
    , mLstSeasons(lstSeasons)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(uiTVSeriesId)
    , mLstSpecials(lstSpecials)
{ }

TVSeries::TVSeries(const QString &sName, const QString &sComments)
    : muiTVSeriesId(0)
    , msComments(sComments), msName(sName)
{ }

TVSeries::TVSeries(const QString &sName, const QList<TVSeason> &lstSeasons)
    : muiTVSeriesId(0)
    , mLstSeasons(lstSeasons)
    , msName(sName)
{ }

TVSeries::TVSeries(const QString &sName, const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(0)
    , mLstSpecials(lstSpecials)
    , msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QString &sComments)
    : muiTVSeriesId(uiTVSeriesId)
    , msComments(sComments), msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSeason> &lstSeasons)
    : muiTVSeriesId(uiTVSeriesId)
    , mLstSeasons(lstSeasons)
    , msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(uiTVSeriesId)
    , mLstSpecials(lstSpecials)
    , msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QString &sComments, const QList<TVSeason> &lstSeasons)
    : muiTVSeriesId(uiTVSeriesId)
    , mLstSeasons(lstSeasons)
    , msComments(sComments), msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QString &sComments, const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(uiTVSeriesId)
    , mLstSpecials(lstSpecials)
    , msComments(sComments), msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QString &sComments, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(uiTVSeriesId)
    , mLstSeasons(lstSeasons)
    , mLstSpecials(lstSpecials)
    , msComments(sComments), msName(sName)
{ }

TVSeries::TVSeries(const TVSeries &refCopy)
    : muiTVSeriesId(refCopy.getTVSeriesId())
    , mLstSeasons(refCopy.getSeasons())
    , mLstSpecials(refCopy.getSpecials())
    , msComments(refCopy.getComments())
    , msName(refCopy.getName())
{ }

TVSeries::~TVSeries()
{ }

void TVSeries::addSeason(const TVSeason &refSeason)
{
    getSeasonsInternal().append(refSeason);

    setChanged();
    notifyObservers("Seasons");
}

void TVSeries::addSpecial(const TVSpecial &refSpecial)
{
    getSpecialsInternal().append(refSpecial);

    setChanged();
    notifyObservers("Specials");
}

QString TVSeries::getComments() const
{
    return(msComments);
}

QString TVSeries::getName() const
{
    return(msName);
}

const QList<TVSeason> TVSeries::getSeasons() const
{
    return(getSeasonsInternal());
}

const QList<TVSpecial> TVSeries::getSpecials() const
{
    return(getSpecialsInternal());
}

unsigned TVSeries::getTVSeriesId() const
{
    return(muiTVSeriesId);
}

bool TVSeries::removeSeason(const TVSeason &refSeason)
{
    bool bRetVal = getSeasonsInternal().removeOne(refSeason);

    setChanged();
    notifyObservers("Seasons");

    return(bRetVal);
}

void TVSeries::removeSeason(const unsigned uiIndex)
{
    getSeasonsInternal().removeAt(static_cast<int>(uiIndex));

    setChanged();
    notifyObservers("Seasons");
}

bool TVSeries::removeSpecial(const TVSpecial &refSpecial)
{
    bool bRetVal = getSpecialsInternal().removeOne(refSpecial);

    setChanged();
    notifyObservers("Specials");

    return(bRetVal);
}

void TVSeries::removeSpecial(const unsigned uiIndex)
{
    getSpecialsInternal().removeAt(static_cast<int>(uiIndex));

    setChanged();
    notifyObservers("Specials");
}

void TVSeries::setComments(const QString &sComments)
{
    msComments = sComments;

    setChanged();
    notifyObservers("Comments");
}

void TVSeries::setName(const QString &sName)
{
    msName = sName;

    setChanged();
    notifyObservers("Name");
}

void TVSeries::setTVSeriesId(const unsigned uiTVSeriesId)
{
    muiTVSeriesId = uiTVSeriesId;

    setChanged();
    notifyObservers("TVSeriesId");
}

TVSeries &TVSeries::operator=(const TVSeries &refCopy)
{
    setComments(refCopy.getComments());
    setName(refCopy.getName());
    setSeasons(refCopy.getSeasons());
    setSpecials(refCopy.getSpecials());
    setTVSeriesId(refCopy.getTVSeriesId());

    return(*this);
}

bool TVSeries::operator==(const TVSeries &refOther) const
{
    return  (   (getComments() == refOther.getComments())
            &&  (getName() == refOther.getName())
            &&  (getSeasons() == refOther.getSeasons())
            &&  (getSpecials() == refOther.getSpecials())
            &&  (getTVSeriesId() == refOther.getTVSeriesId()));
}

bool TVSeries::operator!=(const TVSeries &refOther) const
{
    return(!operator==(refOther));
}
