#pragma once

#include "MediaDetailsDataPanel.h"
#include<QTabWidget>
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
                    QTabWidget *mTabMediaTypes;
                protected:
                    MediaDetailsDataPanel *getDetailsData();
                    QTabWidget *getMediaTypeTabs();
                    void initPanel();
                public:
                    explicit MediaDetailsPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                    void setDisabled(bool disable);
                };
            }
        }
    }
}
