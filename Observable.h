#pragma once

#include<QList>

namespace net
{
    namespace draconia
    {
        namespace util
        {
            class Observable;

            class Observer
            {
            public:
                virtual ~Observer() = 0;
                virtual void update(const Observable &refObservable, const void *ptrArgument) = 0;
            };

            class Observable
            {
                bool mbChanged;
                QList<Observer *> mLstObservers;
            protected:
                QList<Observer *> &getObserversInternal();
            public:
                Observable();
                ~Observable();

                void addObserver(const Observer &refObserver);
                const QList<Observer *> &getObservers();
                bool isChanged() const;
                void notifyObservers(const void *ptrArgument = nullptr);
                void setChanged(const bool bChanged = true);

                bool operator==(const Observable &objOther) const;
                bool operator!=(const Observable &objOther) const;
            };
        }
    }
}

