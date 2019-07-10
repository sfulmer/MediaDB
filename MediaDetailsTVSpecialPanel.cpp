#include "BeanFactory.h"
#include "MediaDetailsTVSpecialPanel.h"
#include<QGridLayout>

using namespace net::draconia::mediadb::ui;

using net::draconia::mediadb::BeanFactory;

QTextEdit *MediaDetailsTVSpecialPanel::getCommentsField()
{
    if(mTxtComments == nullptr)
        mTxtComments = new QTextEdit(this);

    return(mTxtComments);
}

QLabel *MediaDetailsTVSpecialPanel::getCommentsLabel()
{
    if(mLblComments == nullptr)
        mLblComments = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Comments:", false, getCommentsField());

    return(mLblComments);
}

FilePathFieldPanel *MediaDetailsTVSpecialPanel::getFilePathField()
{
    if(mPnlFilePath == nullptr)
        mPnlFilePath = new FilePathFieldPanel(this);

    return(mPnlFilePath);
}

QLabel *MediaDetailsTVSpecialPanel::getFilePathLabel()
{
    if(mLblFilePath == nullptr)
        mLblFilePath = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "File Path:", false, getFilePathField());

    return(mLblFilePath);
}

QLineEdit *MediaDetailsTVSpecialPanel::getNameField()
{
    if(mTxtName == nullptr)
        {
        mTxtName = new QLineEdit(this);

        mTxtName->setFrame(true);
        }

    return(mTxtName);
}

QLabel *MediaDetailsTVSpecialPanel::getNameLabel()
{
    if(mLblName == nullptr)
        mLblName = BeanFactory::getInstance().getLabelBuilder().buildQLabel(this, "Name:", false, getNameField());

    return(mLblName);
}

void MediaDetailsTVSpecialPanel::initPanel()
{
    QGridLayout *loSpecials = new QGridLayout(this);

    loSpecials->addWidget(getNameLabel(), 0, 0, 1, 1);
    loSpecials->addWidget(getNameField(), 0, 1, 1, 1);
    loSpecials->addWidget(getFilePathLabel(), 1, 0, 1, 1);
    loSpecials->addWidget(getFilePathField(), 1, 1, 1, 1);
    loSpecials->addWidget(getCommentsLabel(), 2, 0, 1, 2);
    loSpecials->addWidget(getCommentsField(), 3, 0, 1, 2);

    loSpecials->setSpacing(2);

    setLayout(loSpecials);
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding));
}

MediaDetailsTVSpecialPanel::MediaDetailsTVSpecialPanel(QWidget *parent)
    : QGroupBox("Special", parent)
    , mPnlFilePath(nullptr)
    , mLblComments(nullptr)
    , mLblFilePath(nullptr)
    , mLblName(nullptr)
    , mTxtName(nullptr)
    , mTxtComments(nullptr)
{
    initPanel();
}

QSize MediaDetailsTVSpecialPanel::sizeHint() const
{
    return(QGroupBox::sizeHint());
}

void MediaDetailsTVSpecialPanel::setDisabled(bool disable)
{
    getNameLabel()->setDisabled(disable);
    getNameField()->setDisabled(disable);
    getFilePathLabel()->setDisabled(disable);
    getFilePathField()->setDisabled(disable);
    getCommentsLabel()->setDisabled(disable);
    getCommentsField()->setDisabled(disable);
}
