#pragma once

#include "Artist.h"
#include "TVEpisode.h"
#include "TVSeason.h"

using net::draconia::mediadb::dbo::Artist;
using net::draconia::mediadb::dbo::TVEpisode;
using net::draconia::mediadb::dbo::TVSeason;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                class TVEpisodeDAO
                {
                public:
                    virtual ~TVEpisodeDAO();

                    virtual TVEpisode getById(const unsigned uiId) const = 0;
                    virtual TVEpisode getBySeasonAndEpisodeNumber(const TVSeason &refSeason, const unsigned uiEpisodeNumber) const = 0;
                    virtual TVEpisode getBySeasonAndName(const TVSeason &refSeason, const QString &sName) const = 0;
                    virtual QList<TVEpisode> list() const = 0;
                    virtual QList<TVEpisode> listByArtist(const Artist &refArtist) const = 0;
                    virtual QList<TVEpisode> listByName(const QString &sName) const = 0;
                    virtual QList<TVEpisode> listByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const = 0;
                    virtual QList<TVEpisode> listBySeason(const TVSeason &refSeason) const = 0;
                    virtual QList<TVEpisode> listBySeasonAndArtist(const TVSeason &refSeason, const Artist &refArtist) const = 0;
                    virtual QList<TVEpisode> listByWordInComments(const QString &sWord) const = 0;
                    virtual bool remove(const TVEpisode &refToRemove) const = 0;
                    virtual TVEpisode &save(const TVEpisode &refToSave) const = 0;
                };
            }
        }
    }
}
