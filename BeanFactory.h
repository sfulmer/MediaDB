#pragma once

#include "ArtistDAO.h"
#include "MediaDAO.h"
#include "MovieDAO.h"
#include "MovieViewingDAO.h"
#include<QSharedPointer>
#include<QtSql/QSqlDatabase>
#include "RoleDAO.h"
#include "RoleTypeDAO.h"
#include "TVEpisodeDAO.h"
#include "TVSeasonDAO.h"
#include "TVSeriesDAO.h"
#include "TVSpecialDAO.h"

using net::draconia::mediadb::dao::ArtistDAO;
using net::draconia::mediadb::dao::MediaDAO;
using net::draconia::mediadb::dao::MovieDAO;
using net::draconia::mediadb::dao::MovieViewingDAO;
using net::draconia::mediadb::dao::RoleDAO;
using net::draconia::mediadb::dao::RoleTypeDAO;
using net::draconia::mediadb::dao::TVEpisodeDAO;
using net::draconia::mediadb::dao::TVSeasonDAO;
using net::draconia::mediadb::dao::TVSeriesDAO;
using net::draconia::mediadb::dao::TVSpecialDAO;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            class BeanFactory
            {
                static BeanFactory msObjBeanFactory;

                QSharedPointer<ArtistDAO> mPtrArtistDAO;
                QSqlDatabase mDbDatabase;
                QSharedPointer<MediaDAO> mPtrMediaDAO;
                QSharedPointer<MovieDAO> mPtrMovieDAO;
                QSharedPointer<MovieViewingDAO> mPtrMovieViewingDAO;
                QSharedPointer<RoleDAO> mPtrRoleDAO;
                QSharedPointer<RoleTypeDAO> mPtrRoleTypeDAO;
                QSharedPointer<TVEpisodeDAO> mPtrTVEpisodeDAO;
                QSharedPointer<TVSeasonDAO> mPtrTVSeasonDAO;
                QSharedPointer<TVSeriesDAO> mPtrTVSeriesDAO;
                QSharedPointer<TVSpecialDAO> mPtrTVSpecialDAO;
            protected:
                BeanFactory();
            public:
                ~BeanFactory();

                static BeanFactory &getInstance();

                ArtistDAO &getArtistDAO();
                QSqlDatabase &getDatabase();
                MediaDAO &getMediaDAO();
                MovieDAO &getMovieDAO();
                MovieViewingDAO &getMovieViewingDAO();
                RoleDAO &getRoleDAO();
                RoleTypeDAO &getRoleTypeDAO();
                TVEpisodeDAO &getTVEpisodeDAO();
                TVSeasonDAO &getTVSeasonDAO();
                TVSeriesDAO &getTVSeriesDAO();
                TVSpecialDAO &getTVSpecialDAO();
            };
        }
    }
}
