#pragma once

#include "ListPanel.h"
#include "MediaDetailsPanel.h"
#include<QWidget>

using net::draconia::ui::ListPanel;

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
                    ListPanel *mPnlMediaList;
                protected:
                    MediaDetailsPanel *getMediaDetailsPanel();
                    ListPanel *getMediaListPanel();
                    void initPanel();
                public:
                    explicit MainPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;

                signals:

                public slots:
                    void setDisabled(bool disable);
                };

            }
        }
    }
}
