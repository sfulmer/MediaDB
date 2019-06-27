#pragma once

#include "Artist.h"
#include<QList>
#include<QString>
#include "Single.h"

using net::draconia::mediadb::dbo::Artist;
using net::draconia::mediadb::dbo::Single;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                class SingleDAO
                {
                public:
                    virtual ~SingleDAO();

                    virtual Single getById(const unsigned uiSingleId) const = 0;
                    virtual Single getByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const = 0;
                    virtual QList<Single> list() const = 0;
                    virtual QList<Single> listByArtist(const Artist &refArtist) const = 0;
                    virtual QList<Single> listByName(const QString &sName) const = 0;
                    virtual QList<Single> listByWordInComments(const QString &sWord) const = 0;
                    virtual bool remove(const Single &refToRemove) const = 0;
                    virtual Single &save(const Single &refToSave) const = 0;
                };
            }
        }
    }
}
