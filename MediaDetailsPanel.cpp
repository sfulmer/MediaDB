#include "MediaDetailsArtistPanel.h"
#include "MediaDetailsMoviePanel.h"
#include "MediaDetailsPanel.h"
#include "MediaDetailsTVPanel.h"
#include<QVBoxLayout>
#include "VideoPlayerPanel.h"

using namespace net::draconia::mediadb::ui;

MediaDetailsDataPanel *MediaDetailsPanel::getDetailsData()
{
    if(mPnlDetailsData == nullptr)
        mPnlDetailsData = new MediaDetailsDataPanel(this);

    return(mPnlDetailsData);
}

QTabWidget *MediaDetailsPanel::getMediaTypeTabs()
{
    if(mTabMediaTypes == nullptr)
        {
        mTabMediaTypes = new QTabWidget(this);

        mTabMediaTypes->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

        mTabMediaTypes->addTab(new MediaDetailsArtistPanel(), "Artist");
        mTabMediaTypes->addTab(new MediaDetailsMoviePanel(), "Movie");
        mTabMediaTypes->addTab(new MediaDetailsTVPanel(), "TV");
        mTabMediaTypes->addTab(new QWidget(), "Music");
        mTabMediaTypes->addTab(new QWidget(), "Book");
        mTabMediaTypes->addTab(new VideoPlayerPanel(), "Play");
        }

    return(mTabMediaTypes);
}

void MediaDetailsPanel::initPanel()
{
    QLayout *loDetails = new QVBoxLayout(this);
    QSizePolicy szPolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    loDetails->addWidget(getDetailsData());
    loDetails->addWidget(getMediaTypeTabs());
    loDetails->setSpacing(2);

    szPolicy.setHorizontalStretch(7);

    setLayout(loDetails);
    setSizePolicy(szPolicy);
}

MediaDetailsPanel::MediaDetailsPanel(QWidget *parent)
    : QWidget(parent)
    , mPnlDetailsData(nullptr)
    , mTabMediaTypes(nullptr)
{
    initPanel();
}

QSize MediaDetailsPanel::sizeHint() const
{
    return(QWidget::sizeHint());
}

void MediaDetailsPanel::setDisabled(bool disable)
{
    getDetailsData()->setDisabled(disable);
    getMediaTypeTabs()->setDisabled(disable);
}
