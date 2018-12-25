#include "addemp.h"
#include "ui_addemp.h"

AddEmp::AddEmp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEmp)
{
    ui->setupUi(this);
}

AddEmp::~AddEmp()
{
    delete ui;
}

void AddEmp::on_btnConfirm_clicked()
{

}

void AddEmp::on_btnCancel_clicked()
{
    this->close();
}

void AddEmp::on_rbMale_toggled(bool checked)
{

}

void AddEmp::on_rbFemale_toggled(bool checked)
{

}
