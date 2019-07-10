#pragma once

#include "TVSeries.h"

using net::draconia::mediadb::dbo::TVSeries;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                class TVSeriesDAO
                {
                public:
                    virtual ~TVSeriesDAO();

                    virtual TVSeries getById(const unsigned uiId) const = 0;
                    virtual QList<TVSeries> list() const = 0;
                    virtual QList<TVSeries> listByName(const QString &sName) const = 0;
                    virtual QList<TVSeries> listByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const = 0;
                    virtual QList<TVSeries> listByReleaseYear(const unsigned uiReleaseYear) const = 0;
                    virtual QList<TVSeries> listByWordInComment(const QString &sWord) const = 0;
                    virtual bool remove(const TVSeries &refToRemove) const = 0;
                    virtual TVSeries &save(const TVSeries &refToSave) const = 0;
                };
            }
        }
    }
}
