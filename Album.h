#pragma once

#include "Observable.h"
#include "Song.h"

using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dbo
            {
                class Album : public Observable
                {
                friend class Song;
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
                    QString getName() const;
                    const QList<Song> getSongs() const;
                    bool removeSong(const Song &refSong);
                    void removeSong(const unsigned uiIndex);
                    void setAlbumId(const unsigned uiAlbumId);
                    void setName(const QString &sName);

                    Album &operator=(const Album &refCopy);
                    bool operator==(const Album &refOther) const;
                    bool operator!=(const Album &refOther) const;
                };
            }
        }
    }
}
