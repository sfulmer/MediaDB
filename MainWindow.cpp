#include "MainWindow.h"
#include <QHBoxLayout>
#include <QListWidget>
#include <QGuiApplication>
#include <QMenuBar>
#include <QScreen>

using namespace net::draconia::mediadb::ui;

void MainWindow::exitClicked()
{
    close();
}

QAction *MainWindow::geExitAction()
{
    if(mActExit == nullptr)
        {
        mActExit = new QAction("E&xit", getMediaDBMenu());

        mActExit->setShortcut(QKeySequence::fromString("Alt+F4"));
        mActExit->setToolTip("Exits the Application");
        mActExit->setWhatsThis("Exits the Application");

        connect(mActExit, &QAction::triggered, this, &MainWindow::exitClicked);
        }

    return(mActExit);
}

MainPanel *MainWindow::getMainPanel()
{
    if(mPnlMain == nullptr)
        mPnlMain = new MainPanel(this);

    return(mPnlMain);
}

QMenu *MainWindow::getMediaDBMenu()
{
    if(mMnuMediaDB == nullptr)
        {
        mMnuMediaDB = new QMenu("&MediaDB");

        mMnuMediaDB->addAction(geExitAction());
        }

    return(mMnuMediaDB);
}

QAction *MainWindow::getSettingsAction()
{
    if(mActSettings == nullptr)
        {
        mActSettings = new QAction("&Settings...", getSettingsMenu());

        mActSettings->setToolTip("Opens the Settings dialog box...");
        mActSettings->setWhatsThis("Opens the Settings dialog box...");

        connect(mActSettings, &QAction::triggered, this, &MainWindow::settingsClicked);
        }

    return(mActSettings);
}

QMenu *MainWindow::getSettingsMenu()
{
    if(mMnuSettings == nullptr)
        {
        mMnuSettings = new QMenu("&Settings");

        mMnuSettings->addAction(getSettingsAction());
        }

    return(mMnuSettings);
}

void MainWindow::initControls()
{
    setCentralWidget(getMainPanel());
}

void MainWindow::initMenus()
{
    QMenuBar *bar = new QMenuBar(this);

    setMenuBar(bar);

    bar->addMenu(getMediaDBMenu());
    bar->addMenu(getSettingsMenu());
}

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

void MainWindow::settingsClicked()
{

}

MainWindow::MainWindow(QWidget *parent)
    :   QMainWindow(parent)
    ,   mPnlMain(nullptr)
    ,   mActExit(nullptr), mActSettings(nullptr)
    ,   mMnuMediaDB(nullptr), mMnuSettings(nullptr)
{
    initWindow();
}
