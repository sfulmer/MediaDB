#pragma once

#include "Media.h"

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dbo
            {
                class TVSeason;

                class TVEpisode : public Media
                {
                    unsigned muiNumber, muiTVEpisodeId;
                    QString msComments;
                    QSharedPointer<TVSeason> mPtrTVSeason;
                public:
                    TVEpisode();
                    TVEpisode(TVSeason &refTVSeason);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId);
                    TVEpisode(TVSeason &refTVSeason, const QString &sName);
                    TVEpisode(TVSeason &refTVSeason, const QList<Artist> &lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QDate &dtRelease);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiReleaseYear);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QList<Artist> &lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const QString &sName, const QDate &dtRelease);
                    TVEpisode(TVSeason &refTVSeason, const QString &sName, const unsigned uiReleaseYear);
                    TVEpisode(TVSeason &refTVSeason, const QString &sName, const QString &sFilePath);
                    TVEpisode(TVSeason &refTVSeason, const QString &sName, const QList<Artist> &lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QString &sFilePath);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QList<Artist> &lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QString &sFilePath);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QString &sFilePath);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QList<Artist> &lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QList<Artist> &lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFileName, const QList<Artist> lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFileName, const QList<Artist> lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QString &sFileName, const QList<Artist> lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFileName, const QString &sComments, const QList<Artist> lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QList<Artist> lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFileName, const QString &sComments, const QList<Artist> lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QList<Artist> lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QString &sFileName, const QString &sComments, const QList<Artist> lstArtists);
                    TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QList<Artist> lstArtists);
                    TVEpisode(const TVEpisode &refCopy);
                    virtual ~TVEpisode();

                    QString getComments() const;
                    unsigned getNumber() const;
                    TVSeason getSeason() const;
                    unsigned getTVEpisodeId() const;
                    void setComments(const QString &sComments);
                    void setNumber(const unsigned uiNumber);
                    void setTVEpisodeId(const unsigned uiTVEpisodeId);

                    TVEpisode &operator=(const TVEpisode &refCopy);
                    bool operator==(const TVEpisode &refOther) const;
                    bool operator!=(const TVEpisode &refOther) const;
                };
            }
        }
    }
}
