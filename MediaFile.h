#pragma once

#include "Observable.h"
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
                class MediaFile : public Observable
                {
                    QString msFilePath;
                public:
                    MediaFile();
                    MediaFile(const QString &sFilePath);
                    MediaFile(const MediaFile &refCopy);
                    ~MediaFile();

                    QString getFilePath() const;
                    void setFilePath(const QString &sFilePath);

                    MediaFile &operator=(const MediaFile &refCopy);
                    bool operator==(const MediaFile &refOther) const;
                    bool operator!=(const MediaFile &refOther) const;
                };
            }
        }
    }
}
