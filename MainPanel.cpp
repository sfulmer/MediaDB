#include "MainPanel.h"
#include<QVBoxLayout>

using namespace net::draconia::mediadb::ui;

using net::draconia::ui::ListPanel;

MediaDetailsPanel *MainPanel::getMediaDetailsPanel()
{
    if(mPnlMediaDetails == nullptr)
        mPnlMediaDetails = new MediaDetailsPanel(this);

    return(mPnlMediaDetails);
}

ListPanel *MainPanel::getMediaListPanel()
{
    if(mPnlMediaList == nullptr)
        mPnlMediaList = new ListPanel("Media:", true, this);

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
    return(QWidget::sizeHint());
}

void MainPanel::setDisabled(bool disable)
{
    getMediaListPanel()->setDisabled(disable);
    getMediaDetailsPanel()->setDisabled(disable);
}
