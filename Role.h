#pragma once

#include<QSharedPointer>
#include "RoleType.h"

using net::draconia::util::Observable;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dbo
            {
                class Artist;
                class Media;

                class Role : public Observable
                {
                    unsigned muiRoleId;
                    QSharedPointer<Artist> mPtrArtist;
                    QSharedPointer<Media> mPtrMedia;
                    QSharedPointer<RoleType> mPtrRoleType;
                    QString msName;
                public:
                    Role();
                    Role(const unsigned uiRoleId);
                    Role(const Artist &refArtist);
                    Role(const Media &refMedia);
                    Role(const RoleType &refRoleType);
                    Role(const QString &sName);
                    Role(const unsigned uiRoleId, const Artist &refArtist);
                    Role(const unsigned uiRoleId, const Media &refMedia);
                    Role(const unsigned uiRoleId, const RoleType &refRoleType);
                    Role(const unsigned uiRoleId, const QString &sName);
                    Role(const Artist &refArtist, const Media &refMedia);
                    Role(const Artist &refArtist, const RoleType &refRoleType);
                    Role(const Artist &refArtist, const QString &sName);
                    Role(const Media &refMedia, const RoleType &refRoleType);
                    Role(const Media &refMedia, const QString &sName);
                    Role(const RoleType &refRoleType, const QString &sName);
                    Role(const unsigned uiRoleId, const Artist &refArtist, const Media &refMedia);
                    Role(const unsigned uiRoleId, const Artist &refArtist, const RoleType &refRoleType);
                    Role(const unsigned uiRoleId, const Artist &refArtist, const QString &sName);
                    Role(const unsigned uiRoleId, const Media &refMedia, const RoleType &refRoleType);
                    Role(const unsigned uiRoleId, const Media &refMedia, const QString &sName);
                    Role(const unsigned uiRoleId, const RoleType &refRoleType, const QString &sName);
                    Role(const Artist &refArtist, const Media &refMedia, const QString &sName);
                    Role(const Artist &refArtist, const RoleType &refRoleType, const QString &sName);
                    Role(const Media &refMedia, const RoleType &refRoleType, const QString &sName);
                    Role(const unsigned uiRoleId, const Artist &refArtist, const Media &refMedia, const QString &sName);
                    Role(const unsigned uiRoleId, const Artist &refArtist, const RoleType &refRoleType, const QString &sName);
                    Role(const unsigned uiRoleId, const Media &refMedia, const RoleType &refRoleType, const QString &sName);
                    Role(const Artist &refArtist, const Media &refMedia, const RoleType &refRoleType, const QString &sName);
                    Role(const unsigned uiRoleId, const Artist &refArtist, const Media &refMedia, const RoleType &refRoleType, const QString &sName);
                    Role(const Role &refCopy);
                    ~Role();

                    Artist getArtist() const;
                    Media getMedia() const;
                    QString getName() const;
                    unsigned getRoleId() const;
                    RoleType getRoleType() const;
                    void setArtist(const Artist &refArtist);
                    void setMedia(const Media &refMedia);
                    void setName(const QString &sName);
                    void setRoleId(const unsigned uiRoleId);
                    void setRoleType(const RoleType &refRoleType);

                    Role &operator=(const Role &refCopy);
                    bool operator==(const Role &refOther) const;
                    bool operator!=(const Role &refOther) const;
                };
            }
        }
    }
}
