#include "dbasefile.h"

using namespace dBase;

Field::Field()
    : mbIndex(false), mucDecimalCount(0), mucLength(0)
    , mulAddress(0)
{ }

Field::Field(const char *sName, const unsigned char ucDataType, const unsigned char ucDecimalCount, const unsigned char ucLength, const unsigned long ulAddress, const bool bIndex)
    : mbIndex(bIndex)
    , mucDataType(ucDataType)
    , mucDecimalCount(ucDecimalCount)
    , mucLength(ucLength)
    , mulAddress(ulAddress)
{
    setName(sName);
}

Field::Field(const Field &refCopy)
    : mbIndex(refCopy.isIndex())
    , mucDataType(refCopy.getDataType())
    , mucDecimalCount(refCopy.getDecimalCount())
    , mucLength(refCopy.getLength())
    , mulAddress(refCopy.getAddress())
{
    setName(refCopy.getName());
}

Field::~Field()
{ }

unsigned long Field::getAddress() const
{
    return(mulAddress);
}

unsigned char Field::getDataType() const
{
    return(mucDataType);
}

unsigned char Field::getDecimalCount() const
{
    return(mucDecimalCount);
}

unsigned char Field::getLength() const
{
    return(mucLength);
}

char *Field::getName() const
{
    return(const_cast<char *>(msName));
}

bool Field::isIndex() const
{
    return(mbIndex);
}

void Field::setAddress(const unsigned long ulAddress)
{
    mulAddress = ulAddress;
}

void Field::setDataType(const unsigned char ucDataType)
{
    mucDataType = ucDataType;
}

void Field::setDecimalCount(const unsigned char ucDecimalCount)
{
    mucDecimalCount = ucDecimalCount;
}

void Field::setIndex(const bool bIndex)
{
    mbIndex = bIndex;
}

void Field::setLength(const unsigned char ucLength)
{
    mucLength = ucLength;
}

void Field::setName(const char *sName)
{
    if(sName != nullptr)
        {
        unsigned uiLength = 11, uiLoop = 0;

        for(; (uiLoop < uiLength) && (sName[uiLoop] != '\0'); uiLoop++)
            msName[uiLoop] = sName[uiLoop];

        for(; uiLoop < uiLength; uiLoop++)
            msName[uiLoop] = '\0';
        }
}

Field &Field::operator=(const Field &refOther)
{
    setIndex(refOther.isIndex());
    setName(refOther.getName());
    setDataType(refOther.getDataType());
    setDecimalCount(refOther.getDecimalCount());
    setLength(refOther.getLength());
    setAddress(refOther.getAddress());

    return(*this);
}

bool Field::operator==(const Field &refOther) const
{
    return(     (isIndex() == refOther.isIndex())
           ||   (QString(getName()) == refOther.getName())
           ||   (getDataType() == refOther.getDataType())
           ||   (getDecimalCount() == refOther.getDecimalCount())
           ||   (getLength() == refOther.getLength())
           ||   (getAddress() == refOther.getAddress()));
}

bool Field::operator!=(const Field &refOther) const
{
    return(!operator==(refOther));
}

FieldValue::FieldValue(DBFRecord &refDBFRecord, const Field &refField, const QString &sValue)
    : mRefDBFRecord(refDBFRecord)
    , mObjField(refField), msValue(sValue)
{ }

FieldValue::FieldValue(const FieldValue &refCopy)
    : mRefDBFRecord(refCopy.getDBFRecord())
    , mObjField(refCopy.getField())
    , msValue(refCopy.getValue())
{ }

FieldValue::~FieldValue()
{ }

DBFRecord &FieldValue::getDBFRecord() const
{
    return(mRefDBFRecord);
}

Field &FieldValue::getField() const
{
    return(const_cast<Field &>(mObjField));
}

QString &FieldValue::getValue() const
{
    return(const_cast<QString &>(msValue));
}

void FieldValue::setValue(const QString &sValue)
{
    msValue = sValue;
}

FieldValue &FieldValue::operator=(const QString &sValue)
{
    setValue(sValue);

    return(*this);
}

