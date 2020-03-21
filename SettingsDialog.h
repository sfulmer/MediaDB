#pragma once

#include <QDialog>
#include <QSplitter>
#include <QStackedWidget>
#include <QTreeWidget>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            class MediaDBController;

            namespace ui
            {
                class SettingsDialog : public QDialog
                {
                    Q_OBJECT

                    MediaDBController &mRefController;
                    QSplitter *mPnlSplitter;
                    QStackedWidget *mPnlDetails;
                    QTreeWidget *mTreeSections;
                protected:
                    void initControls();
                    void initDialog();
                public:
                    SettingsDialog(MediaDBController &refController, QWidget *parent = nullptr);

                    MediaDBController &getController() const;
                    QStackedWidget *getDetailsPanel();
                    QTreeWidget *getSectionsTree();
                    QSplitter *getSplitter();
                };
            }
        }
    }
}
