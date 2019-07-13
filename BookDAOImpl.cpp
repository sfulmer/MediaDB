#include "BookDAOImpl.h"
#include<QtSql/QSqlField>

using namespace net::draconia::mediadb::dao;

Book BookDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    Media objMedia = getMediaDAO().getById(refRecord.field("MediaId").value().toUInt());
    Collection objCollection;

    if(refRecord.isNull("CollectionId"))
        objCollection = Collection();
    else
        objCollection = getCollectionDAO().getById(refRecord.field("Collectionid").value().toUInt());

    return(Book (   objMedia.getMediaId()
                ,   refRecord.field("BookId").value().toUInt()
                ,   objMedia.getName()
                ,   objMedia.getReleaseDate()
                ,   objMedia.getFilePath()
                ,   objMedia.getArtists()
                ,   refRecord.field("Comments").value().toString()
                ,   objCollection));
}

CollectionDAO &BookDAOImpl::getCollectionDAO() const
{
    return(mRefCollectionDAO);
}

MediaDAO &BookDAOImpl::getMediaDAO() const
{
    return(mRefMediaDAO);
}

Book &BookDAOImpl::insert(const Book &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into Books (MediaId, Comments, Collection) values(?, ?, ?);");

    getMediaDAO().save(refToSave);

    if(!refToSave.getCollection().getName().isEmpty())
        getCollectionDAO().save(refToSave.getCollection());

    objQuery.bindValue(1, refToSave.getMediaId());
    objQuery.bindValue(2, refToSave.getComments());

    if(refToSave.getCollection().getCollectionId() > 0)
        objQuery.bindValue(3, refToSave.getCollection().getCollectionId());
    else
        objQuery.bindValue(3, QVariant(QVariant::UInt));

    if(objQuery.exec())
        const_cast<Book &>(refToSave).setBookId(objQuery.lastInsertId().toUInt());

    return(const_cast<Book &>(refToSave));
}

bool BookDAOImpl::isTableExists() const
{
    return(const_cast<BookDAOImpl &>(*this).getTableUtils().isTableExists("Books"));
}

void BookDAOImpl::removeTable()
{
    getTableUtils().removeTable("Books");
}

Book &BookDAOImpl::update(const Book &refToSave) const
{
   QSqlQuery objQuery(getDatabase());

   objQuery.prepare("upate Books set MediaId = ?, Comments  ?, Collection = ? where BookId = ?;");

   getMediaDAO().save(refToSave);

   if(!refToSave.getCollection().getName().isEmpty())
       getCollectionDAO().save(refToSave.getCollection());

   objQuery.bindValue(1, refToSave.getMediaId());
   objQuery.bindValue(2, refToSave.getComments());

   if(refToSave.getCollection().getCollectionId() > 0)
       objQuery.bindValue(3, refToSave.getCollection().getCollectionId());
   else
       objQuery.bindValue(3, QVariant(QVariant::UInt));

   objQuery.bindValue(4, refToSave.getBookId());

   return(const_cast<Book &>(refToSave));
}

BookDAOImpl::BookDAOImpl(const QSqlDatabase &refDatabase)
    : AbstractDAO<Book>(refDatabase)
    , mRefCollectionDAO(BeanFactory::getInstance().getCollectionDAO())
    , mRefMediaDAO(BeanFactory::getInstance().getMediaDAO())\
{ }

BookDAOImpl::~BookDAOImpl()
{ }

bool BookDAOImpl::createTable() const
{
    if(!isTableExists())
        {
        QSqlQuery objQuery(getDatabase());

        objQuery.prepare("create table Books (BookId int not null auto_increment primary key, MediaId int not null, Comments varchar(32000) not null default ' ', Collection int null, foreign key(MediaId) references Media(MediaId), foreign key(Collection) references Collections(CollectionId));");

        return(objQuery.exec());
        }
    else
        return(true);
}

Book BookDAOImpl::getById(const unsigned uiBookId) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select BookId, MediaId, Comments, Collection from Books where BookId = ?;");

    objQuery.bindValue(1, uiBookId);

    if(objQuery.exec())
        return(const_cast<BookDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(Book());
}

QList<Book> BookDAOImpl::list() const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select BookId, MediaId, Comments, Collection from Books;");

    if(objQuery.exec())
        return(const_cast<BookDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Book>());
}

QList<Book> BookDAOImpl::listByCollection(const Collection &objCollection) const
{
   if(!isTableExists())
       createTable();

   QSqlQuery objQuery(getDatabase());

   objQuery.prepare("select BookId, MediaId, Comments, Collection from Books where Collection = ?;");

   objQuery.bindValue(1, objCollection.getCollectionId());

   if(objQuery.exec())
       return(const_cast<BookDAOImpl &>(*this).createObjectListFromResults(objQuery));
   else
       return(QList<Book>());
}

QList<Book> BookDAOImpl::listByNoCollection() const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select BookId, MediaId, Comments, Collection from Books where Collection is null;");

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

    objQuery.prepare("select BookId, MediaId, Comments, Collection from Books where Comment like ?;");

    objQuery.bindValue(1, "%" + sWord + "%");

    if(objQuery.exec())
        return(const_cast<BookDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<Book>());
}

bool BookDAOImpl::remove(const Book &refToRemove) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("delete from Books where BookId = ?;");

    objQuery.bindValue(1, refToRemove.getBookId());

    return(objQuery.exec());
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
