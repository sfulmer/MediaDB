#pragma once

#include "MediaDetailsMovieDetailsPanel.h"
#include<QVideoWidget>
#include<QWidget>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace ui
            {
                class MediaDetailsMoviePanel : public QWidget
                {
                    Q_OBJECT
                    MediaDetailsMovieDetailsPanel *mPnlDetails;
                    QVideoWidget *mPlayMedia;
                protected:
                    MediaDetailsMovieDetailsPanel *getDetailsPanel();
                    QVideoWidget *getMediaPlayer();
                    void initPanel();
                public:
                    explicit MediaDetailsMoviePanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                };
            }
        }
    }
}
