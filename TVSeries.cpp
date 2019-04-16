#include "DBO.h"

using namespace net::draconia::dbo;

TVEpisode::TVEpisode(TVSeason &refTVSeason)
    : Media()
    , muiNumber(0), muiTVEpisodeId(0)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease)
    , muiNumber(0), muiTVEpisodeId(0)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear)
    , muiNumber(0), muiTVEpisodeId(0)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiNumber(0), muiTVEpisodeId(0)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiNumber(0), muiTVEpisodeId(0)
    , mRefTVSeason(refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , mRefTVSeason(refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , mRefTVSeason(refTVSeason)
{
   getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , mRefTVSeason(refTVSeason)
{ }

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , mRefTVSeason(refTVSeason)
{
   getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiNumber(0), muiTVEpisodeId(0)
    , msComments(sComments)
    , mRefTVSeason(refTVSeason)
{
   getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiNumber(0), muiTVEpisodeId(0)
    , msComments(sComments)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mRefTVSeason(refTVSeason)
{
   getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mRefTVSeason(refTVSeason)
{
   getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiNumber(0), muiTVEpisodeId(0)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiNumber(0), muiTVEpisodeId(0)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , mRefTVSeason(refTVSeason)
{
   getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , mRefTVSeason(refTVSeason)
{
   getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiNumber(0), muiTVEpisodeId(0)
    , msComments(sComments)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiNumber(0), muiTVEpisodeId(0)
    , msComments(sComments)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiNumber(0), muiTVEpisodeId(0)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiNumber(0), muiTVEpisodeId(0)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiNumber(0), muiTVEpisodeId(0)
    , msComments(sComments)
    , mRefTVSeason(refTVSeason)
{
   getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiNumber(0), muiTVEpisodeId(0)
    , msComments(sComments)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiNumber(0), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiNumber(uiNumber), muiTVEpisodeId(uiTVEpisodeId)
    , msComments(sComments)
    , mRefTVSeason(refTVSeason)
{
    getSeason().addEpisode(*this);
}

TVEpisode::TVEpisode(const TVEpisode &refCopy)
    : Media(refCopy.getMediaId(), refCopy.getName(), refCopy.getReleaseDate(), refCopy.getFilePath(), refCopy.getArtists())
    , muiNumber(refCopy.getNumber()), muiTVEpisodeId(refCopy.getTVEpisodeId())
    , msComments(refCopy.getComments())
    , mRefTVSeason(refCopy.getSeason())
{
   getSeason().addEpisode(*this);
}

TVEpisode::~TVEpisode()
{
    getSeason().removeEpisode(*this);
}

QString &TVEpisode::getComments() const
{
    return(const_cast<QString &>(msComments));
}

unsigned TVEpisode::getNumber() const
{
    return(muiNumber);
}

TVSeason &TVEpisode::getSeason() const
{
    return(mRefTVSeason);
}

unsigned TVEpisode::getTVEpisodeId() const
{
    return(muiTVEpisodeId);
}

void TVEpisode::setComments(const QString &sComments)
{
    msComments = sComments;

    setChanged();
    notifyObservers();
}

void TVEpisode::setNumber(const unsigned uiNumber)
{
    muiNumber = uiNumber;

    setChanged();
    notifyObservers();
}

void TVEpisode::setTVEpisodeId(const unsigned uiTVEpisodeId)
{
    muiTVEpisodeId = uiTVEpisodeId;

    setChanged();
    notifyObservers();
}

TVEpisode &TVEpisode::operator=(const TVEpisode &refOther)
{
    Media::operator=(refOther);

    setComments(refOther.getComments());
    setName(refOther.getName());
    setTVEpisodeId(refOther.getTVEpisodeId());

    setChanged();
    notifyObservers();

    return(*this);
}

void TVSeason::addEpisode(const TVEpisode &refEpisode)
{
    getEpisodesInternal().append(refEpisode);

    setChanged();
    notifyObservers();
}

QList<TVEpisode> &TVSeason::getEpisodesInternal() const
{
    return(const_cast<QList<TVEpisode> &>(mLstEpisodes));
}

void TVSeason::setEpisodes(const QList<TVEpisode> &lstEpisodes)
{
    mLstEpisodes.clear();
    mLstEpisodes.append(lstEpisodes);

    setChanged();
    notifyObservers();
}

TVSeason::TVSeason(TVSeries &refTVSeries)
    : Observable()
    , muiSeasonId(0)
    , muiNumber(0)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSeason(*this);
}

TVSeason::TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId)
    : Observable()
    , muiSeasonId(uiSeasonId)
    , muiNumber(0)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSeason(*this);
}

TVSeason::TVSeason(TVSeries &refTVSeries, const QString &sComments)
    : Observable()
    , muiSeasonId(0)
    , muiNumber(0)
    , msComments(sComments)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSeason(*this);
}

TVSeason::TVSeason(TVSeries &refTVSeries, const QList<TVEpisode> &lstEpisodes)
    : Observable()
    , muiSeasonId(0)
    , muiNumber(0)
    , mRefTVSeries(refTVSeries)
{
    setEpisodes(lstEpisodes);
}

TVSeason::TVSeason(TVSeries &refTVSeries, const QString &sComments, const QList<TVEpisode> &lstEpisodes)
    : Observable()
    , muiSeasonId(0)
    , muiNumber(0)
    , msComments(sComments)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSeason(*this);

    setEpisodes(lstEpisodes);
}

TVSeason::TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const unsigned uiNumber)
    : Observable()
    , muiSeasonId(uiSeasonId)
    , muiNumber(uiNumber)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSeason(*this);
}

TVSeason::TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const QString &sComments)
    : Observable()
    , muiSeasonId(uiSeasonId)
    , muiNumber(0)
    , msComments(sComments)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSeason(*this);
}

TVSeason::TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const QList<TVEpisode> &lstEpisodes)
    : Observable()
    , muiSeasonId(uiSeasonId)
    , muiNumber(0)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSeason(*this);

    setEpisodes(lstEpisodes);
}

