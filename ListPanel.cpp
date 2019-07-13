#include "ListPanel.h"
#include<QMouseEvent>
#include<QVBoxLayout>

using namespace net::draconia::ui;

ListButtonPanel *ListPanel::getButtonPanel()
{
    if(mPnlButtons == nullptr)
        mPnlButtons = new ListButtonPanel(this);

    return(mPnlButtons);
}

QAction *ListPanel::getAddAction()
{
    if(mActAdd == nullptr)
        {
        mActAdd = new QAction(tr("&Add"), this);

        connect(mActAdd, &QAction::triggered, this, &ListPanel::addDetail);
        }

    return(mActAdd);
}

QMenu &ListPanel::getContextMenu()
{
    if(mMnuContext.isEmpty())
        {
        mMnuContext.addAction(getAddAction());
        mMnuContext.addAction(getEditAction());
        mMnuContext.addAction(getRemoveAction());
        }

    return(mMnuContext);
}

QAction *ListPanel::getEditAction()
{
    if(mActEdit == nullptr)
        {
        mActEdit = new QAction(tr("&Edit"), this);

        connect(mActEdit, &QAction::triggered, this, &ListPanel::editDetail);

        mActEdit->setEnabled(getList()->selectedItems().count() == 1);
        }

    return(mActEdit);
}

QListWidget *ListPanel::getList()
{
    if(mLstList == nullptr)
        {
        mLstList = new QListWidget(this);

        mLstList->setSortingEnabled(isSortingEnabled());
        }

    return(mLstList);
}

QAction *ListPanel::getRemoveAction()
{
    if(mActRemove == nullptr)
        {
        mActRemove = new QAction(tr("&Remove"), this);

        connect(mActRemove, &QAction::triggered, this, &ListPanel::removeDetail);

        mActRemove->setEnabled(getList()->selectedItems().count() > 0);
        }

    return(mActRemove);
}

QLabel *ListPanel::getTitleLabel()
{
    if(mLblTitle == nullptr)
        {
        mLblTitle = new QLabel(getTitle(), this);

        mLblTitle->setAutoFillBackground(false);
        mLblTitle->setBuddy(getList());
        mLblTitle->setFont(QFont(font().family(), font().pointSize(), QFont::Bold, font().italic()));
        }

    return(mLblTitle);
}

