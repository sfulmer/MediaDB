#pragma once

#include "FilePathFieldPanel.h"
#include<QDateEdit>
#include<QLabel>
#include<QLineEdit>
#include<QTextEdit>
#include<QWidget>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace ui
            {
                class MediaDetailsMusicSingleDetailPanel : public QWidget
                {
                    Q_OBJECT
                    FilePathFieldPanel *mPnlFilePath;
                    QDateEdit *mDtRelease;
                    QLabel *mLblComments, *mLblFilePath, *mLblName, *mLblRelease;
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
                    explicit MediaDetailsMusicSingleDetailPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                    void setDisabled(bool disable);
                };
            }
        }
    }
}
