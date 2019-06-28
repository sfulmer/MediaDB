#include "mainwindow.h"
#include<QApplication>

using net::draconia::mediadb::ui::MainWindow;

int main(int argc, char *argv[])
{
    QApplication objApp(argc, argv);
    MainWindow wndMain;

    wndMain.show();

    return(objApp.exec());
}
