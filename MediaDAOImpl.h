#pragma once

#include "AbstractDAO.h"
#include "ArtistDAO.h"
#include "MediaDAO.h"
#include<QtSql/QSqlDatabase>
#include "RoleDAO.h"

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                extern template class AbstractDAO<Media>;

                class MediaDAOImpl : public AbstractDAO<Media>, public MediaDAO
                {
                    ArtistDAO &mRefArtistDAO;
                    RoleDAO &mRefRoleDAO;
                protected:
                    virtual Media createObjectFromResults(const QSqlRecord &refRecord);
                    ArtistDAO &getArtistDAO() const;
                    RoleDAO &getRoleDAO() const;
                    virtual Media &insert(const Media &refToSave) const;
                    virtual bool isTableExists() const;
                    virtual void removeTable();
                    virtual Media &update(const Media &refToSave) const;
                public:
                    MediaDAOImpl(const QSqlDatabase &refDatasource = BeanFactory::getInstance().getDatabase());
                    virtual ~MediaDAOImpl() { }

                    virtual bool createTable() const;
                    virtual Media getById(const unsigned uiMediaId) const;
                    virtual Media getByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const;
                    virtual QList<Media> list() const;
                    virtual QList<Media> listByArtist(const Artist &refArtist) const;
                    virtual QList<Media> listByArtistAndName(const Artist &refArtist, const QString &sName) const;
                    virtual QList<Media> listByArtistNameAndReleaseYear(const Artist &refArtist, const QString &sName, const unsigned uiReleaseYear) const;
                    virtual QList<Media> listByArtistNameReleaseYearAndRoleType(const Artist &refArtist, const QString &sName, const unsigned uiReleaseYear, const RoleType &refRoleType) const;
                    virtual QList<Media> listByArtistNameAndRoleType(const Artist &refArtist, const QString &sName, const RoleType &refRoleType) const;
                    virtual QList<Media> listByArtistAndRoleType(const Artist &refArtist, const RoleType &refRoleType) const;
                    virtual QList<Media> listByName(const QString &sName) const;
                    virtual QList<Media> listByReleaseYear(const unsigned uiReleaseYear) const;
                    virtual bool remove(const Media &refMedia) const;
                    virtual Media &save(const Media &refToSave) const;
                };
            }
        }
    }
}
