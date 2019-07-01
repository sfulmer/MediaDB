#pragma once

#include<QLineEdit>
#include<QPushButton>
#include<QWidget>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace ui
            {
                class FilePathFieldPanel : public QWidget
                {
                    Q_OBJECT

                    QLineEdit *mTxtFilePath;
                    QPushButton *mBtnBrowse;
                protected:
                    QPushButton *getBrowseButton();
                    QLineEdit *getFilePathField();
                    void initPanel();
                public:
                    explicit FilePathFieldPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                };
            }
        }
    }
}
