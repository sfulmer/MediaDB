#pragma once

#include "AbstractDAO.h"
#include "AlbumDAO.h"
#include "BeanFactory.h"
#include "MediaDAO.h"
#include<QList>
#include<QString>
#include "RoleDAO.h"
#include "SingleDAO.h"
#include "SongDAO.h"

using net::draconia::mediadb::BeanFactory;

using net::draconia::mediadb::dbo::Album;
using net::draconia::mediadb::dbo::Artist;
using net::draconia::mediadb::dbo::Song;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                extern template class AbstractDAO<Song>;
                class SongDAOImpl : public AbstractDAO<Song>, public SongDAO
                {
                    AlbumDAO &mRefAlbumDAO;
                    MediaDAO &mRefMediaDAO;
                    RoleDAO &mRefRoleDAO;
                    SingleDAO &mRefSingleDAO;
                protected:
                    virtual Song createObjectFromResults(const QSqlRecord &refRecord);
                    AlbumDAO &getAlbumDAO() const;
                    MediaDAO &getMediaDAO() const;
                    RoleDAO &getRoleDAO() const;
                    SingleDAO &getSingleDAO() const;
                    virtual Song &insert(const Song &refToSave) const;
                    virtual bool isTableExists() const;
                    virtual void removeTable();
                    virtual Song &update(const Song &refToSave) const;
                public:
                    SongDAOImpl(const QSqlDatabase &refDatabase = BeanFactory::getInstance().getDatabase());
                    virtual ~SongDAOImpl();

                    virtual bool createTable() const;
                    virtual Song getById(const unsigned uiSongId) const;
                    virtual Song getByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const;
                    virtual QList<Song> list() const;
                    virtual QList<Song> listByAlbum(const Album &refAlbum) const;
                    virtual QList<Song> listByArtist(const Artist &refArtist) const;
                    virtual QList<Song> listByName(const QString &sName) const;
                    virtual QList<Song> listByWordInComments(const QString &sWord) const;
                    virtual bool remove(const Song &refToRemove) const;
                    virtual Song &save(const Song &refToSave) const;
                };
            }
        }
    }
}
