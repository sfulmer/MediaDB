#pragma once

#include "AbstractDAO.h"
#include "ArtistDAO.h"
#include "MediaDAO.h"
#include "RoleDAO.h"
#include "RoleTypeDAO.h"

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                extern template class AbstractDAO<Role>;

                class RoleDAOImpl : public RoleDAO, public AbstractDAO<Role>
                {
                    ArtistDAO &mRefArtistDAO;
                    MediaDAO &mRefMediaDAO;
                    RoleTypeDAO &mRefRoleTypeDAO;
                protected:
                    virtual Role createObjectFromResults(const QSqlRecord &refRecord);
                    ArtistDAO &getArtistDAO() const;
                    MediaDAO &getMediaDAO() const;
                    RoleTypeDAO &getRoleTypeDAO() const;
                    virtual Role &insert(const Role &refToSave) const;
                    virtual bool isTableExists() const;
                    virtual void removeTable();
                    virtual Role &update(const Role &refToSave) const;
                public:
                    RoleDAOImpl(const QSqlDatabase &refDatasource = BeanFactory::getInstance().getDatabase());
                    virtual bool createTable() const;
                    virtual Role getById(const unsigned uiRoleId) const;
                    virtual Role getByNameArtistMediaAndRoleType(const QString &sName, const Artist &refArtist, const Media &refMedia, const RoleType &refRoleType) const;
                    virtual QList<Role> listByArtist(const Artist &refArtist) const;
                    virtual QList<Role> listByArtistAndMedia(const Artist &refArtist, const Media &refMedia) const;
                    virtual QList<Role> listByArtistAndName(const Artist &refArtist, const QString &sName) const;
                    virtual QList<Role> listByMedia(const Media &refMedia) const;
                    virtual QList<Role> listByMediaAndName(const Media &refMedia, const QString &sName) const;
                    virtual QList<Role> listByName(const QString &sName) const;
                    virtual QList<Role> listByNameAndRoleType(const QString &sName, const RoleType &refRoleType) const;
                    virtual QList<Role> listByRoleType(const RoleType &refRoleType) const;
                    virtual bool remove(const Role &refRole) const;
                    virtual Role save(const Role &refToSave) const;
                };
            }
        }
    }
}
