#pragma once

#include<QMediaPlayer>
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
                class VideoPlayerPanel : public QWidget
                {
                    Q_OBJECT
                    QMediaPlayer *mObjMediaPlayer;
                    QVideoWidget *mPnlVideo;
                protected:
                    QMediaPlayer *getMediaPlayer();
                    QVideoWidget *getVideoPanel();
                    void initPanel();
                public:
                    explicit VideoPlayerPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;

                signals:

                public slots:
                    void setDisabled(bool disable);
                };
            }
        }
    }
}
