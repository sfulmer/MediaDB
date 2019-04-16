#pragma once

#include "DBO.h"
#include<QDate>
#include<QList>
#include<QString>

using namespace net::draconia::dbo;

namespace net
{
    namespace draconia
    {
        namespace dao
        {
            class MovieDAO
            {
            public:
                virtual ~MovieDAO();

                virtual Movie getById(const unsigned uiMovieId) const = 0;
                virtual Movie getByNameAndReleaseDate(const QString &sName, const QDate &dtRelease) const = 0;
                virtual QList<Movie> list() const = 0;
                virtual QList<Movie> listByName(const QString &sName) const = 0;
                virtual QList<Movie> listByReleaseYear(const unsigned uiReleaseYear) const = 0;
                virtual void remove(const Movie &refMovie) const = 0;
                virtual Movie &save(const Movie &refMovie) const = 0;
            };
        }
    }
}
