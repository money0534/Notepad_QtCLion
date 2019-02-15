
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
    delete manager;
}

MainDialog::MainDialog(QPair<QString, QString> taskEntity, QWidget *parent) :
        QDialog(parent),
        ui(new Ui::MainDialog), manager(new QNetworkAccessManager(this)) {
    ui->setupUi(this);
    this->taskEntity = taskEntity;

    qDebug() << taskEntity.first << "," << taskEntity.second;


//    connect(manager, &QNetworkAccessManager::finished, this, &MainDialog::replyFinished);
//    startDownload();

    doInstall();
}

void MainDialog::startDownload() {
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
            QString filename = saveFileName(url);
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

    QString dir = "D:\\" + basename;

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


void MainDialog::doInstall() {
    qDebug()<<"开始安装...";

//    doQuit();
}

void MainDialog::doQuit() {
    QCoreApplication::instance()->quit();
}
