#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
    //禁用窗口大小调节和最大化按钮
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());

    //文件选择窗口
    fileDialog = new QFileDialog(this);
    fileDialog->setFileMode(QFileDialog::Directory);

    //下载任务
    tasks = new QQueue<Task *>;

    loadConfFromJsonFile();
}

void MainWindow::loadConfFromJsonFile() {
    QFile jsonFile("conf/conf.json");
    if (!jsonFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败";
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(jsonFile.readAll());
    jsonFile.close();
    //注意take与value差别；take会移除当前
    QJsonObject obj = doc.object().value("obj").toObject();

    appUrl = obj.value("main_data").toObject().value("down_url").toString();
    appPath = obj.value("main_data").toObject().value("install_path").toString();
    cfgUrl = obj.value("conf_data").toObject().value("down_url").toString();
    cfgPath = obj.value("conf_data").toObject().value("install_path").toString();
    sceneUrl = obj.value("scene_data").toObject().value("down_url").toString();
    scenePath = obj.value("scene_data").toObject().value("install_path").toString();

    if (!appUrl.isEmpty()) {
        ui->leAppUrl->setText(appUrl);
    }

    if (!appPath.isEmpty()) {
        ui->lbAppPath->setText(appPath);
    }

    if (!cfgUrl.isEmpty()) {
        ui->leCfgUrl->setText(cfgUrl);
    }

    if (!cfgPath.isEmpty()) {
        ui->lbCfgPath->setText(cfgPath);
    }

    if (!sceneUrl.isEmpty()) {
        ui->leSceneUrl->setText(sceneUrl);
    }

    if (!scenePath.isEmpty()) {
        ui->lbScenePath->setText(scenePath);
    }

    //qDebug() << appUrl;
    //qDebug() << appPath;
    //qDebug() << cfgUrl;
    //qDebug() << cfgPath;
    //qDebug() << sceneUrl;
    //qDebug() << scenePath;
}

MainWindow::~MainWindow() {
    delete tasks;
    delete ui;
    delete fileDialog;
}

void MainWindow::on_btnCancel_clicked() {
    if (nullptr != currentTask)
        currentTask->cancelDownload();
    doQuit();
}

void MainWindow::warn(QString msg) {
    QMessageBox::warning(this, "警告", msg);
}

void MainWindow::initTask(QString &url, QString &path) {
    Task *task = new Task(url, path);
    //使用这种方式绑定，SIGNAL和SLOTS测试无效
    connect(task, &Task::downloadFinish, this, &MainWindow::onDownloadFinish);
    connect(task, &Task::taskFinish, this, &MainWindow::onTaskFinish);

    connect(task, &Task::cancelTask, this, &MainWindow::onTaskCanceled);
    tasks->enqueue(task);
}

void MainWindow::on_btnDownload_clicked() {

    qDebug() << "Download click";

    //app选中
    if (isAppChecked) {
        qDebug() << "app选中";
        appUrl = ui->leAppUrl->text().trimmed();
        if (appUrl.isEmpty()) {
            warn("请输入应用下载地址！");
            return;
        }

        if (appPath.isEmpty()) {
            warn("请选择应用安装路径！");
            return;
        }
    }

    //res选中
    if (isCfgChecked) {
        qDebug() << "res选中";
        cfgUrl = ui->leCfgUrl->text().trimmed();
        if (cfgUrl.isEmpty()) {
            warn("请输入配置文件下载地址！");
            return;
        }

        if (cfgPath.isEmpty()) {
            warn("请选择配置文件解压路径！");
            return;
        }
    }

    //scene选中
    if (isSceneChecked) {
        qDebug() << "scene选中";
        sceneUrl = ui->leSceneUrl->text().trimmed();
        if (sceneUrl.isEmpty()) {
            warn("请输入场景文件下载地址！");
            return;
        }

        if (scenePath.isEmpty()) {
            warn("请选择场景文件解压路径！");
            return;
        }
    }
    if (isAppChecked)
        initTask(appUrl, appPath);
    if (isCfgChecked)
        initTask(cfgUrl, cfgPath);
    if (isSceneChecked)
        initTask(sceneUrl, scenePath);

    //未下载
    if (tasks->isEmpty()) {
        return;
    }

    //禁用下载按钮
    ui->btnDownload->setEnabled(false);
    //开始下载
    startDownload();
}

void MainWindow::startDownload() {

    if (!tasks->isEmpty()) {
        currentTask = tasks->dequeue();
        qDebug() << "开始下载：" << currentTask->downloadUrl;
        showStatus("正在下载 " + currentTask->downloadUrl);
        currentTask->startDownload();
    }
}

void MainWindow::onTaskCanceled() {
    doQuit();
}

void MainWindow::onDownloadFinish() {
    qDebug() << "下载结束：" << currentTask->downloadUrl;
    showStatus("正在解压 " + currentTask->filename + " 到 " + currentTask->decompressPath);
}


void MainWindow::onTaskFinish() {
    qDebug() << "任务结束：" << currentTask->downloadUrl;

    //删除当前任务
//    delete currentTask;
    //开始下一个
    if (!tasks->isEmpty()) {
        startDownload();
    } else {
        onAllTaskFinish();
    }
}

void MainWindow::doQuit() {
    qDebug() << "doQuit()";
    close();
}

void MainWindow::onAllTaskFinish() {
    showStatus("全部下载完成");

    auto msgBox = new QMessageBox;
    msgBox->setText("全部任务下载完成，点击退出！");
    msgBox->exec();

    //提醒 和 退出
    QTimer::singleShot(200, this, SLOT(doQuit()));

}


void MainWindow::on_cbApp_toggled(bool checked) {
    isAppChecked = checked;
    qDebug() << "App " << checked;
}

void MainWindow::on_cbCfg_toggled(bool checked) {
    isCfgChecked = checked;
    qDebug() << "Cfg " << checked;

}

void MainWindow::on_cbScene_toggled(bool checked) {
    isSceneChecked = checked;
    qDebug() << "Scene " << checked;
}

void MainWindow::on_tbAppPath_clicked() {
//    qDebug()<<"AppPath clicked ";

    fileDialog->show();

    if (fileDialog->exec()) {
        appPath = fileDialog->selectedFiles()[0];
        qDebug() << appPath;
        ui->lbAppPath->setText(appPath);
        ui->lbAppPath->setStyleSheet("color: black;");
    }
}

void MainWindow::on_tbCfgPath_clicked() {
//    qDebug()<<"CfgPath clicked ";
    fileDialog->show();

    if (fileDialog->exec()) {
        cfgPath = fileDialog->selectedFiles()[0];
        qDebug() << cfgPath;
        ui->lbCfgPath->setText(cfgPath);
        ui->lbCfgPath->setStyleSheet("color: black;");
    }
}

void MainWindow::on_tbScenePath_clicked() {
    fileDialog->show();

    if (fileDialog->exec()) {
        scenePath = fileDialog->selectedFiles()[0];
        qDebug() << scenePath;
        ui->lbScenePath->setText(scenePath);
        ui->lbScenePath->setStyleSheet("color: black;");
    }
}

void MainWindow::showStatus(QString status) {
    statusBar()->showMessage(status);
}








