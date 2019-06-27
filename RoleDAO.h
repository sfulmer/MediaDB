#pragma once

#include "Artist.h"
#include "Media.h"
#include<QString>
#include "Role.h"

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
                class RoleDAO
                {
                public:
                    virtual ~RoleDAO();

                    virtual Role getById(const unsigned uiRoleId) const = 0;
                    virtual Role getByNameArtistMediaAndRoleType(const QString &sName, const Artist &refArtist, const Media &refMedia, const RoleType &refRoleType) const = 0;
                    virtual QList<Role> listByArtist(const Artist &refArtist) const = 0;
                    virtual QList<Role> listByArtistAndMedia(const Artist &refArtist, const Media &refMedia) const = 0;
                    virtual QList<Role> listByArtistAndName(const Artist &refArtist, const QString &sName) const = 0;
                    virtual QList<Role> listByMedia(const Media &refMedia) const = 0;
                    virtual QList<Role> listByMediaAndName(const Media &refMedia, const QString &sName) const = 0;
                    virtual QList<Role> listByName(const QString &sName) const = 0;
                    virtual QList<Role> listByRoleType(const RoleType &refRoleType) const = 0;
                    virtual QList<Role> listByNameAndRoleType(const QString &sName, const RoleType &refRoleType) const = 0;
                    virtual bool remove(const Role &refRole) const = 0;
                    virtual Role save(const Role &refToSave) const = 0;
                };
            }
        }
    }
}
