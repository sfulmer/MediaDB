#include<QtSql/QSqlField>
#include "RoleDAOImpl.h"
#include "RoleTypeDAO.h"

using namespace net::draconia::mediadb::dao;

Role RoleDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    return(Role (   refRecord.field("RoleId").value().toUInt()
                ,   getArtistDAO().getById(refRecord.field("ArtistId").value().toUInt())
                ,   getMediaDAO().getById(refRecord.field("MediaId").value().toUInt())
                ,   getRoleTypeDAO().getById(refRecord.field("RoleTypeId").value().toUInt())
                ,   refRecord.field("Name").value().toString()));
}

ArtistDAO &RoleDAOImpl::getArtistDAO() const
{
    return(mRefArtistDAO);
}

MediaDAO &RoleDAOImpl::getMediaDAO() const
{
    return(mRefMediaDAO);
}

RoleTypeDAO &RoleDAOImpl::getRoleTypeDAO() const
{
    return(mRefRoleTypeDAO);
}

Role &RoleDAOImpl::insert(const Role &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into Roles (ArtistId, MediaId, Name, RoleTypeId) values(?, ?, ?, ?);");

    getArtistDAO().save(refToSave.getArtist());
    getMediaDAO().save(refToSave.getMedia());
    getRoleTypeDAO().save(refToSave.getRoleType());

    objQuery.bindValue(1, refToSave.getArtist().getArtistId());
    objQuery.bindValue(2, refToSave.getMedia().getMediaId());
    objQuery.bindValue(3, refToSave.getName());
    objQuery.bindValue(4, refToSave.getRoleType().getRoleTypeId());

    if(objQuery.exec())
        const_cast<Role &>(refToSave).setRoleId(objQuery.lastInsertId().toUInt());

    return(const_cast<Role &>(refToSave));
}

bool RoleDAOImpl::isTableExists() const
{
    return(const_cast<RoleDAOImpl &>(*this).getTableUtils().isTableExists("Roles"));
}

void RoleDAOImpl::removeTable()
{
    getTableUtils().removeTable("Roles");
}

Role &RoleDAOImpl::update(const Role &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("update Roles set ArtistId = ?, MediaId = ?, Name = ?, RoleTypeId = ? where RoleId = ?;");

    objQuery.bindValue(1, refToSave.getArtist().getArtistId());
    objQuery.bindValue(2, refToSave.getMedia().getMediaId());
    objQuery.bindValue(3, refToSave.getName());
    objQuery.bindValue(4, refToSave.getRoleType().getRoleTypeId());

    objQuery.exec();

    return(const_cast<Role &>(refToSave));
}

RoleDAOImpl::RoleDAOImpl(const QSqlDatabase &refDatasource)
    : AbstractDAO<Role>(refDatasource)
    , mRefArtistDAO(BeanFactory::getInstance().getArtistDAO())
    , mRefMediaDAO(BeanFactory::getInstance().getMediaDAO())
    , mRefRoleTypeDAO(BeanFactory::getInstance().getRoleTypeDAO())
{ }

bool RoleDAOImpl::createTable() const
{
    if(!isTableExists())
        {
        QSqlQuery objQuery(getDatabase());

        reinterpret_cast<AbstractDAO<Artist> &>(getArtistDAO()).createTable();
        reinterpret_cast<AbstractDAO<Media> &>(getMediaDAO()).createTable();
        reinterpret_cast<AbstractDAO<RoleType> &>(getRoleTypeDAO()).createTable();

        objQuery.prepare("create table Roles (RoleId int not null auto_increment primary key, ArtistId int not null, MediaId int not null, Name varchar(255) not null, RoleTypeId int not null, foreign key(ArtistId) references Artists(ArtistId), foreign key(MediaId) references Media(MediaId), foreign key(RoleTypeId) references RoleTypes(RoleTypeId));");

        return(objQuery.exec());
        }
    else
        return(true);
}

Role RoleDAOImpl::getById(const unsigned uiRoleId) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select RoleId, ArtistId, MediaId, Name, RoleTypeId from Roles where RoleId = ?;");

    objQuery.bindValue(1, uiRoleId);

    if(objQuery.exec())
        return(const_cast<RoleDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(Role());
}

