#pragma once

#include "Album.h"
#include "Song.h"

using net::draconia::mediadb::dbo::Album;
using net::draconia::mediadb::dbo::Artist;
using net::draconia::mediadb::dbo::Song;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                class SongDAO
                {
                public:
                    virtual ~SongDAO();

                    virtual Song getById(const unsigned uiSongId) const = 0;
                    virtual Song getByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const = 0;
                    virtual QList<Song> list() const = 0;
                    virtual QList<Song> listByAlbum(const Album &refAlbum) const = 0;
                    virtual QList<Song> listByArtist(const Artist &refArtist) const = 0;
                    virtual QList<Song> listByName(const QString &sName) const = 0;
                    virtual QList<Song> listByWordInComments(const QString &sWord) const = 0;
                    virtual bool remove(const Song &refToRemove) const = 0;
                    virtual Song &save(const Song &refToSave) const = 0;
                };
            }
        }
    }
}
