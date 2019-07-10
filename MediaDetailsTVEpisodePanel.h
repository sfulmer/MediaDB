#pragma once

#include "FilePathFieldPanel.h"
#include<QGroupBox>
#include<QLabel>
#include<QLineEdit>
#include<QSpinBox>
#include<QTextEdit>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace ui
            {
                class MediaDetailsTVEpisodePanel : public QGroupBox
                {
                    Q_OBJECT
                    FilePathFieldPanel *mPnlFilePath;
                    QLabel *mLblComments, *mLblFilePath, *mLblName, *mLblNumber;
                    QLineEdit *mTxtName;
                    QSpinBox *mSpnNumber;
                    QTextEdit *mTxtComments;
                protected:
                    QTextEdit *getCommentsField();
                    QLabel *getCommentsLabel();
                    FilePathFieldPanel *getFilePathField();
                    QLabel *getFilePathLabel();
                    QLineEdit *getNameField();
                    QLabel *getNameLabel();
                    QSpinBox *getNumberField();
                    QLabel *getNumberLabel();
                    void initPanel();
                public:
                    explicit MediaDetailsTVEpisodePanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                    void setDisabled(bool disable);
                };
            }
        }
    }
}
