#include "MediaDetailsPanel.h"

using namespace net::draconia::mediadb::ui;

QLabel *MediaDetailsPanel::getFilePathLabel()
{
    if(mLblFilePath == nullptr)
        {
        mLblFilePath = new QLabel("File &Path:", this);

        mLblFilePath->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        mLblFilePath->setBuddy(nullptr);
        }

    return(mLblFilePath);
}

QMediaPlayer *MediaDetailsPanel::getMediaPlayer()
{
    if(mPlayMedia == nullptr)
        mPlayMedia = new QMediaPlayer(this);

    return(mPlayMedia);
}

QLineEdit *MediaDetailsPanel::getNameField()
{
    if(mTxtName == nullptr)
        {
        mTxtName = new QLineEdit(this);

        mTxtName->setReadOnly(true);
        }

    return(mTxtName);
}

QLabel *MediaDetailsPanel::getNameLabel()
{
    if(mLblName == nullptr)
        {
        mLblName = new QLabel("&Name: ", this);

        mLblName->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        mLblName->setBuddy(getNameField());
        }

    return(mLblName);
}

QDateEdit *MediaDetailsPanel::getReleaseDateField()
{
    if(mDtRelease == nullptr)
        {
        mDtRelease = new QDateEdit(this);

        mDtRelease->setReadOnly(true);
        }

    return(mDtRelease);
}

QLabel *MediaDetailsPanel::getReleaseDateLabel()
{
    if(mLblReleaseDate == nullptr)
        {
        mLblReleaseDate = new QLabel("Release &Date:", this);

        mLblReleaseDate->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        }

    return(mLblReleaseDate);
}

void MediaDetailsPanel::initPanel()
{
    //
}

MediaDetailsPanel::MediaDetailsPanel(QWidget *parent)
    : QWidget(parent)
    , mDtRelease(nullptr)
    , mLblFilePath(nullptr)
    , mLblName(nullptr)
    , mLblReleaseDate(nullptr)
    , mTxtName(nullptr)
    , mPlayMedia(nullptr)
{
    initPanel();
}

QSize MediaDetailsPanel::sizeHint() const
{
    return(QWidget::sizeHint());
}
