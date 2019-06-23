#include "Movie.h"

using namespace net::draconia::mediadb::dbo;

QList<MovieViewing> &Movie::getViewingsInternal() const
{
    return(const_cast<QList<MovieViewing> &>(mLstViewings));
}

void Movie::setViewings(const QList<MovieViewing> &lstViewings)
{
    getViewingsInternal().clear();
    getViewingsInternal().append(lstViewings);

    setChanged(true);
    notifyObservers();
}

Movie::Movie()
    : Media(), muiMovieId(0)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease), muiMovieId(0)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear), muiMovieId(0)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease), muiMovieId(uiMovieId)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear), muiMovieId(uiMovieId)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, dtRelease), muiMovieId(0), mLstViewings(lstViewings)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear), muiMovieId(0), mLstViewings(lstViewings)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, dtRelease), muiMovieId(uiMovieId), mLstViewings(lstViewings)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear), muiMovieId(uiMovieId), mLstViewings(lstViewings)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath), muiMovieId(0)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), muiMovieId(0)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath), muiMovieId(uiMovieId)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), muiMovieId(uiMovieId)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath), muiMovieId(0), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), muiMovieId(0), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, sFilePath), muiMovieId(0), mLstViewings(lstViewings)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), muiMovieId(0), mLstViewings(lstViewings)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, sFilePath), muiMovieId(0), mLstViewings(lstViewings), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), muiMovieId(0), mLstViewings(lstViewings), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath), muiMovieId(uiMovieId), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), muiMovieId(uiMovieId), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, sFilePath), muiMovieId(uiMovieId), mLstViewings(lstViewings)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), muiMovieId(uiMovieId), mLstViewings(lstViewings)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, sFilePath), muiMovieId(uiMovieId), mLstViewings(lstViewings), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), muiMovieId(uiMovieId), mLstViewings(lstViewings), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists), muiMovieId(0)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), muiMovieId(0)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists), muiMovieId(uiMovieId)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), muiMovieId(uiMovieId)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists), muiMovieId(0), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), muiMovieId(0), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, lstArtists), muiMovieId(0), mLstViewings(lstViewings)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), muiMovieId(0), mLstViewings(lstViewings)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, lstArtists), muiMovieId(0), mLstViewings(lstViewings), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), muiMovieId(0), mLstViewings(lstViewings), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists), muiMovieId(uiMovieId), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), muiMovieId(uiMovieId), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, lstArtists), muiMovieId(uiMovieId), mLstViewings(lstViewings)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), muiMovieId(uiMovieId), mLstViewings(lstViewings)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, lstArtists), muiMovieId(uiMovieId), mLstViewings(lstViewings), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), muiMovieId(uiMovieId), mLstViewings(lstViewings), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), muiMovieId(0)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), muiMovieId(0)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), muiMovieId(uiMovieId)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), muiMovieId(uiMovieId)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), muiMovieId(0), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), muiMovieId(0), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), muiMovieId(0), mLstViewings(lstViewings)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), muiMovieId(0), mLstViewings(lstViewings)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), muiMovieId(uiMovieId), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), muiMovieId(uiMovieId), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), muiMovieId(uiMovieId), mLstViewings(lstViewings)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), muiMovieId(uiMovieId), mLstViewings(lstViewings)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), muiMovieId(uiMovieId), mLstViewings(lstViewings), msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QList<MovieViewing> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), muiMovieId(uiMovieId), mLstViewings(lstViewings), msComments(sComments)
{ }

Movie::Movie(const Movie &refCopy)
    : Media(refCopy), muiMovieId(refCopy.getMovieId()), mLstViewings(refCopy.getViewings()), msComments(refCopy.getComments())
{ }

Movie::~Movie()
{ }

void Movie::addViewing(const MovieViewing &dtViewing)
{
    getViewingsInternal().append(dtViewing);

    setChanged(true);
    notifyObservers();
}

unsigned Movie::getMovieId() const
{
    return(muiMovieId);
}

QString Movie::getComments() const
{
    return(msComments);
}

const QList<MovieViewing> Movie::getViewings() const
{
    return(getViewingsInternal());
}

bool Movie::removeViewing(const MovieViewing &dtViewing)
{
    bool bRetVal = getViewingsInternal().removeOne(dtViewing);

    setChanged(true);
    notifyObservers();

    return(bRetVal);
}

void Movie::removeViewing(const unsigned uiIndex)
{
    getViewingsInternal().removeAt(static_cast<int>(uiIndex));

    setChanged(true);
    notifyObservers();
}

void Movie::setComments(const QString &sComments)
{
    msComments = sComments;

    setChanged(true);
    notifyObservers();
}

void Movie::setMovieId(const unsigned uiMovieId)
{
    muiMovieId = uiMovieId;

    setChanged(true);
    notifyObservers();
}

Movie &Movie::operator=(const Movie &refCopy)
{
    Media::operator=(refCopy);

    setMovieId(refCopy.getMovieId());
    setComments(refCopy.getComments());
    setViewings(refCopy.getViewings());

    return(*this);
}

bool Movie::operator==(const Movie &refOther) const
{
    return  (   (Media::operator==(refOther))
            &&  (getMovieId() == refOther.getMovieId())
            &&  (getComments() == refOther.getComments())
            &&  (getViewings() == refOther.getViewings()));
}

bool Movie::operator!=(const Movie &refOther) const
{
    return(!operator==(refOther));
}
