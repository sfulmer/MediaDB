#include "MediaDetailsMusicSinglePanel.h"
#include<QHBoxLayout>

using namespace net::draconia::mediadb::ui;

MediaDetailsMusicSingleDetailPanel *MediaDetailsMusicSinglePanel::getDetailsPanel()
{
    if(mPnlDetails == nullptr)
        mPnlDetails = new MediaDetailsMusicSingleDetailPanel(this);

    return(mPnlDetails);
}

ListPanel *MediaDetailsMusicSinglePanel::getSinglesList()
{
    if(mLstSingles == nullptr)
        mLstSingles = new ListPanel("Singles:", this);

    return(mLstSingles);
}

void MediaDetailsMusicSinglePanel::initPanel()
{
    QLayout *loSingle = new QHBoxLayout(this);

    loSingle->addWidget(getSinglesList());
    loSingle->addWidget(getDetailsPanel());

    loSingle->setSpacing(2);

    setLayout(loSingle);
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
}

MediaDetailsMusicSinglePanel::MediaDetailsMusicSinglePanel(QWidget *parent)
    : QGroupBox("Singles", parent)
    , mLstSingles(nullptr)
    , mPnlDetails(nullptr)
{
    initPanel();
}

QSize MediaDetailsMusicSinglePanel::sizeHint() const
{
    return(QGroupBox::sizeHint());
}

void MediaDetailsMusicSinglePanel::setDisabled(bool disable)
{
    getDetailsPanel()->setDisabled(disable);
    getSinglesList()->setDisabled(disable);
}
