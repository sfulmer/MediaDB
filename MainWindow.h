#pragma once

#include "MainPanel.h"
#include<QApplication>
#include<QMainWindow>
#include <QMenu>
#include<QSharedPointer>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace ui
            {
                class MainWindow : public QMainWindow
                {
                    Q_OBJECT

                    MainPanel *mPnlMain;
                    QAction *mActExit, *mActSettings;
                    QMenu *mMnuMediaDB, *mMnuSettings;
                protected:
                    void exitClicked();
                    QAction *geExitAction();
                    MainPanel *getMainPanel();
                    QMenu *getMediaDBMenu();
                    QAction *getSettingsAction();
                    QMenu *getSettingsMenu();
                    void initControls();
                    void initMenus();
                    void initWindow();
                    void settingsClicked();
                public:
                    explicit MainWindow(QWidget *parent = nullptr);
                };
            }
        }
    }
}
