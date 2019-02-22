#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //禁用窗口大小调节和最大化按钮
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());

    //文件选择窗口
    fileDialog = new QFileDialog(this);
    fileDialog->setFileMode(QFileDialog::Directory);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete fileDialog;
}

void MainWindow::on_btnCancel_clicked()
{
    qDebug()<<"Cancel click";
    close();
}

void MainWindow::on_btnDownload_clicked()
{
    qDebug()<<"Download click";

    if(!isResChecked&&!isAppChecked){
        //全都未选中
        return;
    }

    //app选中
    if(isAppChecked){

    }

    //res选中
    if(isResChecked){

    }
}

void MainWindow::on_cbApp_toggled(bool checked)
{
    isAppChecked = checked;
    qDebug()<<"App "<<checked;
}

void MainWindow::on_cbRes_toggled(bool checked)
{
    isResChecked=checked;
    qDebug()<<"Res "<<checked;

}


void MainWindow::on_tbAppPath_clicked()
{
//    qDebug()<<"AppPath clicked ";

    fileDialog->show();

    if(fileDialog->exec()){
        appPath = fileDialog->selectedFiles()[0];
            qDebug()<<appPath;
            ui->lbAppPath->setText(appPath);
        ui->lbAppPath->setStyleSheet("color: black;");
    }
}

void MainWindow::on_tbResPath_clicked()
{
//    qDebug()<<"ResPath clicked ";
    fileDialog->show();

    if(fileDialog->exec()){
        resPath = fileDialog->selectedFiles()[0];
        qDebug()<<resPath;
        ui->lbResPath->setText(resPath);
        ui->lbResPath->setStyleSheet("color: black;");
    }
}
