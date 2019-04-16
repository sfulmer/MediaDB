#pragma once

#include "DBO.h"
#include<QDate>
#include<QList>

using namespace net::draconia::dbo;

namespace net
{
    namespace draconia
    {
        namespace dao
        {
            class TVEpisodeDAO
            {
            public:
                virtual ~TVEpisodeDAO();

                virtual TVEpisode getById(const unsigned uiMovieId) const = 0;
                virtual TVEpisode getBySeasonAndNumber(const TVSeason &refSeason, const unsigned uiNumber) const = 0;
                virtual QList<TVEpisode> list() const = 0;
                virtual QList<TVEpisode> listByName(const QString &sName) const = 0;
                virtual QList<TVEpisode> listByReleaseYear(const unsigned uiReleaseYear) const = 0;
                virtual QList<TVEpisode> listBySeason(const TVSeason &refSeason) const = 0;
                virtual void remove(const TVEpisode &refTVEpisode) const = 0;
                virtual TVEpisode &save(const TVEpisode &refTVEpisode) const = 0;
            };
        }
    }
}
