#include "Property.h"
#include <QStringList>

using namespace net::draconia::util;

Property::Property()
{ }

Property::Property(const QString &sKey, const QString &sValue)
    :   msKey(sKey)
    ,   msValue(sValue)
{ }

Property::Property(const Property &refCopy)
    :   msKey(refCopy.getKey())
    ,   msValue(refCopy.getValue())
{ }

Property::Property(Property &refToMove)
    :   msKey(refToMove.getKey())
    ,   msValue(refToMove.getValue())
{ }

QString &Property::getKey() const
{
    return(const_cast<QString &>(msKey));
}

QString &Property::getValue() const
{
    return(const_cast<QString &>(msValue));
}

void Property::setKey(const QString &sKey)
{
    msKey = sKey;
}

void Property::setProperty(const QString &sKey, const QString &sValue)
{
    setKey(sKey);
    setValue(sValue);
}

void Property::setValue(const QString &sValue)
{
    msValue = sValue;
}

Property Property::parse(const QString &sProperty)
{
    QStringList lstParts = sProperty.split("=");

    for(QString sString : lstParts)
        sString = sString.trimmed();

    if(lstParts.size() > 1)
        return(Property(lstParts[0].trimmed(), lstParts[1].trimmed()));
    else
        return(Property(lstParts[0].trimmed()));
}

QString Property::toString() const
{
    return(getKey() + "=" + getValue());
}

Property &Property::operator=(const Property &refCopy)
{
    setKey(refCopy.getKey());
    setValue(refCopy.getValue());

    return(*this);
}

Property &Property::operator=(Property &refToMoveAssign)
{
    setKey(refToMoveAssign.getKey());
    setValue(refToMoveAssign.getValue());

    refToMoveAssign.setProperty("", "");

    return(*this);
}

Property &Property::operator=(const QString &sValue)
{
    setValue(sValue);

    return(*this);
}

bool Property::operator==(const Property &refOther) const
{
    return((getKey() == refOther.getKey()) && (getValue() == refOther.getValue()));
}

bool Property::operator!=(const Property &refOther) const
{
    return(!operator==(refOther));
}