void ListPanel::initPanel()
{
    QLayout *loList = new QVBoxLayout(this);

    loList->addWidget(getTitleLabel());
    loList->addWidget(getList());
    loList->addWidget(getButtonPanel());

    loList->setSpacing(2);

    getList()->setContextMenuPolicy(Qt::CustomContextMenu);
    setLayout(loList);
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    connect(getList(), SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
}

ListPanel::ListPanel(QWidget *parent)
    : QWidget(parent)
    , mbSortingEnabled(false)
    , mPnlButtons(nullptr)
    , mActAdd(nullptr)
    , mActEdit(nullptr)
    , mActRemove(nullptr)
    , mLblTitle(nullptr)
    , mLstList(nullptr)
{
    initPanel();
}

ListPanel::ListPanel(const QString &sTitle, QWidget *parent)
    : QWidget(parent)
    , mbSortingEnabled(false)
    , mPnlButtons(nullptr)
    , mActAdd(nullptr)
    , mActEdit(nullptr)
    , mActRemove(nullptr)
    , mLblTitle(nullptr)
    , mLstList(nullptr)
    , msTitle(sTitle)
{
    initPanel();
}

ListPanel::ListPanel(const QString &sTitle, bool bSortingEnabled, QWidget *parent)
    : QWidget(parent)
    , mbSortingEnabled(bSortingEnabled)
    , mPnlButtons(nullptr)
    , mActAdd(nullptr)
    , mActEdit(nullptr)
    , mActRemove(nullptr)
    , mLblTitle(nullptr)
    , mLstList(nullptr)
    , msTitle(sTitle)
{
    initPanel();
}

int ListPanel::count() const
{
    ListPanel &refThis = const_cast<ListPanel &>(*this);

    return(refThis.getList()->count());
}

QListWidgetItem *ListPanel::currentItem() const
{
    ListPanel &refThis = const_cast<ListPanel &>(*this);

    return(refThis.getList()->currentItem());
}

int	ListPanel::currentRow() const
{
    ListPanel &refThis = const_cast<ListPanel &>(*this);

    return(refThis.getList()->currentRow());
}

void ListPanel::editItem(QListWidgetItem *item)
{
    getList()->editItem(item);
}

bool ListPanel::eventFilter(QObject *object, QEvent *event)
{
    if((object == getList()) && (event->type() == QEvent::Type::MouseButtonPress))
        return(true);

    return(false);
}

QList<QListWidgetItem *> ListPanel::findItems(const QString &text, Qt::MatchFlags flags) const
{
    ListPanel &refThis = const_cast<ListPanel &>(*this);

    return(refThis.getList()->findItems(text, flags));
}

QString &ListPanel::getTitle()
{
    return(msTitle);
}

Qt::ScrollBarPolicy	ListPanel::horizontalScrollBarPolicy() const
{
    ListPanel &refThis = const_cast<ListPanel &>(*this);

    return(refThis.getList()->horizontalScrollBarPolicy());
}

void ListPanel::insertItem(int row, QListWidgetItem *item)
{
    getList()->insertItem(row, item);
}

void ListPanel::insertItem(int row, const QString &label)
{
    getList()->insertItem(row, label);
}

void ListPanel::insertItems(int row, const QStringList &labels)
{
    getList()->insertItems(row, labels);
}

bool ListPanel::isPersistentEditorOpen(QListWidgetItem *item) const
{
    ListPanel &refThis = const_cast<ListPanel &>(*this);

    return(refThis.getList()->isPersistentEditorOpen(item));
}

bool ListPanel::isSortingEnabled() const
{
    return(mbSortingEnabled);
}

QListWidgetItem *ListPanel::item(int row) const
{
    ListPanel &refThis = const_cast<ListPanel &>(*this);

    return(refThis.getList()->item(row));
}

QListWidgetItem *ListPanel::itemAt(const QPoint &p) const
{
    ListPanel &refThis = const_cast<ListPanel &>(*this);

    return(refThis.getList()->itemAt(p));
}

QListWidgetItem *ListPanel::itemAt(int x, int y) const
{
    ListPanel &refThis = const_cast<ListPanel &>(*this);

    return(refThis.getList()->itemAt(x, y));
}

QWidget *ListPanel::itemWidget(QListWidgetItem *item) const
{
    ListPanel &refThis = const_cast<ListPanel &>(*this);

    return(refThis.getList()->itemWidget(item));
}

void ListPanel::openPersistentEditor(QListWidgetItem *item)
{
    getList()->openPersistentEditor(item);
}

void ListPanel::removeItemWidget(QListWidgetItem *item)
{
    getList()->removeItemWidget(item);
}

int	ListPanel::row(const QListWidgetItem *item) const
{
    ListPanel &refThis = const_cast<ListPanel &>(*this);

    return(refThis.getList()->row(item));
}

QList<QListWidgetItem *> ListPanel::selectedItems() const
{
    ListPanel &refThis = const_cast<ListPanel &>(*this);

    return(refThis.getList()->selectedItems());
}

void ListPanel::setCurrentItem(QListWidgetItem *item)
{
    getList()->setCurrentItem(item);
}

void ListPanel::setCurrentItem(QListWidgetItem *item, QItemSelectionModel::SelectionFlags command)
{
    getList()->setCurrentItem(item, command);
}

void ListPanel::setCurrentRow(int row)
{
    getList()->setCurrentRow(row);
}

void ListPanel::setCurrentRow(int row, QItemSelectionModel::SelectionFlags command)
{
    getList()->setCurrentRow(row, command);
}

void ListPanel::setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy policy)
{
    getList()->setHorizontalScrollBarPolicy(policy);
}

void ListPanel::setItemWidget(QListWidgetItem *item, QWidget *widget)
{
    getList()->setItemWidget(item, widget);
}

void ListPanel::setSortingEnabled(bool bSortingEnabled)
{
    mbSortingEnabled = bSortingEnabled;

    getList()->setSortingEnabled(isSortingEnabled());
}

void ListPanel::setTitle(const QString &sTitle)
{
    msTitle = sTitle;

    getTitleLabel()->setText(getTitle());
}

void ListPanel::setVerticalScrollBarPolicy(Qt::ScrollBarPolicy policy)
{
    getList()->setVerticalScrollBarPolicy(policy);
}

QSize ListPanel::sizeHint() const
{
    return(QWidget::sizeHint());
}

void ListPanel::sortItems(Qt::SortOrder order)
{
    getList()->sortItems(order);
}

QListWidgetItem *ListPanel::takeItem(int row)
{
    return(getList()->takeItem(row));
}

Qt::ScrollBarPolicy	ListPanel::verticalScrollBarPolicy() const
{
    ListPanel &refThis = const_cast<ListPanel &>(*this);

    return(refThis.getList()->verticalScrollBarPolicy());
}

QRect ListPanel::visualItemRect(const QListWidgetItem *item) const
{
    ListPanel &refThis = const_cast<ListPanel &>(*this);
    QListWidget *ptrList = refThis.getList();

    return(ptrList->visualItemRect(item));
}

void ListPanel::addDetail()
{ }

void ListPanel::editDetail()
{ }

void ListPanel::removeDetail()
{ }

void ListPanel::setDisabled(bool disable)
{
    getList()->setDisabled(disable);
    getButtonPanel()->setDisabled(disable);
}

void ListPanel::showContextMenu(const QPoint &pos)
{
    getContextMenu().exec(getList()->mapToGlobal(pos));
}
