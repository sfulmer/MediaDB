#include "MediaDetailsDataPanel.h"
#include<QFormLayout>

using namespace net::draconia::mediadb::ui;

/*FilePathFieldPanel *MediaDetailsDataPanel::getFilePathField()
{
    if(mFldFilePath == nullptr)
        {
        mFldFilePath = new FilePathFieldPanel(this);
        }

    return(mFldFilePath);
}

QLabel *MediaDetailsDataPanel::getFilePathLabel()
{
    if(mLblFilePath == nullptr)
        {
        mLblFilePath = new QLabel("File &Path:", this);

        mLblFilePath->setBuddy(getFilePathField());
        mLblFilePath->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        }

    return(mLblFilePath);
}*/

QLineEdit *MediaDetailsDataPanel::getNameField()
{
    if(mTxtName == nullptr)
        {
        mTxtName = new QLineEdit(this);
        }

    return(mTxtName);
}

QLabel *MediaDetailsDataPanel::getNameLabel()
{
    if(mLblName == nullptr)
        {
        mLblName = new QLabel("&Name: ", this);

        mLblName->setBuddy(getNameField());
        mLblName->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        }

    return(mLblName);
}

/*QDateEdit *MediaDetailsDataPanel::getReleaseDateField()
{
    if(mDtRelease == nullptr)
        {
        mDtRelease = new QDateEdit(this);

        mDtRelease->setFixedWidth(100);
        }

    return(mDtRelease);
}

QLabel *MediaDetailsDataPanel::getReleaseDateLabel()
{
    if(mLblReleaseDate == nullptr)
        {
        mLblReleaseDate = new QLabel("Release &Date:", this);

        mLblReleaseDate->setBuddy(getReleaseDateField());
        mLblReleaseDate->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        }

    return(mLblReleaseDate);
}*/

void MediaDetailsDataPanel::initPanel()
{
    QFormLayout *loDetailsData = new QFormLayout(this);

    loDetailsData->addRow(getNameLabel(), getNameField());
    //loDetailsData->addRow(getReleaseDateLabel(), getReleaseDateField());
    //loDetailsData->addRow(getFilePathLabel(), getFilePathField());

    loDetailsData->setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy::AllNonFixedFieldsGrow);
    loDetailsData->setSpacing(3);

    setLayout(loDetailsData);
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));
}

MediaDetailsDataPanel::MediaDetailsDataPanel(QWidget *parent)
    : QWidget(parent)
    /*, mFldFilePath(nullptr)
    , mDtRelease(nullptr)
    , mLblFilePath(nullptr)*/
    , mLblName(nullptr)
    //, mLblReleaseDate(nullptr)
    , mTxtName(nullptr)
{
    initPanel();
}

QSize MediaDetailsDataPanel::sizeHint() const
{
    return(QWidget::sizeHint());
}

void MediaDetailsDataPanel::setDisabled(bool disable)
{
    getNameLabel()->setDisabled(disable);
    getNameField()->setDisabled(disable);
    /*getReleaseDateLabel()->setDisabled(disable);
    getReleaseDateField()->setDisabled(disable);
    getFilePathLabel()->setDisabled(disable);
    getFilePathField()->setDisabled(disable);*/
}
