#pragma once

#include "MediaDetailsPanel.h"
#include "MediaListPanel.h"
#include<QWidget>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace ui
            {
                class MainPanel : public QWidget
                {
                    Q_OBJECT
                    MediaDetailsPanel *mPnlMediaDetails;
                    MediaListPanel *mPnlMediaList;
                protected:
                    MediaDetailsPanel *getMediaDetailsPanel();
                    MediaListPanel *getMediaListPanel();
                    void initPanel();
                public:
                    explicit MainPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;

                signals:

                public slots:
                };

            }
        }
    }
}
