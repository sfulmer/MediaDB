#pragma once

#include<QLayout>
#include "net/draconia/mediadb/ui/MainPanel.h"
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
                    QListWidget *getMediaList();
                    QWidget *getMediaPanel();
                    QScrollArea *getMediaScrollArea();
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
