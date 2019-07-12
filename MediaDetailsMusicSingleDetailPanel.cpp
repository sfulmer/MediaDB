#include "BeanFactory.h"
#include "MediaDetailsMusicSingleDetailPanel.h"
#include<QGridLayout>

using namespace net::draconia::mediadb::ui;

using net::draconia::mediadb::BeanFactory;

QTextEdit *MediaDetailsMusicSingleDetailPanel::getCommentsField()
{
    if(mTxtComments == nullptr)
        mTxtComments = new QTextEdit(this);

    return(mTxtComments);
}

QLabel *MediaDetailsMusicSingleDetailPanel::getCommentsLabel()
{
    if(mLblComments == nullptr)
        mLblComments = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Comments:", false, getCommentsField());

    return(mLblComments);
}

FilePathFieldPanel *MediaDetailsMusicSingleDetailPanel::getFilePathField()
{
    if(mPnlFilePath == nullptr)
        mPnlFilePath = new FilePathFieldPanel(this);

    return(mPnlFilePath);
}

QLabel *MediaDetailsMusicSingleDetailPanel::getFilePathLabel()
{
    if(mLblFilePath == nullptr)
        mLblFilePath = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "File Path:", false, getFilePathField());

    return(mLblFilePath);
}

QLineEdit *MediaDetailsMusicSingleDetailPanel::getNameField()
{
    if(mTxtName == nullptr)
        {
        mTxtName = new QLineEdit(this);

        mTxtName->setFrame(true);
        }

    return(mTxtName);
}

QLabel *MediaDetailsMusicSingleDetailPanel::getNameLabel()
{
    if(mLblName == nullptr)
        mLblName = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Name:", false, getNameField());

    return(mLblName);
}

QDateEdit *MediaDetailsMusicSingleDetailPanel::getReleaseDateField()
{
    if(mDtRelease == nullptr)
        {
        mDtRelease = new QDateEdit(this);

        mDtRelease->setFrame(true);
        }

    return(mDtRelease);
}

QLabel *MediaDetailsMusicSingleDetailPanel::getReleaseDateLabel()
{
    if(mLblRelease == nullptr)
        mLblRelease = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Release Date:", false, getReleaseDateField());

    return(mLblRelease);
}

void MediaDetailsMusicSingleDetailPanel::initPanel()
{
    QGridLayout *loDetail = new QGridLayout(this);

    loDetail->addWidget(getNameLabel(), 0, 0);
    loDetail->addWidget(getNameField(), 0, 1);
    loDetail->addWidget(getReleaseDateLabel(), 1, 0);
    loDetail->addWidget(getReleaseDateField(), 1, 1);
    loDetail->addWidget(getFilePathLabel(), 2, 0);
    loDetail->addWidget(getFilePathField(), 2, 1);
    loDetail->addWidget(getCommentsLabel(), 3, 0, 1, 2);
    loDetail->addWidget(getCommentsField(), 4, 0, 1, 2);

    loDetail->setSpacing(2);

    setLayout(loDetail);
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
}

MediaDetailsMusicSingleDetailPanel::MediaDetailsMusicSingleDetailPanel(QWidget *parent)
    : QWidget(parent)
    , mPnlFilePath(nullptr)
    , mDtRelease(nullptr)
    , mLblComments(nullptr)
    , mLblFilePath(nullptr)
    , mLblName(nullptr)
    , mLblRelease(nullptr)
    , mTxtName(nullptr)
    , mTxtComments(nullptr)
{
    initPanel();
}

QSize MediaDetailsMusicSingleDetailPanel::sizeHint() const
{
    return(QWidget::size());
}

void MediaDetailsMusicSingleDetailPanel::setDisabled(bool disable)
{
    getNameField()->setDisabled(disable);
    getNameLabel()->setDisabled(disable);
    getCommentsField()->setDisabled(disable);
    getCommentsLabel()->setDisabled(disable);
    getFilePathField()->setDisabled(disable);
    getFilePathLabel()->setDisabled(disable);
    getReleaseDateField()->setDisabled(disable);
    getReleaseDateLabel()->setDisabled(disable);
}
