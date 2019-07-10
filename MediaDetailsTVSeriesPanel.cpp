#include "MediaDetailsTVSeriesPanel.h"
#include<QGridLayout>

using namespace net::draconia::mediadb::ui;

QTextEdit *MediaDetailsTVSeriesPanel::getCommentsField()
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

QLabel *MediaDetailsTVSeriesPanel::getCommentsLabel()
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

ListPanel *MediaDetailsTVSeriesPanel::getSeasonList()
{
    if(mPnlSeasons == nullptr)
        {
        mPnlSeasons = new ListPanel("Seasons", true, this);

        mPnlSeasons->setSortingEnabled(true);
        }

    return(mPnlSeasons);
}

ListPanel *MediaDetailsTVSeriesPanel::getSpecialsList()
{
    if(mPnlSpecials == nullptr)
        {
        mPnlSpecials = new ListPanel("Specials", true, this);

        mPnlSpecials->setSortingEnabled(true);
        }

    return(mPnlSpecials);
}

void MediaDetailsTVSeriesPanel::initPanel()
{
    QGridLayout *loTVSeries = new QGridLayout(this);

    loTVSeries->addWidget(getCommentsLabel(), 0, 0, 1, 2);
    loTVSeries->addWidget(getCommentsField(), 1, 0, 1, 2);
    loTVSeries->addWidget(getSeasonList(), 2, 0, 1, 1);
    loTVSeries->addWidget(getSpecialsList(), 2, 1, 1, 1);

    loTVSeries->setSpacing(3);

    setLayout(loTVSeries);
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
}

MediaDetailsTVSeriesPanel::MediaDetailsTVSeriesPanel(QWidget *parent)
    : QGroupBox(tr("Series"), parent)
    , mPnlSeasons(nullptr)
    , mPnlSpecials(nullptr)
    , mLblComments(nullptr)
    , mTxtComments(nullptr)
{
    initPanel();
}

QSize MediaDetailsTVSeriesPanel::sizeHint() const
{
    return(QGroupBox::sizeHint());
}

void MediaDetailsTVSeriesPanel::setDisabled(bool disable)
{
    getCommentsField()->setDisabled(disable);
    getCommentsLabel()->setDisabled(disable);
    getSeasonList()->setDisabled(disable);
    getSpecialsList()->setDisabled(disable);
}
