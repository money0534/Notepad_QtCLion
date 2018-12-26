#ifndef QUERYEMP_H
#define QUERYEMP_H

#include <QDialog>
#include <QtGui/QStandardItemModel>
#include <QtGui/QStandardItem>

namespace Ui {
class QueryEmp;
}

class QueryEmp : public QDialog
{
    Q_OBJECT

public:
    explicit QueryEmp(QWidget *parent = nullptr);
    ~QueryEmp();

private slots:
    void on_btnQuery_clicked();

    void on_cbbType_currentIndexChanged(int index);

private:
    Ui::QueryEmp *ui;
    int queryType;
    QList<QString> queryList;
    QStandardItemModel* model;

    void init();
    void execQuery();

    void displayItem(QStringList &list);
};

#endif // QUERYEMP_H
