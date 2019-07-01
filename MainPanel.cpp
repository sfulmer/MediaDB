#include "MainPanel.h"
#include<QVBoxLayout>

using namespace net::draconia::mediadb::ui;

MediaDetailsPanel *MainPanel::getMediaDetailsPanel()
{
    if(mPnlMediaDetails == nullptr)
        mPnlMediaDetails = new MediaDetailsPanel(this);

    return(mPnlMediaDetails);
}

MediaListPanel *MainPanel::getMediaListPanel()
{
    if(mPnlMediaList == nullptr)
        mPnlMediaList = new MediaListPanel(this);

    return(mPnlMediaList);
}

void MainPanel::initPanel()
{
    QLayout *loMain = new QHBoxLayout(this);

    loMain->addWidget(getMediaListPanel());
    loMain->addWidget(getMediaDetailsPanel());
    loMain->setSpacing(2);

    setLayout(loMain);
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
}

MainPanel::MainPanel(QWidget *parent)
    : QWidget(parent)
    , mPnlMediaDetails(nullptr)
    , mPnlMediaList(nullptr)
{
    initPanel();
}

QSize MainPanel::sizeHint() const
{
    MainPanel &refThis = const_cast<MainPanel &>(*this);

    return(refThis.getMediaListPanel()->sizeHint());
}
