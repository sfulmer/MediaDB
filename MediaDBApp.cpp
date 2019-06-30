#include "MainWindow.h"
#include "MediaDBApp.h"

using namespace net::draconia;

MainWindow &MediaDBApp::getMainWindow() const
{
    return(const_cast<MainWindow &>(mWndMain));
}

void MediaDBApp::initApp()
{
    getMainWindow().show();
}

MediaDBApp::MediaDBApp(int &argc, char **argv)
    : QApplication(argc, argv)
{
    initApp();
}
