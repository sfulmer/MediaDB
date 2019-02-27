#pragma once

#include "Media.h"

namespace net
{
    namespace draconia
    {
        class Album;
        class Single;
        class Song;

        class Single : public Media
        {
            QString msComments;
            unsigned muiSingleId;
        public:
            Single();
            Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease);
            Single(const unsigned uiMediaId, const QString &sName, const unsigned muiReleaseYear);
            Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease);
            Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned muiReleaseYear);
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
        };

        class Song : public Single
        {
            Album &mRefAlbum;
            unsigned muiSongId;
        protected:
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
        public:
            unsigned getSongId() const;
            void setSongId(const unsigned uiSongId);
        };

        class Album
        {
            QList<Song> mLstSongs;
            QString msName;
            unsigned muiAlbumId;
        protected:
            QList<Song> &getSongsInternal() const;
            void setSongs(const QList<Song> &lstSongs);
        public:
            Album();
            Album(const unsigned uiAlbumId);
            Album(const QString &sName);
            Album(const QList<Song> &lstSongs);
            Album(const unsigned uiAlbumId, const QString &sName);
            Album(const unsigned uiAlbumId, const QList<Song> &lstSongs);
            Album(const QString &sName, const QList<Song> &lstSongs);
            Album(const unsigned uiAlbumId, const QString &sName, const QList<Song> &lstSongs);
            Album(const Album &refCopy);
            ~Album();

            void addSong(const Song &refSong);
            unsigned getAlbumId() const;
            QString &getName() const;
            const QList<Song> getSongs() const;
            bool removeSong(const Song &refSong);
            void removeSong(const unsigned uiIndex);
            void setAlbumId(const unsigned uiAlbumId);
            void setName(const QString &sName);
        };
    }
}
