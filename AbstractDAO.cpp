#include "AbstractDAO.h"
#include "Album.h"
#include "Artist.h"
#include "Book.h"
#include "Collection.h"
#include "Media.h"
#include "Movie.h"
#include "MovieViewing.h"
#include<QVariant>
#include "Role.h"
#include "RoleType.h"
#include "Single.h"
#include "Song.h"
#include "TVEpisode.h"
#include "TVSeason.h"
#include "TVSeries.h"
#include "TVSpecial.h"

using namespace net::draconia::mediadb::dao;

using net::draconia::mediadb::dbo::Album;
using net::draconia::mediadb::dbo::Artist;
using net::draconia::mediadb::dbo::Book;
using net::draconia::mediadb::dbo::Collection;
using net::draconia::mediadb::dbo::Media;
using net::draconia::mediadb::dbo::Movie;
using net::draconia::mediadb::dbo::MovieViewing;
using net::draconia::mediadb::dbo::Role;
using net::draconia::mediadb::dbo::RoleType;
using net::draconia::mediadb::dbo::Single;
using net::draconia::mediadb::dbo::Song;
using net::draconia::mediadb::dbo::TVEpisode;
using net::draconia::mediadb::dbo::TVSeason;
using net::draconia::mediadb::dbo::TVSeries;
using net::draconia::mediadb::dbo::TVSpecial;

template<typename T>
void AbstractDAO<T>::closeConnection()
{
    if(getDatabase().isOpen())
        getDatabase().close();
}

template<typename T>
QList<T> AbstractDAO<T>::createObjectListFromResults(const QSqlQuery &refQuery)
{
    QList<T> lst;

    while(const_cast<QSqlQuery &>(refQuery).next())
        lst.append(createObjectFromResults(refQuery.record()));

    return(lst);
}

template<typename T>
QSqlDatabase &AbstractDAO<T>::getDatabase() const
{
    return(*mPtrDatasource);
}

template<typename T>
TableUtils &AbstractDAO<T>::getTableUtils()
{
    if(mPtrTableUtils == nullptr)
        mPtrTableUtils = new TableUtils(getDatabase());

    return(*mPtrTableUtils);
}

template<typename T>
AbstractDAO<T>::AbstractDAO(const QSqlDatabase &refDatasource)
    : mPtrDatasource(&const_cast<QSqlDatabase &>(refDatasource))
{ }

template<typename T>
AbstractDAO<T>::~AbstractDAO()
{
    if(mPtrTableUtils != nullptr)
        {
        delete mPtrTableUtils;

        mPtrTableUtils = nullptr;
        }
}

template class net::draconia::mediadb::dao::AbstractDAO<Album>;
template class net::draconia::mediadb::dao::AbstractDAO<Artist>;
template class net::draconia::mediadb::dao::AbstractDAO<Book>;
template class net::draconia::mediadb::dao::AbstractDAO<Collection>;
template class net::draconia::mediadb::dao::AbstractDAO<Media>;
template class net::draconia::mediadb::dao::AbstractDAO<Movie>;
template class net::draconia::mediadb::dao::AbstractDAO<MovieViewing>;
template class net::draconia::mediadb::dao::AbstractDAO<QDateTime>;
template class net::draconia::mediadb::dao::AbstractDAO<Role>;
template class net::draconia::mediadb::dao::AbstractDAO<RoleType>;
template class net::draconia::mediadb::dao::AbstractDAO<Single>;
template class net::draconia::mediadb::dao::AbstractDAO<Song>;
template class net::draconia::mediadb::dao::AbstractDAO<TVEpisode>;
template class net::draconia::mediadb::dao::AbstractDAO<TVSeason>;
template class net::draconia::mediadb::dao::AbstractDAO<TVSeries>;
template class net::draconia::mediadb::dao::AbstractDAO<TVSpecial>;
