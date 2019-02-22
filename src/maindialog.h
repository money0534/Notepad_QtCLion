#ifndef MAINDIALOG_H
#define MAINDIALOG_H

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
#include "Task.h"
#include "Logger.h"

namespace Ui {
    class MainDialog;
}

class MainDialog : public QDialog {
Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = nullptr);

    explicit MainDialog(QString& url,QString& path, QWidget *parent = nullptr);

    ~MainDialog();

    void showMsg(QString content);

    //开始下载任务
    void startDownload();


private:
    Ui::MainDialog *ui;
    QString downloadUrl;
    QString decompressPath;

    //声明为nullptr 可安全delete
    QProcess *myProcess = nullptr;
    Task* task= nullptr;
    Logger* logger= nullptr;



private slots:

    void onDownloadFinish();

    void installFinish();

    void doQuit();

};

#endif // MAINDIALOG_H
