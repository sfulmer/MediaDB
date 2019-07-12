#include "BeanFactory.h"
#include "MediaDetailsMoviePanel.h"
#include<QVBoxLayout>
#include<iostream>

using namespace net::draconia::mediadb::ui;

QTextEdit *MediaDetailsMoviePanel::getCommentsField()
{
    if(mTxtComments == nullptr)
        {
        mTxtComments = new QTextEdit(this);

        mTxtComments->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        mTxtComments->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        mTxtComments->setWordWrapMode(QTextOption::WrapMode::WrapAtWordBoundaryOrAnywhere);
        }

    return(mTxtComments);
}

QLabel *MediaDetailsMoviePanel::getCommentsLabel()
{
    if(mLblComments == nullptr)
        mLblComments = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Comments:", false, getCommentsField());

    return(mLblComments);
}

FilePathFieldPanel *MediaDetailsMoviePanel::getFilePathField()
{
    if(mFldFilePath == nullptr)
        mFldFilePath = new FilePathFieldPanel(this);

    return(mFldFilePath);
}

QLabel *MediaDetailsMoviePanel::getFilePathLabel()
{
    if(mLblFilePath == nullptr)
        mLblFilePath = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "File Path:", false, getFilePathField());

    return(mLblFilePath);
}

QDateEdit *MediaDetailsMoviePanel::getReleaseDateField()
{
    if(mDtRelease == nullptr)
        {
        mDtRelease = new QDateEdit(this);

        mDtRelease->setFrame(true);
        }

    return(mDtRelease);
}

QLabel *MediaDetailsMoviePanel::getReleaseDatelabel()
{
    if(mLblRelease == nullptr)
        mLblRelease = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Release Date:", false, getReleaseDateField());

    return(mLblRelease);
}

QLabel *MediaDetailsMoviePanel::getViewingsLabel()
{
    if(mLblViewings == nullptr)
        mLblViewings = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Viewings:", false, getViewingsList());

    return(mLblViewings);
}

QListWidget *MediaDetailsMoviePanel::getViewingsList()
{
    if(mLstViewings == nullptr)
        {
        mLstViewings = new QListWidget(this);

        mLstViewings->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        mLstViewings->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        }

    return(mLstViewings);
}

void MediaDetailsMoviePanel::initPanel()
{
    QGridLayout *loDetails = new QGridLayout(this);

    loDetails->addWidget(getReleaseDatelabel(), 0, 0);
    loDetails->addWidget(getReleaseDateField(), 0, 1);
    loDetails->addWidget(getFilePathLabel(), 1, 0);
    loDetails->addWidget(getFilePathField(), 1, 1);
    loDetails->addWidget(getCommentsLabel(), 2, 0, 1, 2);
    loDetails->addWidget(getViewingsLabel(), 2, 2, 1, 2);
    loDetails->addWidget(getCommentsField(), 3, 0, 1, 2);
    loDetails->addWidget(getViewingsList(), 3, 2, 1, 2);

    loDetails->setSpacing(3);

    setLayout(loDetails);
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));
}

MediaDetailsMoviePanel::MediaDetailsMoviePanel(QWidget *parent)
    : QWidget(parent)
    , mFldFilePath(nullptr)
    , mDtRelease(nullptr)
    , mLblComments(nullptr)
    , mLblFilePath(nullptr)
    , mLblRelease(nullptr)
    , mLblViewings(nullptr)
    , mLstViewings(nullptr)
    , mTxtComments(nullptr)
{
    initPanel();
}

QSize MediaDetailsMoviePanel::sizeHint() const
{
    return(QWidget::sizeHint());
}

void MediaDetailsMoviePanel::setDisabled(bool disable)
{
    getCommentsField()->setDisabled(disable);
    getCommentsLabel()->setDisabled(disable);
    getFilePathField()->setDisabled(disable);
    getFilePathLabel()->setDisabled(disable);
    getReleaseDateField()->setDisabled(disable);
    getReleaseDatelabel()->setDisabled(disable);
    getViewingsList()->setDisabled(disable);
    getViewingsLabel()->setDisabled(disable);
}
