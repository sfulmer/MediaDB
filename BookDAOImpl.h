#pragma once

#include "AbstractDAO.h"
#include "BookDAO.h"
#include "MediaDAO.h"

using net::draconia::mediadb::dbo::Book;

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
                    MediaDAO &mRefMediaDAO;
                protected:
                    virtual Book createObjectFromResults(const QSqlRecord &refRecord);
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
                    virtual QList<Book> listByCollection(const QString &sCollection) const;
                    virtual QList<Book> listByWordInComments(const QString &sWord) const;
                    virtual bool remove(const Book &refToRemove) const;
                    virtual Book &save(const Book &refToSave) const;
                };
            }
        }
    }
}
