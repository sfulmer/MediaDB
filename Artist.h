#pragma once

#include "Media.h"
#include<QList>
#include<QString>

namespace net
{
    namespace draconia
    {
        class Artist
        {
            unsigned muiArtistId;
            QString msName;
            QList<Media> mLstRoles;
        protected:
            QList<Media> &getRolesInternal() const;
            void setRoles(const QList<Media> &lstRoles);
        public:
            Artist();
            Artist(const unsigned uiArtistId);
            Artist(const QString &sName);
            Artist(const unsigned uiArtistId, const QString &sName);
            Artist(const unsigned uiArtistId, const QString &sName, const QList<Media> &lstRoles);
            Artist(const Artist &refCopy);
            ~Artist();

            void addRole(const Media &refMedia);
            unsigned getArtistId() const;
            QString &getName() const;
            const QList<Media> &getRoles() const;
            bool removeRole(const Media &refMedia);
            void removeRole(const unsigned uiIndex);
            void setArtistId(const unsigned uiArtistId);
            void setName(const QString &sName);
        };
    }
}
