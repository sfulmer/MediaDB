#pragma once

#include "Observable.h"
#include <QList>

using net::draconia::util::Observable;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            class MediaDBController;

            namespace model
            {
                class SettingsModel : public Observable
                {
                    MediaDBController &mRefController;
                    QList<QString> mLstURLs;
                public:
                    SettingsModel(const MediaDBController &refController);

                    MediaDBController &getController() const;
                };
            }
        }
    }
}
