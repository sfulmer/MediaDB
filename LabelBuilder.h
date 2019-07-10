#pragma once

#include<QLabel>

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace util
            {
                class LabelBuilder
                {
                    QFont &mFntApplication;
                protected:
                    QFont getApplicationFont() const;
                public:
                    LabelBuilder();

                    QLabel *buildQLabel(QLabel *lbl, const bool bAutofillBackground);
                    QLabel *buildQLabel(QLabel *lbl, const bool bAutofillBackground, QWidget *ptrBuddy);
                    QLabel *buildQLabel(QLabel *lbl, const bool bAutofillBackground, QWidget *ptrBuddy, const QFont &fntToUse);
                    QLabel *buildQLabel(QWidget *parent, const QString &sLabelText, const bool bAutofillBackground);
                    QLabel *buildQLabel(QWidget *parent, const QString &sLabelText, const bool bAutofillBackground, QWidget *ptrBuddy);
                    QLabel *buildQLabel(QWidget *parent, const QString &sLabelText, const bool bAutofillBackground, QWidget *ptrBuddy, const QFont &fntToUse);
                };
            }
        }
    }
}
