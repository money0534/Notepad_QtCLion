
#include "maindialog.h"
#include "ProgressDialog.h"
#include "ui_maindialog.h"


MainDialog::MainDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::MainDialog) {
    ui->setupUi(this);
}

MainDialog::~MainDialog() {
    delete ui;
    delete myProcess;
//    delete task;
}

MainDialog::MainDialog(QString& url,QString& path, QWidget *parent) :
        QDialog(parent),
        ui(new Ui::MainDialog),  downloadUrl(url),decompressPath(path) {
    ui->setupUi(this);

    task = new Task(downloadUrl,decompressPath);

    connect(task,&Task::cancelTask,this,&MainDialog::doQuit);
    connect(task, &Task::downloadFinish, this, &MainDialog::onDownloadFinish);
    connect(task,&Task::taskFinish,this,&MainDialog::installFinish);
}

void MainDialog::onDownloadFinish() {
    showMsg("正在安装更新包...");
}


void MainDialog::installFinish(){
//    qDebug() << "解压完成！";
    showMsg("更新完成，即将启动");

    //启动Unity，如：D:/Unity/Projects/HahaRobot
    QString input = decompressPath;

    //截取后：/HahaRobot
    QString program = input.right(input.length()-input.lastIndexOf("/"));
//    qDebug()<<"启动程序："<<program;

    QString appDir=input.append(program).append(".exe");
    qDebug()<<"启动程序："<<appDir;


    QStringList arguments;
    myProcess = new QProcess(QCoreApplication::instance());
    myProcess->start(appDir, arguments);

    //最后延时退出
    QTimer::singleShot(500, this, SLOT(doQuit()));
}


void MainDialog::doQuit() {
    this->close();
//    QCoreApplication::instance()->quit();
}

void MainDialog::showMsg(QString content) {
    ui->lbStatus->setText(content);
}

void MainDialog::startDownload() {
    showMsg("正在下载更新包...");
    task->startDownload();
}
