#include "MediaDetailsArtistPanel.h"
#include "MediaDetailsMoviePanel.h"
#include "MediaDetailsPanel.h"
#include<QVBoxLayout>

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

        mTabMediaTypes->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding));

        mTabMediaTypes->addTab(new MediaDetailsArtistPanel(), "Artist");
        mTabMediaTypes->addTab(new MediaDetailsMoviePanel(), "Movie");
        mTabMediaTypes->addTab(new QWidget(), "TV Show");
        mTabMediaTypes->addTab(new QWidget(), "Music");
        mTabMediaTypes->addTab(new QWidget(), "Book");
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
