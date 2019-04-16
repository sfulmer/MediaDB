#include "DBO.h"

using namespace net::draconia::dbo;

Book::Book()
    : Media(), muiBookId(0)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease)
    , muiBookId(0)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear)
    , muiBookId(0)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease)
    , muiBookId(uiBookId)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear)
    , muiBookId(uiBookId)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiBookId(0)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiBookId(0)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiBookId(uiBookId)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiBookId(uiBookId)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiBookId(0)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiBookId(0)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiBookId(uiBookId)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiBookId(uiBookId)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QString &sCollection)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiBookId(0)
    , msCollection(sCollection)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QString &sCollection)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiBookId(0)
    , msCollection(sCollection)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QString &sCollection)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiBookId(uiBookId)
    , msCollection(sCollection)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QString &sCollection)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiBookId(uiBookId)
    , msCollection(sCollection)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiBookId(0)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiBookId(0)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiBookId(uiBookId)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiBookId(uiBookId)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiBookId(0)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiBookId(0)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiBookId(uiBookId)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiBookId(uiBookId)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiBookId(0)
    , msCollection(sCollection)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiBookId(0)
    , msCollection(sCollection)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiBookId(uiBookId)
    , msCollection(sCollection)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiBookId(uiBookId)
    , msCollection(sCollection)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiBookId(0)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiBookId(0)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiBookId(uiBookId)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiBookId(uiBookId)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiBookId(0)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiBookId(0)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiBookId(uiBookId)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiBookId(uiBookId)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiBookId(0)
    , msCollection(sCollection)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiBookId(0)
    , msCollection(sCollection)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiBookId(uiBookId)
    , msCollection(sCollection)
    , msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiBookId(uiBookId)
    , msCollection(sCollection)
    , msComments(sComments)
{ }

Book::Book(const Book &refCopy)
    : Media(refCopy.getMediaId(), refCopy.getName(), refCopy.getReleaseDate(), refCopy.getFilePath(), refCopy.getArtists())
    , muiBookId(refCopy.getBookId())
    , msCollection(refCopy.getCollection())
    , msComments(refCopy.getComments())
{ }

Book::~Book()
{ }

unsigned Book::getBookId() const
{
    return(muiBookId);
}

QString &Book::getCollection() const
{
    return(const_cast<QString &>(msCollection));
}

QString &Book::getComments() const
{
    return(const_cast<QString &>(msComments));
}

void Book::setBookId(const unsigned uiBookId)
{
    muiBookId = uiBookId;

    setChanged();
    notifyObservers();
}

void Book::setCollection(const QString &sCollection)
{
    msCollection = sCollection;

    setChanged();
    notifyObservers();
}

void Book::setComments(const QString &sComments)
{
    msComments = sComments;

    setChanged();
    notifyObservers();
}
