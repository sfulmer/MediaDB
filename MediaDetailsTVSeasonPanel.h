#pragma once

#include "ListPanel.h"
#include<QGroupBox>
#include<QLabel>
#include<QListWidget>
#include<QSpinBox>
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
                class MediaDetailsTVSeasonPanel : public QGroupBox
                {
                    Q_OBJECT

                    ListPanel *mPnlEpisodes;
                    QLabel *mLblComments, *mLblNumber;
                    QSpinBox *mSpnNumber;
                    QTextEdit *mTxtComments;
                protected:
                    QTextEdit *getCommentsField();
                    QLabel *getCommentsLabel();
                    ListPanel *getEpisodesList();
                    QSpinBox *getNumberField();
                    QLabel *getNumberLabel();
                    void initPanel();
                public:
                    explicit MediaDetailsTVSeasonPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                    void setDisabled(bool disable);
                };
            }
        }
    }
}
