#pragma once

#include "Media.h"
#include "MovieViewing.h"

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dbo
            {
                class Movie : public Media
                {
                    unsigned muiMovieId;
                    QList<MovieViewing> mLstViewings;
                    QString msComments;
                protected:
                    QList<MovieViewing> &getViewingsInternal() const;
                    void setViewings(const QList<MovieViewing> &lstViewings);
                public:
                    Movie();
                    Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease);
                    Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear);
                    Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                    Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                    Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                    Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                    Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                    Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                    Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
                    Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
                    Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
                    Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
                    Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                    Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                    Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QList<MovieViewing> &lstViewings);
                    Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QList<MovieViewing> &lstViewings);
                    Movie(const Movie &refCopy);
                    virtual ~Movie();

                    void addViewing(const MovieViewing &refViewing);
                    unsigned getMovieId() const;
                    QString getComments() const;
                    const QList<MovieViewing> getViewings() const;
                    bool removeViewing(const MovieViewing &refViewing);
                    void removeViewing(const unsigned uiIndex);
                    void setComments(const QString &sComments);
                    void setMovieId(const unsigned uiMovieId);

                    Movie &operator=(const Movie &refCopy);
                    bool operator==(const Movie &refOther) const;
                    bool operator!=(const Movie &refOther) const;
                };
            }
        }
    }
}
