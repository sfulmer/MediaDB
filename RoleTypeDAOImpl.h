#pragma once

#include "AbstractDAO.h"
#include "RoleTypeDAO.h"

using net::draconia::mediadb::dbo::RoleType;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dao
            {
                extern template class AbstractDAO<RoleType>;

                class RoleTypeDAOImpl : public AbstractDAO<RoleType>, public RoleTypeDAO
                {
                    static const QString TableName;
                protected:
                    virtual RoleType createObjectFromResults(const QSqlRecord &refRecord);
                    virtual QString getPrimaryKey() const;
                    virtual QString getQueriedColumnsForSelect() const;
                    virtual QString getTableName() const;
                    virtual RoleType &insert(const RoleType &refToSave) const;
                    virtual RoleType &update(const RoleType &refToSave) const;
                public:
                    RoleTypeDAOImpl(const QSqlDatabase &refDatabase = BeanFactory::getInstance().getDatabase());
                    virtual ~RoleTypeDAOImpl();

                    virtual bool createTable() const;
                    virtual RoleType getById(const unsigned uiRoleTypeId) const;
                    virtual QList<RoleType> list() const;
                    virtual bool remove(const RoleType &refToRemove) const;
                    virtual RoleType &save(const RoleType &refToSave) const;
                };
            }
        }
    }
}
