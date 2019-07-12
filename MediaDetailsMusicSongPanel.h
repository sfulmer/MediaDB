#pragma once

#include "FilePathFieldPanel.h"
#include<QDateEdit>
#include<QGroupBox>
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
                class MediaDetailsMusicSongPanel : public QGroupBox
                {
                    Q_OBJECT
                    FilePathFieldPanel *mPnlFilePath;
                    QLabel *mLblComments, *mLblFilePath, *mLblName;
                    QLineEdit *mTxtName;
                    QTextEdit *mTxtComments;
                protected:
                    QTextEdit *getCommentsField();
                    QLabel *getCommentsLabel();
                    FilePathFieldPanel *getFilePathField();
                    QLabel *getFilePathLabel();
                    QLineEdit *getNameField();
                    QLabel *getNameLabel();
                    void initPanel();
                public:
                    explicit MediaDetailsMusicSongPanel(QWidget *parent = nullptr);
                    virtual QSize sizeHint() const;
                signals:

                public slots:
                    void setDisabled(bool disable);
                };
            }
        }
    }
}
