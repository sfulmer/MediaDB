#pragma once

#include "Album.h"
#include "Artist.h"
#include<QList>
#include<QString>
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
                class AlbumDAO
                {
                public:
                    virtual ~AlbumDAO();

                    virtual Album getById(const unsigned uiAlbumId) const = 0;
                    virtual Album getByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const = 0;
                    virtual Album getBySong(const Song &refSong) const = 0;
                    virtual QList<Album> list() const = 0;
                    virtual QList<Album> listByArtist(const Artist &refArtist) const = 0;
                    virtual QList<Album> listByName(const QString &sName) const = 0;
                    virtual QList<Album> listByWordInComments(const QString &sWord) const = 0;
                    virtual bool remove(const Album &refToRemove) const = 0;
                    virtual Album &save(const Album &refToSave) const = 0;
                };
            }
        }
    }
}
