#ifndef DBASEFILE_H
#define DBASEFILE_H

#include<fstream>
#include<QDate>
#include<QList>
#include<QMap>
#include<QString>

namespace dBase
{\
    class DBaseFile;
    class DBFRecord;
    class Field;
    class FieldValue;
    class Language;
    class Languages;
    class RecordHeader;
    class Version;
    class Versions;

    class Field
    {
        bool mbIndex;
        char msName[11];
        unsigned char mucDataType, mucDecimalCount;
        unsigned char mucLength;
        unsigned long mulAddress;
    public:
        Field();
        Field(const char *sName, const unsigned char ucDataType, const unsigned char ucDecimalCount = 0, const unsigned char ucLength = 0, const unsigned long ulAddress = 0L, const bool bIndex = false);
        Field(const Field &refCopy);
        ~Field();

        unsigned long getAddress() const;
        unsigned char getDataType() const;
        unsigned char getDecimalCount() const;
        unsigned char getLength() const;
        char *getName() const;
        bool isIndex() const;

        void setAddress(const unsigned long ulAddress);
        void setDataType(const unsigned char ucDataType);
        void setDecimalCount(const unsigned char ucDecimalCount);
        void setIndex(const bool bIndex);
        void setLength(const unsigned char ucLength);
        void setName(const char *sName);

        Field &operator=(const Field &refOther);
        bool operator==(const Field &refOther) const;
        bool operator!=(const Field &refOther) const;
    };

    class FieldValue
    {
    friend class DBFRecord;
        DBFRecord &mRefDBFRecord;
        Field mObjField;
        QString msValue;
    protected:
        FieldValue(DBFRecord &refDBFRecord, const Field &refField, const QString &sValue = "");
    public:
        FieldValue(const FieldValue &refCopy);
        ~FieldValue();

        DBFRecord &getDBFRecord() const;
        Field &getField() const;
        QString &getValue() const;
        void setValue(const QString &sValue);

        FieldValue &operator=(const QString &sValue);
        operator QString() const;
    };

    class Language
    {
    friend class Languages;
        QString msCodePage, msDescription;
        unsigned muiValue;
    protected:
        Language();
        Language(const unsigned uiValue, const QString &sCodePage, const QString &sDescription);
    public:
        Language(const Language &refCopy)
            : msCodePage(refCopy.getCodePage())
            , msDescription(refCopy.getDescription())
            , muiValue(refCopy.getValue())
        { }
        ~Language() { }

        QString &getCodePage() const;
        QString &getDescription() const;
        unsigned getValue() const;

        operator unsigned() const;

        static Language NoLanguage;
    };

    class Languages
    {
        QMap<unsigned, Language> mMapLanguages;

        static Languages msObjLanguages;
    protected:
        void addLanguage(const Language &refLanguage);

        Languages();
    public:
        Language get(const unsigned uiValue) const;

        static Languages &getLanguages();
    };

    class Version
    {
    friend class Versions;
        QString msName;
        unsigned char mucVersion;
    protected:
        Version();
        Version(const unsigned char ucVersion, const QString &sName);
    public:
        Version(const Version &refCopy)
            : msName(refCopy.getName())
            , mucVersion(refCopy.getVersion())
        { }
        ~Version() { }

        QString &getName() const;
        unsigned char getVersion() const;

        operator unsigned char() const;
        operator QString() const;
    };

    class Versions
    {
        QMap<unsigned char, Version> mMapVersions;

        static Versions msObjVersions;
    protected:
        void addVersion(const Version &refVersion);

        Versions();
    public:
        QList<Version> findByName(const QString &sName);
        Version get(const unsigned char ucVersion);\
        static Versions getVersions();

        static Version NoVersion;
    };

    class RecordHeader
    {
        bool mbEncrypted, mbIncompleteTransaction, mbMDXFlag;
        Language mObjLanguage;
        QDate mDtLastUpdate;
        QList<Field> mLstFields;
        unsigned short musHeaderLength, musRecordLength;
        unsigned long mulFreeRecordThread, mulRecordCount;
        Version &mRefVersion;
    protected:
        QList<Field> &getFieldsInternal() const;
    public:
        RecordHeader(Version &refVersion);
        RecordHeader(const RecordHeader &refCopy);
        ~RecordHeader();

        bool addField(const Field &refField);
        Field &getField(const unsigned uiIndex) const;
        unsigned getFieldCount() const;
        const QList<Field> &getFields() const;
        unsigned long getFreeRecordThread() const;
        unsigned short getHeaderLength() const;
        Language getLanguage() const;
        QDate &getLastUpdate() const;
        unsigned long getRecordCount() const;
        unsigned short getRecordLength() const;
        Version &getVersion() const;
        bool hasIncompleteTransaction() const;
        bool isEncrypted() const;
        bool isMDX() const;
        bool removeField(const unsigned uiIndex);
        bool removeField(const Field &refField);
        void setEncrypted(const bool bEncrypted);
        void setFreeRecordThread(const unsigned long ulFreeRecordThread);
        void setHeaderLength(const unsigned short usHeaderLength);
        void setIncompleteTransaction(const bool bIncompleteTransaction);
        void setLanguage(const Language objLanguage);
        void setLastUpdate(const QDate &dtLastUpdate);
        void setMDX(const bool bMDX);
        void setRecordCount(const unsigned long ulRecordCount);
        void setRecordLength(const unsigned short usRecordLength);
        void setVersion(const Version &refVersion);
    };

    class DBFRecord
    {
    friend class DBaseFile;
        bool mbDeleted, mbRead;
        DBaseFile *mPtrDBaaseFile;
        long mlRecordIndex;
        QList<FieldValue> mLstFields;
    protected:
        bool isRead() const;
        void loadRecord();
        void persistRecord();

        DBFRecord(DBaseFile &refDBaseFile);
        DBFRecord(DBaseFile &refDBaseFile, const long lRecordIndex);
    public:
        DBFRecord();
        DBFRecord(const DBFRecord &refCopy);
        ~DBFRecord();

        FieldValue getFieldValue(const Field &refField);
        FieldValue getFieldValue(const QString &sFieldName);
        long getRecordIndex() const;
        bool isDeleted();
        void setDeleted(const bool bDeleted);
        void setFieldValue(const Field &refField, const QString &sValue);
        void setFieldValue(const QString &sFieldName, const QString &sValue);
        void setRecordIndex(const long lRecordIndex);
    };

    class DBaseFile
    {
        QList<DBFRecord> mLstRecords;
        RecordHeader mObjRecordHeader;
    protected:
        QList<DBFRecord> getRecordsInternal() const;
    public:
        DBaseFile(Version &refVersion);

        bool addRecord(const DBFRecord &refRecord);
        DBFRecord &getRecord(const unsigned uiIndex);
        RecordHeader &getRecordHeader() const;
        const QList<DBFRecord> getRecords() const;
    };
 }
#endif // DBASEFILE_H
