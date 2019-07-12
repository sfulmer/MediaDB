#pragma once

#include "FilePathFieldPanel.h"
#include<QDateEdit>
#include <QGroupBox>
#include<QLabel>
#include<QLineEdit>
#include<QTextEdit>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace ui
            {
                class MediaDetailsTVSpecialPanel : public QGroupBox
                {
                    Q_OBJECT
                    FilePathFieldPanel *mPnlFilePath;
                    QDateEdit *mDtRelease;
                    QLabel *mLblComments, *mLblFilePath, *mLblName, *mLblReleaseDate;
                    QLineEdit *mTxtName;
                    QTextEdit *mTxtComments;
                protected:
                    QTextEdit *getCommentsField();
                    QLabel *getCommentsLabel();
                    FilePathFieldPanel *getFilePathField();
                    QLabel *getFilePathLabel();
                    QLineEdit *getNameField();
                    QLabel *getNameLabel();
                    QDateEdit *getReleaseDateField();
                    QLabel *getReleaseDateLabel();
                    void initPanel();
                public:
                    explicit MediaDetailsTVSpecialPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                    void setDisabled(bool disable);
                };
            }
        }
    }
}
