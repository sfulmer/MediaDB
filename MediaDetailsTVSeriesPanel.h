#pragma once

#include "ListPanel.h"
#include<QGroupBox>
#include<QLabel>
#include<QTextEdit>

using net::draconia::ui::ListPanel;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace ui
            {
                class MediaDetailsTVSeriesPanel : public QGroupBox
                {
                    Q_OBJECT
                    ListPanel *mPnlSeasons, *mPnlSpecials;
                    QLabel *mLblComments;
                    QTextEdit *mTxtComments;
                protected:
                    QTextEdit *getCommentsField();
                    QLabel *getCommentsLabel();
                    ListPanel *getSeasonList();
                    ListPanel *getSpecialsList();
                    void initPanel();
                public:
                    explicit MediaDetailsTVSeriesPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:
                public slots:
                    void setDisabled(bool disable);
                };
            }
        }
    }
}
