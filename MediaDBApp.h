#pragma once

#include "MainWindow.h"
#include "MediaDBController.h"
#include "Properties.h"
#include <QApplication>

using net::draconia::mediadb::MediaDBController;
using net::draconia::mediadb::ui::MainWindow;
using net::draconia::util::Properties;

namespace net
{
    namespace draconia
    {
        class MediaDBApp : public QApplication
        {
            MediaDBController mObjController;
            MainWindow mWndMain;
            Properties mObjProperties;
            QList<QString> mLstArgs;
        protected:
            void propogatePropertiesToSettings();
            void setArguments(int argc, char *argv[]);
            void showMainWindow();
        public:
            MediaDBApp(int argc, char **argv);

            int exec();
            QList<QString> &getArguments() const;
            MediaDBController &getController() const;
            MainWindow &getMainWindow();
            Properties &getProperties();
        };
    }
}
