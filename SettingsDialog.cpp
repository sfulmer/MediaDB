#include "MediaDBController.h"
#include <QHBoxLayout>
#include "SettingsDialog.h"

using net::draconia::mediadb::MediaDBController;
using namespace net::draconia::mediadb::ui;

void SettingsDialog::initControls()
{
    QLayout *layout = new QHBoxLayout(this);

    layout->addWidget(getSplitter());

    setLayout(layout);
}

void SettingsDialog::initDialog()
{
    initControls();
}

SettingsDialog::SettingsDialog(MediaDBController &refController, QWidget *parent)
    :   QDialog(parent)
    ,   mRefController(refController)
    ,   mPnlSplitter(nullptr)
    ,   mPnlDetails(nullptr)
    ,   mTreeSections(nullptr)
{
    initDialog();
}

MediaDBController &SettingsDialog::getController() const
{
    return(mRefController);
}

QStackedWidget *SettingsDialog::getDetailsPanel()
{
    if(mPnlDetails == nullptr)
        mPnlDetails = new QStackedWidget(this);

    return(mPnlDetails);
}

QTreeWidget *SettingsDialog::getSectionsTree()
{
    if(mTreeSections == nullptr)
        mTreeSections = new QTreeWidget(this);

    return(mTreeSections);
}

QSplitter *SettingsDialog::getSplitter()
{
    if(mPnlSplitter == nullptr)
        {
        mPnlSplitter = new QSplitter(Qt::Orientation::Horizontal, this);

        mPnlSplitter->addWidget(getSectionsTree());
        mPnlSplitter->addWidget(getDetailsPanel());
        }

    return(mPnlSplitter);
}
