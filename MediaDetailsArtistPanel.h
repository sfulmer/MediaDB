#pragma once

#include "MediaDetailsArtistButtonPanel.h"
#include<QLabel>
#include<QTableWidget>
#include<QWidget>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace ui
            {
                class MediaDetailsArtistPanel : public QWidget
                {
                    Q_OBJECT
                    QLabel *mLblArtists;
                    QTableWidget *mTblArtists;
                    MediaDetailsArtistButtonPanel *mPnlButtons;
                protected:
                    QLabel *getArtistsLabel();
                    QTableWidget *getArtistsTable();
                    MediaDetailsArtistButtonPanel *getButtonPanel();
                    void initPanel();
                public:
                    explicit MediaDetailsArtistPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                };
            }
        }
    }
}
