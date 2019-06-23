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

    setChanged(true);
    notifyObservers();
}

void TVSeries::setSpecials(const QList<TVSpecial> &lstSpecials)
{
    getSpecialsInternal().clear();
    getSpecialsInternal().append(lstSpecials);

    setChanged(true);
    notifyObservers();
}

TVSeries::TVSeries()
    : muiTVSeriesId(0)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId)
    : muiTVSeriesId(uiTVSeriesId)
{ }

TVSeries::TVSeries(const QString &sName)
    : muiTVSeriesId(0), msName(sName)
{ }

TVSeries::TVSeries(const QDate &dtRelease)
    : muiTVSeriesId(0), mDtReleaseDate(dtRelease)
{ }

TVSeries::TVSeries(const QList<TVSeason> &lstSeasons)
    : muiTVSeriesId(0), mLstSeasons(lstSeasons)
{ }

TVSeries::TVSeries(const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(0), mLstSpecials(lstSpecials)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName)
    : muiTVSeriesId(uiTVSeriesId), msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QDate &dtRelease)
    : muiTVSeriesId(uiTVSeriesId), mDtReleaseDate(dtRelease)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const unsigned uiReleaseYear)
    : muiTVSeriesId(uiTVSeriesId), mDtReleaseDate(QDate(static_cast<int>(uiReleaseYear), 1, 1))
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QList<TVSeason> &lstSeasons)
    : muiTVSeriesId(uiTVSeriesId), mLstSeasons(lstSeasons)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(uiTVSeriesId), mLstSpecials(lstSpecials)
{ }

TVSeries::TVSeries(const QString &sName, const QString &sComments)
    : muiTVSeriesId(0), msComments(sComments), msName(sName)
{ }

TVSeries::TVSeries(const QString &sName, const QDate &dtRelease)
    : muiTVSeriesId(0), mDtReleaseDate(dtRelease), msName(sName)
{ }

TVSeries::TVSeries(const QString &sName, const unsigned uiReleaseYear)
    : muiTVSeriesId(0), mDtReleaseDate(QDate(static_cast<int>(uiReleaseYear), 1, 1)), msName(sName)
{ }

TVSeries::TVSeries(const QString &sName, const QList<TVSeason> &lstSeasons)
    : muiTVSeriesId(0), mLstSeasons(lstSeasons), msName(sName)
{ }

TVSeries::TVSeries(const QString &sName, const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(0), mLstSpecials(lstSpecials), msName(sName)
{ }

TVSeries::TVSeries(const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(0), mLstSeasons(lstSeasons), mLstSpecials(lstSpecials)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QString &sComments)
    : muiTVSeriesId(uiTVSeriesId), msComments(sComments), msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QDate &dtRelease)
    : muiTVSeriesId(uiTVSeriesId), mDtReleaseDate(dtRelease), msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const unsigned uiReleaseYear)
    : muiTVSeriesId(uiTVSeriesId), mDtReleaseDate(QDate(static_cast<int>(uiReleaseYear), 1, 1)), msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSeason> &lstSeasons)
    : muiTVSeriesId(uiTVSeriesId), mLstSeasons(lstSeasons), msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSpecial> &lstSpecials)
   : muiTVSeriesId(uiTVSeriesId), mLstSpecials(lstSpecials), msName(sName)
{ }

TVSeries::TVSeries(const QString &sName, const QString &sComments, const QList<TVSeason> &lstSeasons)
    : muiTVSeriesId(0), mLstSeasons(lstSeasons), msComments(sComments), msName(sName)
{ }

TVSeries::TVSeries(const QString &sName, const QDate &dtRelease, const QList<TVSeason> &lstSeasons)
    : muiTVSeriesId(0), mDtReleaseDate(dtRelease), mLstSeasons(lstSeasons), msName(sName)
{ }

TVSeries::TVSeries(const QString &sName, const unsigned uiReleaseYear, const QList<TVSeason> &lstSeasons)
    : muiTVSeriesId(0), mDtReleaseDate(QDate(static_cast<int>(uiReleaseYear), 1, 1)), mLstSeasons(lstSeasons), msName(sName)
{ }

