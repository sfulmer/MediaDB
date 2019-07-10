#pragma once

#include "FilePathFieldPanel.h"
#include<QLabel>
#include<QLineEdit>
#include<QListWidget>
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
                class MediaDetailsMoviePanel : public QWidget
                {
                    Q_OBJECT
                    FilePathFieldPanel *mFldFilePath;
                    QLabel *mLblComments, *mLblFilePath, *mLblViewings;
                    QListWidget *mLstViewings;
                    QTextEdit *mTxtComments;
                protected:
                    QTextEdit *getCommentsField();
                    QLabel *getCommentsLabel();
                    FilePathFieldPanel *getFilePathField();
                    QLabel *getFilePathLabel();
                    QLabel *getViewingsLabel();
                    QListWidget *getViewingsList();
                    void initPanel();
                public:
                    explicit MediaDetailsMoviePanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                    void setDisabled(bool disable);
                };
            }
        }
    }
}
