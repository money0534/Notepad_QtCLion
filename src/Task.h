//
// Created by Shinelon on 2019/2/22.
//

#ifndef MAINTENANCETOOL_TASK_H
#define MAINTENANCETOOL_TASK_H

#include <QDialog>
#include <QDebug>
#include <QFile>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtCore/QUrl>
#include <QtWidgets/QMessageBox>
#include <QtCore/QDir>
#include <QProgressDialog>
#include <QProcess>
#include <QTimer>
#include "thread.h"
#include "ProgressDialog.h"

class Task : public QObject{

    Q_OBJECT

public:

    explicit Task(QString &url,QString &path,QObject *parent = nullptr);

    ~Task();

    //开始下载
    void startDownload();

    //解压
    void doDecompress(QNetworkReply *reply);

    signals:
    //一个任务结束，下载和解压
    void taskFinish();

    //下载结束
    void downloadFinish();


public:
    QString filename;
    QString downloadUrl;
    QString decompressPath;

private:
    //声明为nullptr 可安全delete
    QNetworkAccessManager *manager = nullptr;
    QNetworkReply* reply = nullptr;
    WorkerThread* thread = nullptr;

    QString saveFileName(const QUrl &url);

    bool saveToDisk(const QString &filename, QIODevice *data);


private slots:
    void replyFinished(QNetworkReply *);

    bool isHttpRedirect(QNetworkReply *reply);

    //下载取消
    void cancelDownload();

    //解压完成
    void decompressFinish();

};


#endif //MAINTENANCETOOL_TASK_H
