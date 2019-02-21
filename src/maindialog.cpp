
#include "maindialog.h"
#include "ui_maindialog.h"

ProgressDialog::ProgressDialog(const QUrl &url, QWidget *parent)
        : QProgressDialog(parent) {
    setWindowTitle(tr("Download Progress"));
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setLabelText(tr("Downloading %1.").arg(url.toDisplayString()));
    setMinimum(0);
    setValue(0);
    setMinimumDuration(0);
    setMinimumSize(QSize(400, 75));
}

void ProgressDialog::networkReplyProgress(qint64 bytesRead, qint64 totalBytes) {
    setMaximum(totalBytes);
    setValue(bytesRead);
}

MainDialog::MainDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::MainDialog) {
    ui->setupUi(this);
}

MainDialog::~MainDialog() {
    delete ui;
    delete reply;
    delete manager;
    delete myProcess;
    delete thread;
}

MainDialog::MainDialog(QPair<QString, QString> taskEntity, QWidget *parent) :
        QDialog(parent),
        ui(new Ui::MainDialog), manager(new QNetworkAccessManager(this)) {
    ui->setupUi(this);
    this->taskEntity = taskEntity;

    qDebug() << taskEntity.first << "," << taskEntity.second;

}

void MainDialog::startDownload() {
    showMsg("新版本下载中...");

    connect(manager, &QNetworkAccessManager::finished, this, &MainDialog::replyFinished);

    QUrl url(taskEntity.first);
    reply = manager->get(QNetworkRequest(url));
    ProgressDialog *progressDialog = new ProgressDialog(url, this);
    progressDialog->setAttribute(Qt::WA_DeleteOnClose);
    connect(progressDialog, &QProgressDialog::canceled, this, &MainDialog::cancelDownload);
    connect(reply, &QNetworkReply::downloadProgress, progressDialog,
            &ProgressDialog::networkReplyProgress);
    connect(reply, &QNetworkReply::finished, progressDialog, &ProgressDialog::hide);
    progressDialog->show();
}


void MainDialog::replyFinished(QNetworkReply *reply) {
    QUrl url = reply->url();
    if (reply->error()) {
        fprintf(stderr, "Download of %s failed: %s\n",
                url.toEncoded().constData(),
                qPrintable(reply->errorString()));
    } else {
        if (isHttpRedirect(reply)) {
            fputs("Request was redirected.\n", stderr);
        } else {
            filename = saveFileName(url);
            if (saveToDisk(filename, reply)) {
                printf("Download of %s succeeded (saved to %s)\n",
                       url.toEncoded().constData(), qPrintable(filename));
            }

            doInstall();
        }
    }

    reply->deleteLater();

}


bool MainDialog::isHttpRedirect(QNetworkReply *reply) {
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    return statusCode == 301 || statusCode == 302 || statusCode == 303
           || statusCode == 305 || statusCode == 307 || statusCode == 308;
}


QString MainDialog::saveFileName(const QUrl &url) {
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

    //从软件启动升级工具，当前路径为软件所在路径，需要跳到上一级
    //下载到当前所在路径上一级下的/HahaDownload/下
    QString dir = "../HahaDownload" ;

    QDir dlDir(dir);
    if(!dlDir.exists()){
        bool ret = dlDir.mkpath(dir);
        qDebug()<<"创建路径："<<dir<<" "<<ret;
    }

    dir+="/";
    dir+= basename;
    return dir;
}


bool MainDialog::saveToDisk(const QString &filename, QIODevice *data) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        fprintf(stderr, "Could not open %s for writing: %s\n",
                qPrintable(filename),
                qPrintable(file.errorString()));
        return false;
    }

    file.write(data->readAll());
    file.close();

    return true;
}

void MainDialog::cancelDownload() {
    qDebug() << "取消下载！";
    reply->abort();
    reply->deleteLater();
    doQuit();
}


void MainDialog::installFinish(){
    qDebug() << "解压完成！";
    showMsg("更新完成，即将启动");

    //启动Unity，如：D:/Unity/Projects/HahaRobot
    QString input = taskEntity.second;

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


//void MainDialog::installFinish(){
//    qDebug() << "解压完成！";
//    showMsg("更新完成，即将启动");
//
//    //启动Unity
//    QStringList array = taskEntity.second.split("/");
//
//    QString program = taskEntity.second+"/"+array[array.length()-1]+".exe";
//    qDebug()<<"启动程序："<<program;
//
//
//    QStringList arguments;
//    myProcess = new QProcess(QCoreApplication::instance());
//    myProcess->start(program, arguments);
//
//    //最后延时退出
//    QTimer::singleShot(500, this, SLOT(doQuit()));
//}

void MainDialog::doInstall() {

//    filename = "D:/哈哈智能驾校.zip";
    showMsg("安装中，请稍后...");
    qDebug() << "开始解压："<<filename;

    thread = new WorkerThread(this,filename,taskEntity.second);
    connect(thread, &WorkerThread::resultReady, this, &MainDialog::installFinish);


//    JlCompress::extractDir("D:\\哈哈.zip","D:\\111");//compressDir
    thread->start();

}

void MainDialog::doQuit() {
    this->close();
    QCoreApplication::instance()->quit();
    qDebug()<<"doQuit()";
}

void MainDialog::showMsg(QString content) {
    ui->lbStatus->setText(content);
}
