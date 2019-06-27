#pragma once

#include "AbstractDAO.h"
#include "AlbumDAO.h"
#include "BeanFactory.h"
#include "MediaDAO.h"
#include "RoleDAO.h"
#include "SingleDAO.h"
#include "SongDAO.h"

using net::draconia::mediadb::dbo::Album;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                extern template class AbstractDAO<Album>;

                class AlbumDAOImpl : public AbstractDAO<Album>, public AlbumDAO
                {
                    MediaDAO &mRefMediaDAO;
                    RoleDAO &mRefRoleDAO;
                    SingleDAO &mRefSingleDAO;
                    SongDAO &mRefSongDAO;
                protected:
                    virtual Album createObjectFromResults(const QSqlRecord &refRecord);
                    MediaDAO &getMediaDAO() const;
                    RoleDAO &getRoleDAO() const;
                    SingleDAO &getSingleDAO() const;
                    SongDAO &getSongDAO() const;
                    virtual Album &insert(const Album &refToSave) const;
                    virtual bool isTableExists() const;
                    virtual void removeTable();
                    virtual Album &update(const Album &refToSave) const;
                public:
                    AlbumDAOImpl(const QSqlDatabase &refDatabase = BeanFactory::getInstance().getDatabase());
                    virtual ~AlbumDAOImpl();

                    virtual bool createTable() const;
                    virtual Album getById(const unsigned uiAlbumId) const;
                    virtual Album getByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const;
                    virtual Album getBySong(const Song &refSong) const;
                    virtual QList<Album> list() const;
                    virtual QList<Album> listByArtist(const Artist &refArtist) const;
                    virtual QList<Album> listByName(const QString &sName) const;
                    virtual QList<Album> listByWordInComments(const QString &sWord) const;
                    virtual bool remove(const Album &refToRemove) const;
                    virtual Album &save(const Album &refToSave) const;
                };
            }
        }
    }
}
