#pragma once

#include "MainWindow.h"
#include<QApplication>

using net::draconia::mediadb::ui::MainWindow;

namespace net
{
    namespace draconia
    {
        class MediaDBApp : public QApplication
        {
            MainWindow mWndMain;
        protected:
            MainWindow &getMainWindow() const;
            void initApp();
        public:
            MediaDBApp(int &argc, char **argv);
        public slots:
            void onApplicationStateChanged(Qt::ApplicationState state);
        };
    }
}
