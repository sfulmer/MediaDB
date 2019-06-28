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
        main.cpp \
        net/draconia/mediadb/BeanFactory.cpp \
        net/draconia/mediadb/dao/AbstractDAO.cpp \
        net/draconia/mediadb/dao/AlbumDAO.cpp \
        net/draconia/mediadb/dao/AlbumDAOImpl.cpp \
        net/draconia/mediadb/dao/ArtistDAO.cpp \
        net/draconia/mediadb/dao/ArtistDAOImpl.cpp \
        net/draconia/mediadb/dao/BookDAO.cpp \
        net/draconia/mediadb/dao/BookDAOImpl.cpp \
        net/draconia/mediadb/dao/MediaDAOImpl.cpp \
        net/draconia/mediadb/dao/MovieDAO.cpp \
        net/draconia/mediadb/dao/MovieDAOImpl.cpp \
        net/draconia/mediadb/dao/MovieViewingDAO.cpp \
        net/draconia/mediadb/dao/MovieViewingDAOImpl.cpp \
        net/draconia/mediadb/dao/RoleDAO.cpp \
        net/draconia/mediadb/dao/RoleDAOImpl.cpp \
        net/draconia/mediadb/dao/RoleTypeDAO.cpp \
        net/draconia/mediadb/dao/RoleTypeDAOImpl.cpp \
        net/draconia/mediadb/dao/SingleDAO.cpp \
        net/draconia/mediadb/dao/SingleDAOImpl.cpp \
        net/draconia/mediadb/dao/SongDAO.cpp \
        net/draconia/mediadb/dao/SongDAOImpl.cpp \
        net/draconia/mediadb/dao/TVEpisodeDAO.cpp \
        net/draconia/mediadb/dao/TVEpisodeDAOImpl.cpp \
        net/draconia/mediadb/dao/TVSeasonDAO.cpp \
        net/draconia/mediadb/dao/TVSeasonDAOImpl.cpp \
        net/draconia/mediadb/dao/TVSeriesDAO.cpp \
        net/draconia/mediadb/dao/TVSeriesDAOImpl.cpp \
        net/draconia/mediadb/dao/TVSpecialDAO.cpp \
        net/draconia/mediadb/dao/TVSpecialDAOImpl.cpp \
        net/draconia/mediadb/dao/TableUtils.cpp \
        net/draconia/mediadb/dbo/Album.cpp \
        net/draconia/mediadb/dbo/Artist.cpp \
        net/draconia/mediadb/dbo/Book.cpp \
        net/draconia/mediadb/dbo/Media.cpp \
        net/draconia/mediadb/dbo/Movie.cpp \
        net/draconia/mediadb/dbo/MovieViewing.cpp \
        net/draconia/mediadb/dbo/Role.cpp \
        net/draconia/mediadb/dbo/RoleType.cpp \
        net/draconia/mediadb/dbo/Single.cpp \
        net/draconia/mediadb/dbo/Song.cpp \
        net/draconia/mediadb/dbo/TVEpisode.cpp \
        net/draconia/mediadb/dbo/TVSeason.cpp \
        net/draconia/mediadb/dbo/TVSeries.cpp \
        net/draconia/mediadb/dbo/TVSpecial.cpp \
        net/draconia/mediadb/ui/MainPanel.cpp \
        net/draconia/mediadb/ui/MainWindow.cpp \
        net/draconia/util/Observable.cpp

HEADERS += \
        net/draconia/mediadb/BeanFactory.h \
        net/draconia/mediadb/dao/AbstractDAO.h \
        net/draconia/mediadb/dao/AlbumDAO.h \
        net/draconia/mediadb/dao/AlbumDAOImpl.h \
        net/draconia/mediadb/dao/ArtistDAO.h \
        net/draconia/mediadb/dao/ArtistDAOImpl.h \
        net/draconia/mediadb/dao/BookDAO.h \
        net/draconia/mediadb/dao/BookDAOImpl.h \
        net/draconia/mediadb/dao/MediaDAO.h \
        net/draconia/mediadb/dao/MediaDAOImpl.h \
        net/draconia/mediadb/dao/MediaDAOcpp \
        net/draconia/mediadb/dao/MovieDAO.h \
        net/draconia/mediadb/dao/MovieDAOImpl.h \
        net/draconia/mediadb/dao/MovieViewingDAO.h \
        net/draconia/mediadb/dao/MovieViewingDAOImpl.h \
        net/draconia/mediadb/dao/RoleDAO.h \
        net/draconia/mediadb/dao/RoleDAOImpl.h \
        net/draconia/mediadb/dao/RoleTypeDAO.h \
        net/draconia/mediadb/dao/RoleTypeDAOImpl.h \
        net/draconia/mediadb/dao/SingleDAO.h \
        net/draconia/mediadb/dao/SingleDAOImpl.h \
        net/draconia/mediadb/dao/SongDAO.h \
        net/draconia/mediadb/dao/SongDAOImpl.h \
        net/draconia/mediadb/dao/TVEpisodeDAO.h \
        net/draconia/mediadb/dao/TVEpisodeDAOImpl.h \
        net/draconia/mediadb/dao/TVSeasonDAO.h \
        net/draconia/mediadb/dao/TVSeasonDAOImpl.h \
        net/draconia/mediadb/dao/TVSeriesDAO.h \
        net/draconia/mediadb/dao/TVSeriesDAOImpl.h \
        net/draconia/mediadb/dao/TVSpecialDAO.h \
        net/draconia/mediadb/dao/TVSpecialDAOImpl.h \
        net/draconia/mediadb/dao/TableUtils.h \
        net/draconia/mediadb/dbo/Album.h \
        net/draconia/mediadb/dbo/Artist.h \
        net/draconia/mediadb/dbo/Book.h \
        net/draconia/mediadb/dbo/Media.h \
        net/draconia/mediadb/dbo/Movie.h \
        net/draconia/mediadb/dbo/MovieViewing.h \
        net/draconia/mediadb/dbo/Role.h \
        net/draconia/mediadb/dbo/RoleType.h \
        net/draconia/mediadb/dbo/Single.h \
        net/draconia/mediadb/dbo/Song.h \
        net/draconia/mediadb/dbo/TVEpisode.h \
        net/draconia/mediadb/dbo/TVSeason.h \
        net/draconia/mediadb/dbo/TVSeries.h \
        net/draconia/mediadb/dbo/TVSpecial.h \
        net/draconia/mediadb/ui/MainPanel.h \
        net/draconia/mediadb/ui/MainWindow.h \
        net/draconia/util/Observable.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
