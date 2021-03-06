#pragma once

#include "AbstractDAO.h"
#include "BeanFactory.h"
#include "TVSeasonDAO.h"
#include "TVSeriesDAO.h"
#include "TVSpecialDAO.h"

using net::draconia::mediadb::BeanFactory;
using net::draconia::mediadb::dbo::TVSeries;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                extern template class AbstractDAO<TVSeries>;

                class TVSeriesDAOImpl : public AbstractDAO<TVSeries>, public TVSeriesDAO
                {
                    TVSeasonDAO &mRefTVSeasonDAO;
                    TVSpecialDAO &mRefTVSpecialDAO;
                protected:
                    virtual TVSeries createObjectFromResults(const QSqlRecord &refRecord);
                    TVSeasonDAO &getTVSeasonDAO() const;
                    TVSpecialDAO &getTVSpecialDAO() const;
                    virtual TVSeries &insert(const TVSeries &refToSave) const;
                    virtual bool isTableExists() const;
                    virtual void removeTable();
                    virtual TVSeries &update(const TVSeries &refToSave) const;
                public:
                    TVSeriesDAOImpl(const QSqlDatabase &refDatabase = BeanFactory::getInstance().getDatabase());
                    ~TVSeriesDAOImpl();

                    virtual bool createTable() const;
                    virtual TVSeries getById(const unsigned uiId) const;
                    virtual QList<TVSeries> list() const;
                    virtual QList<TVSeries> listByName(const QString &sName) const;
                    virtual QList<TVSeries> listByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const;
                    virtual QList<TVSeries> listByReleaseYear(const unsigned uiReleaseYear) const;
                    virtual QList<TVSeries> listByWordInComment(const QString &sWord) const;
                    virtual bool remove(const TVSeries &refToRemove) const;
                    virtual TVSeries &save(const TVSeries &refToSave) const;
                };
            }
        }
    }
}
