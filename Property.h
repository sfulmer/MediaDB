#pragma once

#include <QString>

namespace net
{
    namespace draconia
    {
        namespace util
        {
            class Property
            {
                QString msKey, msValue;
            public:
                Property();
                Property(const QString &sKey, const QString &sValue = "");
                Property(const Property &refCopy);
                Property(Property &refToMove);

                QString &getKey() const;
                QString &getValue() const;
                void setKey(const QString &sKey);
                void setProperty(const QString &sKey, const QString &sValue);
                void setValue(const QString &sValue);

                static Property parse(const QString &sProperty);
                QString toString() const;

                Property &operator=(const Property &refCopy);
                Property &operator=(Property &refToMoveAssign);
                Property &operator=(const QString &sValue);
                bool operator==(const Property &refOther) const;
                bool operator!=(const Property &refOther) const;
            };
        }
    }
}
