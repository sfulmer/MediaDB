#pragma once

#include<QtSql/QSqlDatabase>

using namespace net::draconia::dao;

namespace net
{
    namespace draconia
    {
        class BeanFactory
        {
            static BeanFactory msObjBeanFactory;

            QSqlDatabase mDbDatabase;
        protected:
            BeanFactory();
        public:
            static BeanFactory &getInstance();

            QSqlDatabase &getDatabase();
        };
    }
}
