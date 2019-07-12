#pragma once

#include "MediaDetailsMusicAlbumPanel.h"
#include "MediaDetailsMusicSinglePanel.h"
#include "MediaDetailsMusicSongPanel.h"
#include <QWidget>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace ui
            {
                class MediaDetailsMusicPanel : public QWidget
                {
                    Q_OBJECT
                    MediaDetailsMusicAlbumPanel *mPnlAlbum;
                    MediaDetailsMusicSinglePanel *mPnlSingle;
                    MediaDetailsMusicSongPanel *mPnlSong;
                protected:
                    MediaDetailsMusicAlbumPanel *getAlbumPanel();
                    MediaDetailsMusicSinglePanel *getSinglePanel();
                    MediaDetailsMusicSongPanel *getSongPanel();
                    void initPanel();
                public:
                    explicit MediaDetailsMusicPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                    void setDisabled(bool disable);
                };
            }
        }
    }
}
