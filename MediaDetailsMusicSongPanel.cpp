#include "BeanFactory.h"
#include "MediaDetailsMusicSongPanel.h"
#include<QGridLayout>

using namespace net::draconia::mediadb::ui;

using net::draconia::mediadb::BeanFactory;

QTextEdit *MediaDetailsMusicSongPanel::getCommentsField()
{
    if(mTxtComments == nullptr)
        mTxtComments = new QTextEdit(this);

    return(mTxtComments);
}

QLabel *MediaDetailsMusicSongPanel::getCommentsLabel()
{
    if(mLblComments == nullptr)
        mLblComments = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Comments:", false, getCommentsField());

    return(mLblComments);
}

FilePathFieldPanel *MediaDetailsMusicSongPanel::getFilePathField()
{
    if(mPnlFilePath == nullptr)
        mPnlFilePath = new FilePathFieldPanel(this);

    return(mPnlFilePath);
}

QLabel *MediaDetailsMusicSongPanel::getFilePathLabel()
{
    if(mLblFilePath == nullptr)
        mLblFilePath = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "File Path:", false, getFilePathField());

    return(mLblFilePath);
}

QLineEdit *MediaDetailsMusicSongPanel::getNameField()
{
    if(mTxtName == nullptr)
        {
        mTxtName = new QLineEdit(this);

        mTxtName->setFrame(true);
        }

    return(mTxtName);
}

QLabel *MediaDetailsMusicSongPanel::getNameLabel()
{
    if(mLblName == nullptr)
        mLblName = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Name:", false, getNameField());

    return(mLblName);
}

void MediaDetailsMusicSongPanel::initPanel()
{
    QGridLayout *loSong = new QGridLayout(this);

    loSong->addWidget(getNameLabel(), 0, 0);
    loSong->addWidget(getNameField(), 0, 1);
    loSong->addWidget(getFilePathLabel(), 1, 0);
    loSong->addWidget(getFilePathField(), 1, 1);
    loSong->addWidget(getCommentsLabel(), 2, 0, 1, 2);
    loSong->addWidget(getCommentsField(), 3, 0, 1, 2);

    loSong->setSpacing(2);

    setLayout(loSong);
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
}

MediaDetailsMusicSongPanel::MediaDetailsMusicSongPanel(QWidget *parent)
    : QGroupBox("Song", parent)
    , mPnlFilePath(nullptr)
    , mLblComments(nullptr)
    , mLblFilePath(nullptr)
    , mLblName(nullptr)
    , mTxtName(nullptr)
    , mTxtComments(nullptr)
{
    initPanel();
}

QSize MediaDetailsMusicSongPanel::sizeHint() const
{
    return(QGroupBox::sizeHint());
}

void MediaDetailsMusicSongPanel::setDisabled(bool disable)
{
    getCommentsField()->setDisabled(disable);
    getCommentsLabel()->setDisabled(disable);
    getFilePathField()->setDisabled(disable);
    getFilePathLabel()->setDisabled(disable);
    getNameField()->setDisabled(disable);
    getNameLabel()->setDisabled(disable);
}
