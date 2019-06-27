#include "MovieViewingDAOImpl.h"
#include<QtSql/QSqlField>

using namespace net::draconia::mediadb::dao;

using net::draconia::mediadb::dbo::MovieViewing;

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

MovieViewing &MovieViewingDAOImpl::insert(const MovieViewing &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("insert into MovieViewings (MovieId, ViewingDate) values(?, ?);");

    objQuery.bindValue(1, refToSave.getMovie().getMovieId());
    objQuery.bindValue(2, refToSave.getViewing());

    if(objQuery.exec())
        const_cast<MovieViewing &>(refToSave).setMovieViewingId(objQuery.lastInsertId().toUInt());

    return(const_cast<MovieViewing &>(refToSave));
}

bool MovieViewingDAOImpl::isTableExists() const
{
    return(const_cast<MovieViewingDAOImpl &>(*this).getTableUtils().isTableExists("MovieViewings"));
}

void MovieViewingDAOImpl::removeTable()
{
    getTableUtils().removeTable("MovieViewings");
}

MovieViewing &MovieViewingDAOImpl::update(const MovieViewing &refToSave) const
{
    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("update MovieViewings set MovieId = ?, ViewingDate = ? where MovieViewingId = ?;");

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

        objQuery.prepare("create table MovieViewings (MovieViewingId int not null auto_increment primary key, MovieId int not null, ViewingDate datetime not null, foreign key(MovieId) references Movies(MovieId));");

        return(objQuery.exec());
        }
    else
        return(true);
}

MovieViewing MovieViewingDAOImpl::getById(const unsigned uiMovieViewingId) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select MovieViewingId, MovieId, ViewingDate from MovieViewings where MovieViewingId = ?;");

    objQuery.bindValue(1, uiMovieViewingId);

    if(objQuery.exec())
        return(const_cast<MovieViewingDAOImpl &>(*this).createObjectFromResults(objQuery.record()));
    else
        return(MovieViewing());
}

QList<MovieViewing> MovieViewingDAOImpl::list() const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select MovieViewingId, MovieId, ViewingDate from MovieViewings;");

    if(objQuery.exec())
        return(const_cast<MovieViewingDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<MovieViewing>());
}

QList<MovieViewing> MovieViewingDAOImpl::listByMovie(const Movie &refMovie) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("select MovieViewingId, MovieId, ViewingDate from MovieViewings where MovieId = ?;");

    objQuery.bindValue(1, refMovie.getMovieId());

    if(objQuery.exec())
        return(const_cast<MovieViewingDAOImpl &>(*this).createObjectListFromResults(objQuery));
    else
        return(QList<MovieViewing>());
}

bool MovieViewingDAOImpl::remove(const MovieViewing &refViewing) const
{
    if(!isTableExists())
        createTable();

    QSqlQuery objQuery(getDatabase());

    objQuery.prepare("delete from MovieViewings where MovieViewingId = ?;");

    objQuery.bindValue(1, refViewing.getMovieViewingId());

    return(objQuery.exec());
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
