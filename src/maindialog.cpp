
#include "maindialog.h"
#include "ui_maindialog.h"

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;
}

MainDialog::MainDialog(QPair<QString,QString>  taskEntity, QWidget *parent) :
        QDialog(parent),
        ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    this->taskEntity = taskEntity;

    qDebug()<<taskEntity.first<<","<<taskEntity.second;

}



