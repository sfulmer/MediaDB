#pragma once

#include "Observable.h"
#include<QDate>
#include<QDateTime>
#include<QList>
#include<QString>

using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace dbo
        {
            class Album;
            class Artist;
            class Book;
            class Media;
            class Movie;
            class Role;
            class RoleType;
            class Single;
            class Song;
            class TVEpisode;
            class TVSeason;
            class TVSeries;
            class TVSpecial;

            class Artist : public Observable
            {
                unsigned muiArtistId;
                QString msName;
                QList<Role> mLstRoles;
            protected:
                QList<Role> &getRolesInternal() const;
                void setRoles(const QList<Role> &lstRoles);
            public:
                Artist();
                Artist(const unsigned uiArtistId);
                Artist(const QString &sName);
                Artist(const unsigned uiArtistId, const QString &sName);
                Artist(const unsigned uiArtistId, const QString &sName, const QList<Role> &lstRoles);
                Artist(const Artist &refCopy);
                ~Artist();

                void addRole(const Role &refRole);
                unsigned getArtistId() const;
                QString &getName() const;
                const QList<Role> &getRoles() const;
                bool removeRole(const Role &refRole);
                void removeRole(const unsigned uiIndex);
                void setArtistId(const unsigned uiArtistId);
                void setName(const QString &sName);

                bool operator==(const Artist &refOther) const;
            };

            class Media : public Observable
            {
                unsigned muiMediaId;
                QDate mDtRelease;
                QList<Artist> mLstArtists;
                QString msFilePath, msName;
            protected:
                QList<Artist> &getArtistsInternal() const;
                void setArtists(const QList<Artist> &lstArtists);
            public:
                Media();
                Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease);
                Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear);
                Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                Media(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
                Media(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
                Media(const Media &refCopy);
                virtual ~Media();

                void addArtist(const Artist &refArtist);
                const QList<Artist> &getArtists() const;
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

                bool operator==(const Media &refOther) const;
            };

            class Book : public Media
            {
                unsigned muiBookId;
                QString msCollection, msComments;
            public:
                Book();
                Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease);
                Book(const unsigned uiMediaId, const QString &sName, const unsigned muiReleaseYear);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned muiReleaseYear);
                Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QString &sCollection);
                Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QString &sCollection);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QString &sCollection);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QString &sCollection);
                Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
                Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
                Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection);
                Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection);
                Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
                Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
                Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection);
                Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection);
                Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection);
                Book(const Book &refCopy);
                virtual ~Book();

                unsigned getBookId() const;
                QString &getCollection() const;
                QString &getComments() const;
                void setBookId(const unsigned uiBookId);
                void setCollection(const QString &sCollection);
                void setComments(const QString &sComments);
            };

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
                Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear);
                Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease);
                Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear);
                Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<QDateTime> &lstViewings);
                Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<QDateTime> &lstViewings);
                Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<QDateTime> &lstViewings);
                Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<QDateTime> &lstViewings);
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

                void addViewing(const QDateTime &dtViewing);
                unsigned getMovieId() const;
                QString &getComments() const;
                const QList<QDateTime> &getViewings() const;
                bool removeViewing(const QDateTime &dtViewing);
                void removeViewing(const unsigned uiIndex);
                void setComments(const QString &sComments);
                void setMovieId(const unsigned uiMovieId);
            };

            class NoMedia : public Media
            {
            public:
                NoMedia();
                NoMedia(const NoMedia &refCopy);
                virtual ~NoMedia();
            };

            class RoleType : public Observable
            {
                unsigned muiRoleTypeId;
                QString msRoleType;
            public:
                RoleType();
                RoleType(const unsigned uiRoleTypeId);
                RoleType(const QString &sRoleType);
                RoleType(const unsigned uiRoleTypeId, const QString &sRoleType);
                RoleType(const RoleType &refCopy);
                ~RoleType();

                unsigned getRoleTypeId() const;
                QString &getRoleType() const;
                void setRoleTypeId(const unsigned uiRoleTypeId);
                void setRoleType(const QString &sRoleType);

                RoleType &operator=(const RoleType &refOther);
                bool operator==(const RoleType &refOther) const;
            };

            class Role : public Observable
            {
                unsigned muiRoleId;
                Media *mPtrMedia;
                RoleType mObjRoleType;
            protected:
                NoMedia mObjNoMedia;
            public:
                Role();
                Role(const unsigned uiRoleId);
                Role(const Media &refMedia);
                Role(const RoleType &refRoleType);
                Role(const unsigned uiRoleId, const Media &refMedia);
                Role(const unsigned uiRoleId, const RoleType &refRoleType);
                Role(const unsigned uiRoleId, const Media &refMedia, const RoleType &refRoleType);
                Role(const Role &refCopy);
                ~Role();

                Media &getMedia() const;
                unsigned getRoleId() const;
                RoleType &getRoleType() const;
                void setMedia(const Media &refMedia);
                void setRoleId(const unsigned uiRoleId);
                void setRoleType(const RoleType &refRoleType);

                bool operator==(const Role &refOther) const;
            };

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

                QString &getComments() const;
                unsigned getSingleId() const;
                void setComments(const QString &sComments);
                void setSingleId(const unsigned uiSingleId);
            };

            class Song : public Single
            {
                Album &mRefAlbum;
                unsigned muiSongId;
            public:
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

                Album &getAlbum() const;
                unsigned getSongId() const;
                void setSongId(const unsigned uiSongId);

                Song &operator=(const Song &refOther);
            };

            class Album : public Observable
            {
            friend class Song;
                QList<Song> mLstSongs;
                QString msName;
                unsigned muiAlbumId;
            protected:
                void addSong(const Song &refSong);
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

                unsigned getAlbumId() const;
                QString &getName() const;
                const QList<Song> getSongs() const;
                bool removeSong(const Song &refSong);
                void removeSong(const unsigned uiIndex);
                void setAlbumId(const unsigned uiAlbumId);
                void setName(const QString &sName);
            };

            class TVEpisode : public Media
            {
                unsigned muiNumber, muiTVEpisodeId;
                QString msComments;
                TVSeason &mRefTVSeason;
            public:
                TVEpisode(TVSeason &refTVSeason);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned muiRelease);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned muiRelease);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned muiRelease);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                TVEpisode(TVSeason &refTVSeason, const unsigned uiMediaId, const unsigned uiTVEpisodeId, const unsigned uiNumber, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                TVEpisode(const TVEpisode &refCopy);
                virtual ~TVEpisode();

                QString &getComments() const;
                unsigned getNumber() const;
                TVSeason &getSeason() const;
                unsigned getTVEpisodeId() const;
                void setComments(const QString &sComments);
                void setNumber(const unsigned uiNumber);
                void setTVEpisodeId(const unsigned uiTVEpisodeId);

                TVEpisode &operator=(const TVEpisode &refOther);
            };

            class TVSeason : public Observable
            {
            friend class TVEpisode;
                unsigned muiSeasonId, muiNumber;
                QList<TVEpisode> mLstEpisodes;
                QString msComments;
                TVSeries &mRefTVSeries;
            protected:
                void addEpisode(const TVEpisode &refEpisode);
                QList<TVEpisode> &getEpisodesInternal() const;
                void setEpisodes(const QList<TVEpisode> &lstEpisodes);
            public:
                TVSeason(TVSeries &refTVSeries);
                TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId);
                TVSeason(TVSeries &refTVSeries, const QString &sComments);
                TVSeason(TVSeries &refTVSeries, const QList<TVEpisode> &lstEpisodes);
                TVSeason(TVSeries &refTVSeries, const QString &sComments, const QList<TVEpisode> &lstEpisodes);
                TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const unsigned uiNumber);
                TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const QString &sComments);
                TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const QList<TVEpisode> &lstEpisodes);
                TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const unsigned uiNumber, const QString &sComments);
                TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const unsigned uiNumber, const QList<TVEpisode> &lstEpisodes);
                TVSeason(TVSeries &refTVSeries, const unsigned uiSeasonId, const unsigned uiNumber, const QString &sComments, const QList<TVEpisode> &lstEpisodes);
                TVSeason(const TVSeason &refCopy);
                virtual ~TVSeason();

                QString &getComments() const;
                const QList<TVEpisode> getEpisodes() const;
                unsigned getNumber() const;
                unsigned getSeasonId() const;
                TVSeries &getSeries() const;
                bool removeEpisode(const TVEpisode &refEpisode);
                void removeEpisode(const unsigned uiIndex);
                void setComments(const QString &sComments);
                void setNumber(const unsigned uiNUmber);
                void setSeasonId(const unsigned uiSeasonId);

                TVSeason &operator=(const TVSeason &refOther);
                bool operator==(const TVSeason &refOther) const;
            };

            class TVSeries : public Observable
            {
            friend class TVSeason;
            friend class TVSpecial;
                unsigned muiTVSeriesId;
                QList<TVSeason> mLstSeasons;
                QList<TVSpecial> mLstSpecials;
                QString msComments, msName;
            protected:
                void addSeason(const TVSeason &refSeason);
                void addSpecial(const TVSpecial &refSpecial);
                QList<TVSeason> getSeasonsInternal() const;
                QList<TVSpecial> getSpecialsInternal() const;
                void setSeasons(const QList<TVSeason> &lstSeasons);
                void setSpecials(const QList<TVSpecial> &lstSpecials);
            public:
                TVSeries();
                TVSeries(const unsigned uiTVSeriesId);
                TVSeries(const QString &sName);
                TVSeries(const QList<TVSeason> &lstSeasons);
                TVSeries(const QList<TVSpecial> &lstSpecials);
                TVSeries(const unsigned uiTVSeriesId, const QString &sName);
                TVSeries(const unsigned uiTVSeriesId, const QList<TVSeason> &lstSeasons);
                TVSeries(const unsigned uiTVSeriesId, const QList<TVSpecial> &lstSpecials);
                TVSeries(const QString &sName, const QString &sComments);
                TVSeries(const QString &sName, const QList<TVSeason> &lstSeasons);
                TVSeries(const QString &sName, const QList<TVSpecial> &lstSpecials);
                TVSeries(const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials);
                TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QString &sComments);
                TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSeason> &lstSeasons);
                TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSpecial> &lstSpecials);
                TVSeries(const QString &sName, const QString &sComments, const QList<TVSeason> &lstSeasons);
                TVSeries(const QString &sName, const QString &sComments, const QList<TVSpecial> &lstSpecials);
                TVSeries(const QString &sName, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials);
                TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials);
                TVSeries(const unsigned uiTVSeriesId, const QString &sName, const QString &sComments, const QList<TVSeason> &lstSeasons, const QList<TVSpecial> &lstSpecials);
                TVSeries(const TVSeries &refCopy);
                virtual ~TVSeries();

                QString &getComments() const;
                QString &getName() const;
                const QList<TVSeason> getSeasons() const;
                const QList<TVSpecial> getSpecials() const;
                unsigned getTVSeriesId() const;
                bool removeSeason(const TVSeason &refSeason);
                void removeSeason(const unsigned uiIndex);
                bool removeSpecial(const TVSpecial &refSpecial);
                void removeSpecial(const unsigned uiIndex);
                void setComments(const QString &sComments);
                void setName(const QString &sName);
                void setTVSeriesId(const unsigned uiTVSeriesId);

                bool operator==(const TVSeries &refOther) const;
            };

            class TVSpecial : public Media
            {
                unsigned muiTVSpecialId;
                QString msComments;
                TVSeries &mRefTVSeries;
            public:
                TVSpecial(TVSeries &refTVSeries);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned muiRelease);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned muiRelease);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                TVSpecial(TVSeries &refTVSeries, const unsigned uiMediaId, const unsigned uiTVSpecialId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                TVSpecial(const TVSpecial &refCopy);
                virtual ~TVSpecial();

                QString &getComments() const;
                TVSeries &getSeries() const;
                unsigned getTVSpecialId() const;
                void setComments(const QString &sComments);
                void setTVSpecialId(const unsigned uiTVSpecialId);

                TVSpecial &operator=(const TVSpecial &refOther);
            };
        }
    }
}
