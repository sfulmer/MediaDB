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
                    static const QString TableName;

                    MediaDAO &mRefMediaDAO;
                protected:
                    virtual Book createObjectFromResults(const QSqlRecord &refRecord);
                    MediaDAO &getMediaDAO() const;
                    virtual QString getPrimaryKey() const;
                    virtual QString getQueriedColumnsForSelect() const;
                    virtual QString getTableName() const;
                    virtual Book &insert(const Book &refToSave) const;
                    virtual Book &update(const Book &refToSave) const;
                public:
                    BookDAOImpl(const QSqlDatabase &refDatabase = BeanFactory::getInstance().getDatabase());
                    virtual ~BookDAOImpl();
                    virtual bool createTable() const;
                    virtual Book getById(const unsigned uiBookId) const;
                    virtual QList<Book> listByCollection(const QString &sCollection) const;
                    virtual QList<Book> listByWordInComments(const QString &sWord) const;
                    virtual bool remove(const Book &refToRemove) const;
                    virtual Book &save(const Book &refToSave) const;
                };
            }
        }
    }
}
