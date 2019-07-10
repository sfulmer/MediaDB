#pragma once

#include "Observable.h"
#include<QDate>
#include<QList>
#include<QString>
#include "TVSeason.h"
#include "TVSpecial.h"

using net::draconia::util::Observable;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dbo
            {
                class TVSeries : public Observable
                {
                    unsigned muiTVSeriesId;
                    QList<TVSeason> mLstSeasons;
                    QList<TVSpecial> mLstSpecials;
                    QString msComments, msName;
                protected:
                    QList<TVSeason> getSeasonsInternal() const;
                    QList<TVSpecial> getSpecialsInternal() const;
                    void setSeasons(const QList<TVSeason> &lstSeasons);
                    void setSpecials(const QList<TVSpecial> &lstSpecials);
                public:
                    TVSeries();
                    TVSeries(const unsigned uiTVSeriesId);
                    TVSeries(const QString &sName);
                    TVSeries(const QList<TVSeason> &lstSeasons);
                    TVSeries(const QList<TVSpecial> &lstSpecials);
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName);
                    TVSeries(const unsigned uiTVSeriesId, const QList<TVSeason> &lstSeasons);
                    TVSeries(const unsigned uiTVSeriesId, const QList<TVSpecial> &lstSpecials);
                    TVSeries(const QString &sName, const QString &sComments);
                    TVSeries(const QString &sName, const QList<TVSeason> &lstSeasons);
                    TVSeries(const QString &sName, const QList<TVSpecial> &lstSpecials);
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QString &sComments);
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSeason> &lstSeasons);
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSpecial> &lstSpecials);
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QString &sComments, const QList<TVSeason> &lstSeasons);
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QString &sComments, const QList<TVSpecial> &lstSpecials);
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QString &sComments, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials);
                    TVSeries(const TVSeries &refCopy);
                    virtual ~TVSeries();

                    void addSeason(const TVSeason &refSeason);
                    void addSpecial(const TVSpecial &refSpecial);
                    QString getComments() const;
                    QString getName() const;
                    const QList<TVSeason> getSeasons() const;
                    const QList<TVSpecial> getSpecials() const;
                    unsigned getTVSeriesId() const;
                    bool removeSeason(const TVSeason &refSeason);
                    void removeSeason(const unsigned uiIndex);
                    bool removeSpecial(const TVSpecial &refSpecial);
                    void removeSpecial(const unsigned uiIndex);
                    void setComments(const QString &sComments);
                    void setName(const QString &sName);
                    void setTVSeriesId(const unsigned uiTVSeriesId);

                    TVSeries &operator=(const TVSeries &refCopy);
                    bool operator==(const TVSeries &refOther) const;
                    bool operator!=(const TVSeries &refOther) const;
                };
            }
        }
    }
}
