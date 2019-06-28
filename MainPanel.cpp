#include "MainPanel.h"
#include<QHBoxLayout>
#include<QVBoxLayout>

using namespace net::draconia::mediadb::ui;

QListWidget *MainPanel::getMediaList()
{
    if(mLstMedia == nullptr)
        {
        mLstMedia = new QListWidget(getMediaScrollArea());

        mLstMedia->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
        }

    return(mLstMedia);
}

QWidget *MainPanel::getMediaPanel()
{
    if(mPnlMediaList == nullptr)
        {
        mPnlMediaList = new QWidget(this);

        QLayout *loMediaList = new QVBoxLayout(mPnlMediaList);

        mPnlMediaList->setLayout(loMediaList);
        mPnlMediaList->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

        loMediaList->addWidget(getMediaScrollArea());
        }

    return(mPnlMediaList);
}

QScrollArea *MainPanel::getMediaScrollArea()
{
    if(mScrMediaList == nullptr)
        {
        mScrMediaList = new QScrollArea(getMediaPanel());

        mScrMediaList->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));
        mScrMediaList->setWidget(getMediaList());
        }

    return(mScrMediaList);
}

void MainPanel::initPanel()
{
    QLayout *loMain = new QHBoxLayout(this);

    setLayout(loMain);
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    loMain->addWidget(getMediaPanel());
}

MainPanel::MainPanel(QWidget *parent)
    : QWidget(parent)
{
    initPanel();
}
