#include "AlbumDAOImpl.h"
#include "BeanFactory.h"
#include "MediaDAOImpl.h"
#include<QtSql/QSqlField>
#include "RoleDAOImpl.h"
#include "SingleDAOImpl.h"
#include "SongDAOImpl.h"

using namespace net::draconia::mediadb::dao;

using net::draconia::mediadb::BeanFactory;

using net::draconia::mediadb::dbo::Album;
using net::draconia::mediadb::dbo::Artist;
using net::draconia::mediadb::dbo::Song;

Album AlbumDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    Album objAlbum  (   refRecord.field("AlbumId").value().toUInt()
                    ,   refRecord.field("Name").value().toString()
                    ,   refRecord.field("ReleaseDate").value().toDate()
                    ,   refRecord.field("Comments").value().toString());

    for(Song objSong : getSongDAO().listByAlbum(objAlbum))
        objAlbum.addSong(objSong);

    return(objAlbum);
}

MediaDAO &AlbumDAOImpl::getMediaDAO() const
{
    return(mRefMediaDAO);
}

RoleDAO &AlbumDAOImpl::getRoleDAO() const
{
    return(mRefRoleDAO);
}

SingleDAO &AlbumDAOImpl::getSingleDAO() const
{
    return(mRefSingleDAO);
}

SongDAO &AlbumDAOImpl::getSongDAO() const
{
    return(mRefSongDAO);
}

Album &AlbumDAOImpl::insert(const Album &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into Albums (Name, ReleaseDate, Comments) values(?, ?, ?);");

    objQuery.bindValue(1, refToSave.getName());
    objQuery.bindValue(2, refToSave.getReleaseDate());
    objQuery.bindValue(3, refToSave.getComments());

    if(objQuery.exec())
        const_cast<Album &>(refToSave).setAlbumId(objQuery.lastInsertId().toUInt());

    return(const_cast<Album &>(refToSave));
}

bool AlbumDAOImpl::isTableExists() const
{
    return(const_cast<AlbumDAOImpl &>(*this).getTableUtils().isTableExists("Albums"));
}

void AlbumDAOImpl::removeTable()
{
    getTableUtils().removeTable("Albums");
}

Album &AlbumDAOImpl::update(const Album &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("update Albums set Name = ?, ReleaseDate = ?, Comments = ? where AlbumId = ?;");

    objQuery.bindValue(1, refToSave.getName());
    objQuery.bindValue(2, refToSave.getReleaseDate());
    objQuery.bindValue(3, refToSave.getComments());
    objQuery.bindValue(4, refToSave.getAlbumId());

    objQuery.exec();

    return(const_cast<Album &>(refToSave));
}

AlbumDAOImpl::AlbumDAOImpl(const QSqlDatabase &refDatabase)
    : AbstractDAO<Album>(refDatabase)
    , mRefMediaDAO(BeanFactory::getInstance().getMediaDAO())
    , mRefRoleDAO(BeanFactory::getInstance().getRoleDAO())
    , mRefSingleDAO(BeanFactory::getInstance().getSingleDAO())
    , mRefSongDAO(BeanFactory::getInstance().getSongDAO())
{ }

AlbumDAOImpl::~AlbumDAOImpl()
{ }

bool AlbumDAOImpl::createTable() const
{
    if(!isTableExists())
        {
        QSqlQuery objQuery(getDatabase());

        objQuery.prepare("create table Albums (AlbumId int not null auto_correct primary key, Name varchar(255) not null, ReleaseDate date not null, Comments varchar(32000) not null default ' ');");

        return(objQuery.exec());
        }
    else
        return(true);
}

Album AlbumDAOImpl::getById(const unsigned uiAlbumId) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select AlbumId, Name, ReleaseDate, Comments from Albums where AlbumId = ?;");

    objQuery.bindValue(1, uiAlbumId);

    if(objQuery.exec())
        return(const_cast<AlbumDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(Album());
}

Album AlbumDAOImpl::getByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select AlbumId, Name, ReleaseDate, Comments from Albums where Name = ? and ReleaseDate between ? and ?;");

    objQuery.bindValue(1, sName);
    objQuery.bindValue(2, QDate(static_cast<int>(uiReleaseYear), 1, 1));
    objQuery.bindValue(2, QDate(static_cast<int>(uiReleaseYear) + 1, 1, 1));

    if(objQuery.exec())
        return(const_cast<AlbumDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(Album());
}

Album AlbumDAOImpl::getBySong(const Song &refSong) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select AlbumId, Name, ReleaseDate, Comments from Albums inner join Songs on Songs.AlbumId = Albums.AlbumId and Songs.SongId = ?;");

    static_cast<SongDAOImpl &>(getSongDAO()).createTable();

    objQuery.bindValue(1, refSong.getSongId());

    if(objQuery.exec())
        return(const_cast<AlbumDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(Album());
}

QList<Album> AlbumDAOImpl::list() const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select AlbumId, Name, ReleaseDate, Comments from Albums;");

    if(objQuery.exec())
        return(const_cast<AlbumDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Album>());
}

QList<Album> AlbumDAOImpl::listByArtist(const Artist &refArtist) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select AlbumId, Name, ReleaseDate, Comments from Albums inner join Songs on Songs.AlbumId = Albums.AlbumId inner join Singles on Songs.SingleId = Singles.SingleId inner join Media on Singles.MediaId = Media.MediaId inner join Roles on Roles.MediaId = Media.MediaId and Roles.ArtistId = ?;");

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<RoleDAOImpl &>(getRoleDAO()).createTable();
    static_cast<SingleDAOImpl &>(getSingleDAO()).createTable();
    static_cast<SongDAOImpl &>(getSongDAO()).createTable();

    objQuery.bindValue(1, refArtist.getArtistId());

    if(objQuery.exec())
        return(const_cast<AlbumDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Album>());
}

QList<Album> AlbumDAOImpl::listByName(const QString &sName) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select AlbumId, Name, ReleaseDate, Comments from Albums where Name = ?;");

    objQuery.bindValue(1, sName);

    if(objQuery.exec())
        return(const_cast<AlbumDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Album>());
}

QList<Album> AlbumDAOImpl::listByWordInComments(const QString &sWord) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select AlbumId, Name, ReleaseDate, Comments from Albums where Comments like ?;");

    objQuery.bindValue(1, "%" + sWord + "%");

    if(objQuery.exec())
        return(const_cast<AlbumDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Album>());
}

bool AlbumDAOImpl::remove(const Album &refToRemove) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("delete from Albums where AlbumId = ?;");

    objQuery.bindValue(1, refToRemove.getAlbumId());

    return(objQuery.exec());
}

Album &AlbumDAOImpl::save(const Album &refToSave) const
{
    if(!isTableExists())
        createTable();

    if(refToSave.getAlbumId() > 0)
        return(update(refToSave));
    else
        return(insert(refToSave));
}