TVSeries::TVSeries(const QString &sName, const QString &sComments, const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(0), mLstSpecials(lstSpecials), msComments(sComments), msName(sName)
{ }

TVSeries::TVSeries(const QString &sName, const QDate &dtRelease, const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(0), mDtReleaseDate(dtRelease), mLstSpecials(lstSpecials), msName(sName)
{ }

TVSeries::TVSeries(const QString &sName, const unsigned uiReleaseYear, const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(0), mDtReleaseDate(QDate(static_cast<int>(uiReleaseYear), 1, 1)), mLstSpecials(lstSpecials), msName(sName)
{ }

TVSeries::TVSeries(const QString &sName, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(0), mLstSeasons(lstSeasons), mLstSpecials(lstSpecials), msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(uiTVSeriesId), mLstSeasons(lstSeasons), mLstSpecials(lstSpecials), msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QString &sComments, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(uiTVSeriesId), mLstSeasons(lstSeasons), mLstSpecials(lstSpecials), msComments(sComments), msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QDate &dtRelease, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(uiTVSeriesId), mDtReleaseDate(dtRelease), mLstSeasons(lstSeasons), mLstSpecials(lstSpecials), msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const unsigned uiReleaseYear, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(uiTVSeriesId), mDtReleaseDate(QDate(static_cast<int>(uiReleaseYear), 1, 1)), mLstSeasons(lstSeasons), mLstSpecials(lstSpecials), msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QDate &dtRelease, const QString &sComments)
    : muiTVSeriesId(uiTVSeriesId), mDtReleaseDate(dtRelease), msComments(sComments), msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const unsigned uiReleaseYear, const QString &sComments)
    : muiTVSeriesId(uiTVSeriesId), mDtReleaseDate(QDate(static_cast<int>(uiReleaseYear), 1, 1)), msComments(sComments), msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QDate &dtRelease, const QString &sComments, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(uiTVSeriesId), mDtReleaseDate(dtRelease), mLstSeasons(lstSeasons), mLstSpecials(lstSpecials), msComments(sComments), msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const unsigned uiReleaseYear, const QString &sComments, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials)
    : muiTVSeriesId(uiTVSeriesId), mDtReleaseDate(QDate(static_cast<int>(uiReleaseYear), 1, 1)), mLstSeasons(lstSeasons), mLstSpecials(lstSpecials), msComments(sComments), msName(sName)
{ }

TVSeries::TVSeries(const TVSeries &refCopy)
    : muiTVSeriesId(refCopy.getTVSeriesId()), mDtReleaseDate(refCopy.getReleaseDate())
    , mLstSeasons(refCopy.getSeasons()), mLstSpecials(refCopy.getSpecials())
    , msComments(refCopy.getComments()), msName(refCopy.getName())
{ }

TVSeries::~TVSeries()
{ }

void TVSeries::addSeason(const TVSeason &refSeason)
{
    getSeasonsInternal().append(refSeason);

    setChanged(true);
    notifyObservers();
}

void TVSeries::addSpecial(const TVSpecial &refSpecial)
{
    getSpecialsInternal().append(refSpecial);

    setChanged(true);
    notifyObservers();
}

QString TVSeries::getComments() const
{
    return(msComments);
}

QString TVSeries::getName() const
{
    return(msName);
}

QDate TVSeries::getReleaseDate() const
{
    return(mDtReleaseDate);
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

    setChanged(true);
    notifyObservers();

    return(bRetVal);
}

void TVSeries::removeSeason(const unsigned uiIndex)
{
    getSeasonsInternal().removeAt(static_cast<int>(uiIndex));

    setChanged(true);
    notifyObservers();
}

bool TVSeries::removeSpecial(const TVSpecial &refSpecial)
{
    bool bRetVal = getSpecialsInternal().removeOne(refSpecial);

    setChanged(true);
    notifyObservers();

    return(bRetVal);
}

void TVSeries::removeSpecial(const unsigned uiIndex)
{
    getSpecialsInternal().removeAt(static_cast<int>(uiIndex));

    setChanged(true);
    notifyObservers();
}

void TVSeries::setComments(const QString &sComments)
{
    msComments = sComments;

    setChanged(true);
    notifyObservers();
}

void TVSeries::setName(const QString &sName)
{
    msName = sName;

    setChanged(true);
    notifyObservers();
}

void TVSeries::setReleaseDate(const QDate &dtRelease)
{
    mDtReleaseDate = dtRelease;

    setChanged(true);
    notifyObservers();
}

void TVSeries::setReleaseYear(const unsigned uiReleaseYear)
{
    setReleaseDate(QDate(static_cast<int>(uiReleaseYear), 1, 1));
}

void TVSeries::setTVSeriesId(const unsigned uiTVSeriesId)
{
    muiTVSeriesId = uiTVSeriesId;

    setChanged(true);
    notifyObservers();
}

TVSeries &TVSeries::operator=(const TVSeries &refCopy)
{
    Observable::operator=(refCopy);

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
