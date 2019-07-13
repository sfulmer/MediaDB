#pragma once

#include "Book.h"

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
                class BookDAO
                {
                public:
                    virtual ~BookDAO();

                    virtual Book getById(const unsigned uiBookId) const = 0;
                    virtual QList<Book> list() const = 0;
                    virtual QList<Book> listByCollection(const Collection &objCollection) const = 0;
                    virtual QList<Book> listByNoCollection() const = 0;
                    virtual QList<Book> listByWordInComments(const QString &sWord) const = 0;
                    virtual bool remove(const Book &refToRemove) const = 0;
                    virtual Book &save(const Book &refToSave) const = 0;
                };
            }
        }
    }
}
