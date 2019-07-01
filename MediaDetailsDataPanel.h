#pragma once

#include "FilePathFieldPanel.h"
#include<QDateEdit>
#include<QLabel>
#include<QLineEdit>
#include <QWidget>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace ui
            {
                class MediaDetailsDataPanel : public QWidget
                {
                    Q_OBJECT
                    FilePathFieldPanel *mFldFilePath;
                    QDateEdit *mDtRelease;
                    QLabel *mLblFilePath, *mLblName, *mLblReleaseDate;
                    QLineEdit *mTxtName;
                protected:
                    FilePathFieldPanel *getFilePathField();
                    QLabel *getFilePathLabel();
                    QLineEdit *getNameField();
                    QLabel *getNameLabel();
                    QDateEdit *getReleaseDateField();
                    QLabel *getReleaseDateLabel();
                    void initPanel();
                public:
                    explicit MediaDetailsDataPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                };
            }
        }
    }
}
