#include "BeanFactory.h"

using namespace net::draconia;

BeanFactory BeanFactory::msObjBeanFactory;

BeanFactory::BeanFactory()
{
    mDbDatabase = QSqlDatabase::addDatabase("QMYSQL");
}

BeanFactory &BeanFactory::getInstance()
{
    return(msObjBeanFactory);
}

QSqlDatabase &BeanFactory::getDatabase()
{
    if(!mDbDatabase.isOpen())
        {
        mDbDatabase.setDatabaseName("Media");
        mDbDatabase.setHostName("localhost");
        mDbDatabase.setPassword("R3g1n@ 1$ my Qu3En!");
        mDbDatabase.setPort(3306);
        mDbDatabase.setUserName("root");
        mDbDatabase.open();
        }

    return(mDbDatabase);
}
