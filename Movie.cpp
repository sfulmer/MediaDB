#include "DBO.h"

using namespace net::draconia::dbo;

QList<QDateTime> &Movie::getViewingsInternal() const
{
    return(const_cast<QList<QDateTime> &>(mLstViewings));
}

void Movie::setViewings(const QList<QDateTime> &lstViewings)
{
    mLstViewings.clear();
    mLstViewings.append(lstViewings);
}

Movie::Movie()
    : Media(), muiMovieId(0)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease)
    , muiMovieId(0)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear)
    , muiMovieId(0)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease)
    : Media(uiMediaId, sName, dtRelease)
    , muiMovieId(uiMovieId)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear)
    : Media(uiMediaId, sName, uiReleaseYear)
    , muiMovieId(uiMovieId)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, dtRelease)
    , muiMovieId(0)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear)
    , muiMovieId(0)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, dtRelease)
    , muiMovieId(uiMovieId)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear)
    , muiMovieId(uiMovieId)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiMovieId(0)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiMovieId(0)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiMovieId(uiMovieId)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiMovieId(uiMovieId)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiMovieId(0)
    , msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiMovieId(0)
    , msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiMovieId(0)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiMovieId(0)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiMovieId(0)
    , msComments(sComments)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiMovieId(0)
    , msComments(sComments)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiMovieId(uiMovieId)
    , msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiMovieId(uiMovieId)
    , msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiMovieId(uiMovieId)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiMovieId(uiMovieId)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, sFilePath)
    , muiMovieId(uiMovieId)
    , msComments(sComments)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath)
    , muiMovieId(uiMovieId)
    , msComments(sComments)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiMovieId(0)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiMovieId(0)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiMovieId(uiMovieId)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiMovieId(uiMovieId)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiMovieId(0)
    , msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiMovieId(0)
    , msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiMovieId(0)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiMovieId(0)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiMovieId(0)
    , msComments(sComments)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiMovieId(0)
    , msComments(sComments)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiMovieId(uiMovieId)
    , msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiMovieId(uiMovieId)
    , msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiMovieId(uiMovieId)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiMovieId(uiMovieId)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, lstArtists)
    , muiMovieId(uiMovieId)
    , msComments(sComments)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, lstArtists)
    , muiMovieId(uiMovieId)
    , msComments(sComments)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiMovieId(0)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiMovieId(0)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiMovieId(uiMovieId)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiMovieId(uiMovieId)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiMovieId(0)
    , msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiMovieId(0)
    , msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiMovieId(0)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiMovieId(0)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiMovieId(uiMovieId)
    , msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiMovieId(uiMovieId)
    , msComments(sComments)
{ }

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiMovieId(uiMovieId)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiMovieId(uiMovieId)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, dtRelease, sFilePath, lstArtists)
    , muiMovieId(uiMovieId)
    , msComments(sComments)
{
    setViewings(lstViewings);
}

Movie::Movie(const unsigned uiMediaId, const unsigned uiMovieId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QList<QDateTime> &lstViewings)
    : Media(uiMediaId, sName, uiReleaseYear, sFilePath, lstArtists)
    , muiMovieId(uiMovieId)
    , msComments(sComments)
{
    setViewings(lstViewings);
}

Movie::Movie(const Movie &refCopy)
    : Media(refCopy.getMediaId(), refCopy.getName(), refCopy.getReleaseDate(), refCopy.getFilePath(), refCopy.getArtists())
    , muiMovieId(refCopy.getMovieId())
    , msComments(refCopy.getComments())
{
    setViewings(refCopy.getViewings());
}

Movie::~Movie()
{ }

void Movie::addViewing(const QDateTime &dtViewing)
{
    getViewingsInternal().append(dtViewing);

    setChanged();
    notifyObservers();
}

unsigned Movie::getMovieId() const
{
    return(muiMovieId);
}

QString &Movie::getComments() const
{
    return(const_cast<QString &>(msComments));
}

const QList<QDateTime> &Movie::getViewings() const
{
    return(getViewingsInternal());
}

bool Movie::removeViewing(const QDateTime &dtViewing)
{
    bool bReturnValue = getViewingsInternal().removeOne(dtViewing);

    setChanged();
    notifyObservers();

    return(bReturnValue);
}

void Movie::removeViewing(const unsigned uiIndex)
{
    getViewingsInternal().removeAt(static_cast<int>(uiIndex));

    setChanged();
    notifyObservers();
}

void Movie::setComments(const QString &sComments)
{
    msComments = sComments;

    setChanged();
    notifyObservers();
}

void Movie::setMovieId(const unsigned uiMovieId)
{
    muiMovieId = uiMovieId;

    setChanged();
    notifyObservers();
}
