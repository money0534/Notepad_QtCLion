#include <QtCore/QTextStream>
#include <QtWidgets/QMessageBox>
#include "addemp.h"
#include "ui_addemp.h"

AddEmp::AddEmp(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::AddEmp) {
    ui->setupUi(this);

    //下拉框设置数据
    for (int i = 0; i < 40; ++i) {
        ui->cbbAge->insertItem(i, QString::number(i));
    }

    ui->cbbDept->insertItem(0, "研发部");
    ui->cbbDept->insertItem(1, "财务部");
    ui->cbbDept->insertItem(2, "行政部");
    ui->cbbDept->insertItem(3, "生产部");
}

AddEmp::~AddEmp() {
    delete ui;
}

void AddEmp::on_btnConfirm_clicked() {
    EmpModel model;

    model.setName(ui->leName->text());
    model.setId(ui->leId->text());

    model.setGender(ui->rbMale->isChecked()?"男":"女");
    model.setAge(ui->cbbAge->currentIndex());
    model.setDept(ui->cbbDept->currentText());
    QString hoboy;
    if(ui->cbBasketball->isChecked()){
        hoboy+=ui->cbBasketball->text();
        hoboy+=",";
    }
    if(ui->cbBadminton->isChecked()){
        hoboy+=ui->cbBadminton->text();
        hoboy+=",";
    }
    if(ui->cbPool->isChecked()){
        hoboy+=ui->cbPool->text();
        hoboy+=",";

    }
    if(ui->cbGame->isChecked()){
        hoboy+=ui->cbGame->text();
        hoboy+=",";

    }

    model.setHobby(hoboy);

    writeToFile(model);
}

void AddEmp::on_btnCancel_clicked() {
    this->close();
}

void AddEmp::on_rbMale_toggled(bool checked) {

}

void AddEmp::on_rbFemale_toggled(bool checked) {

}

void AddEmp::on_cbbAge_currentIndexChanged(int arg1)
{

}

void AddEmp::on_cbbDept_currentIndexChanged(const QString &arg1)
{

}

void AddEmp::on_cbPool_stateChanged(int arg1)
{

}

void AddEmp::on_cbBasketball_stateChanged(int arg1)
{

}

void AddEmp::on_cbBadminton_stateChanged(int arg1)
{

}

void AddEmp::on_cbGame_stateChanged(int arg1)
{

}

void AddEmp::writeToFile(EmpModel& model) {
    QFile file("emps.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)){
        int ret = QMessageBox::critical(this,"错误","打开文件失败","确定");
        return;
    }

    QTextStream out(&file);
    out <<model.getName()<<" "<<model.getId()<<" "<<model.getGender()<<" "
    <<model.getAge()<<" "<<model.getDept()<<" "<<model.getHobby()<<"\n";

    file.close();
    this->close();
}
