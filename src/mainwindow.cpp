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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCancel_clicked()
{
    qDebug()<<"Cancel click";
    close();
}

void MainWindow::on_btnDownload_clicked()
{
    qDebug()<<"Download click";

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
    qDebug()<<"AppPath clicked ";
//    ui->lbAppPath->setText("D:/Unity/Projects/哈哈智能驾校");
}

void MainWindow::on_tbResPath_clicked()
{
    qDebug()<<"ResPath clicked ";

}
