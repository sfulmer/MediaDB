#include "AlbumDAOImpl.h"
#include "ArtistDAOImpl.h"
#include "BeanFactory.h"
#include "MediaDAOImpl.h"
#include "MovieDAOImpl.h"
#include "MovieViewingDAOImpl.h"
#include "RoleDAOImpl.h"
#include "RoleTypeDAOImpl.h"
#include "SingleDAOImpl.h"
#include "SongDAOImpl.h"
#include "TVEpisodeDAOImpl.h"
#include "TVSeasonDAOImpl.h"
#include "TVSeriesDAOImpl.h"
#include "TVSpecialDAOImpl.h"

using namespace net::draconia::mediadb;

using net::draconia::mediadb::dao::AlbumDAOImpl;
using net::draconia::mediadb::dao::ArtistDAOImpl;
using net::draconia::mediadb::dao::MediaDAOImpl;
using net::draconia::mediadb::dao::MovieDAOImpl;
using net::draconia::mediadb::dao::MovieViewingDAOImpl;
using net::draconia::mediadb::dao::RoleDAOImpl;
using net::draconia::mediadb::dao::RoleTypeDAOImpl;
using net::draconia::mediadb::dao::SingleDAOImpl;
using net::draconia::mediadb::dao::SongDAOImpl;
using net::draconia::mediadb::dao::TVEpisodeDAOImpl;
using net::draconia::mediadb::dao::TVSeasonDAOImpl;
using net::draconia::mediadb::dao::TVSeriesDAOImpl;
using net::draconia::mediadb::dao::TVSpecialDAOImpl;

BeanFactory BeanFactory::msObjBeanFactory;

BeanFactory::BeanFactory()
    : mPtrAlbumDAO(nullptr), mPtrArtistDAO(nullptr)
    , mPtrMediaDAO(nullptr), mPtrMovieDAO(nullptr)
    , mPtrMovieViewingDAO(nullptr)
    , mPtrRoleDAO(nullptr), mPtrRoleTypeDAO(nullptr)
    , mPtrSingleDAO(nullptr), mPtrSongDAO(nullptr)
    , mPtrTVEpisodeDAO(nullptr), mPtrTVSeasonDAO(nullptr)
    , mPtrTVSeriesDAO(nullptr), mPtrTVSpecialDAO(nullptr)
{
    mDbDatabase = QSqlDatabase::addDatabase("QMYSQL");
}

BeanFactory::~BeanFactory()
{ }

BeanFactory &BeanFactory::getInstance()
{
    return(msObjBeanFactory);
}

AlbumDAO &BeanFactory::getAlbumDAO()
{
    if(mPtrAlbumDAO.isNull())
        mPtrAlbumDAO.reset(static_cast<AlbumDAO *>(new AlbumDAOImpl(getDatabase())));

    return(*mPtrAlbumDAO);
}

ArtistDAO &BeanFactory::getArtistDAO()
{
    if(mPtrArtistDAO.isNull())
        mPtrArtistDAO.reset(static_cast<ArtistDAO *>(new ArtistDAOImpl(getDatabase())));

    return(*mPtrArtistDAO);
}

QSqlDatabase &BeanFactory::getDatabase()
{
    if(!mDbDatabase.isOpen())
        {
        mDbDatabase.setDatabaseName("Media");
        mDbDatabase.setHostName("localhost");
        mDbDatabase.setPassword("R3g1n@ 1$ my Qu3En!");
        mDbDatabase.setPort(3306);
        mDbDatabase.setUserName("root");
        mDbDatabase.open();
        }

    return(mDbDatabase);
}

MediaDAO &BeanFactory::getMediaDAO()
{
    if(mPtrMediaDAO.isNull())
        mPtrMediaDAO.reset(static_cast<MediaDAO *>(new MediaDAOImpl(getDatabase())));

    return(*mPtrMediaDAO);
}

MovieDAO &BeanFactory::getMovieDAO()
{
    if(mPtrMovieDAO.isNull())
        mPtrMovieDAO.reset(static_cast<MovieDAO *>(new MovieDAOImpl(getDatabase())));

    return(*mPtrMovieDAO);
}

MovieViewingDAO &BeanFactory::getMovieViewingDAO()
{
    if(mPtrMovieViewingDAO.isNull())
        mPtrMovieViewingDAO.reset(static_cast<MovieViewingDAO *>(new MovieViewingDAOImpl(getDatabase())));

    return(*mPtrMovieViewingDAO);
}

RoleDAO &BeanFactory::getRoleDAO()
{
    if(mPtrRoleDAO.isNull())
        mPtrRoleDAO.reset(static_cast<RoleDAO *>(new RoleDAOImpl(getDatabase())));

    return(*mPtrRoleDAO);
}

RoleTypeDAO &BeanFactory::getRoleTypeDAO()
{
    if(mPtrRoleTypeDAO.isNull())
        mPtrRoleTypeDAO.reset(static_cast<RoleTypeDAO *>(new RoleTypeDAOImpl(getDatabase())));

    return(*mPtrRoleTypeDAO);
}

SingleDAO &BeanFactory::getSingleDAO()
{
    if(mPtrSingleDAO.isNull())
        mPtrSingleDAO.reset(static_cast<SingleDAOImpl *>(new SingleDAOImpl(getDatabase())));

    return(*mPtrSingleDAO);
}

SongDAO &BeanFactory::getSongDAO()
{
    if(mPtrSongDAO.isNull())
        mPtrSongDAO.reset(static_cast<SongDAOImpl *>(new SongDAOImpl(getDatabase())));

    return(*mPtrSongDAO);
}

TVEpisodeDAO &BeanFactory::getTVEpisodeDAO()
{
    if(mPtrTVEpisodeDAO.isNull())
        mPtrTVEpisodeDAO.reset(static_cast<TVEpisodeDAO *>(new TVEpisodeDAOImpl(getDatabase())));

    return(*mPtrTVEpisodeDAO);
}

TVSeasonDAO &BeanFactory::getTVSeasonDAO()
{
    if(mPtrTVSeasonDAO.isNull())
        mPtrTVSeasonDAO.reset(static_cast<TVSeasonDAO *>(new TVSeasonDAOImpl(getDatabase())));

    return(*mPtrTVSeasonDAO);
}

TVSeriesDAO &BeanFactory::getTVSeriesDAO()
{
    if(mPtrTVSeriesDAO.isNull())
        mPtrTVSeriesDAO.reset(static_cast<TVSeriesDAO *>(new TVSeriesDAOImpl(getDatabase())));

    return(*mPtrTVSeriesDAO);
}

TVSpecialDAO &BeanFactory::getTVSpecialDAO()
{
    if(mPtrTVSpecialDAO.isNull())
        mPtrTVSpecialDAO.reset(static_cast<TVSpecialDAO *>(new TVSpecialDAOImpl(getDatabase())));

    return(*mPtrTVSpecialDAO);
}
