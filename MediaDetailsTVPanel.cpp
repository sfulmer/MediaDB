#include "MediaDetailsTVPanel.h"
#include<QGridLayout>

using namespace net::draconia::mediadb::ui;

MediaDetailsTVEpisodePanel *MediaDetailsTVPanel::getTVEpisodePanel()
{
    if(mPnlTVEpisode == nullptr)
        mPnlTVEpisode = new MediaDetailsTVEpisodePanel(this);

    return(mPnlTVEpisode);
}

MediaDetailsTVSeasonPanel *MediaDetailsTVPanel::getTVSeasonPanel()
{
    if(mPnlTVSeason == nullptr)
        mPnlTVSeason = new MediaDetailsTVSeasonPanel(this);

    return(mPnlTVSeason);
}

MediaDetailsTVSeriesPanel *MediaDetailsTVPanel::getTVSeriesPanel()
{
    if(mPnlTVSeries == nullptr)
        mPnlTVSeries = new MediaDetailsTVSeriesPanel(this);

    return(mPnlTVSeries);
}

MediaDetailsTVSpecialPanel *MediaDetailsTVPanel::getTVSpecialPanel()
{
    if(mPnlTVSpecial == nullptr)
        mPnlTVSpecial = new MediaDetailsTVSpecialPanel(this);

    return(mPnlTVSpecial);
}

void MediaDetailsTVPanel::initPanel()
{
    QGridLayout *loTV = new QGridLayout(this);

    loTV->addWidget(getTVSeriesPanel(), 0, 0);
    loTV->addWidget(getTVSpecialPanel(), 0, 1);
    loTV->addWidget(getTVSeasonPanel(), 1, 0);
    loTV->addWidget(getTVEpisodePanel(), 1, 1);

    loTV->setSpacing(2);

    setLayout(loTV);
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
}

MediaDetailsTVPanel::MediaDetailsTVPanel(QWidget *parent)
    : QWidget(parent)
    , mPnlTVEpisode(nullptr)
    , mPnlTVSeason(nullptr)
    , mPnlTVSeries(nullptr)
    , mPnlTVSpecial(nullptr)
{
    initPanel();
}

QSize MediaDetailsTVPanel::sizeHint() const
{
    return(QWidget::sizeHint());
}

void MediaDetailsTVPanel::setDisabled(bool disable)
{
    getTVSeriesPanel()->setDisabled(disable);
    getTVSeasonPanel()->setDisabled(disable);
    getTVEpisodePanel()->setDisabled(disable);
}
