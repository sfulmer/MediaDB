#pragma once

#include "Observable.h"
#include<QList>
#include<QSharedPointer>
#include<QString>
#include "TVEpisode.h"

using net::draconia::util::Observable;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dbo
            {
                class TVSeries;

                class TVSeason : public Observable
                {
                    unsigned muiSeasonId, muiNumber;
                    QList<TVEpisode> mLstEpisodes;
                    QString msComments;
                    QSharedPointer<TVSeries> mPtrTVSeries;
                protected:
                    QList<TVEpisode> &getEpisodesInternal() const;
                    void setEpisodes(const QList<TVEpisode> &lstEpisodes);
                public:
                    TVSeason();
                    TVSeason(TVSeries &refTVSeries);
                    TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId);
                    TVSeason(TVSeries &refTVSeries, const QString &sComments);
                    TVSeason(TVSeries &refTVSeries, const QList<TVEpisode> &lstEpisodes);
                    TVSeason(TVSeries &refTVSeries, const QString &sComments, const QList<TVEpisode> &lstEpisodes);
                    TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const unsigned uiNumber);
                    TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const QString &sComments);
                    TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const QList<TVEpisode> &lstEpisodes);
                    TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const unsigned uiNumber, const QString &sComments);
                    TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const unsigned uiNumber, const QList<TVEpisode> &lstEpisodes);
                    TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const unsigned uiNumber, const QString &sComments, const QList<TVEpisode> &lstEpisodes);
                    TVSeason(const TVSeason &refCopy);
                    virtual ~TVSeason();

                    void addEpisode(const TVEpisode &refEpisode);
                    QString getComments() const;
                    const QList<TVEpisode> getEpisodes() const;
                    unsigned getNumber() const;
                    unsigned getSeasonId() const;
                    TVSeries getSeries() const;
                    bool removeEpisode(const TVEpisode &refEpisode);
                    void removeEpisode(const unsigned uiIndex);
                    void setComments(const QString &sComments);
                    void setNumber(const unsigned uiNUmber);
                    void setSeasonId(const unsigned uiSeasonId);
                    void setSeries(const TVSeries &refSeries);

                    TVSeason &operator=(const TVSeason &refCopy);
                    bool operator==(const TVSeason &refOther) const;
                    bool operator!=(const TVSeason &refOther) const;
                };
            }
        }
    }
}
