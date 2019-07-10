#pragma once

#include "Media.h"
#include<QSharedPointer>

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
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId);
                    TVSpecial(TVSeries &refTVSeries, const QString &sName);
                    TVSpecial(TVSeries &refTVSeries, const QList<Artist> &lstArtists);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QDate &dtRelease);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiReleaseYear);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QList<Artist> &lstArtists);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QDate &dtRelease);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const unsigned uiReleaseYear);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QList<Artist> &lstArtists);
                    TVSpecial(TVSeries &refTVSeries, const QString &sName, const QDate &dtRelease);
                    TVSpecial(TVSeries &refTVSeries, const QString &sName, const unsigned uiReleaseYear);
                    TVSpecial(TVSeries &refTVSeries, const QString &sName, const QString &sFilePath);
                    TVSpecial(TVSeries &refTVSeries, const QString &sName, const QList<Artist> &lstArtists);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QString &sFilePath);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QList<Artist> &lstArtists);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QString &sFilePath);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QList<Artist> &lstArtists);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> lstArtists);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> lstArtists);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QList<Artist> &lstArtists);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QList<Artist> &lstArtists);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QList<Artist> &lstArtists);
                    TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QList<Artist> &lstArtists);
                    TVSpecial(const TVSpecial &refCopy);
                    virtual ~TVSpecial();

                    QString getComments() const;
                    TVSeries getSeries() const;
                    unsigned getTVSpecialId() const;
                    void setComments(const QString &sComments);
                    void setSeries(const TVSeries &refSeries);
                    void setTVSpecialId(const unsigned uiMediaId);

                    TVSpecial &operator=(const TVSpecial &refCopy);
                    bool operator==(const TVSpecial &refOther) const;
                    bool operator!=(const TVSpecial &refOther) const;
                };
            }
        }
    }
}
