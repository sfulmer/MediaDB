#include "MainWindow.h"
#include<QApplication>

using net::draconia::mediadb::ui::MainWindow;

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

    MainWindow wnd;
    wnd.show();

    return(app.exec());
}
