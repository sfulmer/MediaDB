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

        mLstMedia->addItem("The 41 Year Old Virgin Who Knocked Up Sarah Marshall and Felt Superbad About It");
        mLstMedia->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        mLstMedia->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        }

    return(mLstMedia);
}

void MediaListPanel::initPanel()
{
    QLayout *loMediaList = new QVBoxLayout(this);
    QSizePolicy szPolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    loMediaList->addWidget(getMediaList());
    loMediaList->addWidget(getButtonPanel());
    loMediaList->setSpacing(5);

    szPolicy.setHorizontalStretch(1);

    setLayout(loMediaList);
    setSizePolicy(szPolicy);
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
