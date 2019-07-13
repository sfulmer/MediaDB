#include "Book.h"

using namespace net::draconia::mediadb::dbo;

Book::Book()
    : Media(), muiBookId(0)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease), muiBookId(0)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear), muiBookId(0)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease), muiBookId(uiBookId)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear), muiBookId(uiBookId)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath), muiBookId(0)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), muiBookId(0)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath), muiBookId(uiBookId)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), muiBookId(uiBookId)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath), muiBookId(0), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), muiBookId(0), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath), muiBookId(uiBookId), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), muiBookId(uiBookId), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const Collection &objCollection)
    : Media(uiMediaId, sName, dtRelease, sFilePath), mObjCollection(objCollection), muiBookId(0), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const Collection &objCollection)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), mObjCollection(objCollection), muiBookId(0), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const Collection &objCollection)
    : Media(uiMediaId, sName, dtRelease, sFilePath), mObjCollection(objCollection), muiBookId(uiBookId), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const Collection &objCollection)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), mObjCollection(objCollection), muiBookId(uiBookId), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists), muiBookId(0)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), muiBookId(0)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists), muiBookId(uiBookId)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), muiBookId(uiBookId)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists), muiBookId(0), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), muiBookId(0), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists), muiBookId(uiBookId), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), muiBookId(uiBookId), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments, const Collection &objCollection)
    : Media(uiMediaId, sName, dtRelease, lstArtists), mObjCollection(objCollection), muiBookId(0), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments, const Collection &objCollection)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), mObjCollection(objCollection), muiBookId(0), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments, const Collection &objCollection)
    : Media(uiMediaId, sName, dtRelease, lstArtists), mObjCollection(objCollection), muiBookId(uiBookId), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments, const Collection &objCollection)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), mObjCollection(objCollection), muiBookId(uiBookId), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), muiBookId(0)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), muiBookId(0)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), muiBookId(uiBookId)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), muiBookId(uiBookId)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), muiBookId(0), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), muiBookId(0), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), muiBookId(uiBookId), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), muiBookId(uiBookId), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const Collection &objCollection)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), mObjCollection(objCollection), muiBookId(0), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const Collection &objCollection)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), mObjCollection(objCollection), muiBookId(0), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const Collection &objCollection)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), mObjCollection(objCollection), muiBookId(uiBookId), msComments(sComments)
{ }

Book::Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const Collection &objCollection)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), mObjCollection(objCollection), muiBookId(uiBookId), msComments(sComments)
{ }

Book::Book(const Book &refCopy)
    : Media(refCopy), mObjCollection(refCopy.getCollection()), muiBookId(refCopy.getBookId()), msComments(refCopy.getComments())
{ }

Book::~Book()
{ }

unsigned Book::getBookId() const
{
    return(muiBookId);
}

Collection Book::getCollection() const
{
    return(mObjCollection);
}

QString Book::getComments() const
{
    return(msComments);
}

void Book::setBookId(const unsigned uiBookId)
{
    muiBookId = uiBookId;

    setChanged(true);
    notifyObservers();
}
void Book::setCollection(const Collection &objCollection)
{
    mObjCollection = objCollection;

    setChanged(true);
    notifyObservers();
}

void Book::setComments(const QString &sComments)
{
    msComments = sComments;

    setChanged(true);
    notifyObservers();
}

Book &Book::operator=(const Book &refCopy)
{
    Media::operator=(refCopy);

    setBookId(refCopy.getBookId());
    setCollection(refCopy.getCollection());
    setComments(refCopy.getComments());

    return(*this);
}

bool Book::operator==(const Book &refOther) const
{
    return  (   (Media::operator==(refOther))
            &&  (getBookId() == refOther.getBookId())
            &&  (getCollection() == refOther.getCollection())
            &&  (getComments() == refOther.getComments()));
}

bool Book::operator!=(const Book &refOther) const
{
    return(!operator==(refOther));
}
