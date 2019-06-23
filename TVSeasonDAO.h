#pragma once

#include "TVSeries.h"

using net::draconia::mediadb::dbo::Artist;
using net::draconia::mediadb::dbo::TVSeason;
using net::draconia::mediadb::dbo::TVSeries;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                class TVSeasonDAO
                {
                public:
                    virtual ~TVSeasonDAO();

                    virtual TVSeason getById(const unsigned uiTVSeasonId) const = 0;
                    virtual TVSeason getByTVSeriesAndNumber(const TVSeries &refTVSeries, const unsigned uiNumber) const = 0;
                    virtual QList<TVSeason> list() const = 0;
                    virtual QList<TVSeason> listByArtist(const Artist &refArtist) const = 0;
                    virtual QList<TVSeason> listByTVSeries(const TVSeries &refTVSeries) const = 0;
                    virtual QList<TVSeason> listByTVSeriesAndArtist(const TVSeries &refTVSeries, const Artist &refArtist) const = 0;
                    virtual QList<TVSeason> listByTVSeriesAndEpisodeName(const TVSeries &refTVSeries, const QString &sName) const = 0;
                    virtual QList<TVSeason> listByWordInComments(const QString &sWord) const = 0;
                    virtual bool remove(const TVSeason &refToRemove) const = 0;
                    virtual TVSeason &save(const TVSeason &refToSave) const = 0;
                };
            }
        }
    }
}
