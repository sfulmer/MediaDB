#include "Observable.h"

using namespace net::draconia::util;

QList<Observer *> &Observable::getObserversInternal()
{
    return(mLstObservers);
}

Observable::Observable()
    : mbChanged(false)
{ }

Observable::~Observable()
{ }

void Observable::addObserver(const Observer &refObserver)
{
    getObserversInternal().append(const_cast<Observer *>(static_cast<const Observer *>(&refObserver)));
}

const QList<Observer *> &Observable::getObservers()
{
    return(getObserversInternal());
}

bool Observable::isChanged() const
{
    return(mbChanged);
}

void Observable::notifyObservers(const QString &sProperty)
{
    for(Observer *ptrObserver : getObserversInternal())
        (*ptrObserver).update(*this, sProperty);

    setChanged(false);
}

void Observable::setChanged(const bool bChanged)
{
    mbChanged = bChanged;
}

bool Observable::operator==(const Observable &refOther) const
{
    return  (   (isChanged() == refOther.isChanged())
            &&  (mLstObservers == refOther.mLstObservers));
}

bool Observable::operator!=(const Observable &refOther) const
{
    return(!operator==(refOther));
}
