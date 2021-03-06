#pragma once

#include "Observable.h"
#include<QDate>
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
                    QDate mDtRelease;
                    QList<Song> mLstSongs;
                    QString msComments, msName;
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
                    Album(const QString &sName, const QDate dtRelease);
                    Album(const QString &sName, const unsigned uiReleaseYear);
                    Album(const QString &sName, const QList<Song> &lstSongs);
                    Album(const QString &sName, const QString &sComments);
                    Album(const QString &sName, const QDate dtRelease, const QString &sComments);
                    Album(const QString &sName, const unsigned uiReleaseYear, const QString &sComments);
                    Album(const unsigned uiAlbumId, const QString &sName, const QDate dtRelease);
                    Album(const unsigned uiAlbumId, const QString &sName, const unsigned uiReleaseYear);
                    Album(const unsigned uiAlbumId, const QString &sName, const QList<Song> &lstSongs);
                    Album(const unsigned uiAlbumId, const QString &sName, const QString &sComments);
                    Album(const unsigned uiAlbumId, const QString &sName, const QDate dtRelease, const QString &sComments);
                    Album(const unsigned uiAlbumId, const QString &sName, const unsigned uiReleaseYear, const QString &sComments);
                    Album(const unsigned uiAlbumId, const QString &sName, const QDate dtRelease, const QList<Song> &lstSongs);
                    Album(const unsigned uiAlbumId, const QString &sName, const unsigned uiReleaseYear, const QList<Song> &lstSongs);
                    Album(const unsigned uiAlbumId, const QString &sName, const QDate dtRelease, const QList<Song> &lstSongs, const QString &sComments);
                    Album(const unsigned uiAlbumId, const QString &sName, const unsigned uiReleaseYear, const QList<Song> &lstSongs, const QString &sComments);
                    Album(const Album &refCopy);
                    ~Album();

                    void addSong(const Song &refSong);
                    unsigned getAlbumId() const;
                    QString getComments() const;
                    QString getName() const;
                    QDate getReleaseDate() const;
                    const QList<Song> getSongs() const;
                    bool removeSong(const Song &refSong);
                    void removeSong(const unsigned uiIndex);
                    void setAlbumId(const unsigned uiAlbumId);
                    void setComments(const QString &sComments);
                    void setName(const QString &sName);
                    void setReleaseDate(const QDate &dtRelease);

                    Album &operator=(const Album &refCopy);
                    bool operator==(const Album &refOther) const;
                    bool operator!=(const Album &refOther) const;
                };
            }
        }
    }
}