FieldValue::operator QString() const
{
    return(getValue());
}

Language::Language()
{ }

Language::Language(const unsigned uiValue, const QString &sCodePage, const QString &sDescription)
    : msCodePage(sCodePage)
    , msDescription(sDescription)
    , muiValue(uiValue)
{ }

/*Language::Language(const Language &refCopy)
    : msCodePage(refCopy.getCodePage())
    , msDescription(refCopy.getDescription())
    , muiValue(refCopy.getValue())
{ }*/

//Language::~Language() { }

QString &Language::getCodePage() const
{
    return(const_cast<QString &>(msCodePage));
}

QString &Language::getDescription() const
{
    return(const_cast<QString &>(msDescription));
}

unsigned Language::getValue() const
{
    return(muiValue);
}

Language::operator unsigned() const
{
    return(getValue());
}

Language Language::NoLanguage;

Languages Languages::msObjLanguages;

void Languages::addLanguage(const Language &refLanguage)
{
    mMapLanguages.insert(refLanguage.getValue(), refLanguage);
}

Languages::Languages()
{
    addLanguage(Language(0x01, "437", "DOS USA"));
    addLanguage(Language(0x02, "850", "DOS Multilingual"));
    addLanguage(Language(0x03, "1252", "Windows ANSI"));
    addLanguage(Language(0x04, "", "Standard Macintosh"));
    addLanguage(Language(0x64, "852", "EE MS-DOS"));
    addLanguage(Language(0x65, "865", "Nordic MS-DOS"));
    addLanguage(Language(0x66, "866", "Russian MS-DOS"));
    addLanguage(Language(0x67, "", "Icelandic MS-DOS"));
    addLanguage(Language(0x68, "", "Kamenicky (Czech) MS-DOS"));
    addLanguage(Language(0x69, "", "Mazovia (Polish) MS-DOS"));
    addLanguage(Language(0x6A, "", "Greek MS-DOS (437G)"));
    addLanguage(Language(0x6B, "", "Turkish MS-DOS"));
    addLanguage(Language(0x96, "", "Russian Macintosh"));
    addLanguage(Language(0x97, "", "Eastern European Macintosh"));
    addLanguage(Language(0x98, "", "Greek Macintosh"));
    addLanguage(Language(0xC8, "1250", "Windows EE"));
    addLanguage(Language(0xC9, "", "Russian Windows"));
    addLanguage(Language(0xCA, "", "Turkish Windows"));
    addLanguage(Language(0xCB, "", "Greek Windows"));
}

Language Languages::get(const unsigned uiValue) const
{
    return(mMapLanguages.value(uiValue, Language()));
}

Languages &Languages::getLanguages()
{
    return(msObjLanguages);
}

Version::Version()
    : msName(""), mucVersion(0)
{ }

Version::Version(const unsigned char ucVersion, const QString &sName)
    : msName(sName), mucVersion(ucVersion)
{ }

/*Version::Version(const Version &refCopy)
    : msName(refCopy.getName()), mucVersion(refCopy.getVersion())
{ }

Version::~Version()
{ }*/

QString &Version::getName() const
{
    return(const_cast<QString &>(msName));
}

unsigned char Version::getVersion() const
{
    return(mucVersion);
}

Version::operator unsigned char() const
{
    return(getVersion());
}

Version::operator QString() const
{
    return(getName());
}

Versions Versions::msObjVersions;

void Versions::addVersion(const Version &refVersion)
{
    mMapVersions.insert(refVersion.getVersion(), refVersion);
}

