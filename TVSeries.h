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
                    QDate mDtReleaseDate;
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
                    TVSeries(const QDate &dtRelease); // Addition
                    TVSeries(const QList<TVSeason> &lstSeasons);
                    TVSeries(const QList<TVSpecial> &lstSpecials);
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName);
                    TVSeries(const unsigned uiTVSeriesId, const QDate &dtRelease);  // Addition
                    TVSeries(const unsigned uiTVSeriesId, const unsigned uiReleaseYear); // Addition
                    TVSeries(const unsigned uiTVSeriesId, const QList<TVSeason> &lstSeasons);
                    TVSeries(const unsigned uiTVSeriesId, const QList<TVSpecial> &lstSpecials);
                    TVSeries(const QString &sName, const QString &sComments);
                    TVSeries(const QString &sName, const QDate &dtRelease); //Addition
                    TVSeries(const QString &sName, const unsigned uiReleaseYear); //Addition
                    TVSeries(const QString &sName, const QList<TVSeason> &lstSeasons);
                    TVSeries(const QString &sName, const QList<TVSpecial> &lstSpecials);
                    TVSeries(const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials);
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QString &sComments);
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QDate &dtRelease); //Addition
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const unsigned uiReleaseYear); //Addition
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSeason> &lstSeasons);
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSpecial> &lstSpecials);
                    TVSeries(const QString &sName, const QString &sComments, const QList<TVSeason> &lstSeasons);
                    TVSeries(const QString &sName, const QDate &dtRelease, const QList<TVSeason> &lstSeasons);  // Addition
                    TVSeries(const QString &sName, const unsigned uiReleaseYear, const QList<TVSeason> &lstSeasons);  // Addition
                    TVSeries(const QString &sName, const QString &sComments, const QList<TVSpecial> &lstSpecials);
                    TVSeries(const QString &sName, const QDate &dtRelease, const QList<TVSpecial> &lstSpecials);    // Addition
                    TVSeries(const QString &sName, const unsigned uiReleaseYear, const QList<TVSpecial> &lstSpecials);    // Addition
                    TVSeries(const QString &sName, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials);
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials);
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QString &sComments, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials);
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QDate &dtRelease, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials);
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const unsigned uiReleaseYear, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials);
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QDate &dtRelease, const QString &sComments); // Addition
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const unsigned uiReleaseYear, const QString &sComments); // Addition
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QDate &dtRelease, const QString &sComments, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials);
                    TVSeries(const unsigned uiTVSeriesId, const QString &sName, const unsigned uiReleaseYear, const QString &sComments, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials);
                    TVSeries(const TVSeries &refCopy);
                    virtual ~TVSeries();

                    void addSeason(const TVSeason &refSeason);
                    void addSpecial(const TVSpecial &refSpecial);
                    QString getComments() const;
                    QString getName() const;
                    QDate getReleaseDate() const;
                    const QList<TVSeason> getSeasons() const;
                    const QList<TVSpecial> getSpecials() const;
                    unsigned getTVSeriesId() const;
                    bool removeSeason(const TVSeason &refSeason);
                    void removeSeason(const unsigned uiIndex);
                    bool removeSpecial(const TVSpecial &refSpecial);
                    void removeSpecial(const unsigned uiIndex);
                    void setComments(const QString &sComments);
                    void setName(const QString &sName);
                    void setReleaseDate(const QDate &dtRelease);
                    void setReleaseYear(const unsigned uiReleaseYear);
                    void setTVSeriesId(const unsigned uiTVSeriesId);

                    TVSeries &operator=(const TVSeries &refCopy);
                    bool operator==(const TVSeries &refOther) const;
                    bool operator!=(const TVSeries &refOther) const;
                };
            }
        }
    }
}
