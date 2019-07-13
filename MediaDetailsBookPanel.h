#pragma once

#include "FilePathFieldPanel.h"
#include<QComboBox>
#include<QDateEdit>
#include<QLabel>
#include<QTextEdit>
#include <QWidget>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace ui
            {
                class MediaDetailsBookPanel : public QWidget
                {
                    Q_OBJECT
                    FilePathFieldPanel *mPnlFilePath;
                    QComboBox *mCboCollection;
                    QDateEdit *mDtRelease;
                    QLabel *mLblCollection, *mLblComments, *mLblFilePath, *mLblReleaseDate;
                    QTextEdit *mTxtComments;
                protected:
                    QComboBox *getCollectionField();
                    QLabel *getCollectionLabel();
                    QTextEdit *getCommentsField();
                    QLabel *getCommentsLabel();
                    FilePathFieldPanel *getFilePathField();
                    QLabel *getFilePathLabel();
                    QDateEdit *getReleaseDateField();
                    QLabel *getReleaseDateLabel();
                    void initPanel();
                public:
                    explicit MediaDetailsBookPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                    void setDisabled(bool disable);
                };
            }
        }
    }
}
