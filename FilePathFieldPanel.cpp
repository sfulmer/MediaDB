#include "FilePathFieldPanel.h"
#include<QHBoxLayout>

using namespace net::draconia::mediadb::ui;

QPushButton *FilePathFieldPanel::getBrowseButton()
{
    if(mBtnBrowse == nullptr)
        {
        mBtnBrowse = new QPushButton("&Browse...", this);

        mBtnBrowse->setFlat(false);
        mBtnBrowse->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        }

    return(mBtnBrowse);
}

QLineEdit *FilePathFieldPanel::getFilePathField()
{
    if(mTxtFilePath == nullptr)
        mTxtFilePath = new QLineEdit(this);

    return(mTxtFilePath);
}

void FilePathFieldPanel::initPanel()
{
    QLayout *loFilePath = new QHBoxLayout(this);

    loFilePath->addWidget(getFilePathField());
    loFilePath->addWidget(getBrowseButton());

    loFilePath->setSpacing(3);
    loFilePath->setMargin(0);

    setLayout(loFilePath);
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
}

FilePathFieldPanel::FilePathFieldPanel(QWidget *parent)
    : QWidget(parent)
    , mTxtFilePath(nullptr)
    , mBtnBrowse(nullptr)
{
    initPanel();
}

QSize FilePathFieldPanel::sizeHint() const
{
    return(QWidget::sizeHint());
}
