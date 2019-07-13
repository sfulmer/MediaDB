#include "Collection.h"

using namespace net::draconia::mediadb::dbo;

Collection::Collection()
    : muiCollectionId(0)
{ }

Collection::Collection(const QString &sName)
    : muiCollectionId(0)
    , msName(sName)
{ }

Collection::Collection(const unsigned uiCollectionId, const QString &sName)
    : muiCollectionId(uiCollectionId)
    , msName(sName)
{ }

Collection::Collection(const Collection &refCopy)
    : muiCollectionId(refCopy.getCollectionId())
    , msName(refCopy.getName())
{ }

Collection::~Collection()
{ }

unsigned Collection::getCollectionId() const
{
    return(muiCollectionId);
}

QString Collection::getName() const
{
    return(msName);
}

void Collection::setCollectionId(const unsigned uiCollectionId)
{
    muiCollectionId = uiCollectionId;
}

void Collection::setName(const QString &sName)
{
    msName = sName;
}

Collection &Collection::operator=(const Collection &refCopy)
{
    setCollectionId(refCopy.getCollectionId());
    setName(refCopy.getName());

    return(*this);
}

bool Collection::operator==(const Collection &refOther)
{
    return(     (getCollectionId() == refOther.getCollectionId())
          &&    (getName() == refOther.getName()));
}

bool Collection::operator!=(const Collection &refOther)
{
    return(!operator==(refOther));
}
