#include "MediaDetailsDataPanel.h"
#include<QFormLayout>

using namespace net::draconia::mediadb::ui;

QLabel *MediaDetailsDataPanel::getFilePathLabel()
{
    if(mLblFilePath == nullptr)
        {
        mLblFilePath = new QLabel("File &Path:", this);

        mLblFilePath->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        mLblFilePath->setBuddy(nullptr);
        }

    return(mLblFilePath);
}

QLineEdit *MediaDetailsDataPanel::getNameField()
{
    if(mTxtName == nullptr)
        {
        mTxtName = new QLineEdit(this);

        mTxtName->setReadOnly(true);
        }

    return(mTxtName);
}

QLabel *MediaDetailsDataPanel::getNameLabel()
{
    if(mLblName == nullptr)
        {
        mLblName = new QLabel("&Name: ", this);

        mLblName->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        mLblName->setBuddy(getNameField());
        }

    return(mLblName);
}

QDateEdit *MediaDetailsDataPanel::getReleaseDateField()
{
    if(mDtRelease == nullptr)
        {
        mDtRelease = new QDateEdit(this);

        mDtRelease->setReadOnly(true);
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
}

void MediaDetailsDataPanel::initPanel()
{
    QFormLayout *loDetailsData = new QFormLayout(this);

    loDetailsData->addRow(getNameLabel(), getNameField());
    loDetailsData->addRow(getReleaseDateLabel(), getReleaseDateField());
    //loDetailsData->addRow(getFilePathLabel(), getFilePathField());
    loDetailsData->setSpacing(3);

    setLayout(loDetailsData);
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));
}

MediaDetailsDataPanel::MediaDetailsDataPanel(QWidget *parent)
    : QWidget(parent)
    , mDtRelease(nullptr)
    , mLblFilePath(nullptr)
    , mLblName(nullptr)
    , mLblReleaseDate(nullptr)
    , mTxtName(nullptr)
{
    initPanel();
}

QSize MediaDetailsDataPanel::sizeHint() const
{
    return(QWidget::sizeHint());
}
