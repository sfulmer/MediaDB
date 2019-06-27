#pragma once

#include "AbstractDAO.h"
#include "BeanFactory.h"
#include "MovieDAO.h"
#include "MovieViewingDAO.h"

using net::draconia::mediadb::BeanFactory;

using net::draconia::mediadb::dbo::Movie;
using net::draconia::mediadb::dbo::MovieViewing;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                extern template class AbstractDAO<MovieViewing>;

                class MovieViewingDAOImpl : public AbstractDAO<MovieViewing>, public MovieViewingDAO
                {
                    MovieDAO &mRefMovieDAO;
                protected:
                    virtual MovieViewing createObjectFromResults(const QSqlRecord &refRecord);
                    MovieDAO &getMovieDAO() const;
                    virtual MovieViewing &insert(const MovieViewing &refToSave) const;
                    virtual bool isTableExists() const;
                    virtual void removeTable();
                    virtual MovieViewing &update(const MovieViewing &refToSave) const;
                public:
                    MovieViewingDAOImpl(const QSqlDatabase &refDatabase = BeanFactory::getInstance().getDatabase());
                    ~MovieViewingDAOImpl();
                    virtual bool createTable() const;
                    virtual MovieViewing getById(const unsigned uiMovieViewingId) const;
                    virtual QList<MovieViewing> list() const;
                    virtual QList<MovieViewing> listByMovie(const Movie &refMovie) const;
                    virtual bool remove(const MovieViewing &refViewing) const;
                    virtual MovieViewing &save(const MovieViewing &refToSave) const;
                };
            }
        }
    }
}
