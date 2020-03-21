#include "MediaFile.h"

using namespace net::draconia::mediadb::dbo;

MediaFile::MediaFile()
    : Observable()
{ }

MediaFile::MediaFile(const QString &sFilePath)
    : Observable()
    , msFilePath(sFilePath)
{ }

MediaFile::MediaFile(const MediaFile &refCopy)
    : Observable(refCopy)
    , msFilePath(refCopy.getFilePath())
{ }

MediaFile::~MediaFile()
{ }

QString MediaFile::getFilePath() const
{
    return(msFilePath);
}

void MediaFile::setFilePath(const QString &sFilePath)
{
    msFilePath = sFilePath;

    setChanged();
    notifyObservers("FilePath");
}

MediaFile &MediaFile::operator=(const MediaFile &refCopy)
{
    setFilePath(refCopy.getFilePath());

    return(*this);
}

bool MediaFile::operator==(const MediaFile &refOther) const
{
    return(getFilePath() == refOther.getFilePath());
}

bool MediaFile::operator!=(const MediaFile &refOther) const
{
    return(!operator==(refOther));
}
