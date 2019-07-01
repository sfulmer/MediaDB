#pragma once

#include<QDateEdit>
#include<QLabel>
#include<QLineEdit>
#include<QMediaPlayer>
#include<QWidget>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace ui
            {
                class MediaDetailsPanel : public QWidget
                {
                    Q_OBJECT
                    QDateEdit *mDtRelease;
                    QLabel *mLblFilePath, *mLblName, *mLblReleaseDate;
                    QLineEdit *mTxtName;
                    QMediaPlayer *mPlayMedia;
                protected:
                    QLabel *getFilePathLabel();
                    QMediaPlayer *getMediaPlayer();
                    QLineEdit *getNameField();
                    QLabel *getNameLabel();
                    QDateEdit *getReleaseDateField();
                    QLabel *getReleaseDateLabel();
                    void initPanel();
                public:
                    explicit MediaDetailsPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                };
            }
        }
    }
}
