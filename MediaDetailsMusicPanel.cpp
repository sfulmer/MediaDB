#include "MediaDetailsMusicPanel.h"
#include<QGridLayout>

using namespace net::draconia::mediadb::ui;

MediaDetailsMusicAlbumPanel *MediaDetailsMusicPanel::getAlbumPanel()
{
    if(mPnlAlbum == nullptr)
        mPnlAlbum = new MediaDetailsMusicAlbumPanel(this);

    return(mPnlAlbum);
}

MediaDetailsMusicSinglePanel *MediaDetailsMusicPanel::getSinglePanel()
{
    if(mPnlSingle == nullptr)
        mPnlSingle = new MediaDetailsMusicSinglePanel(this);

    return(mPnlSingle);
}

MediaDetailsMusicSongPanel *MediaDetailsMusicPanel::getSongPanel()
{
    if(mPnlSong == nullptr)
        mPnlSong = new MediaDetailsMusicSongPanel(this);

    return(mPnlSong);
}

void MediaDetailsMusicPanel::initPanel()
{
    QGridLayout *loMusic = new QGridLayout(this);

    loMusic->addWidget(getAlbumPanel(), 0, 0);
    loMusic->addWidget(getSongPanel(), 0, 1);
    loMusic->addWidget(getSinglePanel(), 1, 0, 1, 2);

    loMusic->setSpacing(2);

    setLayout(loMusic);
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
}

MediaDetailsMusicPanel::MediaDetailsMusicPanel(QWidget *parent)
    : QWidget(parent)
    , mPnlAlbum(nullptr)
    , mPnlSingle(nullptr)
    , mPnlSong(nullptr)
{
    initPanel();
}


QSize MediaDetailsMusicPanel::sizeHint() const
{
    return(QWidget::sizeHint());
}

void MediaDetailsMusicPanel::setDisabled(bool disable)
{
    getAlbumPanel()->setDisabled(disable);
    getSinglePanel()->setDisabled(disable);
    getSongPanel()->setDisabled(disable);
}
