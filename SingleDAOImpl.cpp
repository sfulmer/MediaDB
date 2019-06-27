#include "MediaDAOImpl.h"
#include<QtSql/QSqlField>
#include "RoleDAOImpl.h"
#include "SingleDAOImpl.h"

using namespace net::draconia::mediadb::dao;

using net::draconia::mediadb::dbo::Single;

Single SingleDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    Media objMedia = getMediaDAO().getById(refRecord.field("MediaId").value().toUInt());

    return(Single(  objMedia.getMediaId()
                 ,  refRecord.field("SingleId").value().toUInt()
                 ,  objMedia.getName()
                 ,  objMedia.getReleaseDate()
                 ,  objMedia.getFilePath()
                 ,  objMedia.getArtists()
                 ,  refRecord.field("Comments").value().toString()));
}

MediaDAO &SingleDAOImpl::getMediaDAO() const
{
    return(mRefMediaDAO);
}

RoleDAO &SingleDAOImpl::getRoleDAO() const
{
    return(mRefRoleDAO);
}

Single &SingleDAOImpl::insert(const Single &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into Singles (MediaId, Comments) values(?, ?);");

    getMediaDAO().save(refToSave);

    objQuery.bindValue(1, refToSave.getMediaId());
    objQuery.bindValue(2, refToSave.getComments());

    if(objQuery.exec())
        const_cast<Single &>(refToSave).setSingleId(objQuery.lastInsertId().toUInt());

    return(const_cast<Single &>(refToSave));
}

bool SingleDAOImpl::isTableExists() const
{
    return(const_cast<SingleDAOImpl &>(*this).getTableUtils().isTableExists("Singles"));
}

void SingleDAOImpl::removeTable()
{
    getTableUtils().removeTable("Singles");
}

Single &SingleDAOImpl::update(const Single &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("update Singles set MediaId = ?, Comments = ? where SingleId = ?;");

    getMediaDAO().save(refToSave);

    objQuery.bindValue(1, refToSave.getMediaId());
    objQuery.bindValue(2, refToSave.getComments());
    objQuery.bindValue(3, refToSave.getSingleId());

    objQuery.exec();

    return(const_cast<Single &>(refToSave));
}

SingleDAOImpl::SingleDAOImpl(const QSqlDatabase &refDatabase)
    : AbstractDAO<Single>(refDatabase)
    , mRefMediaDAO(BeanFactory::getInstance().getMediaDAO())
    , mRefRoleDAO(BeanFactory::getInstance().getRoleDAO())
{ }

SingleDAOImpl::~SingleDAOImpl()
{ }

bool SingleDAOImpl::createTable() const
{
    if(!isTableExists())
        {
        QSqlQuery objQuery(getDatabase());

        objQuery.prepare("create table Singles (SingleId int not null auto_increment primary key, MediaId int not null, Comments varchar(32000) default ' ', foreign key(MediaId) references Media(MediaId));");

        return(objQuery.exec());
        }
    else
        return(true);
}

Single SingleDAOImpl::getById(const unsigned uiSingleId) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select SingleId, MediaId, Comments from Singles where SingleId = ?;");

    objQuery.bindValue(1, uiSingleId);

    if(objQuery.exec())
        return(const_cast<SingleDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(Single());
}

Single SingleDAOImpl::getByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select SingleId, MediaId, Comments from Singles inner join Media on Singles.MediaId = Media.MediaId and Media.Name = ? and Media.ReleaseDate between ? and ?;");

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();

    objQuery.bindValue(1, sName);
    objQuery.bindValue(2, QDate(static_cast<int>(uiReleaseYear), 1, 1));
    objQuery.bindValue(2, QDate(static_cast<int>(uiReleaseYear) + 1, 1, 1));

    if(objQuery.exec())
        return(const_cast<SingleDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(Single());
}

QList<Single> SingleDAOImpl::list() const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select SingleId, MediaId, Comments from Singles;");

    if(objQuery.exec())
        return(const_cast<SingleDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Single>());
}

QList<Single> SingleDAOImpl::listByArtist(const Artist &refArtist) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select SingleId, MediaId, Comments from Singles inner join Media on Singles.MediaId = Media.MediaId inner join Roles on Roles.MediaId = Media.MediaId and Roles.ArtistId = ?;");

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();
    static_cast<RoleDAOImpl &>(getRoleDAO()).createTable();

    objQuery.bindValue(1, refArtist.getArtistId());

    if(objQuery.exec())
        return(const_cast<SingleDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Single>());
}

QList<Single> SingleDAOImpl::listByName(const QString &sName) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select SingleId, MediaId, Comments from Singles inner join Media on Singles.MediaId = Media.MediaId and Media.Name = ?;");

    static_cast<MediaDAOImpl &>(getMediaDAO()).createTable();

    objQuery.bindValue(1, sName);

    if(objQuery.exec())
        return(const_cast<SingleDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Single>());
}

QList<Single> SingleDAOImpl::listByWordInComments(const QString &sWord) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select SingleId, MediaId, Comments from Singles where Comments like ?;");

    objQuery.bindValue(1, "%" + sWord + "%");

    if(objQuery.exec())
        return(const_cast<SingleDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Single>());
}

bool SingleDAOImpl::remove(const Single &refToRemove) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("delete from Singles where SingleId = ?;");

    objQuery.bindValue(1, refToRemove.getSingleId());

    return(objQuery.exec());
}

Single &SingleDAOImpl::save(const Single &refToSave) const
{
    if(!isTableExists())
        createTable();

    if(refToSave.getSingleId() > 0)
        return(update(refToSave));
    else
        return(insert(refToSave));
}
