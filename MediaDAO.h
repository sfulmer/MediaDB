#pragma once

#include "DBO.h"

using namespace net::draconia::dbo;

namespace net
{
    namespace draconia
    {
        namespace dao
        {
            class MediaDAO
            {
            public:
                virtual ~MediaDAO();

                virtual QSharedPointer<Media> getById(const unsigned uiMediaId) const = 0;
                virtual bool remove(const Media &refMedia) const = 0;
                virtual Media &save(const Media &refToSave) const = 0;
            };
        }
    }
}
