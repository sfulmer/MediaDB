#include<QApplication>
#include "MainWindow.h"
#include <QApplication>

using net::draconia::mediadb::ui::MainWindow;

int main(int argc, char *argv[])
{
    QApplication objApp(argc, argv);
    MainWindow wndMain;

    wndMain.setFixedSize(1280, 720); // For easier debugging of UI.
    wndMain.show();

    return(objApp.exec());
}
