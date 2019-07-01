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

        for(QString sMediaType : {"Artists", "Movie", "TV Show", "Music", "Book"})
            mTabMediaTypes->addTab(sMediaType);
        }

    return(mTabMediaTypes);
}

void MediaDetailsPanel::initPanel()
{
    QLayout *loDetails = new QVBoxLayout(this);

    loDetails->addWidget(getDetailsData());
    loDetails->addWidget(getMediaTypeTabs());
    loDetails->setSpacing(3);

    setLayout(loDetails);
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
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
