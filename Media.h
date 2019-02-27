#include "Artist.h"
#include<QDate>
#include<QList>
#include<QString>

#pragma once

namespace net
{
    namespace draconia
    {
        class Media
        {
            unsigned muiMediaId;
            QDate mDtRelease;
            QList<Artist> mLstArtists;
            QString msFilePath, msName;
        protected:
            QList<Artist> getArtistsInternal() const;
            void setArtists(const QList<Artist> &lstArtists);
        public:
            Media();
            Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease);
            Media(const unsigned uiMediaId, const QString &sName, const unsigned muiReleaseYear);
            Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
            Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
            Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
            Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
            Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
            Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
            Media(const Media &refCopy);
            virtual ~Media() = 0;

            void addArtist(const Artist &refArtist);
            const QList<Artist> getArtists() const;
            QString &getFilePath() const;
            unsigned getMediaId() const;
            QString getName() const;
            QDate getReleaseDate() const;
            bool removeArtist(const Artist &refArtist);
            void removeArtist(const unsigned uiIndex);
            void setFilePath(const QString &sFilePath);
            void setMediaId(const unsigned uiMediaId);
            void setName(const QString &sName);
            void setReleaseDate(const QDate &dtRelease);
            void setReleaseDate(const unsigned uiReleaseYear);
        };
    }
}
