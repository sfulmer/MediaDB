#pragma once

#include "ListButtonPanel.h"
#include<QLabel>
#include<QListWidget>
#include<QWidget>

namespace net
{
    namespace draconia
    {
        namespace ui
        {
            class ListPanel : public QWidget
            {
                Q_OBJECT
                bool mbSortingEnabled;
                ListButtonPanel *mPnlButtons;
                QLabel *mLblTitle;
                QListWidget *mLstList;
                QString msTitle;
            protected:
                ListButtonPanel *getButtonPanel();
                QListWidget *getList();
                QLabel *getTitleLabel();
                void initPanel();
            public:
                ListPanel(QWidget *parent);
                ListPanel(const QString &sTitle, QWidget *parent);
                ListPanel(const QString &sTitle, bool bSortingEnabled, QWidget *parent);
                int count() const;
                QListWidgetItem *currentItem() const;
                int	currentRow() const;
                void editItem(QListWidgetItem *item);
                QList<QListWidgetItem *> findItems(const QString &text, Qt::MatchFlags flags) const;
                QString &getTitle();
                Qt::ScrollBarPolicy	horizontalScrollBarPolicy() const;
                void insertItem(int row, QListWidgetItem *item);
                void insertItem(int row, const QString &label);
                void insertItems(int row, const QStringList &labels);
                bool isPersistentEditorOpen(QListWidgetItem *item) const;
                bool isSortingEnabled() const;
                QListWidgetItem *item(int row) const;
                QListWidgetItem *itemAt(const QPoint &p) const;
                QListWidgetItem *itemAt(int x, int y) const;
                QWidget *itemWidget(QListWidgetItem *item) const;
                void openPersistentEditor(QListWidgetItem *item);
                void removeItemWidget(QListWidgetItem *item);
                int	row(const QListWidgetItem *item) const;
                QList<QListWidgetItem *> selectedItems() const;
                void setCurrentItem(QListWidgetItem *item);
                void setCurrentItem(QListWidgetItem *item, QItemSelectionModel::SelectionFlags command);
                void setCurrentRow(int row);
                void setCurrentRow(int row, QItemSelectionModel::SelectionFlags command);
                void setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy);
                void setItemWidget(QListWidgetItem *item, QWidget *widget);
                void setSortingEnabled(bool bSortingEnabled);
                void setTitle(const QString &sTitle);
                void setVerticalScrollBarPolicy(Qt::ScrollBarPolicy);
                virtual QSize sizeHint() const;
                void sortItems(Qt::SortOrder order = Qt::AscendingOrder);
                QListWidgetItem *takeItem(int row);
                Qt::ScrollBarPolicy	verticalScrollBarPolicy() const;
                QRect visualItemRect(const QListWidgetItem *item) const;
            signals:

            public slots:
                void setDisabled(bool disable);
            };
        }
    }
}
