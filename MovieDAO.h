#pragma once

#include "Movie.h"

using net::draconia::mediadb::dbo::Artist;
using net::draconia::mediadb::dbo::Movie;
using net::draconia::mediadb::dbo::RoleType;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                class MovieDAO
                {
                public:
                    virtual ~MovieDAO() = 0;

                    virtual Movie getById(const unsigned uiMovieId) const = 0;
                    virtual Movie getByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const = 0;
                    virtual QList<Movie> list() const = 0;
                    virtual QList<Movie> listByArtist(const Artist &refArtist) const = 0;
                    virtual QList<Movie> listByArtistAndName(const Artist &refArtist, const QString &sName) const = 0;
                    virtual QList<Movie> listByArtistNameAndReleaseYear(const Artist &refArtist, const QString &sName, const unsigned uiReleaseYear) const = 0;
                    virtual QList<Movie> listByArtistNameReleaseYearAndRoleType(const Artist &refArtist, const QString &sName, const unsigned uiReleaseYear, const RoleType &refRoleType) const = 0;
                    virtual QList<Movie> listByArtistNameAndRoleType(const Artist &refArtist, const QString &sName, const RoleType &refRoleType) const = 0;
                    virtual QList<Movie> listByArtistAndRoleType(const Artist &refArtist, const RoleType &refRoleType) const = 0;
                    virtual QList<Movie> listByName(const QString &sName) const = 0;
                    virtual QList<Movie> listByReleaseYear(const unsigned uiReleaseYear) const = 0;
                    virtual QList<Movie> listByWordInComments(const QString &sWord) const = 0;
                    virtual bool remove(const Movie &refToRemove) const = 0;
                    virtual Movie &save(const Movie &refToSave) const = 0;
                };
            }
        }
    }
}
