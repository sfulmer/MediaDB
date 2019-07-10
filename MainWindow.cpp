#include "MainWindow.h"
#include<QHBoxLayout>
#include<QListWidget>
#include<QGuiApplication>
#include<QScreen>

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

    QSize sz = size();
    QRect rect = QGuiApplication::primaryScreen()->availableGeometry();

    QRect alignedRect(  (rect.width() - sz.width()) / 4
                     ,  (rect.height() - sz.height()) / 4
                     ,  sz.width()
                     ,  sz.height());

    setGeometry(alignedRect);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mPnlMain(nullptr)
{
    initWindow();
}
