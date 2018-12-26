#include "queryemp.h"
#include "ui_queryemp.h"
#include <QDebug>
#include <QtCore/QFile>
#include <QtWidgets/QMessageBox>


QueryEmp::QueryEmp(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::QueryEmp) {
    queryType = 0;
    ui->setupUi(this);
    ui->cbbType->insertItem(0, "请选择查询条件");
    ui->cbbType->insertItem(1, "姓名");
    ui->cbbType->insertItem(2, "工号");
    ui->cbbType->insertItem(3, "年龄");

    model = new QStandardItemModel;
    model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    model->setHorizontalHeaderItem(1,new QStandardItem("工号"));
    model->setHorizontalHeaderItem(2,new QStandardItem("性别"));
    model->setHorizontalHeaderItem(3,new QStandardItem("年龄"));
    model->setHorizontalHeaderItem(4,new QStandardItem("部门"));
    model->setHorizontalHeaderItem(5,new QStandardItem("爱好"));

    ui->tableView->setModel(model);
    init();
}

QueryEmp::~QueryEmp() {
    delete model;
    delete ui;
}

void QueryEmp::on_btnQuery_clicked() {
    execQuery();
}

void QueryEmp::on_cbbType_currentIndexChanged(int index) {
    queryType = index;
    qDebug() << ui->cbbType->currentText();
}

void QueryEmp::execQuery() {
    model->clear();
    if(queryType==0){
        return;
    }
    QString key = ui->leKey->text().trimmed();
    for (int i = 0; i < queryList.length(); ++i) {
        QString item = queryList.at(i);
        qDebug()<<item;
        QStringList fields = item.split(" ");
        switch (queryType) {
            case 1:
                //姓名
                if(fields[0]==key){
                    displayItem(fields);
                }
                break;
            case 2:
                //工号
                if(fields[1]==key){
                    displayItem(fields);
                }
                break;
            case 3:
                //年龄
                if(fields[2]==key){
                    displayItem(fields);

                }
                break;
        }
    }

}

void QueryEmp::init() {
    QFile file("emps.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        int ret = QMessageBox::critical(this, "错误", "打开文件失败", "确定");
        return;
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        queryList.append(line);
    }
    file.close();
}

void QueryEmp::displayItem(QStringList &list) {
    int count = model->rowCount();
    qDebug()<<count;
    for (int i = 0; i < list.length(); ++i) {
        model->setItem(count,i,new QStandardItem(list[i]));
    }
}

