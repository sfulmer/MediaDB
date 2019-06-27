#pragma once

#include "AbstractDAO.h"
#include "ArtistDAO.h"
#include "BeanFactory.h"
#include "MediaDAO.h"
#include "RoleDAO.h"
#include "TVSeriesDAO.h"
#include "TVSpecialDAO.h"

using net::draconia::mediadb::BeanFactory;

using net::draconia::mediadb::dbo::TVSeries;
using net::draconia::mediadb::dbo::TVSpecial;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                extern template class AbstractDAO<TVSpecial>;

                class TVSpecialDAOImpl : public AbstractDAO<TVSpecial>, public TVSpecialDAO
                {
                    ArtistDAO &mRefArtistDAO;
                    MediaDAO &mRefMediaDAO;
                    RoleDAO &mRefRoleDAO;
                    TVSeriesDAO &mRefTVSeriesDAO;
                protected:
                    virtual TVSpecial createObjectFromResults(const QSqlRecord &refRecord);
                    ArtistDAO &getArtistDAO() const;
                    MediaDAO &getMediaDAO() const;
                    RoleDAO &getRoleDAO() const;
                    TVSeriesDAO &getTVSeriesDAO() const;
                    virtual TVSpecial &insert(const TVSpecial &refToSave) const;
                    virtual bool isTableExists() const;
                    virtual void removeTable();
                    virtual TVSpecial &update(const TVSpecial &refToSave) const;
                public:
                    TVSpecialDAOImpl(const QSqlDatabase &refDatabase = BeanFactory::getInstance().getDatabase());
                    virtual ~TVSpecialDAOImpl();

                    virtual bool createTable() const;
                    virtual TVSpecial getById(const unsigned uiId) const;
                    virtual TVSpecial getByNameAndreleaseYear(const QString &sName, const unsigned uiReleaseYear) const;
                    virtual QList<TVSpecial> list() const;
                    virtual QList<TVSpecial> listByArtist(const Artist &refArtist) const;
                    virtual QList<TVSpecial> listByArtistAndSeries(const Artist &refArtist, const TVSeries &refTVSeries) const;
                    virtual QList<TVSpecial> listByName(const QString &sName) const;
                    virtual QList<TVSpecial> listByTVSeries(const TVSeries &refTVSeries) const;
                    virtual QList<TVSpecial> listByWordInComment(const QString &sWord) const;
                    virtual bool remove(const TVSpecial &refToRemove) const;
                    virtual TVSpecial &save(const TVSpecial &refToSave) const;
                };
            }
        }
    }
}
