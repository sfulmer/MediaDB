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
                class Single : public Media
                {
                    QString msComments;
                    unsigned muiSingleId;
                public:
                    Single();
                    Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease);
                    Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear);
                    Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease);
                    Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear);
                    Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                    Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                    Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                    Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                    Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                    Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                    Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                    Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                    Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                    Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                    Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                    Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                    Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
                    Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
                    Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
                    Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
                    Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
                    Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
                    Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
                    Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
                    Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                    Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                    Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                    Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                    Single(const Single &refCopy);
                    virtual ~Single();

                    QString getComments() const;
                    unsigned getSingleId() const;
                    void setComments(const QString &sComments);
                    void setSingleId(const unsigned uiSingleId);

                    Single &operator=(const Single &refCopy);
                    bool operator==(const Single &refOther) const;
                    bool operator!=(const Single &refOther) const;
                };
            }
        }
    }
}
