#include "ListButtonPanel.h"
#include<QHBoxLayout>

using namespace net::draconia::ui;

QPushButton *ListButtonPanel::getAddButton()
{
    if(mBtnAdd == nullptr)
        {
        mBtnAdd = new QPushButton("&Add", this);

        mBtnAdd->setFlat(false);
        mBtnAdd->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        }

    return(mBtnAdd);
}

QPushButton *ListButtonPanel::getEditButton()
{
    if(mBtnEdit == nullptr)
        {
        mBtnEdit = new QPushButton("&Edit", this);

        mBtnEdit->setDisabled(true);
        mBtnEdit->setFlat(false);
        mBtnEdit->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        }

    return(mBtnEdit);
}

QPushButton *ListButtonPanel::getRemoveButton()
{
    if(mBtnRemove == nullptr)
        {
        mBtnRemove = new QPushButton("&Remove", this);

        mBtnRemove->setDisabled(true);
        mBtnRemove->setFlat(false);
        mBtnRemove->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        }

    return(mBtnRemove);
}

void ListButtonPanel::initPanel()
{
    QLayout *loButtons = new QHBoxLayout(this);

    loButtons->addWidget(getAddButton());
    loButtons->addWidget(getEditButton());
    loButtons->addWidget(getRemoveButton());
    loButtons->setSpacing(3);

    setLayout(loButtons);
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
}

ListButtonPanel::ListButtonPanel(QWidget *parent)
    : QWidget(parent)
    , mBtnAdd(nullptr), mBtnEdit(nullptr), mBtnRemove(nullptr)
{
    initPanel();
}

QSize ListButtonPanel::sizeHiint() const
{
    return(QWidget::sizeHint());
}

void ListButtonPanel::setDisabled(bool disable)
{
    getAddButton()->setDisabled(disable);
    getEditButton()->setDisabled(disable);
    getRemoveButton()->setDisabled(disable);
}
