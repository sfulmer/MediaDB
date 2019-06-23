#pragma once

#include "Media.h"

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace dbo
            {
                class Book : public Media
                {
                    unsigned muiBookId;
                    QString msCollection, msComments;
                public:
                    Book();
                    Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease);
                    Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear);
                    Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                    Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath);
                    Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                    Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments);
                    Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QString &sCollection);
                    Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QString &sCollection);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QString &sComments, const QString &sCollection);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QString &sComments, const QString &sCollection);
                    Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                    Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists);
                    Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
                    Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments);
                    Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection);
                    Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection);
                    Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
                    Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists);
                    Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                    Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments);
                    Book(const unsigned uiMediaId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection);
                    Book(const unsigned uiMediaId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const QDate &dtRelease, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection);
                    Book(const unsigned uiMediaId, const unsigned uiBookId, const QString &sName, const unsigned uiReleaseYear, const QString &sFilePath, const QList<Artist> &lstArtists, const QString &sComments, const QString &sCollection);
                    Book(const Book &refCopy);
                    virtual ~Book();

                    unsigned getBookId() const;
                    QString getCollection() const;
                    QString getComments() const;
                    void setBookId(const unsigned uiBookId);
                    void setCollection(const QString &sCollection);
                    void setComments(const QString &sComments);

                    Book &operator=(const Book &refCopy);
                    bool operator==(const Book &refOther) const;
                    bool operator!=(const Book &refOther) const;
                };
            }
        }
    }
}
