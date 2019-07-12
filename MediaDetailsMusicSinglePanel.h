#pragma once

#include "ListPanel.h"
#include "MediaDetailsMusicSingleDetailPanel.h"
#include<QGroupBox>

using net::draconia::ui::ListPanel;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace ui
            {
                class MediaDetailsMusicSinglePanel : public QGroupBox
                {
                    Q_OBJECT
                    ListPanel *mLstSingles;
                    MediaDetailsMusicSingleDetailPanel *mPnlDetails;
                protected:
                    MediaDetailsMusicSingleDetailPanel *getDetailsPanel();
                    ListPanel *getSinglesList();
                    void initPanel();
                public:
                    explicit MediaDetailsMusicSinglePanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                    void setDisabled(bool disable);
                };
            }
        }
    }
}
