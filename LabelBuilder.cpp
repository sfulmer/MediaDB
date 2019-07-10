#include "BeanFactory.h"
#include "LabelBuilder.h"

using namespace net::draconia::mediadb::util;

QFont LabelBuilder::getApplicationFont() const
{
    return(mFntApplication);
}

LabelBuilder::LabelBuilder()
    : mFntApplication(BeanFactory::getInstance().getApplicationFont())
{ }

QLabel *LabelBuilder::buildQLabel(QLabel *lbl, const bool bAutofillBackground)
{
    lbl->setAutoFillBackground(bAutofillBackground);

    return(lbl);
}

QLabel *LabelBuilder::buildQLabel(QLabel *lbl, const bool bAutofillBackground, QWidget *ptrBuddy)
{
    QFont fnt = QFont(getApplicationFont().family(), getApplicationFont().pointSize(), QFont::Bold, getApplicationFont().italic());

    return(buildQLabel(lbl, bAutofillBackground, ptrBuddy, fnt));
}

QLabel *LabelBuilder::buildQLabel(QLabel *lbl, const bool bAutofillBackground, QWidget *ptrBuddy, const QFont &fntToUse)
{
    lbl->setAutoFillBackground(bAutofillBackground);
    lbl->setBuddy(ptrBuddy);
    lbl->setFont(fntToUse);

    return(lbl);
}

QLabel *LabelBuilder::buildQLabel(QWidget *parent, const QString &sLabelText, const bool bAutofillBackground)
{
    return(buildQLabel(new QLabel(sLabelText, parent), bAutofillBackground));
}

QLabel *LabelBuilder::buildQLabel(QWidget *parent, const QString &sLabelText, const bool bAutofillBackground, QWidget *ptrBuddy)
{
    return(buildQLabel(new QLabel(sLabelText, parent), bAutofillBackground, ptrBuddy));
}

QLabel *LabelBuilder::buildQLabel(QWidget *parent, const QString &sLabelText, const bool bAutofillBackground, QWidget *ptrBuddy, const QFont &fntToUse)
{
    return(buildQLabel(new QLabel(sLabelText, parent), bAutofillBackground, ptrBuddy, fntToUse));
}
