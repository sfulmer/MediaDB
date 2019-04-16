#pragma once

#include "Observer.h"
#include<QList>
#include<QSharedPointer>

namespace net
{
    namespace draconia
    {
        namespace util
        {
            class Observable
            {
                bool mbChanged;
                QList<QSharedPointer<Observer>> mLstObservers;
            protected:
                QList<QSharedPointer<Observer>> getObservers();
            public:
                Observable();
                Observable(const Observable &refCopy);
                virtual ~Observable();

                void addObserver(const Observer &refObserver);
                bool isChanged() const;
                void notifyObservers(const void *ptrArgument = nullptr);
                void removeObserver(const Observer &refObserver);
                void setChanged(const bool bChanged = true);
            };
        }
    }
}
