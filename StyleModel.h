#pragma once

#include "GeneralModel.h"
#include "Observable.h"
#include <QString>

using net::draconia::util::Observable;
using net::draconia::util::Observer;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            class MediaDBController;

            namespace model
            {
                class StyleModel : public Observable, Observer
                {
                    GeneralModel mObjGeneralModel;
                    MediaDBController &mRefController;

                    QString msWindowBackground;
                public:
                    StyleModel(MediaDBController &refController);

                    MediaDBController &getController() const;
                    GeneralModel &getGeneral() const;
                    const QString &getWindowBackground() const;
                    void setWindowBackground(const QString &sWindowBackground);
                    virtual void update(const Observable &refObservable, const QString &sProperty);
                };
            }
        }
    }
}
