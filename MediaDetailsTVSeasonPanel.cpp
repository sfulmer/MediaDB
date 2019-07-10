#include "MediaDetailsTVSeasonPanel.h"
#include<QGridLayout>

using namespace net::draconia::mediadb::ui;

QTextEdit *MediaDetailsTVSeasonPanel::getCommentsField()
{
    if(mTxtComments == nullptr)
        mTxtComments = new QTextEdit(this);

    return(mTxtComments);
}

QLabel *MediaDetailsTVSeasonPanel::getCommentsLabel()
{
    if(mLblComments == nullptr)
        {
        mLblComments = new QLabel("Comments:", this);

        mLblComments->setAutoFillBackground(false);
        mLblComments->setBuddy(getCommentsField());
        mLblComments->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        }

    return(mLblComments);
}

ListPanel *MediaDetailsTVSeasonPanel::getEpisodesList()
{
    if(mPnlEpisodes == nullptr)
        {
        mPnlEpisodes = new ListPanel("Episodes:", true, this);

        mPnlEpisodes->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        mPnlEpisodes->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        }

    return(mPnlEpisodes);
}

QSpinBox *MediaDetailsTVSeasonPanel::getNumberField()
{
    if(mSpnNumber == nullptr)
        {
        mSpnNumber = new QSpinBox(this);

        mSpnNumber->setMinimum(1);
        mSpnNumber->setMaximum(100);
        mSpnNumber->setValue(1);
        }

    return(mSpnNumber);
}

QLabel *MediaDetailsTVSeasonPanel::getNumberLabel()
{
    if(mLblNumber == nullptr)
        {
        mLblNumber = new QLabel("Number:", this);

        mLblNumber->setAutoFillBackground(false);
        mLblNumber->setBuddy(getNumberField());
        mLblNumber->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        }

    return(mLblNumber);
}

void MediaDetailsTVSeasonPanel::initPanel()
{
    QGridLayout *loSeason = new QGridLayout(this);

    loSeason->addWidget(getNumberLabel(), 0, 0, 1, 1);
    loSeason->addWidget(getNumberField(), 0, 1, 1, 1);
    loSeason->addWidget(getCommentsLabel(), 1, 0, 1, 2);
    loSeason->addWidget(getCommentsField(), 2, 0, 1, 2);
    loSeason->addWidget(getEpisodesList(), 3, 0, 1, 2);

    loSeason->setSpacing(2);

    setLayout(loSeason);
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
}

MediaDetailsTVSeasonPanel::MediaDetailsTVSeasonPanel(QWidget *parent)
    : QGroupBox(tr("Season"), parent)
    , mPnlEpisodes(nullptr)
    , mLblComments(nullptr)
    , mLblNumber(nullptr)
    , mSpnNumber(nullptr)
    , mTxtComments(nullptr)
{
    initPanel();
}

QSize MediaDetailsTVSeasonPanel::sizeHint() const
{
    return(QGroupBox::sizeHint());
}

void MediaDetailsTVSeasonPanel::setDisabled(bool disable)
{
    getNumberField()->setDisabled(disable);
    getNumberLabel()->setDisabled(disable);
    getCommentsField()->setDisabled(disable);
    getCommentsLabel()->setDisabled(disable);
    getEpisodesList()->setDisabled(disable);
}
