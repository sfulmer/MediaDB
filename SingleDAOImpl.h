#pragma once

#include "AbstractDAO.h"
#include "BeanFactory.h"
#include "MediaDAO.h"
#include "RoleDAO.h"
#include "SingleDAO.h"

using net::draconia::mediadb::BeanFactory;

using net::draconia::mediadb::dbo::Single;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                extern template class AbstractDAO<Single>;
                class SingleDAOImpl : public AbstractDAO<Single>, public SingleDAO
                {
                    MediaDAO &mRefMediaDAO;
                    RoleDAO &mRefRoleDAO;
                protected:
                    virtual Single createObjectFromResults(const QSqlRecord &refRecord);
                    MediaDAO &getMediaDAO() const;
                    RoleDAO &getRoleDAO() const;
                    virtual Single &insert(const Single &refToSave) const;
                    virtual bool isTableExists() const;
                    virtual void removeTable();
                    virtual Single &update(const Single &refToSave) const;
                public:
                    SingleDAOImpl(const QSqlDatabase &refDatabase = BeanFactory::getInstance().getDatabase());
                    virtual ~SingleDAOImpl();

                    virtual bool createTable() const;
                    virtual Single getById(const unsigned uiSingleId) const;
                    virtual Single getByNameAndReleaseYear(const QString &sName, const unsigned uiReleaseYear) const;
                    virtual QList<Single> list() const;
                    virtual QList<Single> listByArtist(const Artist &refArtist) const;
                    virtual QList<Single> listByName(const QString &sName) const;
                    virtual QList<Single> listByWordInComments(const QString &sWord) const;
                    virtual bool remove(const Single &refToRemove) const;
                    virtual Single &save(const Single &refToSave) const;
                };
            }
        }
    }
}
