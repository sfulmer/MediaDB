#pragma once

#include "Observable.h"
#include "Role.h"
#include<QList>
#include<QString>

using net::draconia::util::Observable;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dbo
            {
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
                    Artist(const QString &sName, const QList<Role> &lstRoles);
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

                    Artist &operator=(const Artist &refOther);
                    bool operator==(const Artist &refOther) const;
                    bool operator!=(const Artist &refOther) const;
                };
            }
        }
    }
}
