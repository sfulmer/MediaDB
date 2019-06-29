#-------------------------------------------------
#
# Project created by QtCreator 2019-06-11T11:57:08
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MediaDB
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        MediaDBApp.cpp \
        main.cpp \
        BeanFactory.cpp \
        AbstractDAO.cpp \
        AlbumDAO.cpp \
        AlbumDAOImpl.cpp \
        ArtistDAO.cpp \
        ArtistDAOImpl.cpp \
        BookDAO.cpp \
        BookDAOImpl.cpp \
        MediaDAOImpl.cpp \
        MovieDAO.cpp \
        MovieDAOImpl.cpp \
        MovieViewingDAO.cpp \
        MovieViewingDAOImpl.cpp \
        RoleDAO.cpp \
        RoleDAOImpl.cpp \
        RoleTypeDAO.cpp \
        RoleTypeDAOImpl.cpp \
        SingleDAO.cpp \
        SingleDAOImpl.cpp \
        SongDAO.cpp \
        SongDAOImpl.cpp \
        TVEpisodeDAO.cpp \
        TVEpisodeDAOImpl.cpp \
        TVSeasonDAO.cpp \
        TVSeasonDAOImpl.cpp \
        TVSeriesDAO.cpp \
        TVSeriesDAOImpl.cpp \
        TVSpecialDAO.cpp \
        TVSpecialDAOImpl.cpp \
        TableUtils.cpp \
        Album.cpp \
        Artist.cpp \
        Book.cpp \
        Media.cpp \
        Movie.cpp \
        MovieViewing.cpp \
        Role.cpp \
        RoleType.cpp \
        Single.cpp \
        Song.cpp \
        TVEpisode.cpp \
        TVSeason.cpp \
        TVSeries.cpp \
        TVSpecial.cpp \
        MainPanel.cpp \
        MainWindow.cpp \
        Observable.cpp \
        CrawlerImpl.cpp

HEADERS += \
        BeanFactory.h \
        AbstractDAO.h \
        AlbumDAO.h \
        AlbumDAOImpl.h \
        ArtistDAO.h \
        ArtistDAOImpl.h \
        BookDAO.h \
        BookDAOImpl.h \
        MediaDAO.h \
        MediaDAOImpl.h \
        MediaDAOcpp \
        MediaDBApp.h \
        MovieDAO.h \
        MovieDAOImpl.h \
        MovieViewingDAO.h \
        MovieViewingDAOImpl.h \
        RoleDAO.h \
        RoleDAOImpl.h \
        RoleTypeDAO.h \
        RoleTypeDAOImpl.h \
        SingleDAO.h \
        SingleDAOImpl.h \
        SongDAO.h \
        SongDAOImpl.h \
        TVEpisodeDAO.h \
        TVEpisodeDAOImpl.h \
        TVSeasonDAO.h \
        TVSeasonDAOImpl.h \
        TVSeriesDAO.h \
        TVSeriesDAOImpl.h \
        TVSpecialDAO.h \
        TVSpecialDAOImpl.h \
        TableUtils.h \
        Album.h \
        Artist.h \
        Book.h \
        Media.h \
        Movie.h \
        MovieViewing.h \
        Role.h \
        RoleType.h \
        Single.h \
        Song.h \
        TVEpisode.h \
        TVSeason.h \
        TVSeries.h \
        TVSpecial.h \
        MainPanel.h \
        MainWindow.h \
        Observable.h \
        Crawler.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
