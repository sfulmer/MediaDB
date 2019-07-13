#pragma once

#include "AbstractDAO.h"
#include "BookDAO.h"
#include "CollectionDAO.h"
#include "MediaDAO.h"

using net::draconia::mediadb::dbo::Book;
using net::draconia::mediadb::dbo::Collection;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                extern template class AbstractDAO<Book>;

                class BookDAOImpl : public AbstractDAO<Book>, public BookDAO
                {
                    CollectionDAO &mRefCollectionDAO;
                    MediaDAO &mRefMediaDAO;
                protected:
                    virtual Book createObjectFromResults(const QSqlRecord &refRecord);
                    CollectionDAO &getCollectionDAO() const;
                    MediaDAO &getMediaDAO() const;
                    virtual Book &insert(const Book &refToSave) const;
                    virtual bool isTableExists() const;
                    virtual void removeTable();
                    virtual Book &update(const Book &refToSave) const;
                public:
                    BookDAOImpl(const QSqlDatabase &refDatabase = BeanFactory::getInstance().getDatabase());
                    virtual ~BookDAOImpl();
                    virtual bool createTable() const;
                    virtual Book getById(const unsigned uiBookId) const;
                    virtual QList<Book> list() const;
                    virtual QList<Book> listByCollection(const Collection &objCollection) const;
                    virtual QList<Book> listByNoCollection() const;
                    virtual QList<Book> listByWordInComments(const QString &sWord) const;
                    virtual bool remove(const Book &refToRemove) const;
                    virtual Book &save(const Book &refToSave) const;
                };
            }
        }
    }
}
