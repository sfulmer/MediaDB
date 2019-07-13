#pragma once

#include<QString>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dbo
            {
                class Collection
                {
                    unsigned muiCollectionId;
                    QString msName;
                public:
                    Collection();
                    Collection(const QString &sName);
                    Collection(const unsigned uiCollectionId, const QString &sName);
                    Collection(const Collection &refCopy);
                    ~Collection();

                     unsigned getCollectionId() const;
                     QString getName() const;
                     void setCollectionId(const unsigned uiCollectionId);
                     void setName(const QString &sName);

                     Collection &operator=(const Collection &refCopy);
                     bool operator==(const Collection &refOther);
                     bool operator!=(const Collection &refOther);
                };
            }
        }
    }
}
