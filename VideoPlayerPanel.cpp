#include<QGraphicsEffect>
#include<QVBoxLayout>
#include "VideoPlayerPanel.h"

using namespace net::draconia::mediadb::ui;

QMediaPlayer *VideoPlayerPanel::getMediaPlayer()
{
    if(mObjMediaPlayer == nullptr)
        mObjMediaPlayer = new QMediaPlayer(this);

    return(mObjMediaPlayer);
}

QVideoWidget *VideoPlayerPanel::getVideoPanel()
{
    if(mPnlVideo == nullptr)
        {
        mPnlVideo = new QVideoWidget(this);

        mPnlVideo->setStyleSheet("border: 1px solid black;background-color: black;");
        }

    return(mPnlVideo);
}

void VideoPlayerPanel::initPanel()
{
    QLayout *loVideo = new QVBoxLayout(this);
    QSizePolicy szPolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    loVideo->addWidget(getVideoPanel());

    loVideo->setMargin(2);
    loVideo->setSpacing(0);

    szPolicy.setVerticalStretch(3);

    setLayout(loVideo);
    setSizePolicy(szPolicy);
}

VideoPlayerPanel::VideoPlayerPanel(QWidget *parent)
    : QWidget(parent)
    , mObjMediaPlayer(nullptr)
    , mPnlVideo(nullptr)
{
    initPanel();
}

QSize VideoPlayerPanel::sizeHint() const
{
    return(QWidget::sizeHint());
}

void VideoPlayerPanel::setDisabled(bool disable)
{
    getVideoPanel()->setDisabled(disable);
}