Versions::Versions()
{
    addVersion(Version(0x02, "FoxBase"));
    addVersion(Version(0x03, "File without DBT"));
    addVersion(Version(0x04, "dBASE IV w/o memo file"));
    addVersion(Version(0x05, "dBASE V w/o memo file"));
    addVersion(Version(0x07, "VISUAL OBJECTS (first 1.0 versions) for the Dbase III files w/o memo file"));
    addVersion(Version(0x30, "Visual FoxPro w. DBC"));
    addVersion(Version(0x31, "Visual FoxPro w. AutoIncrement field"));
    addVersion(Version(0x43, ".dbv memo var size (Flagship)"));
    addVersion(Version(0x7B, "dBASE IV with memo"));
    addVersion(Version(0x83, "dBASE III+ with memo file"));
    addVersion(Version(0x87, "VISUAL OBJECTS (first 1.0 versions) for the Dbase III files (NTX clipper driver) with memo file"));
    addVersion(Version(0x8B, "dBASE IV w. memo"));
    addVersion(Version(0x8E, "dBASE IV w. SQL table"));
    addVersion(Version(0xB3, ".dbv and .dbt memo (Flagship)"));
    addVersion(Version(0xE5, "Clipper SIX driver w. SMT memo file."));
    addVersion(Version(0xF5, "FoxPro w. memo file"));
    addVersion(Version(0xFB, "FoxPro ???"));
}

QList<Version> Versions::findByName(const QString &sName)
{
    QList<Version> lstVersions;

    for(Version objVersion : mMapVersions)
        if(objVersion.getName() == sName)
            lstVersions.append(objVersion);

    return(lstVersions);
}

Version Versions::get(const unsigned char ucVersion)
{
    return(mMapVersions.value(ucVersion, Versions::NoVersion));
}

Versions Versions::getVersions()
{
    return(msObjVersions);
}

Version Versions::NoVersion;

QList<Field> &RecordHeader::getFieldsInternal() const
{
    return(const_cast<QList<Field> &>(mLstFields));
}

RecordHeader::RecordHeader(Version &refVersion)
    : mObjLanguage(Language::NoLanguage)
    , mRefVersion(refVersion)
{ }

RecordHeader::RecordHeader(const RecordHeader &refCopy)
    : mbEncrypted(refCopy.isEncrypted())
    , mbIncompleteTransaction(refCopy.hasIncompleteTransaction())
    , mbMDXFlag(refCopy.isMDX())
    , mObjLanguage(refCopy.getLanguage())
    , mDtLastUpdate(refCopy.getLastUpdate())
    , mLstFields(refCopy.getFields())
    , musHeaderLength(refCopy.getHeaderLength())
    , musRecordLength(refCopy.getRecordLength())
    , mulFreeRecordThread(refCopy.getFreeRecordThread())
    , mulRecordCount(refCopy.getRecordCount())
    , mRefVersion(refCopy.getVersion())
{ }

RecordHeader::~RecordHeader()
{ }

bool RecordHeader::addField(const Field &refField)
{
    if(getFieldsInternal().count() <= 128)
        {
        getFieldsInternal().append(refField);

        return(true);
        }

    return(false);
}

Field &RecordHeader::getField(const unsigned uiIndex) const
{
    return(const_cast<Field &>(getFieldsInternal()[static_cast<int>(uiIndex)]));
}

unsigned RecordHeader::getFieldCount() const
{
    return(static_cast<unsigned>(getFieldsInternal().count()));
}

const QList<Field> &RecordHeader::getFields() const
{
    return(getFieldsInternal());
}

unsigned long RecordHeader::getFreeRecordThread() const
{
    return(mulFreeRecordThread);
}

unsigned short RecordHeader::getHeaderLength() const
{
    return(musHeaderLength);
}

Language RecordHeader::getLanguage() const
{
    return(mObjLanguage);
}

QDate &RecordHeader::getLastUpdate() const
{
    return(const_cast<QDate &>(mDtLastUpdate));
}

unsigned long RecordHeader::getRecordCount() const
{
    return(mulRecordCount);
}

unsigned short RecordHeader::getRecordLength() const
{
    return(musRecordLength);
}

Version &RecordHeader::getVersion() const
{
    return(const_cast<Version &>(mRefVersion));
}

bool RecordHeader::hasIncompleteTransaction() const
{
    return(mbIncompleteTransaction);
}

bool RecordHeader::isEncrypted() const
{
    return(mbEncrypted);
}

bool RecordHeader::isMDX() const
{
    return(mbMDXFlag);
}

bool RecordHeader::removeField(const unsigned uiIndex)
{
    if((static_cast<int>(uiIndex) <= getFieldsInternal().size()))
        return(removeField(getFieldsInternal()[static_cast<int>(uiIndex)]));

    return(false);
}

