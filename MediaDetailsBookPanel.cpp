#include "BeanFactory.h"
#include "MediaDetailsBookPanel.h"
#include<QGridLayout>

using namespace net::draconia::mediadb::ui;

using net::draconia::mediadb::BeanFactory;

QComboBox *MediaDetailsBookPanel::getCollectionField()
{
    if(mCboCollection == nullptr)
        {
        mCboCollection = new QComboBox(this);

        mCboCollection->setDuplicatesEnabled(false);
        mCboCollection->setEditable(true);
        mCboCollection->setFrame(true);
        mCboCollection->setInsertPolicy(QComboBox::InsertPolicy::InsertAlphabetically);
        }

    return(mCboCollection);
}

QLabel *MediaDetailsBookPanel::getCollectionLabel()
{
    if(mLblCollection == nullptr)
        mLblCollection = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Collection:", false, getCollectionField());

    return(mLblCollection);
}

QTextEdit *MediaDetailsBookPanel::getCommentsField()
{
    if(mTxtComments == nullptr)
        mTxtComments = new QTextEdit(this);

    return(mTxtComments);
}

QLabel *MediaDetailsBookPanel::getCommentsLabel()
{
    if(mLblComments == nullptr)
        mLblComments = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Comments:", false, getCommentsField());

    return(mLblComments);
}

FilePathFieldPanel *MediaDetailsBookPanel::getFilePathField()
{
    if(mPnlFilePath == nullptr)
        mPnlFilePath = new FilePathFieldPanel(this);

    return(mPnlFilePath);
}

QLabel *MediaDetailsBookPanel::getFilePathLabel()
{
    if(mLblFilePath == nullptr)
        mLblFilePath = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "File Path:", false, getFilePathField());

    return(mLblFilePath);
}

QDateEdit *MediaDetailsBookPanel::getReleaseDateField()
{
    if(mDtRelease == nullptr)
        {
        mDtRelease = new QDateEdit(this);

        mDtRelease->setFrame(true);
        }

    return(mDtRelease);
}

QLabel *MediaDetailsBookPanel::getReleaseDateLabel()
{
    if(mLblReleaseDate == nullptr)
        mLblReleaseDate = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Release Date:", false, getReleaseDateField());

    return(mLblReleaseDate);
}

void MediaDetailsBookPanel::initPanel()
{
    QGridLayout *loBook = new QGridLayout(this);

    loBook->addWidget(getReleaseDateLabel(), 0, 0);
    loBook->addWidget(getReleaseDateField(), 0, 1);
    loBook->addWidget(getFilePathLabel(), 1, 0);
    loBook->addWidget(getFilePathField(), 1, 1);
    loBook->addWidget(getCollectionLabel(), 2, 0);
    loBook->addWidget(getCollectionField(), 2, 1);
    loBook->addWidget(getCommentsLabel(), 3, 0, 1, 2);
    loBook->addWidget(getCommentsField(), 4, 0, 1, 2);

    loBook->setSpacing(2);

    setLayout(loBook);
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
}

MediaDetailsBookPanel::MediaDetailsBookPanel(QWidget *parent)
    : QWidget(parent)
    , mPnlFilePath(nullptr)
    , mCboCollection(nullptr)
    , mDtRelease(nullptr)
    , mLblCollection(nullptr)
    , mLblComments(nullptr)
    , mLblFilePath(nullptr)
    , mLblReleaseDate(nullptr)
    , mTxtComments(nullptr)
{
    initPanel();
}

QSize MediaDetailsBookPanel::sizeHint() const
{
    return(QWidget::sizeHint());
}

void MediaDetailsBookPanel::setDisabled(bool disable)
{
    getCollectionField()->setDisabled(disable);
    getCollectionLabel()->setDisabled(disable);
    getCommentsField()->setDisabled(disable);
    getCommentsLabel()->setDisabled(disable);
    getFilePathField()->setDisabled(disable);
    getFilePathLabel()->setDisabled(disable);
    getReleaseDateField()->setDisabled(disable);
    getReleaseDateLabel()->setDisabled(disable);
}
