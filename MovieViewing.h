#pragma once

#include "Observable.h"
#include<QDateTime>
#include<QSharedPointer>

using net::draconia::util::Observable;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dbo
            {
                class Movie;

                class MovieViewing : public Observable
                {
                    QSharedPointer<Movie> mPtrMovie;
                    QDateTime mDtViewing;
                    unsigned muiMovieViewingId;
                public:
                    MovieViewing();
                    MovieViewing(const unsigned uiMovieViewingId);
                    MovieViewing(const Movie &refMovie);
                    MovieViewing(const unsigned uiMovieViewingId, const Movie &refMovie);
                    MovieViewing(const Movie &refMovie, const QDateTime &dtViewing);
                    MovieViewing(const unsigned uiMovieViewingId, const Movie &refMovie, const QDateTime &dtViewing);
                    MovieViewing(const MovieViewing &refCopy);
                    ~MovieViewing();

                    Movie getMovie() const;
                    unsigned getMovieViewingId() const;
                    QDateTime getViewing() const;
                    void setMovie(const Movie &refMovie);
                    void setMovieViewingId(const unsigned uiMovieViewingId);
                    void setViewing(const QDateTime &dtViewing);

                    MovieViewing &operator=(const MovieViewing &refCopy);
                    bool operator==(const MovieViewing &refOther) const;
                    bool operator!=(const MovieViewing &refOther) const;
                };
            }
        }
    }
}
