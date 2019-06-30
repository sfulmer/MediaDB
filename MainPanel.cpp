#include "MainPanel.h"
#include<QVBoxLayout>

QListWidget *MainPanel::getList()
{
    if(mList == nullptr)
        {
        mList = new QListWidget(this);

        mList->addItem("Testing");
        }

    return(mList);
}

MainPanel::MainPanel(QWidget *parent)
    : QWidget(parent)
{
    QLayout *lo = new QVBoxLayout(this);
    mList = new QListWidget(this);

    mList->addItem("Testing");

    lo->addWidget(mList);
    lo->setSpacing(5);

    setLayout(lo);
}
