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
        AbstractDAO.cpp \
        Album.cpp \
        Artist.cpp \
        ArtistDAO.cpp \
        ArtistDAOImpl.cpp \
        BeanFactory.cpp \
        Book.cpp \
        BookDAO.cpp \
        BookDAOImpl.cpp \
        Media.cpp \
        MediaDAOImpl.cpp \
        Movie.cpp \
        MovieDAO.cpp \
        MovieDAOImpl.cpp \
        MovieViewing.cpp \
        MovieViewingDAO.cpp \
        MovieViewingDAOImpl.cpp \
        Observable.cpp \
        Role.cpp \
        RoleDAO.cpp \
        RoleDAOImpl.cpp \
        RoleType.cpp \
        RoleTypeDAO.cpp \
        RoleTypeDAOImpl.cpp \
        Single.cpp \
        Song.cpp \
        TVEpisode.cpp \
        TVEpisodeDAO.cpp \
        TVEpisodeDAOImpl.cpp \
        TVSeason.cpp \
        TVSeasonDAO.cpp \
        TVSeasonDAOImpl.cpp \
        TVSeries.cpp \
        TVSeriesDAO.cpp \
        TVSeriesDAOImpl.cpp \
        TVSpecial.cpp \
        TVSpecialDAO.cpp \
        TVSpecialDAOImpl.cpp \
        TableUtils.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        AbstractDAO.h \
        Album.h \
        Artist.h \
        ArtistDAO.h \
        ArtistDAOImpl.h \
        BeanFactory.h \
        Book.h \
        BookDAO.h \
        BookDAOImpl.h \
        Media.h \
        MediaDAO.h \
        MediaDAOImpl.h \
        MediaDAOcpp \
        Movie.h \
        MovieDAO.h \
        MovieDAOImpl.h \
        MovieViewing.h \
        MovieViewingDAO.h \
        MovieViewingDAOImpl.h \
        Observable.h \
        Role.h \
        RoleDAO.h \
        RoleDAOImpl.h \
        RoleType.h \
        RoleTypeDAO.h \
        RoleTypeDAOImpl.h \
        Single.h \
        Song.h \
        TVEpisode.h \
        TVEpisodeDAO.h \
        TVEpisodeDAOImpl.h \
        TVSeason.h \
        TVSeasonDAO.h \
        TVSeasonDAOImpl.h \
        TVSeries.h \
        TVSeriesDAO.h \
        TVSeriesDAOImpl.h \
        TVSpecial.h \
        TVSpecialDAO.h \
        TVSpecialDAOImpl.h \
        TableUtils.h \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
