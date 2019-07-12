#include "BeanFactory.h"
#include "MediaDetailsMusicAlbumPanel.h"
#include<QGridLayout>

using namespace net::draconia::mediadb::ui;

QTextEdit *MediaDetailsMusicAlbumPanel::getCommentsField()
{
    if(mTxtComments == nullptr)
        mTxtComments = new QTextEdit(this);

    return(mTxtComments);
}

QLabel *MediaDetailsMusicAlbumPanel::getCommentsLabel()
{
    if(mLblComments == nullptr)
        mLblComments = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Comments:", false, getCommentsField());

    return(mLblComments);
}

QDateEdit *MediaDetailsMusicAlbumPanel::getReleaseDateField()
{
    if(mDtRelease == nullptr)
        mDtRelease = new QDateEdit(this);

    return(mDtRelease);
}

QLabel *MediaDetailsMusicAlbumPanel::getReleaseDateLabel()
{
    if(mLblReleaseDate == nullptr)
        mLblReleaseDate = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Release Date:", false, getReleaseDateField());

    return(mLblReleaseDate);
}

ListPanel *MediaDetailsMusicAlbumPanel::getSongsList()
{
    if(mLstSongs == nullptr)
        mLstSongs = new ListPanel(tr("Songs:"), this);

    return(mLstSongs);
}

void MediaDetailsMusicAlbumPanel::initPanel()
{
    QGridLayout *loAlbum = new QGridLayout(this);

    loAlbum->addWidget(getReleaseDateLabel(), 0, 0);
    loAlbum->addWidget(getReleaseDateField(), 0, 1);
    loAlbum->addWidget(getCommentsLabel(), 1, 0, 1, 2);
    loAlbum->addWidget(getCommentsField(), 2, 0, 1, 2);
    loAlbum->addWidget(getSongsList(), 3, 0, 1, 2);

    loAlbum->setSpacing(2);

    setLayout(loAlbum);
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
}

MediaDetailsMusicAlbumPanel::MediaDetailsMusicAlbumPanel(QWidget *parent)
    : QGroupBox(tr("Album:"), parent)
    , mLstSongs(nullptr)
    , mDtRelease(nullptr)
    , mLblComments(nullptr)
    , mLblReleaseDate(nullptr)
    , mTxtComments(nullptr)
{
    initPanel();
}

QSize MediaDetailsMusicAlbumPanel::sizeHint() const
{
    return(QGroupBox::sizeHint());
}

void MediaDetailsMusicAlbumPanel::setDisabled(bool disable)
{
    getCommentsField()->setDisabled(disable);
    getCommentsLabel()->setDisabled(disable);
    getReleaseDateField()->setDisabled(disable);
    getReleaseDateLabel()->setDisabled(disable);
    getSongsList()->setDisabled(disable);
}
