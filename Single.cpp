#include "Single.h"

using namespace net::draconia::mediadb::dbo;

Single::Single()
    : Media(), muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease), muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear), muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease), muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear), muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath), muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath), muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath), msComments(sComments), muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), msComments(sComments), muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath), msComments(sComments), muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath), msComments(sComments), muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists), muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists), muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists), msComments(sComments), muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), msComments(sComments), muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists), msComments(sComments), muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists), msComments(sComments), muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), msComments(sComments), muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), msComments(sComments), muiSingleId(0)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists), msComments(sComments), muiSingleId(uiSingleId)
{ }

Single::Single(const unsigned uiMediaId, const unsigned uiSingleId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists), msComments(sComments), muiSingleId(uiSingleId)
{ }

Single::Single(const Single &refCopy)
    : Media(refCopy)
    , msComments(refCopy.getComments())
    , muiSingleId(refCopy.getSingleId())
{ }

Single::~Single()
{ }

QString Single::getComments() const
{
    return(msComments);
}

unsigned Single::getSingleId() const
{
    return(muiSingleId);
}

void Single::setComments(const QString &sComments)
{
    msComments = sComments;

    setChanged(true);
    notifyObservers();
}

void Single::setSingleId(const unsigned uiSingleId)
{
    muiSingleId = uiSingleId;

    setChanged(true);
    notifyObservers();
}

Single &Single::operator=(const Single &refCopy)
{
    Media::operator=(refCopy);

    setSingleId(refCopy.getSingleId());
    setComments(refCopy.getComments());

    return(*this);
}

bool Single::operator==(const Single &refOther) const
{
    return  (   Media::operator==(refOther)
            &&  (getSingleId() == refOther.getSingleId())
            &&  (getComments() == refOther.getComments()));
}

bool Single::operator!=(const Single &refOther) const
{
    return(!operator==(refOther));
}
