#include "MediaDetailsPanel.h"
#include<QVBoxLayout>

using namespace net::draconia::mediadb::ui;

MediaDetailsDataPanel *MediaDetailsPanel::getDetailsData()
{
    if(mPnlDetailsData == nullptr)
        mPnlDetailsData = new MediaDetailsDataPanel(this);

    return(mPnlDetailsData);
}

QTabBar *MediaDetailsPanel::getMediaTypeTabs()
{
    if(mTabMediaTypes == nullptr)
        {
        mTabMediaTypes = new QTabBar(this);

        mTabMediaTypes->setDrawBase(false);
        mTabMediaTypes->setShape(QTabBar::Shape::RoundedNorth);
        mTabMediaTypes->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding));

        for(QString sMediaType : {"Artist", "Movie", "TV Show", "Music", "Book"})
            mTabMediaTypes->addTab(sMediaType);
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
