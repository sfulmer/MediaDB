#include "MediaListButtonPanel.h"
#include<QHBoxLayout>

using namespace net::draconia::mediadb::ui;

QPushButton *MediaListButtonPanel::getAddButton()
{
    if(mBtnAdd == nullptr)
        {
        mBtnAdd = new QPushButton("&Add", this);

        mBtnAdd->setFlat(false);
        mBtnAdd->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        }

    return(mBtnAdd);
}

QPushButton *MediaListButtonPanel::getEditButton()
{
    if(mBtnEdit == nullptr)
        {
        mBtnEdit = new QPushButton("&Edit", this);

        mBtnEdit->setFlat(false);
        mBtnEdit->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        }

    return(mBtnEdit);
}

QPushButton *MediaListButtonPanel::getRemoveButton()
{
    if(mBtnRemove == nullptr)
        {
        mBtnRemove = new QPushButton("&Remove", this);

        mBtnRemove->setFlat(false);
        mBtnRemove->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        }

    return(mBtnRemove);
}

void MediaListButtonPanel::initPanel()
{
    QLayout *loButtons = new QHBoxLayout(this);

    loButtons->addWidget(getAddButton());
    loButtons->addWidget(getEditButton());
    loButtons->addWidget(getRemoveButton());
    loButtons->setSpacing(3);

    setLayout(loButtons);
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
}

MediaListButtonPanel::MediaListButtonPanel(QWidget *parent)
    : QWidget(parent)
    , mBtnAdd(nullptr), mBtnEdit(nullptr), mBtnRemove(nullptr)
{
    initPanel();
}
