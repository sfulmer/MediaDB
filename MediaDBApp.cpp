#include "MediaDBApp.h"
#include "PropertyFileIO.h"

using namespace net::draconia;
using net::draconia::io::PropertyFileIO;

void MediaDBApp::propogatePropertiesToSettings()
{
    // Do something with this once I define properties :-P
}

void MediaDBApp::setArguments(int argc, char *argv[])
{
    for(int iLength = argc, iLoop = 0; iLoop < iLength; iLoop++)
        getArguments().append(argv[iLoop]);
}

void MediaDBApp::showMainWindow()
{
    getMainWindow().show();
}

MediaDBApp::MediaDBApp(int argc, char **argv)
    :   QApplication(argc, argv)
    ,   mObjController(*this)
{
    setArguments(argc, argv);
}

int MediaDBApp::exec()
{
    showMainWindow();

    return(QApplication::exec());
}

QList<QString> &MediaDBApp::getArguments() const
{
    return(const_cast<QList<QString> &>(mLstArgs));
}

MediaDBController &MediaDBApp::getController() const
{
    return(const_cast<MediaDBApp &>(*this).mObjController);
}

MainWindow &MediaDBApp::getMainWindow()
{
    return(mWndMain);
}

Properties &MediaDBApp::getProperties()
{
    if(mObjProperties.isEmpty())
        return(mObjProperties = PropertyFileIO().load("Config.properties"));
    else
        return(mObjProperties);
}
