#pragma once

#include<QListWidget>
#include<QScrollArea>
#include <QWidget>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace ui
            {
                class MainPanel : public QWidget
                {
                    Q_OBJECT
                    QListWidget *mLstMedia;
                    QScrollArea *mScrMediaList;
                    QWidget *mPnlMediaList;
                protected:
                    QListWidget *getMediaList();
                    QWidget *getMediaPanel();
                    QScrollArea *getMediaScrollArea();

                    void initPanel();
                public:
                    explicit MainPanel(QWidget *parent = nullptr);

                signals:

                public slots:
                };
            }
        }
    }
}
