//
// Created by Shinelon on 2019/2/22.
//

#include "Task.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Task::~Task() {
    qDebug()<<"~Task()";
    delete reply;
    delete manager;
    delete thread;
}

Task::Task(QString url,QString path,QObject*parent) :
        QObject(parent),
         manager(new QNetworkAccessManager(this)), downloadUrl(url),
        decompressPath(path) {


    qDebug() << downloadUrl << "," << decompressPath;

}

void Task::startDownload() {

    connect(manager, &QNetworkAccessManager::finished, this, &Task::replyFinished);

    QUrl url(downloadUrl);
    reply = manager->get(QNetworkRequest(url));
    ProgressDialog *progressDialog = new ProgressDialog(url, nullptr);
    progressDialog->setAttribute(Qt::WA_DeleteOnClose);
    connect(progressDialog, &QProgressDialog::canceled, this, &Task::cancelDownload);
    connect(reply, &QNetworkReply::downloadProgress, progressDialog,
            &ProgressDialog::networkReplyProgress);
    connect(reply, &QNetworkReply::finished, progressDialog, &ProgressDialog::hide);
    progressDialog->show();
}

void Task::doDecompress() {

    qDebug() << "开始解压："<<filename;

    thread = new WorkerThread(this,filename,decompressPath);
    connect(thread, &WorkerThread::resultReady, this, &Task::decompressFinish);

    thread->start();

}

void Task::replyFinished(QNetworkReply *reply) {
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

            doDecompress();
        }
    }

    reply->deleteLater();

}

bool Task::isHttpRedirect(QNetworkReply *reply) {
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    return statusCode == 301 || statusCode == 302 || statusCode == 303
           || statusCode == 305 || statusCode == 307 || statusCode == 308;
}

QString Task::saveFileName(const QUrl &url) {
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

bool Task::saveToDisk(const QString &filename, QIODevice *data) {
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

void Task::cancelDownload() {
    qDebug() << "取消下载！";
    reply->abort();
    reply->deleteLater();
}

void Task::decompressFinish() {
    qDebug()<<"解压完成："<<decompressPath;
    emit taskFinish();

}
