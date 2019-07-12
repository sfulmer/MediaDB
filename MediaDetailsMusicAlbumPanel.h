#pragma once

#include "ListPanel.h"
#include<QDateEdit>
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
                class MediaDetailsMusicAlbumPanel : public QGroupBox
                {
                    Q_OBJECT
                    ListPanel *mLstSongs;
                    QDateEdit *mDtRelease;
                    QLabel *mLblComments, *mLblReleaseDate;
                    QTextEdit *mTxtComments;
                protected:
                    QTextEdit *getCommentsField();
                    QLabel *getCommentsLabel();
                    QDateEdit *getReleaseDateField();
                    QLabel *getReleaseDateLabel();
                    ListPanel *getSongsList();
                    void initPanel();
                public:
                    explicit MediaDetailsMusicAlbumPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                    void setDisabled(bool disable);
                };
            }
        }
    }
}
