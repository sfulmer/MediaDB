#include "MovieViewingDAOImpl.h"
#include<QtSql/QSqlField>

using namespace net::draconia::mediadb::dao;

const QString MovieViewingDAOImpl::TableName("MovieViewings");

MovieViewing MovieViewingDAOImpl::createObjectFromResults(const QSqlRecord &refRecord)
{
    return(MovieViewing (   refRecord.field("MovieViewingId").value().toUInt()
                        ,   getMovieDAO().getById(refRecord.field("MovieId").value().toUInt())
                        ,   refRecord.field("ViewingDate").value().toDateTime()));
}

MovieDAO &MovieViewingDAOImpl::getMovieDAO() const
{
    return(mRefMovieDAO);
}

QString MovieViewingDAOImpl::getPrimaryKey() const
{
    return("MovieViewingId");
}

QString MovieViewingDAOImpl::getQueriedColumnsForSelect() const
{
    return("MovieId, ViewingDate");
}

QString MovieViewingDAOImpl::getTableName() const
{
    return(TableName);
}

MovieViewing &MovieViewingDAOImpl::insert(const MovieViewing &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into " + getTableName() + "(" + getQueriedColumnsForSelect() + ") values (?, ?);");

    objQuery.bindValue(1, refToSave.getMovie().getMovieId());
    objQuery.bindValue(2, refToSave.getViewing());

    if(objQuery.exec())
        const_cast<MovieViewing &>(refToSave).setMovieViewingId(objQuery.lastInsertId().toUInt());

    return(const_cast<MovieViewing &>(refToSave));
}

MovieViewing &MovieViewingDAOImpl::update(const MovieViewing &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("update " + getTableName() + " set MovieId = ?, ViewingDate = ? where MovieViewingId = ;");

    objQuery.bindValue(1, refToSave.getMovie().getMovieId());
    objQuery.bindValue(2, refToSave.getViewing());
    objQuery.bindValue(3, refToSave.getMovieViewingId());

    objQuery.exec();

    return(const_cast<MovieViewing &>(refToSave));
}

MovieViewingDAOImpl::MovieViewingDAOImpl(const QSqlDatabase &refDatabase)
    : AbstractDAO<MovieViewing>(refDatabase)
    , mRefMovieDAO(BeanFactory::getInstance().getMovieDAO())
{ }

MovieViewingDAOImpl::~MovieViewingDAOImpl()
{ }

bool MovieViewingDAOImpl::createTable() const
{
    if(!isTableExists())
        {
        QSqlQuery objQuery(getDatabase());

        objQuery.prepare("create table " + getTableName() + "( " + getPrimaryKey() + " int not null auto_increment primary key, MovieId int not null, ViewingDate datetime not null, foreign key (MovieId) references Movies(MovieId));");

        return(objQuery.exec());
        }
    else
        return(true);
}

QList<MovieViewing> MovieViewingDAOImpl::listByMovie(const Movie &refMovie) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select " + getPrimaryKey() + ", " + getQueriedColumnsForSelect() + " from " + getTableName() + " where MovieId = ?;");

    objQuery.bindValue(1, refMovie.getMovieId());

    if(objQuery.exec())
        return(const_cast<MovieViewingDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<MovieViewing>());
}

bool MovieViewingDAOImpl::remove(const MovieViewing &refViewing) const
{
    return(AbstractDAO<MovieViewing>::remove(refViewing.getMovieViewingId()));
}

MovieViewing &MovieViewingDAOImpl::save(const MovieViewing &refToSave) const
{
    if(!isTableExists())
        createTable();

    if(refToSave.getMovieViewingId() > 0)
        return(update(refToSave));
    else
        return(insert(refToSave));
}
