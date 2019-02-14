
#include "maindialog.h"
#include "ui_maindialog.h"

MainDialog::MainDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::MainDialog) {
    ui->setupUi(this);
}

MainDialog::~MainDialog() {
    delete ui;
    delete manager;
}

MainDialog::MainDialog(QPair<QString, QString> taskEntity, QWidget *parent) :
        QDialog(parent),
        ui(new Ui::MainDialog), manager(new QNetworkAccessManager(this)) {
    ui->setupUi(this);
    this->taskEntity = taskEntity;

    qDebug() << taskEntity.first << "," << taskEntity.second;


    connect(manager, &QNetworkAccessManager::finished, this, &MainDialog::replyFinished);
    startDownload();
}

void MainDialog::startDownload() {
    manager->get(QNetworkRequest(QUrl(taskEntity.first)));
}

//void MainDialog::replyFinished(QNetworkReply* reply) {
//    if (reply->error() == QNetworkReply::NoError)
//    {
//        qDebug()<<reply->readAll ();
//    }
//    else
//    {
//        qDebug()<<reply->errorString();
//    }
//}

void MainDialog::replyFinished(QNetworkReply *reply)
{
    QUrl url = reply->url();
    if (reply->error()) {
        fprintf(stderr, "Download of %s failed: %s\n",
                url.toEncoded().constData(),
                qPrintable(reply->errorString()));
    } else {
        if (isHttpRedirect(reply)) {
            fputs("Request was redirected.\n", stderr);
        } else {
            QString filename = saveFileName(url);
            if (saveToDisk(filename, reply)) {
                printf("Download of %s succeeded (saved to %s)\n",
                       url.toEncoded().constData(), qPrintable(filename));
            }
        }
    }

    reply->deleteLater();

}


bool MainDialog::isHttpRedirect(QNetworkReply *reply)
{
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    return statusCode == 301 || statusCode == 302 || statusCode == 303
           || statusCode == 305 || statusCode == 307 || statusCode == 308;
}


QString MainDialog::saveFileName(const QUrl &url)
{
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

//    if (basename.isEmpty())
//        basename = "download";
//
//    if (QFile::exists(basename)) {
//        // already exists, don't overwrite
//        int i = 0;
//        basename += '.';
//        while (QFile::exists(basename + QString::number(i)))
//            ++i;
//
//        basename += QString::number(i);
//    }

    QString dir = "D:\\"+basename;

    return dir;
}


bool MainDialog::saveToDisk(const QString &filename, QIODevice *data)
{
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