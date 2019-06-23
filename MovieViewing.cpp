#include "Movie.h"
#include "MovieViewing.h"

using namespace net::draconia::mediadb::dbo;

MovieViewing::MovieViewing()
    : mPtrMovie(nullptr), muiMovieViewingId(0)
{ }

MovieViewing::MovieViewing(const unsigned uiMovieViewingId)
    : mPtrMovie(nullptr), muiMovieViewingId(uiMovieViewingId)
{ }

MovieViewing::MovieViewing(const Movie &refMovie)
    : mPtrMovie(const_cast<Movie *>(&refMovie)), muiMovieViewingId(0)
{ }

MovieViewing::MovieViewing(const unsigned uiMovieViewingId, const Movie &refMovie)
    : mPtrMovie(const_cast<Movie *>(&refMovie)), muiMovieViewingId(uiMovieViewingId)
{ }

MovieViewing::MovieViewing(const Movie &refMovie, const QDateTime &dtViewing)
    : mPtrMovie(const_cast<Movie *>(&refMovie)), mDtViewing(dtViewing), muiMovieViewingId(0)
{ }

MovieViewing::MovieViewing(const unsigned uiMovieViewingId, const Movie &refMovie, const QDateTime &dtViewing)
    : mPtrMovie(const_cast<Movie *>(&refMovie)), mDtViewing(dtViewing), muiMovieViewingId(uiMovieViewingId)
{ }

MovieViewing::MovieViewing(const MovieViewing &refCopy)
    : mPtrMovie(refCopy.mPtrMovie), mDtViewing(refCopy.getViewing()), muiMovieViewingId(refCopy.getMovieViewingId())
{ }

MovieViewing::~MovieViewing()
{ }

Movie MovieViewing::getMovie() const
{
    if(!mPtrMovie.isNull())
        return(*mPtrMovie);
    else
        return(Movie());
}

unsigned MovieViewing::getMovieViewingId() const
{
    return(muiMovieViewingId);
}

QDateTime MovieViewing::getViewing() const
{
    return(mDtViewing);
}

void MovieViewing::setMovie(const Movie &refMovie)
{
    mPtrMovie.reset(const_cast<Movie *>(&refMovie));

    setChanged(true);
    notifyObservers();
}

void MovieViewing::setMovieViewingId(const unsigned uiMovieViewingId)
{
    muiMovieViewingId = uiMovieViewingId;

    setChanged(true);
    notifyObservers();
}

void MovieViewing::setViewing(const QDateTime &dtViewing)
{
    mDtViewing = dtViewing;

    setChanged(true);
    notifyObservers();
}

MovieViewing &MovieViewing::operator=(const MovieViewing &refCopy)
{
    setMovie(refCopy.getMovie());
    setMovieViewingId(refCopy.getMovieViewingId());
    setViewing(refCopy.getViewing());

    return(*this);
}

bool MovieViewing::operator==(const MovieViewing &refOther) const
{
    return  (   (getMovie() == refOther.getMovie())
            &&  (getMovieViewingId() == refOther.getMovieViewingId())
            &&  (getViewing() == getViewing()));
}

bool MovieViewing::operator!=(const MovieViewing &refOther) const
{
    return(!operator==(refOther));
}
