#include "MainWindow.h"
#include<QHBoxLayout>
#include<QScrollArea>

using namespace net::draconia::mediadb::ui;

QListWidget *MainWindow::getMediaList()
{
    if(mLstMedia == nullptr)
        {
        mLstMedia = new QListWidget(getMediaScrollArea());

        mLstMedia->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
        }

    return(mLstMedia);
}

QWidget *MainWindow::getMediaPanel()
{
    if(mPnlMediaList == nullptr)
        {
        mPnlMediaList = new QWidget(getMainPanel());

        QLayout *loMediaList = new QVBoxLayout(mPnlMediaList);

        mPnlMediaList->setLayout(loMediaList);
        mPnlMediaList->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

        loMediaList->addWidget(getMediaScrollArea());
        }

    return(mPnlMediaList);
}

QScrollArea *MainWindow::getMediaScrollArea()
{
    if(mScrMediaList == nullptr)
        {
        mScrMediaList = new QScrollArea(getMediaPanel());

        mScrMediaList->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));
        mScrMediaList->setWidget(getMediaList());
        }

    return(mScrMediaList);
}

void MainWindow::initControls()
{
    QWidget *pnlMain = new QWidget(this);

    QLayout *loMain = new QHBoxLayout(pnlMain);

    pnlMain->setLayout(loMain);
    pnlMain->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    loMain->addWidget(getMediaPanel());
}

void MainWindow::initMenus()
{ }

void MainWindow::initWindow()
{
    setWindowTitle("Media Database");

    initControls();
    initMenus();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initWindow();
}

MainWindow::~MainWindow()
{ }