TVSeason::TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const unsigned uiNumber, const QString &sComments)
    : Observable()
    , muiSeasonId(uiSeasonId)
    , muiNumber(uiNumber)
    , msComments(sComments)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSeason(*this);
}

TVSeason::TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const unsigned uiNumber, const QList<TVEpisode> &lstEpisodes)
    : Observable()
    , muiSeasonId(uiSeasonId)
    , muiNumber(uiNumber)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSeason(*this);

    setEpisodes(lstEpisodes);
}

TVSeason::TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const unsigned uiNumber, const QString &sComments, const QList<TVEpisode> &lstEpisodes)
    : Observable()
    , muiSeasonId(uiSeasonId)
    , muiNumber(uiNumber)
    , msComments(sComments)
    , mRefTVSeries(refTVSeries)
{
   getSeries().addSeason(*this);

   setEpisodes(lstEpisodes);
}

TVSeason::TVSeason(const TVSeason &refCopy)
    : Observable()
    , muiSeasonId(refCopy.getSeasonId())
    , muiNumber(refCopy.getNumber())
    , msComments(refCopy.getComments())
    , mRefTVSeries(refCopy.getSeries())
{
    getSeries().addSeason(*this);

    setEpisodes(refCopy.getEpisodes());
}

TVSeason::~TVSeason()
{
    getSeries().removeSeason(*this);
}

QString &TVSeason::getComments() const
{
    return(const_cast<QString &>(msComments));
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

TVSeries &TVSeason::getSeries() const
{
    return(mRefTVSeries);
}

bool TVSeason::removeEpisode(const TVEpisode &refEpisode)
{
    bool bReturnValue = getEpisodesInternal().removeOne(refEpisode);

    setChanged();
    notifyObservers();

    return(bReturnValue);
}

void TVSeason::removeEpisode(const unsigned uiIndex)
{
    getEpisodesInternal().removeAt(static_cast<int>(uiIndex));

    setChanged();
    notifyObservers();
}

void TVSeason::setComments(const QString &sComments)
{
    msComments = sComments;

    setChanged();
    notifyObservers();
}

void TVSeason::setNumber(const unsigned uiNUmber)
{
    muiNumber = uiNUmber;

    setChanged();
    notifyObservers();
}

void TVSeason::setSeasonId(const unsigned uiSeasonId)
{
    muiSeasonId = uiSeasonId;

    setChanged();
    notifyObservers();
}

TVSeason &TVSeason::operator=(const TVSeason &refOther)
{
    setSeasonId(refOther.getSeasonId());
    setNumber(refOther.getNumber());
    setComments(refOther.getComments());
    setEpisodes(refOther.getEpisodes());

    setChanged();
    notifyObservers();

    return(*this);
}

bool TVSeason::operator==(const TVSeason &refOther) const
{
    return  (   (getSeries() == refOther.getSeries())
            &&  (getSeasonId() == refOther.getSeasonId())
            &&  (getNumber() == refOther.getNumber())
            &&  (getComments() == refOther.getComments())
            &&  (getEpisodes() == refOther.getEpisodes()));
}

void TVSeries::addSeason(const TVSeason &refSeason)
{
    getSeasonsInternal().append(refSeason);

    setChanged();
    notifyObservers();
}

void TVSeries::addSpecial(const TVSpecial &refSpecial)
{
    getSpecialsInternal().append(refSpecial);

    setChanged();
    notifyObservers();
}

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
    mLstSeasons.clear();
    mLstSeasons.append(lstSeasons);

    setChanged();
    notifyObservers();
}

