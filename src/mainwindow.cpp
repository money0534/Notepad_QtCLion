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

    //下载任务
    tasks = new QQueue<Task*>;
}

MainWindow::~MainWindow()
{
    delete tasks;
    delete ui;
    delete fileDialog;
}

void MainWindow::on_btnCancel_clicked()
{
    qDebug()<<"Cancel click";
    close();
}

void MainWindow::warn(QString msg){
    QMessageBox::warning(this,"警告",msg);
}

void MainWindow::initTask(QString& url,QString& path) {
    Task* task = new Task(url,path);
    //使用这种方式绑定，SIGNAL和SLOTS测试无效
    connect(task,&Task::downloadFinish,this,&MainWindow::onDownloadFinish);
    connect(task,&Task::taskFinish,this,&MainWindow::onTaskFinish);
    tasks->enqueue(task);
}

void MainWindow::on_btnDownload_clicked()
{
    //禁用下载按钮
    ui->btnDownload->setEnabled(false);

    qDebug()<<"Download click";

    //app选中
    if(isAppChecked){
        qDebug()<<"app选中";
        QString appUrl = ui->leAppUrl->text().trimmed();
        if(appUrl.isEmpty()){
            warn("请输入应用下载地址！");
            return;
        }

        if(appPath.isEmpty()){
            warn("请选择应用安装路径！");
            return;
        }
        initTask(appUrl,appPath);
    }

    //res选中
    if(isCfgChecked){
        qDebug()<<"res选中";
        QString cfgUrl = ui->leCfgUrl->text().trimmed();
        if(cfgUrl.isEmpty()){
            warn("请输入配置文件下载地址！");
            return;
        }

        if(cfgPath.isEmpty()){
            warn("请选择配置文件解压路径！");
            return;
        }
        initTask(cfgUrl,cfgPath);
    }

    //scene选中
    if(isSceneChecked){
        qDebug()<<"scene选中";
        QString sceneUrl = ui->leSceneUrl->text().trimmed();
        if(sceneUrl.isEmpty()){
            warn("请输入场景文件下载地址！");
            return;
        }

        if(scenePath.isEmpty()){
            warn("请选择场景文件解压路径！");
            return;
        }
        initTask(sceneUrl,scenePath);
    }

    startDownload();
}

void MainWindow::startDownload() {
    if (!tasks->isEmpty()){
        currentTask = tasks->dequeue();
        qDebug()<<"开始下载："<<currentTask->downloadUrl;
        showStatus("正在下载 "+currentTask->downloadUrl);
        currentTask->startDownload();
    }
}

void MainWindow::onDownloadFinish() {
    qDebug()<<"下载结束："<<currentTask->downloadUrl;
    showStatus("正在解压 "+currentTask->filename +" 到 "+currentTask->decompressPath);
}


void MainWindow::onTaskFinish() {
    qDebug()<<"任务结束："<<currentTask->downloadUrl;

    //删除当前任务
//    delete currentTask;
    //开始下一个
    if (!tasks->isEmpty()){
        startDownload();
    } else{
        onAllTaskFinish();
    }
}

void MainWindow::onAllTaskFinish() {
    showStatus("全部下载完成");

    //提醒 和 退出
}



void MainWindow::on_cbApp_toggled(bool checked)
{
    isAppChecked = checked;
    qDebug()<<"App "<<checked;
}

void MainWindow::on_cbCfg_toggled(bool checked)
{
    isCfgChecked=checked;
    qDebug()<<"Cfg "<<checked;

}

void MainWindow::on_cbScene_toggled(bool checked)
{
    isSceneChecked=checked;
    qDebug()<<"Scene "<<checked;
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

void MainWindow::on_tbCfgPath_clicked()
{
//    qDebug()<<"CfgPath clicked ";
    fileDialog->show();

    if(fileDialog->exec()){
        cfgPath = fileDialog->selectedFiles()[0];
        qDebug()<<cfgPath;
        ui->lbCfgPath->setText(cfgPath);
        ui->lbCfgPath->setStyleSheet("color: black;");
    }
}

void MainWindow::on_tbScenePath_clicked()
{
    fileDialog->show();

    if(fileDialog->exec()){
        scenePath = fileDialog->selectedFiles()[0];
        qDebug()<<scenePath;
        ui->lbScenePath->setText(scenePath);
        ui->lbScenePath->setStyleSheet("color: black;");
    }
}

void MainWindow::showStatus(QString status) {
    statusBar()->showMessage(status);
}






