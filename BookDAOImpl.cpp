#include "BookDAOImpl.h"
#include<QtSql/QSqlField>

using namespace net::draconia::mediadb::dao;

const QString BookDAOImpl::TableName("Books");

Book BookDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    Media objMedia = getMediaDAO().getById(refRecord.field("MediaId").value().toUInt());

    return(Book (   objMedia.getMediaId()
                ,   refRecord.field("BookId").value().toUInt()
                ,   objMedia.getName()
                ,   objMedia.getReleaseDate()
                ,   objMedia.getFilePath()
                ,   objMedia.getArtists()
                ,   refRecord.field("Comments").value().toString()
                ,   refRecord.field("Collection").value().toString()));
}

MediaDAO &BookDAOImpl::getMediaDAO() const
{
    return(mRefMediaDAO);
}

QString BookDAOImpl::getPrimaryKey() const
{
    return("BookId");
}

QString BookDAOImpl::getQueriedColumnsForSelect() const
{
    return("MediaId, Comments, Collection");
}

QString BookDAOImpl::getTableName() const
{
    return(TableName);
}

Book &BookDAOImpl::insert(const Book &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into " + getTableName() + " (" + getQueriedColumnsForSelect() + ") values(?, ?, ?);");

    getMediaDAO().save(refToSave);

    objQuery.bindValue(1, refToSave.getMediaId());
    objQuery.bindValue(2, refToSave.getComments());
    objQuery.bindValue(3, refToSave.getCollection());

    if(objQuery.exec())
        const_cast<Book &>(refToSave).setBookId(objQuery.lastInsertId().toUInt());

    return(const_cast<Book &>(refToSave));
}

Book &BookDAOImpl::update(const Book &refToSave) const
{
   QSqlQuery objQuery(getDatabase());

   objQuery.prepare("update " + getTableName() + " set MediaId = ?, Comments = ?, Collection = ? where BookId = ?;");

   getMediaDAO().save(refToSave);

   objQuery.bindValue(1, refToSave.getMediaId());
   objQuery.bindValue(2, refToSave.getComments());
   objQuery.bindValue(3, refToSave.getCollection());
   objQuery.bindValue(4, refToSave.getBookId());

   return(const_cast<Book &>(refToSave));
}

BookDAOImpl::BookDAOImpl(const QSqlDatabase &refDatabase)
    : AbstractDAO<Book>(refDatabase)
    , mRefMediaDAO(BeanFactory::getInstance().getMediaDAO())
{ }

BookDAOImpl::~BookDAOImpl()
{ }

bool BookDAOImpl::createTable() const
{
    if(!isTableExists())
        {
        QSqlQuery objQuery(getDatabase());

        objQuery.prepare("create table " + getTableName() + " (" + getPrimaryKey() + " int not null auto_increment primary key, MediaId int not null, Comments varchar(32000) not null default ' ', Collection varchar(255) not null default ' ', foreign key(MediaId) references Media(MediaId), index(Collection))");

        return(objQuery.exec());
        }
    else
        return(true);
}

Book BookDAOImpl::getById(const unsigned uiBookId) const
{
    return(AbstractDAO<Book>::getById(uiBookId));
}

QList<Book> BookDAOImpl::listByCollection(const QString &sCollection) const
{
   if(!isTableExists())
       createTable();

   QSqlQuery objQuery(getDatabase());

   objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + "where Collection = ?;");

   objQuery.bindValue(1, sCollection);

   if(objQuery.exec())
       return(const_cast<BookDAOImpl &>(*this).createObjectListFromResults(objQuery));
   else
       return(QList<Book>());
}

QList<Book> BookDAOImpl::listByWordInComments(const QString &sWord) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + "where Comment like ?;");

    objQuery.bindValue(1, "%" + sWord + "%");

    if(objQuery.exec())
        return(const_cast<BookDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Book>());
}

bool BookDAOImpl::remove(const Book &refToRemove) const
{
    return(AbstractDAO<Book>::remove(refToRemove.getBookId()));
}

Book &BookDAOImpl::save(const Book &refToSave) const
{
    if(!isTableExists())
        createTable();

    if(refToSave.getBookId() > 0)
        return(update(refToSave));
    else
        return(insert(refToSave));
}
