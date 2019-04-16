//#include "MainWindow.h"
//#include <QApplication>

#include<iostream>
#include "MovieDAOImpl.h"

using namespace net::draconia::dao;
using namespace net::draconia::dbo;
using namespace std;

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/

    MovieDAOImpl objMovieDAO;
    Movie objMovie = objMovieDAO.save(Movie(0, 0, "Ralph Breaks the Internet", 2018, "", QList<Artist>(), "Great movie!", QList<QDateTime>()));
    cout << "The Id of the movie is " << objMovie.getMovieId() << endl;

    return(0);
}
