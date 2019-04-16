#include "Observable.h"

using namespace net::draconia::util;

QList<QSharedPointer<Observer>> Observable::getObservers()
{
    return(mLstObservers);
}

Observable::Observable() : mbChanged(false), mLstObservers()
{ }

Observable::Observable(const Observable &refCopy) : mbChanged(refCopy.isChanged()), mLstObservers(const_cast<Observable &>(refCopy).getObservers())
{ }

Observable::~Observable()
{ }

void Observable::addObserver(const Observer &refObserver)
{
    getObservers().append(QSharedPointer<Observer>(&refObserver));
}

bool Observable::isChanged() const
{
    return(mbChanged);
}

void Observable::notifyObservers(const void *ptrArgument)
{
    for(QSharedPointer<Observer> &ptrObserver : getObservers())
        ptrObserver->update(this, ptrArgument);
}

void Observable::removeObserver(const Observer &refObserver)
{
    getObservers().removeOne(QSharedPointer<Observer>(const_cast<Observer *>(&refObserver)));
}

void Observable::setChanged(const bool bChanged)
{
    mbChanged = bChanged;
}
