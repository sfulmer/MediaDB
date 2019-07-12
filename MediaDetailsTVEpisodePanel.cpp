#include "BeanFactory.h"
#include "MediaDetailsTVEpisodePanel.h"
#include<QGridLayout>

using namespace net::draconia::mediadb::ui;

using net::draconia::mediadb::BeanFactory;

QTextEdit *MediaDetailsTVEpisodePanel::getCommentsField()
{
    if(mTxtComments == nullptr)
        {
        mTxtComments = new QTextEdit(this);
        }

    return(mTxtComments);
}

QLabel *MediaDetailsTVEpisodePanel::getCommentsLabel()
{
    if(mLblComments == nullptr)
        mLblComments = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Comments:", false, getCommentsField());

    return(mLblComments);
}

FilePathFieldPanel *MediaDetailsTVEpisodePanel::getFilePathField()
{
    if(mPnlFilePath == nullptr)
        mPnlFilePath = new FilePathFieldPanel(this);

    return(mPnlFilePath);
}

QLabel *MediaDetailsTVEpisodePanel::getFilePathLabel()
{
    if(mLblFilePath == nullptr)
        mLblFilePath = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "File Path:", false, getFilePathField());

    return(mLblFilePath);
}

QLineEdit *MediaDetailsTVEpisodePanel::getNameField()
{
    if(mTxtName == nullptr)
        {
        mTxtName = new QLineEdit(this);

        mTxtName->setFrame(true);
        }

    return(mTxtName);
}

QLabel *MediaDetailsTVEpisodePanel::getNameLabel()
{
    if(mLblName == nullptr)
        mLblName = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Name:", false, getNameField());

    return(mLblName);
}

QSpinBox *MediaDetailsTVEpisodePanel::getNumberField()
{
    if(mSpnNumber == nullptr)
        {
        mSpnNumber = new QSpinBox(this);

        mSpnNumber->setMaximum(50);
        mSpnNumber->setMinimum(1);
        }

    return(mSpnNumber);
}

QLabel *MediaDetailsTVEpisodePanel::getNumberLabel()
{
    if(mLblNumber == nullptr)
        mLblNumber = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Number:", false, getNumberField());

    return(mLblNumber);
}

QDateEdit *MediaDetailsTVEpisodePanel::getReleaseDateField()
{
    if(mDtRelease == nullptr)
        {
        mDtRelease = new QDateEdit(this);

        mDtRelease->setFrame(true);
        }

    return(mDtRelease);
}

QLabel *MediaDetailsTVEpisodePanel::getReleaseDateLabel()
{
    if(mLblReleaseDate == nullptr)
        mLblReleaseDate = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Release Date:", false, getReleaseDateField());

    return(mLblReleaseDate);
}

void MediaDetailsTVEpisodePanel::initPanel()
{
    QGridLayout *loEpisode = new QGridLayout(this);

    loEpisode->addWidget(getNameLabel(), 0, 0);
    loEpisode->addWidget(getNameField(), 0, 1);
    loEpisode->addWidget(getNumberLabel(), 1, 0);
    loEpisode->addWidget(getNumberField(), 1, 1);
    loEpisode->addWidget(getReleaseDateLabel(), 2, 0);
    loEpisode->addWidget(getReleaseDateField(), 2, 1);
    loEpisode->addWidget(getFilePathLabel(), 3, 0);
    loEpisode->addWidget(getFilePathField(), 3, 1);
    loEpisode->addWidget(getCommentsLabel(), 4, 0, 1, 2);
    loEpisode->addWidget(getCommentsField(), 5, 0, 1, 2);

    loEpisode->setSpacing(2);

    setLayout(loEpisode);
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
}

MediaDetailsTVEpisodePanel::MediaDetailsTVEpisodePanel(QWidget *parent)
    : QGroupBox(tr("Episode"), parent)
    , mPnlFilePath(nullptr)
    , mDtRelease(nullptr)
    , mLblComments(nullptr)
    , mLblFilePath(nullptr)
    , mLblName(nullptr)
    , mLblNumber(nullptr)
    , mLblReleaseDate(nullptr)
    , mTxtName(nullptr)
    , mSpnNumber(nullptr)
    , mTxtComments(nullptr)
{
    initPanel();
}

QSize MediaDetailsTVEpisodePanel::sizeHint() const
{
    return(QGroupBox::sizeHint());
}

void MediaDetailsTVEpisodePanel::setDisabled(bool disable)
{
    getCommentsField()->setDisabled(disable);
    getCommentsLabel()->setDisabled(disable);
    getNameField()->setDisabled(disable);
    getNameLabel()->setDisabled(disable);
    getNumberField()->setDisabled(disable);
    getNumberLabel()->setDisabled(disable);
}
