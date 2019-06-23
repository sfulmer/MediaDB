#include "ArtistDAOImpl.h"
#include "Media.h"
#include<QtSql/QSqlField>

using namespace net::draconia::mediadb::dao;

const QString ArtistDAOImpl::TableName("Artists");

Artist ArtistDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    Artist objArtist;

    objArtist.setArtistId(refRecord.field("ArtistId").value().toUInt());
    objArtist.setName(refRecord.field("Name").value().toString());

    for(Role objRole : getRoleDAO().listByArtist(objArtist.getArtistId()))
        objArtist.addRole(objRole);

    return(objArtist);
}

QString ArtistDAOImpl::getPrimaryKey() const
{
    return("ArtistId");
}

QString ArtistDAOImpl::getQueriedColumnsForSelect() const
{
    return("Name");
}

RoleDAO &ArtistDAOImpl::getRoleDAO() const
{
    return(mRefRoleDAO);
}

QString ArtistDAOImpl::getTableName() const
{
    return(TableName);
}

Artist &ArtistDAOImpl::insert(const Artist &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    if(!isTableExists())
        createTable();

    objQuery.prepare("insert into " + getTableName() + " (" + getQueriedColumnsForSelect() + ") values (?);");

    objQuery.bindValue(1, refToSave.getName());

    for(Role objRole : refToSave.getRoles())
        getRoleDAO().save(objRole);

    if(objQuery.exec())
        const_cast<Artist &>(refToSave).setArtistId(objQuery.lastInsertId().toUInt());

    return(const_cast<Artist &>(refToSave));
}

Artist &ArtistDAOImpl::update(const Artist &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    if(!isTableExists())
        createTable();

    objQuery.prepare("update " + getTableName() + " set Name = ? where " + getPrimaryKey() + " = ?;");

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

        objQuery.prepare("create table " + TableName + "(ArtistId int not null auto_increment primary key, Name varchar(255) not nullate not null, unique key(Name));");

        return(objQuery.exec());
        }
    else
        return(true);
}

Artist ArtistDAOImpl::getById(const unsigned uiArtistId) const
{
    return(AbstractDAO<Artist>::getById(uiArtistId));
}

Artist ArtistDAOImpl::getByNameRoleTypeAndRoleName(const QString &sName, const RoleType &refRoleType, const QString sRoleName) const
{
    QSqlQuery objQuery(getDatabase());

    if(!isTableExists())
        createTable();

    objQuery.prepare("select " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Role on Role.ArtistId = Artist.ArtistId and Role.RoleTypeId = ? and Role.Name = ? where Artist.Name = ?;");

    objQuery.bindValue(1, refRoleType.getRoleTypeId());
    objQuery.bindValue(2, sRoleName);
    objQuery.bindValue(3, sName);

    if(objQuery.exec())
        return(const_cast<ArtistDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(Artist());
}

QList<Artist> ArtistDAOImpl::listByMedia(const Media &refMedia) const
{
    QSqlQuery objQuery(getDatabase());

    if(!isTableExists())
        createTable();

    objQuery.prepare("select " + getQueriedColumnsForSelect() + " from " + getTableName() + " where Artist.MediaId = ?;");

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

    objQuery.prepare("select " + getQueriedColumnsForSelect() + " from " + getTableName() + " inner join Role on Role.ArtistId = Artist.ArtistId and ROle.RoleTypeId = ? where Artist.MediaId = ?;");

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

    objQuery.prepare("select " + getQueriedColumnsForSelect() + " from " + getTableName() + " where Artist.Name = ?;");

    objQuery.bindValue(1, sName);

    if(objQuery.exec())
        return(const_cast<ArtistDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Artist>());
}

bool ArtistDAOImpl::remove(const Artist &refToRemove) const
{
    return(AbstractDAO<Artist>::remove(refToRemove.getArtistId()));
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
