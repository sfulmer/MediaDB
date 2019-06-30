#pragma once

#include "AbstractDAO.h"
#include "BeanFactory.h"
#include "MediaDAO.h"
#include "MovieDAO.h"
#include "MovieViewingDAO.h"

using net::draconia::mediadb::dbo::Movie;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                extern template class AbstractDAO<Movie>;

                class MovieDAOImpl : public AbstractDAO<Movie>, public MovieDAO
                {
                    ArtistDAO &mRefArtistDAO;
                    MediaDAO &mRefMediaDAO;
                    MovieViewingDAO &mRefMovieViewingDAO;
                    RoleDAO &mRefRoleDAO;
                protected:
                    virtual Movie createObjectFromResults(const QSqlRecord &refRecord);
                    ArtistDAO &getArtistDAO() const;
                    MediaDAO &getMediaDAO() const;
                    MovieViewingDAO &getMovieViewingDAO() const;
                    RoleDAO &getRoleDAO() const;
                    virtual Movie &insert(const Movie &refToSave) const;
                    virtual bool isTableExists() const;
                    virtual void removeTable();
                    virtual Movie &update(const Movie &refToSave) const;
                public:
                    MovieDAOImpl(const QSqlDatabase &refDatabase = BeanFactory::getInstance().getDatabase());
                    virtual ~MovieDAOImpl();
                    virtual bool createTable() const;
                    virtual Movie getById(const unsigned uiMovieId) const;
                    virtual Movie getByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const;
                    virtual QList<Movie> list() const;
                    virtual QList<Movie> listByArtist(const Artist &refArtist) const;
                    virtual QList<Movie> listByArtistAndName(const Artist &refArtist, const QString &sName) const;
                    virtual QList<Movie> listByArtistNameAndReleaseYear(const Artist &refArtist, const QString &sName, const unsigned uiReleaseYear) const;
                    virtual QList<Movie> listByArtistNameReleaseYearAndRoleType(const Artist &refArtist, const QString &sName, const unsigned uiReleaseYear, const RoleType &refRoleType) const;
                    virtual QList<Movie> listByArtistNameAndRoleType(const Artist &refArtist, const QString &sName, const RoleType &refRoleType) const;
                    virtual QList<Movie> listByArtistAndRoleType(const Artist &refArtist, const RoleType &refRoleType) const;
                    virtual QList<Movie> listByName(const QString &sName) const;
                    virtual QList<Movie> listByReleaseYear(const unsigned uiReleaseYear) const;
                    virtual QList<Movie> listByWordInComments(const QString &sWord) const;
                    virtual bool remove(const Movie &refToRemove) const;
                    virtual Movie &save(const Movie &refToSave) const;
                };
            }
        }
    }
}
