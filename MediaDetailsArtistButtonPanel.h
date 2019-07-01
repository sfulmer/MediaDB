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
                class MediaDetailsArtistButtonPanel : public QWidget
                {
                    Q_OBJECT
                    QPushButton *mBtnAdd, *mBtnEdit, *mBtnRemove;
                protected:
                    QPushButton *getAddButton();
                    QPushButton *getEditButton();
                    QPushButton *getRemoveButton();
                    void initPanel();
                public:
                    explicit MediaDetailsArtistButtonPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                };
            }
        }
    }
}
