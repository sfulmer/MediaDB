#pragma once

#include "SettingsModel.h"
#include "StyleModel.h"

using net::draconia::mediadb::model::SettingsModel;
using net::draconia::mediadb::model::StyleModel;

namespace net
{
    namespace draconia
    {
        class MediaDBApp;

        namespace mediadb
        {
            class MediaDBController
            {
                MediaDBApp &mRefApp;
                SettingsModel mObjSettingsModel;
                StyleModel mObjStyleModel;
            public:
                MediaDBController(const MediaDBApp &refApp);

                MediaDBApp &getApplication() const;
                SettingsModel &getSettingsModel() const;
                StyleModel &getStyleModel() const;
            };
        }
    }
}
