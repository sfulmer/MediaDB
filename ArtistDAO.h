#pragma once

#include "Artist.h"

using net::draconia::mediadb::dbo::Artist;
using net::draconia::mediadb::dbo::Media;
using net::draconia::mediadb::dbo::Role;
using net::draconia::mediadb::dbo::RoleType;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                class ArtistDAO
                {
                public:
                    virtual ~ArtistDAO();

                    virtual Artist getById(const unsigned uiArtistId) const = 0;
                    virtual Artist getByNameRoleTypeAndRoleName(const QString &sName, const RoleType &refRoleType, const QString sRoleName) const = 0;
                    virtual QList<Artist> list() const = 0;
                    virtual QList<Artist> listByMedia(const Media &refMedia) const = 0;
                    virtual QList<Artist> listByMediaAndRoleType(const Media &refMedia, const RoleType &refRoleType) const = 0;
                    virtual bool remove(const Artist &refToRemove) const = 0;
                    virtual QList<Artist> listByName(const QString &sName) const = 0;
                    virtual Artist &save(const Artist &refToSave) const = 0;
                };
            }
        }
    }
}
