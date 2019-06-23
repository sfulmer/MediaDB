#pragma once

#include "AbstractDAO.h"
#include "ArtistDAO.h"
#include "BeanFactory.h"
#include "MediaDAO.h"
#include "RoleDAO.h"
#include "TVEpisodeDAO.h"
#include "TVSeasonDAO.h"

using net::draconia::mediadb::BeanFactory;

using net::draconia::mediadb::dbo::Artist;
using net::draconia::mediadb::dbo::TVEpisode;
using net::draconia::mediadb::dbo::TVSeason;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                extern template class AbstractDAO<TVEpisode>;

                class TVEpisodeDAOImpl : public AbstractDAO<TVEpisode>, public TVEpisodeDAO
                {
                    static const QString TableName;

                    MediaDAO &mRefMediaDAO;
                    RoleDAO &mRefRoleDAO;
                    TVSeasonDAO &mRefTVSeasonDAO;
                protected:
                    virtual TVEpisode createObjectFromResults(const QSqlRecord &refRecord);
                    MediaDAO &getMediaDAO() const;
                    virtual QString getPrimaryKey() const;
                    virtual QString getQueriedColumnsForSelect() const;
                    RoleDAO &getRoleDAO() const;
                    virtual QString getTableName() const;
                    TVSeasonDAO &getTVSeasonDAO() const;
                    virtual TVEpisode &insert(const TVEpisode &refToSave) const;
                    virtual TVEpisode &update(const TVEpisode &refToSave) const;
                public:
                    TVEpisodeDAOImpl(const QSqlDatabase &refDatabase = BeanFactory::getInstance().getDatabase());
                    virtual ~TVEpisodeDAOImpl();

                    virtual bool createTable() const;
                    virtual TVEpisode getById(const unsigned uiId) const;
                    virtual TVEpisode getBySeasonAndEpisodeNumber(const TVSeason &refSeason, const unsigned uiEpisodeNumber) const;
                    virtual TVEpisode getBySeasonAndName(const TVSeason &refSeason, const QString &sName) const;
                    virtual QList<TVEpisode> list() const;
                    virtual QList<TVEpisode> listByArtist(const Artist &refArtist) const;
                    virtual QList<TVEpisode> listByName(const QString &sName) const;
                    virtual QList<TVEpisode> listByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const;
                    virtual QList<TVEpisode> listBySeason(const TVSeason &refSeason) const;
                    virtual QList<TVEpisode> listBySeasonAndArtist(const TVSeason &refSeason, const Artist &refArtist) const;
                    virtual QList<TVEpisode> listByWordInComments(const QString &sWord) const;
                    virtual bool remove(const TVEpisode &refToRemove) const;
                    virtual TVEpisode &save(const TVEpisode &refToSave) const;
                };
            }
        }
    }
}
