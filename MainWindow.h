#pragma once

#include<QLayout>
#include "MainPanel.h"
#include<QMainWindow>
#include<QScrollArea>
#include<QListWidget>

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

                    void initControls();
                    void initMenus();
                    void initWindow();
                public:
                    explicit MainWindow(QWidget *parent = nullptr);
                    ~MainWindow();
                };
            }
        }
    }
}
