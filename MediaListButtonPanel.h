#pragma once

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
                class MediaListButtonPanel : public QWidget
                {
                    Q_OBJECT
                    QPushButton *mBtnAdd, *mBtnEdit, *mBtnRemove;
                protected:
                    QPushButton *getAddButton();
                    QPushButton *getEditButton();
                    QPushButton *getRemoveButton();
                    void initPanel();
                public:
                    explicit MediaListButtonPanel(QWidget *parent = nullptr);
                signals:

                public slots:
                };
            }
        }
    }
}
