//#include "mainwindow.h"
//#include <QApplication>

#include<iostream>
#include<QtSql/QSqlDatabase>

using namespace std;

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Test.db");
    bool db_ok = db.open();

    cout << "It's " << ((!db_ok) ? "not " : "") << "open" << endl;
}
