#include "MediaDetailsArtistPanel.h"
#include<QVBoxLayout>

using namespace net::draconia::mediadb::ui;

QLabel *MediaDetailsArtistPanel::getArtistsLabel()
{
    if(mLblArtists == nullptr)
        {
        mLblArtists = new QLabel("Artists:", this);

        mLblArtists->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        mLblArtists->setBuddy(getArtistsTable());
        }

    return(mLblArtists);
}

QTableWidget *MediaDetailsArtistPanel::getArtistsTable()
{
    if(mTblArtists == nullptr)
        {
        mTblArtists = new QTableWidget(this);

        mTblArtists->setSortingEnabled(true);
        mTblArtists->setColumnCount(2);
        mTblArtists->setHorizontalHeaderLabels({"Artist", "Role"});
        }

    return(mTblArtists);
}

MediaDetailsArtistButtonPanel *MediaDetailsArtistPanel::getButtonPanel()
{
    if(mPnlButtons == nullptr)
        mPnlButtons = new MediaDetailsArtistButtonPanel(this);

    return(mPnlButtons);
}

void MediaDetailsArtistPanel::initPanel()
{
    QLayout *loArtists = new QVBoxLayout(this);

    loArtists->addWidget(getArtistsLabel());
    loArtists->addWidget(getArtistsTable());
    loArtists->addWidget(getButtonPanel());

    loArtists->setSpacing(3);

    setLayout(loArtists);
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
}

MediaDetailsArtistPanel::MediaDetailsArtistPanel(QWidget *parent)
    : QWidget(parent)
    , mLblArtists(nullptr)
    , mTblArtists(nullptr)
    , mPnlButtons(nullptr)
{
    initPanel();
}

QSize MediaDetailsArtistPanel::sizeHint() const
{
    return(QWidget::sizeHint());
}
