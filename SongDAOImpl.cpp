#include "AlbumDAOImpl.h"
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

Song SongDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    Album objAlbum = getAlbumDAO().getById(refRecord.field("AlbumId").value().toUInt());
    Single objSingle = getSingleDAO().getById(refRecord.field("SingleId").value().toUInt());

    return(Song(    objAlbum
               ,    objSingle.getMediaId()
               ,    objSingle.getSingleId()
               ,    refRecord.field("SongId").value().toUInt()
               ,    objSingle.getName()
               ,    objSingle.getReleaseDate()
               ,    objSingle.getFilePath()
               ,    objSingle.getArtists()
               ,    objSingle.getComments()));
}

AlbumDAO &SongDAOImpl::getAlbumDAO() const
{
    return(mRefAlbumDAO);
}

MediaDAO &SongDAOImpl::getMediaDAO() const
{
    return(mRefMediaDAO);
}

RoleDAO &SongDAOImpl::getRoleDAO() const
{
    return(mRefRoleDAO);
}

SingleDAO &SongDAOImpl::getSingleDAO() const
{
    return(mRefSingleDAO);
}

Song &SongDAOImpl::insert(const Song &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into Songs (AlbumId, SingleId) values(?, ?);");

    getSingleDAO().save(refToSave);

    objQuery.bindValue(1, refToSave.getAlbum().getAlbumId());
    objQuery.bindValue(2, refToSave.getSingleId());

    if(objQuery.exec())
        const_cast<Song &>(refToSave).setSongId(objQuery.lastInsertId().toUInt());

    return(const_cast<Song &>(refToSave));
}

bool SongDAOImpl::isTableExists() const
{
    return(const_cast<SongDAOImpl &>(*this).getTableUtils().isTableExists("Songs"));
}

void SongDAOImpl::removeTable()
{
    getTableUtils().removeTable("Songs");
}

Song &SongDAOImpl::update(const Song &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("update Songs set AlbumId = ?, SingleId = ? where SongId = ?;");

    getSingleDAO().save(refToSave);

    objQuery.bindValue(1, refToSave.getAlbum().getAlbumId());
    objQuery.bindValue(2, refToSave.getSingleId());
    objQuery.bindValue(3, refToSave.getSongId());

    objQuery.exec();

    return(const_cast<Song &>(refToSave));
}

SongDAOImpl::SongDAOImpl(const QSqlDatabase &refDatabase)
    : AbstractDAO<Song>(refDatabase)
    , mRefAlbumDAO(BeanFactory::getInstance().getAlbumDAO())
    , mRefMediaDAO(BeanFactory::getInstance().getMediaDAO())
    , mRefRoleDAO(BeanFactory::getInstance().getRoleDAO())
    , mRefSingleDAO(BeanFactory::getInstance().getSingleDAO())
{ }

SongDAOImpl::~SongDAOImpl()
{ }

bool SongDAOImpl::createTable() const
{
    if(!isTableExists())
        {
        QSqlQuery objQuery(getDatabase());

        objQuery.prepare("create table Songs(SongId int not null auto_increment primary key, AlbumId int not null, SingleId int not null, foreign key(AlbumId) references Albums(AlbumId), foreign key(SingleId) references Singles(SingleId));");

        return(objQuery.exec());
        }
    else
        return(true);
}

Song SongDAOImpl::getById(const unsigned uiSongId) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select SongId, AlbumId, SingleId from Songs where SongId = ?;");

    objQuery.bindValue(1, uiSongId);

    if(objQuery.exec())
        return(const_cast<SongDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(Song());
}

Song SongDAOImpl::getByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select SongId, AlbumId, SingleId from Songs inner join Singles on Song.SingleId = Singles.SingleId inner join Media on Singles.MediaId = Media.MediaId and Media.Name = ? and Media.ReleaseDate between ? and ?;");

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<SingleDAOImpl &>(getSingleDAO()).createTable();

    objQuery.bindValue(1, sName);
    objQuery.bindValue(2, QDate(static_cast<int>(uiReleaseYear), 1, 1));
    objQuery.bindValue(3, QDate(static_cast<int>(uiReleaseYear) + 1, 1, 1));

    if(objQuery.exec())
        return(const_cast<SongDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(Song());
}

QList<Song> SongDAOImpl::list() const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select SongId, AlbumId, SingleId from Songs;");

    if(objQuery.exec())
        return(const_cast<SongDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Song>());
}

QList<Song> SongDAOImpl::listByAlbum(const Album &refAlbum) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select SongId, AlbumId, SingleId from Songs where AlbumId = ?;");

    objQuery.bindValue(1, refAlbum.getAlbumId());

    if(objQuery.exec())
        return(const_cast<SongDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Song>());
}

QList<Song> SongDAOImpl::listByArtist(const Artist &refArtist) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select SongId, AlbumId, SingleId from Songs inner join Singles on SingleId = Songs.SingleId inner join Media on Singles.MediaId = Media.MediaId inner join Roles on Roles.MediaId = Media.MediaId and Roles.ArtistId = ?;");

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<RoleDAOImpl &>(getRoleDAO()).createTable();
    static_cast<SingleDAOImpl &>(getSingleDAO()).createTable();

    objQuery.bindValue(1, refArtist.getArtistId());

    if(objQuery.exec())
        return(const_cast<SongDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Song>());
}

QList<Song> SongDAOImpl::listByName(const QString &sName) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select SongId, AlbumId, SingleId from Songs inner join Singles on Songs.SingleId = Singles.SingleId inner join Media on Singles.MediaId = Media.MediaId and Media.Name = ?;");

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<SingleDAOImpl &>(getSingleDAO()).createTable();

    objQuery.bindValue(1, sName);

    if(objQuery.exec())
        return(const_cast<SongDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Song>());
}

QList<Song> SongDAOImpl::listByWordInComments(const QString &sWord) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select SongId, AlbumId, SingleId from Songs inner join Singles on Songs.SingleId = Singles.SingleId and Singles.Comments like ?;");

    static_cast<SingleDAOImpl &>(getSingleDAO()).createTable();

    objQuery.bindValue(1, "%" + sWord + "%");

    if(objQuery.exec())
        return(const_cast<SongDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Song>());
}

bool SongDAOImpl::remove(const Song &refToRemove) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("delete from Songs where SongId = ?;");

    objQuery.bindValue(1, refToRemove.getSongId());

    return(objQuery.exec());
}

Song &SongDAOImpl::save(const Song &refToSave) const
{
    if(!isTableExists())
        createTable();

    if(refToSave.getSongId() > 0)
        return(update(refToSave));
    else
        return(insert(refToSave));
}
