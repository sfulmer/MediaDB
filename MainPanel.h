#pragma once

#include<QListWidget>
#include<QWidget>

class MainPanel : public QWidget
{
    Q_OBJECT
    QListWidget *mList;
protected:
    QListWidget *getList();
public:
    explicit MainPanel(QWidget *parent = nullptr);

signals:

public slots:
};
