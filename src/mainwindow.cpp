#include "mainwindow.h"
#include "ui_mainwindow.h"

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

}

void MainWindow::on_btnDownload_clicked()
{

}

void MainWindow::on_cbApp_toggled(bool checked)
{

}

void MainWindow::on_cbRes_toggled(bool checked)
{

}
