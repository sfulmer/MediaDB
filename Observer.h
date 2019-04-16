#pragma once

namespace net
{
    namespace draconia
    {
        namespace util
        {
            class Observer
            {
            public:
                virtual ~Observer();

                virtual void update(const Observable &refObservable, const void *ptrArgument);
            };
        }
    }
}
