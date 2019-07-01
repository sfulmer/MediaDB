#include "MediaDetailsMoviePanel.h"
#include<QVBoxLayout>

using namespace net::draconia::mediadb::ui;

MediaDetailsMovieDetailsPanel *MediaDetailsMoviePanel::getDetailsPanel()
{
    if(mPnlDetails == nullptr)
        mPnlDetails = new MediaDetailsMovieDetailsPanel(this);

    return(mPnlDetails);
}

QVideoWidget *MediaDetailsMoviePanel::getMediaPlayer()
{
    if(mPlayMedia == nullptr)
        mPlayMedia = new QVideoWidget(this);

    return(mPlayMedia);
}

void MediaDetailsMoviePanel::initPanel()
{
    QLayout *loMovies = new QVBoxLayout(this);

    loMovies->addWidget(getDetailsPanel());
    loMovies->addWidget(getMediaPlayer());

    loMovies->setSpacing(2);

    setLayout(loMovies);
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
}

MediaDetailsMoviePanel::MediaDetailsMoviePanel(QWidget *parent)
    : QWidget(parent)
    , mPnlDetails(nullptr)
    , mPlayMedia(nullptr)
{
    initPanel();
}

QSize MediaDetailsMoviePanel::sizeHint() const
{
    return(QWidget::sizeHint());
}
