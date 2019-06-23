#pragma once

#include "Movie.h"
#include "MovieViewing.h"

using net::draconia::mediadb::dbo::Movie;
using net::draconia::mediadb::dbo::MovieViewing;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                class MovieViewingDAO
                {
                public:
                    virtual ~MovieViewingDAO();

                    virtual QList<MovieViewing> listByMovie(const Movie &refMovie) const = 0;
                    virtual bool remove(const MovieViewing &refViewing) const = 0;
                    virtual MovieViewing &save(const MovieViewing &refToSave) const = 0;
                };
            }
        }
    }
}
