#pragma once

#include "Property.h"
#include <QList>

namespace net
{
    namespace draconia
    {
        namespace util
        {
            class Properties
            {
                QList<Property> mLstProperties;
            protected:
                QList<Property> &getList() const;
            public:
                Properties();
                Properties(const Properties &refCopy);
                Properties(Properties &refToMove);

                Properties &add(const QString sKey, const QString &sValue);
                Properties &add(const Properties &refToAdd);
                Properties &add(Properties &refToAdd);
                Properties &add(const Property &refProperty);
                Properties &add(Property &refProperty);
                Properties &add(const QList<Property> &lstToAdd);
                QList<Property>::iterator begin();
                QList<Property>::const_iterator begin() const;
                QList<Property>::const_iterator cbegin() const;
                QList<Property>::const_iterator cend() const;
                QList<Property>::const_reverse_iterator	crbegin() const;
                QList<Property>::const_reverse_iterator	crend() const;
                QList<Property>::iterator end();
                QList<Property>::const_iterator end() const;
                bool hasKey(const QString &sKey);
                bool hasValue(const QString &sValue);
                bool isEmpty() const;
                Properties &remove(const QList<Property> &lstToRemove);
                Properties &remove(const Property &refToRemove);
                Properties &remove(const Properties &refToRemove);

                Property operator[](const QString &sKey);
                Properties &operator=(const Properties &ToCopy);
                Properties &operator=(Properties &ToMoveAssign);
                bool operator==(const Properties &refOther) const;
                bool operator!=(const Properties &refOther) const;
            };
        }
    }
}
