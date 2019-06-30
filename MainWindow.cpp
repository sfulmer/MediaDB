#include "MainWindow.h"
#include<QHBoxLayout>
#include<QListWidget>

using namespace net::draconia::mediadb::ui;

MainPanel *MainWindow::getMainPanel()
{
    if(mPnlMain == nullptr)
        mPnlMain = new MainPanel(this);

    return(mPnlMain);
}

void MainWindow::initControls()
{
    setCentralWidget(getMainPanel());
}

void MainWindow::initMenus()
{ }

void MainWindow::initWindow()
{
    setWindowTitle(QObject::tr("Media Database"));

    initControls();
    initMenus();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mPnlMain(nullptr)
{
    initWindow();
}
