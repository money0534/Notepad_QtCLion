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

namespace Ui {
    class MainDialog;
}

/**
 * 下载信息封装
 */
struct EncapUrl {
    QString appUrl;
    QString cfgUrl;
    QString envUrl;
};

class ProgressDialog : public QProgressDialog {
Q_OBJECT

public:
    explicit ProgressDialog(const QUrl &url, QWidget *parent = nullptr);

public slots:
    void networkReplyProgress(qint64 bytesRead, qint64 totalBytes);
};

class MainDialog : public QDialog {
Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = nullptr);

    explicit MainDialog(QPair<QString, QString> taskEntity, QWidget *parent = nullptr);

    ~MainDialog();

private:
    Ui::MainDialog *ui;
    QPair<QString, QString> taskEntity;
    QNetworkAccessManager *manager;
    QNetworkReply* reply;

    void startDownload();
    QString saveFileName(const QUrl &url);
    bool saveToDisk(const QString &filename, QIODevice *data);
    void doQuit();

    void doInstall();


private slots:

    void replyFinished(QNetworkReply *);

    bool isHttpRedirect(QNetworkReply *reply);

    void cancelDownload();
};

#endif // MAINDIALOG_H
