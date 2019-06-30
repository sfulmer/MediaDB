#pragma once

#include "MediaListButtonPanel.h"
#include <QListWidget>
#include <QWidget>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace ui
            {
                class MediaListPanel : public QWidget
                {
                    Q_OBJECT
                    MediaListButtonPanel *mPnlButtons;
                    QListWidget *mLstMedia;
                protected:
                    MediaListButtonPanel *getButtonPanel();
                    QListWidget *getMediaList();
                    void initPanel();
                public:
                    MediaListPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                };
            }
        }
    }
}
