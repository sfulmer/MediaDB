#pragma once

#include "AbstractDAO.h"
#include "MovieDAO.h"
#include "TableUtils.h"

namespace net
{
    namespace draconia
    {
        namespace dao
        {
            class MovieDAOImpl : public MovieDAO, public AbstractDAO<Movie>
            {
                const static QString TableName;
            protected:
                virtual Movie createObjectFromResults(const QSqlRecord &refRecord);
                virtual QList<Movie> createObjectListFromResults(const QSqlQuery &refQuery);
                virtual bool createTable() const;
                virtual QString getQueriedColumnsForSelect() const;
                virtual Movie &insert(const Movie &refToSave) const;
                virtual bool isTableExists() const;
                virtual void removeTable();
                virtual Movie &update(const Movie &refToSave) const;
            public:
                MovieDAOImpl(const QSqlDatabase &refDatasource = BeanFactory::getInstance().getDatabase());
                virtual ~MovieDAOImpl();

                virtual Movie getById(const unsigned uiMovieId) const;
                virtual Movie getByNameAndReleaseDate(const QString &sName, const QDate &dtRelease) const;
                virtual QList<Movie> list() const;
                virtual QList<Movie> listByName(const QString &sName) const;
                virtual QList<Movie> listByReleaseYear(const unsigned uiReleaseYear) const;
                virtual void remove(const Movie &refMovie) const;
                virtual Movie &save(const Movie &refMovie) const;
            };
        }
    }
}
