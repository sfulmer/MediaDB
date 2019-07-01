#pragma once

#include "MediaDetailsDataPanel.h"
#include<QTabBar>
#include<QWidget>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace ui
            {
                class MediaDetailsPanel : public QWidget
                {
                    Q_OBJECT
                    MediaDetailsDataPanel *mPnlDetailsData;
                    QTabBar *mTabMediaTypes;
                protected:
                    MediaDetailsDataPanel *getDetailsData();
                    QTabBar *getMediaTypeTabs();
                    void initPanel();
                public:
                    explicit MediaDetailsPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                };
            }
        }
    }
}
