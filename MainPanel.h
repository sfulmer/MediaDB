#pragma once

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
                    MediaListPanel *mPnlMediaList;
                protected:
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
