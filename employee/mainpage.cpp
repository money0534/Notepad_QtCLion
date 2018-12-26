#include "mainpage.h"
#include "ui_mainpage.h"
#include <QMessageBox>

MainPage::MainPage(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainPage) {
    ui->setupUi(this);
    //初始化放在事件中？
    addEmp = new AddEmp;
    queryEmp = new QueryEmp;
}

MainPage::~MainPage() {
    delete addEmp;
    delete queryEmp;
    delete ui;
}

void MainPage::on_actionadd_triggered() {

    addEmp->show();
    //模态窗口
//    AddEmp addEmp2;
//    addEmp2.exec();
}

void MainPage::on_actionqueryEmp_triggered() {
    queryEmp->show();
}

/**
 * 关于
 */
void MainPage::on_actionabout_triggered() {
    QMessageBox::aboutQt(this);
}
