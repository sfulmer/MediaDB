#pragma once

#include<QPushButton>
#include<QWidget>

namespace net
{
    namespace draconia
    {
        namespace ui
        {
            class ListButtonPanel : public QWidget
            {
                Q_OBJECT
                QPushButton *mBtnAdd, *mBtnEdit, *mBtnRemove;
            protected:
                QPushButton *getAddButton();
                QPushButton *getEditButton();
                QPushButton *getRemoveButton();
                void initPanel();
            public:
                explicit ListButtonPanel(QWidget *parent = nullptr);

                virtual QSize sizeHiint() const;
            signals:

            public slots:
                void setDisabled(bool disable);
            };
        }
    }
}
