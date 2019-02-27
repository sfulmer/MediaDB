#pragma once

#include "Artist.h"
#include "Media.h"
#include<QList>
#include<QString>

namespace net
{
    namespace draconia
    {
        class Movie : public Media
        {
            unsigned muiMovieId;
            QList<QDateTime> mLstViewings;
            QString msComments;
        protected:
            QList<QDateTime> &getViewingsInternal() const;
            void setViewings(const QList<QDateTime> &lstViewings);
        public:
            Movie();
            Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease);
            Movie(const unsigned uiMediaId, const QString &sName, const unsigned muiRelease);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned muiRelease);
            Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const QString &sName, const unsigned muiRelease, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned muiRelease, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
            Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
            Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
            Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
            Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
            Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
            Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
            Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
            Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
            Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
            Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
            Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
            Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QList<QDateTime> &lstViewings);
            Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QList<QDateTime> &lstViewings);
            Movie(const Movie &refCopy);
            virtual ~Movie();

            =void addViewing(const QDateTime &dtViewing);
            unsigned getMovieId() const;
            QString &getComments() const;
            const QList<QDateTime> &getViewings() const;
            bool removeViewing(const QDateTime &dtViewing);
            void removeViewing(const unsigned uiIndex);
            void setComments(const QString &sComments);
            void setMovieId(const unsigned uiMovieId);
        };
    }
}
