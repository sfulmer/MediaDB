#include "MediaListPanel.h"
#include<QtGlobal>
#include<QVBoxLayout>

using namespace net::draconia::mediadb::ui;

MediaListButtonPanel *MediaListPanel::getButtonPanel()
{
    if(mPnlButtons == nullptr)
        mPnlButtons = new MediaListButtonPanel(this);

    return(mPnlButtons);
}

QListWidget *MediaListPanel::getMediaList()
{
    if(mLstMedia == nullptr)
        {
        mLstMedia = new QListWidget(this);

        mLstMedia->addItem("Testing");
        mLstMedia->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        mLstMedia->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        }

    return(mLstMedia);
}

void MediaListPanel::initPanel()
{
    QLayout *loMediaList = new QVBoxLayout(this);

    loMediaList->addWidget(getMediaList());
    loMediaList->addWidget(getButtonPanel());
    loMediaList->setSpacing(5);

    setLayout(loMediaList);
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding));
}

MediaListPanel::MediaListPanel(QWidget *parent)
    : QWidget(parent)
    , mPnlButtons(nullptr)
    , mLstMedia(nullptr)
{
    initPanel();
}

QSize MediaListPanel::sizeHint() const
{
    MediaListPanel &refThis = const_cast<MediaListPanel &>(*this);
    QSize szHint = QSize(   qMax(   refThis.getMediaList()->sizeHint().width()
                                ,   refThis.getButtonPanel()->sizeHint().width())
                         ,  refThis.getMediaList()->sizeHint().height()
                         +  refThis.getButtonPanel()->sizeHint().height()
                         +  3);

    return(szHint);
}
