#pragma once

#include "AlbumDAO.h"
#include "ArtistDAO.h"
#include "CollectionDAO.h"
#include "LabelBuilder.h"
#include "MediaDAO.h"
#include "MovieDAO.h"
#include "MovieViewingDAO.h"
#include<QFont>
#include<QSharedPointer>
#include<QtSql/QSqlDatabase>
#include "RoleDAO.h"
#include "RoleTypeDAO.h"
#include "SingleDAO.h"
#include "SongDAO.h"
#include "TVEpisodeDAO.h"
#include "TVSeasonDAO.h"
#include "TVSeriesDAO.h"
#include "TVSpecialDAO.h"

using net::draconia::mediadb::util::LabelBuilder;

using net::draconia::mediadb::dao::AlbumDAO;
using net::draconia::mediadb::dao::ArtistDAO;
using net::draconia::mediadb::dao::CollectionDAO;
using net::draconia::mediadb::dao::MediaDAO;
using net::draconia::mediadb::dao::MovieDAO;
using net::draconia::mediadb::dao::MovieViewingDAO;
using net::draconia::mediadb::dao::RoleDAO;
using net::draconia::mediadb::dao::RoleTypeDAO;
using net::draconia::mediadb::dao::SingleDAO;
using net::draconia::mediadb::dao::SongDAO;
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

                LabelBuilder mObjLabelBuilder;
                QFont mFntApplication;
                QSharedPointer<AlbumDAO> mPtrAlbumDAO;
                QSharedPointer<ArtistDAO> mPtrArtistDAO;
                QSharedPointer<CollectionDAO> mPtrCollectionDAO;
                QSqlDatabase mDbDatabase;
                QSharedPointer<MediaDAO> mPtrMediaDAO;
                QSharedPointer<MovieDAO> mPtrMovieDAO;
                QSharedPointer<MovieViewingDAO> mPtrMovieViewingDAO;
                QSharedPointer<RoleDAO> mPtrRoleDAO;
                QSharedPointer<RoleTypeDAO> mPtrRoleTypeDAO;
                QSharedPointer<SingleDAO> mPtrSingleDAO;
                QSharedPointer<SongDAO> mPtrSongDAO;
                QSharedPointer<TVEpisodeDAO> mPtrTVEpisodeDAO;
                QSharedPointer<TVSeasonDAO> mPtrTVSeasonDAO;
                QSharedPointer<TVSeriesDAO> mPtrTVSeriesDAO;
                QSharedPointer<TVSpecialDAO> mPtrTVSpecialDAO;
            protected:
                BeanFactory();
            public:
                ~BeanFactory();

                static BeanFactory &getInstance();

                AlbumDAO &getAlbumDAO();
                QFont &getApplicationFont() const;
                ArtistDAO &getArtistDAO();
                CollectionDAO &getCollectionDAO();
                QSqlDatabase &getDatabase();
                LabelBuilder &getLabelBuilder();
                MediaDAO &getMediaDAO();
                MovieDAO &getMovieDAO();
                MovieViewingDAO &getMovieViewingDAO();
                RoleDAO &getRoleDAO();
                RoleTypeDAO &getRoleTypeDAO();
                SingleDAO &getSingleDAO();
                SongDAO &getSongDAO();
                TVEpisodeDAO &getTVEpisodeDAO();
                TVSeasonDAO &getTVSeasonDAO();
                TVSeriesDAO &getTVSeriesDAO();
                TVSpecialDAO &getTVSpecialDAO();
            };
        }
    }
}
