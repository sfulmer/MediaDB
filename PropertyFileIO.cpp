#include "Property.h"
#include "PropertyFileIO.h"

using namespace net::draconia::io;
using net::draconia::util::Property;
using net::draconia::util::Properties;

fstream &PropertyFileIO::getPropertiesFile()
{
    if(mFileProperties == nullptr)
        mFileProperties = new fstream(getFilename().toStdString());

    return(*mFileProperties);
}

PropertyFileIO::PropertyFileIO()
    :   mFileProperties(nullptr)
{ }

PropertyFileIO::PropertyFileIO(const QString &sFilename)
    :   mFileProperties(nullptr)
    ,   msFilename(sFilename)
{ }

PropertyFileIO::PropertyFileIO(PropertyFileIO &refToMove)
    :   mFileProperties(&(refToMove.getPropertiesFile()))
    ,   msFilename(refToMove.getFilename())
{
    refToMove.msFilename = nullptr;
}

PropertyFileIO::~PropertyFileIO()
{
    if(getPropertiesFile().is_open())
        {
        getPropertiesFile().close();

        delete mFileProperties;
        mFileProperties = nullptr;
        }
}

PropertyFileIO &PropertyFileIO::operator=(PropertyFileIO &refToMoveAssign)
{
    setFilename(refToMoveAssign.getFilename());

    mFileProperties = refToMoveAssign.mFileProperties;
    refToMoveAssign.mFileProperties = nullptr;

    return(*this);
}

QString &PropertyFileIO::getFilename() const
{
    return(const_cast<QString &>(msFilename));
}

Properties PropertyFileIO::load()
{
    return(load(getFilename()));
}

Properties PropertyFileIO::load(const QString &sFilename)
{
    Properties objProperties;

    if(getPropertiesFile().is_open())
        getPropertiesFile().close();

    if(sFilename.isEmpty())
        getPropertiesFile().open(getFilename().toStdString(), fstream::in);
    else
        getPropertiesFile().open(sFilename.toStdString(), fstream::in);

    while(!getPropertiesFile().eof())
        {
        char sProperty[120];

        getPropertiesFile().getline(sProperty, 120);

        objProperties.add(Property::parse(sProperty));
        }

    getPropertiesFile().close();

    return(objProperties);
}

void PropertyFileIO::save(const Properties &refProperties)
{
    save(refProperties, getFilename());
}

void PropertyFileIO::save(const Properties &refProperties, const QString &sFilename)
{
    if(getPropertiesFile().is_open())
        getPropertiesFile().close();

    if(sFilename.isEmpty())
        getPropertiesFile().open(getFilename().toStdString(), fstream::out);
    else
        getPropertiesFile().open(sFilename.toStdString(), fstream::out);

    for(Property objProperty : refProperties)
        {
        QString sProperty = objProperty.toString();

        getPropertiesFile().write(sProperty.toStdString().c_str(), sProperty.size());
        }

    getPropertiesFile().close();
}

void PropertyFileIO::setFilename(const QString &sFilename)
{
    msFilename = sFilename;

    if(getPropertiesFile().is_open())
        getPropertiesFile().close();
}
