#pragma once

#include "MainPanel.h"
#include<QApplication>
#include<QMainWindow>
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
                protected:
                    MainPanel *getMainPanel();
                    void initControls();
                    void initMenus();
                    void initWindow();
                public:
                    explicit MainWindow(QWidget *parent = nullptr);
                };
            }
        }
    }
}

extern QSharedPointer<QApplication> mPtrApp;
