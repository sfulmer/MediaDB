#pragma once

#include "TVSpecial.h"

using net::draconia::mediadb::dbo::Artist;
using net::draconia::mediadb::dbo::TVSeries;
using net::draconia::mediadb::dbo::TVSpecial;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                class TVSpecialDAO
                {
                public:
                    virtual ~TVSpecialDAO();

                    virtual TVSpecial getById(const unsigned uiId) const = 0;
                    virtual TVSpecial getByNameAndreleaseYear(const QString &sName, const unsigned uiReleaseYear) const = 0;
                    virtual QList<TVSpecial> list() const = 0;
                    virtual QList<TVSpecial> listByArtist(const Artist &refArtist) const = 0;
                    virtual QList<TVSpecial> listByArtistAndSeries(const Artist &refArtist, const TVSeries &refTVSeries) const = 0;
                    virtual QList<TVSpecial> listByName(const QString &sName) const = 0;
                    virtual QList<TVSpecial> listByTVSeries(const TVSeries &refTVSeries) const = 0;
                    virtual QList<TVSpecial> listByWordInComment(const QString &sWord) const = 0;
                    virtual bool remove(const TVSpecial &refToRemove) const = 0;
                    virtual TVSpecial &save(const TVSpecial &refToSave) const = 0;
                };
            }
        }
    }
}
