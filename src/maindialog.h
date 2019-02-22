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

namespace Ui {
    class MainDialog;
}

class MainDialog : public QDialog {
Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = nullptr);

    explicit MainDialog(QPair<QString, QString> taskEntity, QWidget *parent = nullptr);

    ~MainDialog();

    void startDownload();

    void doInstall();

    void showMsg(QString content);


private:
    QString filename;
    QPair<QString, QString> taskEntity;
    Ui::MainDialog *ui;
    //声明为nullptr 可安全delete
    QNetworkAccessManager *manager = nullptr;
    QNetworkReply* reply = nullptr;
    QProcess *myProcess = nullptr;
    WorkerThread* thread = nullptr;

    QString saveFileName(const QUrl &url);
    bool saveToDisk(const QString &filename, QIODevice *data);


private slots:

    void replyFinished(QNetworkReply *);

    bool isHttpRedirect(QNetworkReply *reply);

    void cancelDownload();

    void installFinish();

    void doQuit();

};

#endif // MAINDIALOG_H