bool RecordHeader::removeField(const Field &refField)
{
    return(getFieldsInternal().removeOne(refField));
}

void RecordHeader::setEncrypted(const bool bEncrypted)
{
    mbEncrypted = bEncrypted;
}

void RecordHeader::setFreeRecordThread(const unsigned long ulFreeRecordThread)
{
    mulFreeRecordThread = ulFreeRecordThread;
}

void RecordHeader::setHeaderLength(const unsigned short usHeaderLength)
{
    musHeaderLength = usHeaderLength;
}

void RecordHeader::setIncompleteTransaction(const bool bIncompleteTransaction)
{
    mbIncompleteTransaction = bIncompleteTransaction;
}

void RecordHeader::setLanguage(const Language objLanguage)
{
    mObjLanguage = objLanguage;
}

void RecordHeader::setLastUpdate(const QDate &dtLastUpdate)
{
    mDtLastUpdate = dtLastUpdate;
}

void RecordHeader::setMDX(const bool bMDX)
{
    mbMDXFlag = bMDX;
}

void RecordHeader::setRecordCount(const unsigned long ulRecordCount)
{
    mulRecordCount = ulRecordCount;
}

void RecordHeader::setRecordLength(const unsigned short usRecordLength)
{
    musRecordLength = usRecordLength;
}

void RecordHeader::setVersion(const Version &refVersion)
{
    mRefVersion = refVersion;
}

bool DBFRecord::isRead() const
{
    return(mbRead);
}

void DBFRecord::loadRecord()
{
    // TODO: Need to load record here
}

void DBFRecord::persistRecord()
{
    // TODO: Need to persist record here
}

DBFRecord::DBFRecord(DBaseFile &refDBaseFile)
    : mbDeleted(false), mbRead(false)
    , mPtrDBaaseFile(&refDBaseFile)
    , mlRecordIndex(-1)
{ }

DBFRecord::DBFRecord(DBaseFile &refDBaseFile, const long lRecordIndex)
    : mbDeleted(false), mbRead(false)
    , mPtrDBaaseFile(&refDBaseFile)
    , mlRecordIndex(lRecordIndex)
{ }

DBFRecord::DBFRecord()
    : mbDeleted(false), mbRead(false)
    , mPtrDBaaseFile(nullptr)
    , mlRecordIndex(-1)
{ }

DBFRecord::DBFRecord(const DBFRecord &refCopy)
    : mbDeleted(const_cast<DBFRecord &>(refCopy).isDeleted())
    , mbRead(refCopy.isRead())
    , mPtrDBaaseFile(refCopy.mPtrDBaaseFile)
    , mlRecordIndex(refCopy.getRecordIndex())
    , mLstFields(refCopy.mLstFields)
{ }

DBFRecord::~DBFRecord()
{ }

FieldValue DBFRecord::getFieldValue(const Field &refField)
{
    return(getFieldValue(refField.getName()));
}

FieldValue DBFRecord::getFieldValue(const QString &sFieldName)
{
    if(!isRead())
        loadRecord();

    for(FieldValue objFieldValue : mLstFields)
        if(objFieldValue.getField().getName() == sFieldName)
            return(objFieldValue);

    return(FieldValue(*this, Field()));
}

long DBFRecord::getRecordIndex() const
{
    return(mlRecordIndex);
}

bool DBFRecord::isDeleted()
{
    if(!isRead())
        loadRecord();

    return(mbDeleted);
}

void DBFRecord::setDeleted(const bool bDeleted)
{
    mbDeleted = bDeleted;

    if(isRead())
        persistRecord();
}

void DBFRecord::setFieldValue(const Field &refField, const QString &sValue)
{
    setFieldValue(refField.getName(), sValue);
}

void DBFRecord::setFieldValue(const QString &sFieldName, const QString &sValue)
{
    if(!isRead())
        loadRecord();

    for(FieldValue refFieldValue : mLstFields)
        if(refFieldValue.getField().getName() == sFieldName)
            refFieldValue.setValue(sValue);
}