void TVSeries::setSpecials(const QList<TVSpecial> &lstSpecials)
{
    mLstSpecials.clear();
    mLstSpecials.append(lstSpecials);

    setChanged();
    notifyObservers();
}

TVSeries::TVSeries()
    : Observable()
    , muiTVSeriesId(0)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId)
    : Observable()
    , muiTVSeriesId(uiTVSeriesId)
{ }

TVSeries::TVSeries(const QString &sName)
    : Observable()
    , muiTVSeriesId(0)
    , msName(sName)
{ }

TVSeries::TVSeries(const QList<TVSeason> &lstSeasons)
    : Observable()
    , muiTVSeriesId(0)
{
    setSeasons(lstSeasons);
}

TVSeries::TVSeries(const QList<TVSpecial> &lstSpecials)
    : Observable()
    , muiTVSeriesId(0)
{
    setSpecials(lstSpecials);
}

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName)
    : Observable()
    , muiTVSeriesId(uiTVSeriesId)
    , msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QList<TVSeason> &lstSeasons)
    : Observable()
    , muiTVSeriesId(uiTVSeriesId)
{
    setSeasons(lstSeasons);
}

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QList<TVSpecial> &lstSpecials)
    : Observable()
    , muiTVSeriesId(uiTVSeriesId)
{
    setSpecials(lstSpecials);
}

TVSeries::TVSeries(const QString &sName, const QString &sComments)
    : Observable()
    , muiTVSeriesId(0)
    , msComments(sComments)
    , msName(sName)
{ }

TVSeries::TVSeries(const QString &sName, const QList<TVSeason> &lstSeasons)
    : Observable()
    , muiTVSeriesId(0)
    , msName(sName)
{
    setSeasons(lstSeasons);
}

TVSeries::TVSeries(const QString &sName, const QList<TVSpecial> &lstSpecials)
    : Observable()
    , muiTVSeriesId(0)
    , msName(sName)
{
    setSpecials(lstSpecials);
}

TVSeries::TVSeries(const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials)
    : Observable()
    , muiTVSeriesId(0)
{
    setSeasons(lstSeasons);
    setSpecials(lstSpecials);
}

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QString &sComments)
    : Observable()
    , muiTVSeriesId(uiTVSeriesId)
    , msComments(sComments)
    , msName(sName)
{ }

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSeason> &lstSeasons)
    : Observable()
    , muiTVSeriesId(uiTVSeriesId)
    , msName(sName)
{
    setSeasons(lstSeasons);
}

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSpecial> &lstSpecials)
    : Observable()
    , muiTVSeriesId(uiTVSeriesId)
    , msName(sName)
{
    setSpecials(lstSpecials);
}

TVSeries::TVSeries(const QString &sName, const QString &sComments, const QList<TVSeason> &lstSeasons)
    : Observable()
    , muiTVSeriesId(0)
    , msComments(sComments)
    , msName(sName)
{
    setSeasons(lstSeasons);
}

TVSeries::TVSeries(const QString &sName, const QString &sComments, const QList<TVSpecial> &lstSpecials)
    : Observable()
    , muiTVSeriesId(0)
    , msComments(sComments)
    , msName(sName)
{
    setSpecials(lstSpecials);
}

TVSeries::TVSeries(const QString &sName, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials)
    : Observable()
    , muiTVSeriesId(0)
    , msName(sName)
{
    setSeasons(lstSeasons);
    setSpecials(lstSpecials);
}

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials)
    : Observable()
    , muiTVSeriesId(uiTVSeriesId)
    , msName(sName)
{
    setSeasons(lstSeasons);
    setSpecials(lstSpecials);
}

TVSeries::TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QString &sComments, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials)
    : Observable()
    , muiTVSeriesId(uiTVSeriesId)
    , msComments(sComments)
    , msName(sName)
{
    setSeasons(lstSeasons);
    setSpecials(lstSpecials);
}

TVSeries::TVSeries(const TVSeries &refCopy)
    : Observable()
    , muiTVSeriesId(refCopy.getTVSeriesId())
    , msComments(refCopy.getComments())
    , msName(refCopy.getName())
{
    setSeasons(refCopy.getSeasons());
    setSpecials(refCopy.getSpecials());
}

TVSeries::~TVSeries()
{ }

QString &TVSeries::getComments() const
{
    return(const_cast<QString &>(msComments));
}

QString &TVSeries::getName() const
{
    return(const_cast<QString &>(msName));
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
    bool bReturnValue = getSeasonsInternal().removeOne(refSeason);

    setChanged();
    notifyObservers();

    return(bReturnValue);
}

