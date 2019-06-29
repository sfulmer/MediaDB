#pragma once

#include "Media.h"

using net::draconia::mediadb::dbo::Artist;
using net::draconia::mediadb::dbo::Media;
using net::draconia::mediadb::dbo::RoleType;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                class MediaDAO
                {
                public:
                    virtual ~MediaDAO();

                    virtual Media getById(const unsigned uiMediaId) const = 0;
                    virtual Media getByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const = 0;
                    virtual QList<Media> list() const = 0;
                    virtual QList<Media> listByArtist(const Artist &refArtist) const = 0;
                    virtual QList<Media> listByArtistAndName(const Artist &refArtist, const QString &sName) const = 0;
                    virtual QList<Media> listByArtistNameAndReleaseYear(const Artist &refArtist, const QString &sName, const unsigned uiReleaseYear) const = 0;
                    virtual QList<Media> listByArtistNameReleaseYearAndRoleType(const Artist &refArtist, const QString &sName, const unsigned uiReleaseYear, const RoleType &refRoleType) const = 0;
                    virtual QList<Media> listByArtistNameAndRoleType(const Artist &refArtist, const QString &sName, const RoleType &refRoleType) const = 0;
                    virtual QList<Media> listByArtistAndRoleType(const Artist &refArtist, const RoleType &refRoleType) const = 0;
                    virtual QList<Media> listByName(const QString &sName) const = 0;
                    virtual QList<Media> listByReleaseYear(const unsigned uiReleaseYear) const = 0;
                    virtual bool remove(const Media &refMedia) const = 0;
                    virtual Media &save(const Media &refToSave) const = 0;
                };
            }
        }
    }
}
