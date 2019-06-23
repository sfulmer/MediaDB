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
                class TVSeries;

                class TVSpecial : public Media
                {
                    QString msComments;
                    unsigned muiTVSpecialId;
                    QSharedPointer<TVSeries> mPtrTVSeries;
                public:
                    TVSpecial();
                    TVSpecial(TVSeries &refTVSeries);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear);
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
                    TVSpecial(const TVSpecial &refCopy);
                    virtual ~TVSpecial();

                    QString getComments() const;
                    TVSeries getSeries() const;
                    unsigned getTVSpecialId() const;
                    void setComments(const QString &sComments);
                    void setSeries(const TVSeries &refSeries);
                    void setTVSpecialId(const unsigned uiTVSpecialId);

                    TVSpecial &operator=(const TVSpecial &refCopy);
                    bool operator==(const TVSpecial &refOther) const;
                    bool operator!=(const TVSpecial &refOther) const;
                };
            }
        }
    }
}