void TVSeries::removeSeason(const unsigned uiIndex)
{
    getSeasonsInternal().removeAt(static_cast<int>(uiIndex));

    setChanged();
    notifyObservers();
}

bool TVSeries::removeSpecial(const TVSpecial &refSpecial)
{
    bool bReturnValue = getSpecialsInternal().removeOne(refSpecial);

    setChanged();
    notifyObservers();

    return(bReturnValue);
}

void TVSeries::removeSpecial(const unsigned uiIndex)
{
    getSpecialsInternal().removeAt(static_cast<int>(uiIndex));

    setChanged();
    notifyObservers();
}

void TVSeries::setComments(const QString &sComments)
{
    msComments = sComments;

    setChanged();
    notifyObservers();
}

void TVSeries::setName(const QString &sName)
{
    msName = sName;

    setChanged();
    notifyObservers();
}

void TVSeries::setTVSeriesId(const unsigned uiTVSeriesId)
{
    muiTVSeriesId = uiTVSeriesId;

    setChanged();
    notifyObservers();
}

bool TVSeries::operator==(const TVSeries &refOther) const
{
    return  (   (getTVSeriesId() == refOther.getTVSeriesId())
            &&  (getComments() == refOther.getComments())
            &&  (getName() == refOther.getName())
            &&  (getSeasons() == refOther.getSeasons())
            &&  (getSpecials() == refOther.getSpecials()));
}

TVSpecial::TVSpecial(TVSeries &refTVSeries)
    : Media()
    , muiTVSpecialId(0)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease)
    , muiTVSpecialId(0)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYeasr)
    : Media(uiMediaId, sName, uiReleaseYeasr)
    , muiTVSpecialId(0)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease)
    , muiTVSpecialId(uiTVSpecialId)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear)
    , muiTVSpecialId(uiTVSpecialId)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiTVSpecialId(0)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiTVSpecialId(0)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiTVSpecialId(uiTVSpecialId)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiTVSpecialId(uiTVSpecialId)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiTVSpecialId(0)
    , msComments(sComments)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiTVSpecialId(0)
    , msComments(sComments)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiTVSpecialId(uiTVSpecialId)
    , msComments(sComments)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiTVSpecialId(uiTVSpecialId)
    , msComments(sComments)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiTVSpecialId(0)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiTVSpecialId(0)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiTVSpecialId(uiTVSpecialId)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiTVSpecialId(uiTVSpecialId)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiTVSpecialId(0)
    , msComments(sComments)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiTVSpecialId(0)
    , msComments(sComments)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiTVSpecialId(uiTVSpecialId)
    , msComments(sComments)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiTVSpecialId(uiTVSpecialId)
    , msComments(sComments)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiTVSpecialId(0)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiTVSpecialId(0)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiTVSpecialId(uiTVSpecialId)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiTVSpecialId(uiTVSpecialId)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiTVSpecialId(0)
    , msComments(sComments)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiTVSpecialId(0)
    , msComments(sComments)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiTVSpecialId(uiTVSpecialId)
    , msComments(sComments)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiTVSpecialId(uiTVSpecialId)
    , msComments(sComments)
    , mRefTVSeries(refTVSeries)
{
    getSeries().addSpecial(*this);
}

TVSpecial::TVSpecial(const TVSpecial &refCopy)
    : Media(refCopy.getMediaId(), refCopy.getName(), refCopy.getReleaseDate(), refCopy.getFilePath(), refCopy.getArtists())
    , muiTVSpecialId(refCopy.getTVSpecialId())
    , msComments(refCopy.getComments())
    , mRefTVSeries(refCopy.getSeries())
{
    getSeries().addSpecial(*this);
}

TVSpecial::~TVSpecial()
{
    getSeries().removeSpecial(*this);
}

QString &TVSpecial::getComments() const
{
    return(const_cast<QString &>(msComments));
}

TVSeries &TVSpecial::getSeries() const
{
    return(mRefTVSeries);
}

unsigned TVSpecial::getTVSpecialId() const
{
    return(muiTVSpecialId);
}

void TVSpecial::setComments(const QString &sComments)
{
    msComments = sComments;

    setChanged();
    notifyObservers();
}

void TVSpecial::setTVSpecialId(const unsigned uiTVSpecialId)
{
    muiTVSpecialId = uiTVSpecialId;

    setChanged();
    notifyObservers();
}

TVSpecial &TVSpecial::operator=(const TVSpecial &refOther)
{
    Media::operator=(refOther);

    setTVSpecialId(refOther.getTVSpecialId());
    setComments(refOther.getComments());

    setChanged();
    notifyObservers();

    return(*this);
}
