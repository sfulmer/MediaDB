#pragma once

#include<QLabel>
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
                class MediaDetailsMovieDetailsPanel : public QWidget
                {
                    Q_OBJECT
                    QLabel *mLblComments, *mLblViewings;
                    QListWidget *mLstViewings;
                    QTextEdit *mTxtComments;
                protected:
                    QTextEdit *getCommentsField();
                    QLabel *getCommentsLabel();
                    QListWidget *getViewingsList();
                    QLabel *getViewingsLabel();
                    void initPanel();
                public:
                    explicit MediaDetailsMovieDetailsPanel(QWidget *parent = nullptr);

                    virtual QSize sizeHint() const;
                signals:

                public slots:
                };
            }
        }
    }
}
