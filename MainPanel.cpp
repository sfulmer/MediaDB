#include "MainPanel.h"
#include<QVBoxLayout>

using namespace net::draconia::mediadb::ui;

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
    loMain->setSpacing(2);

    setLayout(loMain);
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
}

MainPanel::MainPanel(QWidget *parent)
    : QWidget(parent)
    , mPnlMediaList(nullptr)
{
    initPanel();
}

QSize MainPanel::sizeHint() const
{
    MainPanel &refThis = const_cast<MainPanel &>(*this);

    return(refThis.getMediaListPanel()->sizeHint());
}
