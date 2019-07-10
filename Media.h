#pragma once

#include "Artist.h"
#include "MediaFile.h"
#include<QDate>
#include<QList>
#include<QString>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dbo
            {
                class Artist;

                class Media : public MediaFile
                {
                    unsigned muiMediaId;
                    QDate mDtRelease;
                    QList<Artist> mLstArtists;
                    QString msName;
                protected:
                    QList<Artist> &getArtistsInternal() const;
                    void setArtists(const QList<Artist> lstArtists);
                public:
                    Media();
                    Media(const unsigned uiMediaId);
                    Media(const QString &sName);
                    Media(const QList<Artist> &lstArtists);
                    Media(const unsigned uiMediaId, const QString &sName);
                    Media(const unsigned uiMediaId, const QDate &dtRelease);
                    Media(const unsigned uiMediaId, const unsigned uiReleaseYear);
                    Media(const unsigned uiMediaId, const QList<Artist> &lstArtists);
                    Media(const QString &sName, const QDate &dtRelease);
                    Media(const QString &sName, const unsigned uiReleaseYear);
                    Media(const QString &sName, const QString &sFilePath);
                    Media(const QString &sName, const QList<Artist> &lstArtists);
                    Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease);
                    Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear);
                    Media(const unsigned uiMediaId, const QString &sName, const QString &sFilePath);
                    Media(const unsigned uiMediaId, const QString &sName, const QList<Artist> &lstArtists);
                    Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                    Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                    Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                    Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                    Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFileName, const QList<Artist> lstArtists);
                    Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> lstArtists);
                    Media(const Media &refCopy);
                    ~Media();

                    void addArtist(const Artist &refArtist);
                    const QList<Artist> getArtists() const;
                    unsigned getMediaId() const;
                    QString getName() const;
                    QDate getReleaseDate() const;
                    void removeArtist(const Artist &refArtist);
                    void setMediaId(const unsigned uiMediaId);
                    void setName(const QString &sName);
                    void setReleaseDate(const QDate &dtRelease);
                    void setReleaseDate(const unsigned uiReleaseYear);

                    Media &operator=(const Media &refCopy);
                    bool operator==(const Media &refOther) const;
                    bool operator!=(const Media &refOther) const;
                };
            }
        }
    }
}
