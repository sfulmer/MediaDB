#include "Properties.h"

using namespace net::draconia::util;

QList<Property> &Properties::getList() const
{
    return(const_cast<QList<Property> &>(mLstProperties));
}

Properties::Properties()
{ }

Properties::Properties(const Properties &refCopy)
    :   mLstProperties(refCopy.getList())
{ }

Properties::Properties(Properties &refToMove)
    :   mLstProperties(refToMove.getList())
{
    refToMove.mLstProperties.clear();
}

Properties &Properties::add(const QString sKey, const QString &sValue)
{
    getList().append(Property(sKey, sValue));

    return(*this);
}

Properties &Properties::add(const Properties &refToAdd)
{
    getList().append(refToAdd.getList());

    return(*this);
}

Properties &Properties::add(Properties &refToAdd)
{
    getList().append(refToAdd.getList());

    refToAdd.mLstProperties.clear();

    return(*this);
}

Properties &Properties::add(const Property &refProperty)
{
    getList().append(refProperty);

    return(*this);
}

Properties &Properties::add(Property &refProperty)
{
    getList().append(refProperty);

    return(*this);
}

Properties &Properties::add(const QList<Property> &lstToAdd)
{
    getList().append(lstToAdd);

    return(*this);
}

QList<Property>::iterator Properties::begin()
{
    return(getList().begin());
}

QList<Property>::const_iterator Properties::begin() const
{
    return(getList().begin());
}

QList<Property>::const_iterator Properties::cbegin() const
{
    return(getList().cbegin());
}

QList<Property>::const_iterator Properties::cend() const
{
    return(getList().cend());
}

QList<Property>::const_reverse_iterator	Properties::crbegin() const
{
    return(getList().crbegin());
}

QList<Property>::const_reverse_iterator	Properties::crend() const
{
    return(getList().crend());
}

QList<Property>::iterator Properties::end()
{
    return(getList().end());
}

QList<Property>::const_iterator Properties::end() const
{
    return(getList().end());
}

bool Properties::hasKey(const QString &sKey)
{
    for(Property objProperty : getList())
        if(objProperty.getKey() == sKey)
            return(true);

    return(false);
}

bool Properties::hasValue(const QString &sValue)
{
    for(Property objProperty : getList())
        if(objProperty.getValue() == sValue)
            return(true);

    return(false);
}

bool Properties::isEmpty() const
{
    return(getList().isEmpty());
}

Properties &Properties::remove(const Property &refToRemove)
{
    getList().removeOne(refToRemove);

    return(*this);
}

Properties &Properties::remove(const Properties &refToRemove)
{
    return(remove(refToRemove.getList()));
}

Properties &Properties::remove(const QList<Property> &lstToRemove)
{
    for(Property objProperty : lstToRemove)
        getList().removeOne(objProperty);

    return(*this);
}

Property Properties::operator[](const QString &sKey)
{
    for(Property objProperty : getList())
        if(objProperty.getKey() == sKey)
            return(objProperty);

    return(Property());
}

Properties &Properties::operator=(const Properties &refToCopy)
{
    getList().clear();
    getList().append(refToCopy.getList());

    return(*this);
}

Properties &Properties::operator=(Properties &ToMoveAssign)
{
    getList().clear();
    getList().append(ToMoveAssign.getList());

    ToMoveAssign.getList().clear();

    return(*this);
}

bool Properties::operator==(const Properties &refOther) const
{
    return(getList() == refOther.getList());
}

bool Properties::operator!=(const Properties &refOther) const
{
    return(!operator==(refOther));
}
