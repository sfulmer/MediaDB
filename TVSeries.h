#pragma once

#include "Media.h"
#include<QList>
#include<QString>

namespace net
{
    namespace draconia
    {
        class TVEpisode;
        class TVSeason;
        class TVSeason;
        class TVSeries;
        class TVSpecial;

        class TVEpisode : public Media
        {
        friend class TVSeason;
            unsigned muiTVEpisodeId;
            QString msComments;
            TVSeason &mRefTVSeason;
        protected:
            TVEpisode(TVSeason &refTVSeason);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned muiRelease);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned muiRelease);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
            TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
        public:
            TVEpisode(const TVEpisode &refCopy);
            virtual ~TVEpisode();

            QString &getComments() const;
            TVSeason &getSeason() const;
            unsigned getTVEpisodeId() const;
            void setTVEpisodeId(const unsigned uiTVEpisodeId);
        };

        class TVSeason
        {
        friend class TVSeries;
            unsigned muiSeasonId, muiNumber;
            QList<TVEpisode> mLstEpisodes;
            QString msComments;
            TVSeries &mRefTVSeries;
        protected:
            QList<TVEpisode> &getEpisodesInternal() const;
            void setEpisodes(const QList<TVEpisode> &lstEpisodes);

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
        public:
            TVSeason(const TVSeason &refCopy);
            virtual ~TVSeason();

            void addEpisode(const TVEpisode &refEpisode);
            QString &getComments() const;
            const QList<TVEpisode> getEpisodes() const;
            unsigned getNumber() const;
            unsigned getSeasonId() const;
            TVSeries &getSeries() const;
            bool removeEpisode(const TVEpisode &refEpisode);
            void removeEpisode(const unsigned uiIndex);
            void setComments(const QString &sComments);
            void setNumber(const unsigned uiNUmber);
            void setSeasonId(const unsigned uiSeasonId);
        };

        class TVSeries
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
            TVSeries(const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials);
            TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QString &sComments);
            TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSeason> &lstSeasons);
            TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSpecial> &lstSpecials);
            TVSeries(const QString &sName, const QString &sComments, const QList<TVSeason> &lstSeasons);
            TVSeries(const QString &sName, const QString &sComments, const QList<TVSpecial> &lstSpecials);
            TVSeries(const QString &sName, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials);
            TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials);
            TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QString &sComments, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials);
            TVSeries(const TVSeries &refCopy);
            virtual ~TVSeries();

            void addSeason(const TVSeason &refSeason);
            void addSpecial(const TVSpecial &refSpecial);
            QString &getComments() const;
            const QList<TVSeason> getSeasons() const;
            const QList<TVSpecial> getSpecials() const;
            unsigned getTVSeriesId() const;
            bool removeSeason(const TVSeason &refSeason);
            void removeSeason(const unsigned uiIndex);
            bool removeSpecial(const TVSpecial &refSpecial);
            void removeSpecial(const unsigned uiIndex);
        };

        class TVSpecial : public Media
        {
        friend class TVSeries;
            unsigned muiTVSpecialId;
            QString msComments;
            TVSeries &mRefTVSeries;
        protected:
            TVSpecial(TVSeries &refTVSeries);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned muiRelease);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned muiRelease);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
            TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
        public:
            TVSpecial(const TVSpecial &refCopy);
            virtual ~TVSpecial();
        };
    }
}
