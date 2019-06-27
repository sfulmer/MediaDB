#include "ArtistDAOImpl.h"
#include "Media.h"
#include<QtSql/QSqlField>
#include "RoleDAOImpl.h"

using namespace net::draconia::mediadb::dao;

Artist ArtistDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    Artist objArtist;

    objArtist.setArtistId(refRecord.field("ArtistId").value().toUInt());
    objArtist.setName(refRecord.field("Name").value().toString());

    for(Role objRole : getRoleDAO().listByArtist(objArtist.getArtistId()))
        objArtist.addRole(objRole);

    return(objArtist);
}

RoleDAO &ArtistDAOImpl::getRoleDAO() const
{
    return(mRefRoleDAO);
}

Artist &ArtistDAOImpl::insert(const Artist &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into Artists (Name) values (?);");

    objQuery.bindValue(1, refToSave.getName());

    for(Role objRole : refToSave.getRoles())
        getRoleDAO().save(objRole);

    if(objQuery.exec())
        const_cast<Artist &>(refToSave).setArtistId(objQuery.lastInsertId().toUInt());

    return(const_cast<Artist &>(refToSave));
}

bool ArtistDAOImpl::isTableExists() const
{
    return(const_cast<ArtistDAOImpl &>(*this).getTableUtils().isTableExists("Artists"));
}

void ArtistDAOImpl::removeTable()
{
    getTableUtils().removeTable("Artists");
}

Artist &ArtistDAOImpl::update(const Artist &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("update Artists set Name = ? where ArtistId = ?;");

    objQuery.bindValue(1, refToSave.getName());
    objQuery.bindValue(2, refToSave.getArtistId());

    for(Role objRole : refToSave.getRoles())
        getRoleDAO().save(objRole);

    return(const_cast<Artist &>(refToSave));
}

ArtistDAOImpl::ArtistDAOImpl(const QSqlDatabase &refDatasource)
    : AbstractDAO<Artist>(refDatasource)
    , mRefRoleDAO(BeanFactory::getInstance().getRoleDAO())
{ }

ArtistDAOImpl::~ArtistDAOImpl()
{ }

bool ArtistDAOImpl::createTable() const
{
    if(!isTableExists())
        {
        QSqlQuery objQuery(getDatabase());

        objQuery.prepare("create table Artists(ArtistId int not null auto_increment primary key, Name varchar(255) not null, unique key(Name));");

        return(objQuery.exec());
        }
    else
        return(true);
}

Artist ArtistDAOImpl::getById(const unsigned uiArtistId) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select ArtistId, Name from Artists where ArtistId = ?;");

    objQuery.bindValue(1, uiArtistId);

    if(objQuery.exec())
        return(const_cast<ArtistDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(Artist());
}

Artist ArtistDAOImpl::getByNameRoleTypeAndRoleName(const QString &sName, const RoleType &refRoleType, const QString sRoleName) const
{
    QSqlQuery objQuery(getDatabase());

    if(!isTableExists())
        createTable();

    objQuery.prepare("select ArtistId, Name from Artists inner join Roles on Roles.ArtistId = Artist.ArtistId and Roles.RoleTypeId = ? and Roles.Name = ? where Artist.Name = ?;");

    static_cast<RoleDAOImpl &>(getRoleDAO()).createTable();

    objQuery.bindValue(1, refRoleType.getRoleTypeId());
    objQuery.bindValue(2, sRoleName);
    objQuery.bindValue(3, sName);

    if(objQuery.exec())
        return(const_cast<ArtistDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(Artist());
}

QList<Artist> ArtistDAOImpl::list() const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select ArtistId, Name from Artists;");

    if(objQuery.exec())
        return(const_cast<ArtistDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Artist>());
}

QList<Artist> ArtistDAOImpl::listByMedia(const Media &refMedia) const
{
    QSqlQuery objQuery(getDatabase());

    if(!isTableExists())
        createTable();

    objQuery.prepare("select ArtistId, Name from Artists inner join Roles on Artists.ArtistId = Roles.ArtistId and Roles.MediaId = ?;");

    static_cast<RoleDAOImpl &>(getRoleDAO()).createTable();

    objQuery.bindValue(1, refMedia.getMediaId());

    if(objQuery.exec())
        return(const_cast<ArtistDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Artist>());
}

QList<Artist> ArtistDAOImpl::listByMediaAndRoleType(const Media &refMedia, const RoleType &refRoleType) const
{
    QSqlQuery objQuery(getDatabase());

    if(!isTableExists())
        createTable();

    objQuery.prepare("select ArtistId, Name from Artists from Artists inner join Roles on Roles.ArtistId = Artist.ArtistId and Roles.RoleTypeId = ? and Roles.MediaId = ?;");

    static_cast<RoleDAOImpl &>(getRoleDAO()).createTable();

    objQuery.bindValue(1, refRoleType.getRoleTypeId());
    objQuery.bindValue(2, refMedia.getMediaId());

    if(objQuery.exec())
        return(const_cast<ArtistDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Artist>());
}

QList<Artist> ArtistDAOImpl::listByName(const QString &sName) const
{
    QSqlQuery objQuery(getDatabase());

    if(!isTableExists())
        createTable();

    objQuery.prepare("select ArtistId, Name from Artists from Artists where Artist.Name = ?;");

    objQuery.bindValue(1, sName);

    if(objQuery.exec())
        return(const_cast<ArtistDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Artist>());
}

bool ArtistDAOImpl::remove(const Artist &refToRemove) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("delete from Artists where ArtistId = ?;");

    objQuery.bindValue(1, refToRemove.getArtistId());

    return(objQuery.exec());
}

Artist &ArtistDAOImpl::save(const Artist &refToSave) const
{
    if(!isTableExists())
        createTable();

    if(refToSave.getArtistId() > 0)
        return(update(refToSave));
    else
        return(insert(refToSave));
}
