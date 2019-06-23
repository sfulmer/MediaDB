#pragma once

#include<QSharedPointer>
#include "Single.h"

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dbo
            {
                class Album;

                class Song : public Single
                {
                    QSharedPointer<Album> mPtrAlbum;
                    unsigned muiSongId;
                public:
                    Song();
                    Song(Album &refAlbum);
                    Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease);
                    Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned muiReleaseYear);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned muiReleaseYear);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned muiReleaseYear);
                    Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                    Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                    Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                    Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                    Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                    Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                    Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
                    Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
                    Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
                    Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
                    Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                    Song(Album &refAlbum, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                    Song(Album &refAlbum, const unsigned uiMediaId, const unsigned uiSingleId, const unsigned uiSongId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                    Song(const Song &refCopy);
                    virtual ~Song();

                    Album getAlbum() const;
                    unsigned getSongId() const;
                    void setAlbum(const Album &refAlbum);
                    void setSongId(const unsigned uiSongId);

                    Song &operator=(const Song &refOther);
                    bool operator==(const Song &refOther) const;
                    bool operator!=(const Song &refOther) const;
                };
            }
        }
    }
}