Role RoleDAOImpl::getByNameArtistMediaAndRoleType(const QString &sName, const Artist &refArtist, const Media &refMedia, const RoleType &refRoleType) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select RoleId, ArtistId, MediaId, Name, RoleTypeId from Roles where ArtistId = ? and MediaId = ? and Name = ? and RoleTypeId = ?;");

    objQuery.bindValue(1, refArtist.getArtistId());
    objQuery.bindValue(2, refMedia.getMediaId());
    objQuery.bindValue(3, sName);
    objQuery.bindValue(4, refRoleType.getRoleTypeId());

    if(objQuery.exec())
        return(const_cast<RoleDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(Role());
}

QList<Role> RoleDAOImpl::listByArtist(const Artist &refArtist) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select RoleId, ArtistId, MediaId, Name, RoleTypeId from Roles where ArtistId = ?;");

    objQuery.bindValue(1, refArtist.getArtistId());

    if(objQuery.exec())
        return(const_cast<RoleDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Role>());
}

QList<Role> RoleDAOImpl::listByArtistAndMedia(const Artist &refArtist, const Media &refMedia) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select RoleId, ArtistId, MediaId, Name, RoleTypeId from Roles where ArtistId = ? and MediaId = ?;");

    objQuery.bindValue(1, refArtist.getArtistId());
    objQuery.bindValue(2, refMedia.getMediaId());

    if(objQuery.exec())
        return(const_cast<RoleDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Role>());
}

QList<Role> RoleDAOImpl::listByArtistAndName(const Artist &refArtist, const QString &sName) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select RoleId, ArtistId, MediaId, Name, RoleTypeId from Roles where ArtistId = ? and Name = ?;");

    objQuery.bindValue(1, refArtist.getArtistId());
    objQuery.bindValue(2, sName);

    if(objQuery.exec())
        return(const_cast<RoleDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Role>());
}

QList<Role> RoleDAOImpl::listByMedia(const Media &refMedia) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select RoleId, ArtistId, MediaId, Name, RoleTypeId from Roles where MediaId = ?;");

    objQuery.bindValue(1, refMedia.getMediaId());

    if(objQuery.exec())
        return(const_cast<RoleDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Role>());
}

QList<Role> RoleDAOImpl::listByMediaAndName(const Media &refMedia, const QString &sName) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select RoleId, ArtistId, MediaId, Name, RoleTypeId from Roles where MediaId = ? and Name = ?;");

    objQuery.bindValue(1, refMedia.getMediaId());
    objQuery.bindValue(2, sName);

    if(objQuery.exec())
        return(const_cast<RoleDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Role>());
}

QList<Role> RoleDAOImpl::listByName(const QString &sName) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select RoleId, ArtistId, MediaId, Name, RoleTypeId from Roles where Name = ?;");

    objQuery.bindValue(1, sName);

    if(objQuery.exec())
        return(const_cast<RoleDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Role>());
}

QList<Role> RoleDAOImpl::listByNameAndRoleType(const QString &sName, const RoleType &refRoleType) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select RoleId, ArtistId, MediaId, Name, RoleTypeId from Roles where Name = ? and RoleTypeId = ?;");

    objQuery.bindValue(1, sName);
    objQuery.bindValue(2, refRoleType.getRoleTypeId());

    if(objQuery.exec())
        return(const_cast<RoleDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Role>());
}

QList<Role> RoleDAOImpl::listByRoleType(const RoleType &refRoleType) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select RoleId, ArtistId, MediaId, Name, RoleTypeId from Roles where RoleTypeId = ?;");

    objQuery.bindValue(1, refRoleType.getRoleTypeId());

    if(objQuery.exec())
        return(const_cast<RoleDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Role>());
}

bool RoleDAOImpl::remove(const Role &refRole) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("delete from Roles where RoleId = ?;");

    objQuery.bindValue(1, refRole.getRoleId());

    return(objQuery.exec());
}

Role RoleDAOImpl::save(const Role &refToSave) const
{
    if(!isTableExists())
        createTable();

    if(refToSave.getRoleId() > 0)
        return(update(refToSave));
    else
        return(insert(refToSave));
}
