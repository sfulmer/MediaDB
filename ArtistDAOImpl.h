#pragma once

#include "AbstractDAO.h"
#include "ArtistDAO.h"
#include "RoleDAO.h"

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
                extern template class AbstractDAO<Artist>;

                class ArtistDAOImpl : public ArtistDAO, public AbstractDAO<Artist>
                {
                    RoleDAO &mRefRoleDAO;
                protected:
                    virtual Artist createObjectFromResults(const QSqlRecord &refRecord);
                    RoleDAO &getRoleDAO() const;
                    virtual Artist &insert(const Artist &refToSave) const;
                    virtual bool isTableExists() const;
                    virtual void removeTable();
                    virtual Artist &update(const Artist &refToSave) const;
                public:
                    ArtistDAOImpl(const QSqlDatabase &refDatasource = BeanFactory::getInstance().getDatabase());
                    virtual ~ArtistDAOImpl();

                    virtual bool createTable() const;
                    virtual Artist getById(const unsigned uiArtistId) const;
                    virtual Artist getByNameRoleTypeAndRoleName(const QString &sName, const RoleType &refRoleType, const QString sRoleName) const;
                    virtual QList<Artist> list() const;
                    virtual QList<Artist> listByMedia(const Media &refMedia) const;
                    virtual QList<Artist> listByMediaAndRoleType(const Media &refMedia, const RoleType &refRoleType) const;
                    virtual QList<Artist> listByName(const QString &sName) const;
                    virtual bool remove(const Artist &refToRemove) const;
                    virtual Artist &save(const Artist &refToSave) const;
                };
            }
        }
    }
}
