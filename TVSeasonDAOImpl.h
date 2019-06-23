#pragma once

#include "AbstractDAO.h"
#include "MediaDAO.h"
#include "RoleDAO.h"
#include "TVEpisodeDAO.h"
#include "TVSeasonDAO.h"
#include "TVSeriesDAO.h"

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                extern template class AbstractDAO<TVSeason>;

                class TVSeasonDAOImpl : public AbstractDAO<TVSeason>, public TVSeasonDAO
                {
                    static const QString TableName;

                    MediaDAO &mRefMediaDAO;
                    RoleDAO &mRefRoleDAO;
                    TVEpisodeDAO &mRefTVEpisodeDAO;
                    TVSeriesDAO &mRefTVSeriesDAO;
                protected:
                    virtual TVSeason createObjectFromResults(const QSqlRecord &refRecord);
                    MediaDAO &getMediaDAO() const;
                    virtual QString getPrimaryKey() const;
                    virtual QString getQueriedColumnsForSelect() const;
                    RoleDAO &getRoleDAO() const;
                    virtual QString getTableName() const;
                    TVEpisodeDAO &getTVEpisodeDAO() const;
                    TVSeriesDAO &getTVSeriesDAO() const;
                    virtual TVSeason &insert(const TVSeason &refToSave) const;
                    virtual TVSeason &update(const TVSeason &refToSave) const;
                public:
                    TVSeasonDAOImpl(const QSqlDatabase &refDatabase = BeanFactory::getInstance().getDatabase());
                    ~TVSeasonDAOImpl();

                    virtual bool createTable() const;
                    virtual TVSeason getById(const unsigned uiTVSeasonId) const;
                    virtual TVSeason getByTVSeriesAndNumber(const TVSeries &refTVSeries, const unsigned uiNumber) const;
                    virtual QList<TVSeason> list() const;
                    virtual QList<TVSeason> listByArtist(const Artist &refArtist) const;
                    virtual QList<TVSeason> listByTVSeries(const TVSeries &refTVSeries) const;
                    virtual QList<TVSeason> listByTVSeriesAndArtist(const TVSeries &refTVSeries, const Artist &refArtist) const;
                    virtual QList<TVSeason> listByTVSeriesAndEpisodeName(const TVSeries &refTVSeries, const QString &sName) const;
                    virtual QList<TVSeason> listByWordInComments(const QString &sWord) const;
                    virtual bool remove(const TVSeason &refToRemove) const;
                    virtual TVSeason &save(const TVSeason &refToSave) const;
                };
            }
        }
    }
}
