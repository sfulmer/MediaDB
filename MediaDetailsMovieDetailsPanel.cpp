#include "MediaDetailsMovieDetailsPanel.h"
#include<QGridLayout>

using namespace net::draconia::mediadb::ui;

QTextEdit *MediaDetailsMovieDetailsPanel::getCommentsField()
{
    if(mTxtComments == nullptr)
        {
        mTxtComments = new QTextEdit(this);

        mTxtComments->setReadOnly(true);
        }

    return(mTxtComments);
}

QLabel *MediaDetailsMovieDetailsPanel::getCommentsLabel()
{
    if(mLblComments == nullptr)
        {
        mLblComments = new QLabel("&Comments:", this);

        mLblComments->setBuddy(getCommentsField());
        mLblComments->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        }

    return(mLblComments);
}

QListWidget *MediaDetailsMovieDetailsPanel::getViewingsList()
{
    if(mLstViewings == nullptr)
        {
        mLstViewings = new QListWidget(this);
        }

    return(mLstViewings);
}

QLabel *MediaDetailsMovieDetailsPanel::getViewingsLabel()
{
    if(mLblViewings == nullptr)
        {
        mLblViewings = new QLabel("Viewings:", this);

        mLblViewings->setBuddy(getViewingsList());
        mLblViewings->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        }

    return(mLblViewings);
}

void MediaDetailsMovieDetailsPanel::initPanel()
{
    QGridLayout *loDetails = new QGridLayout(this);

    loDetails->addWidget(getCommentsLabel(), 0, 0);
    loDetails->addWidget(getViewingsLabel(), 0, 1);
    loDetails->addWidget(getCommentsField(), 1, 0);
    loDetails->addWidget(getViewingsList(), 1, 1);

    loDetails->setSpacing(3);

    setLayout(loDetails);
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));
}

MediaDetailsMovieDetailsPanel::MediaDetailsMovieDetailsPanel(QWidget *parent)
    : QWidget(parent)
    , mLblComments(nullptr)
    , mLblViewings(nullptr)
    , mLstViewings(nullptr)
    , mTxtComments(nullptr)
{
    initPanel();
}

QSize MediaDetailsMovieDetailsPanel::sizeHint() const
{
    return(QWidget::sizeHint());
}
