#include "MainWindow.h"
#include<QHBoxLayout>
#include<QScrollArea>

using namespace net::draconia::mediadb::ui;

void MainWindow::initControls()
{
    new MainPanel(this);
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
