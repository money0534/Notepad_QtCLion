#include <QtCore/QUrl>
#include <QtWidgets/QMessageBox>
#include <QtCore/QDir>
#include "maindialog.h"
#include "ui_maindialog.h"

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;
    delete urlEntity;
}

MainDialog::MainDialog(EncapUrl* urlEntity, QWidget *parent) :
        QDialog(parent),
        ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    this->urlEntity = urlEntity;

    qDebug()<<urlEntity->appUrl;


}

void MainDialog::downloadFile(QString urlSpec)
{
    if (urlSpec.isEmpty())
        return;

    const QUrl newUrl = QUrl::fromUserInput(urlSpec);
    if (!newUrl.isValid()) {
        QMessageBox::information(this, tr("Error"),
                                 tr("Invalid URL: %1: %2").arg(urlSpec, newUrl.errorString()));
        return;
    }

    QString fileName = newUrl.fileName();
//    if (fileName.isEmpty())
//        fileName = defaultFileLineEdit->text().trimmed();
//    if (fileName.isEmpty())
//        fileName = defaultFileName;

//    QString downloadDirectory = QDir::cleanPath(downloadDirectoryLineEdit->text().trimmed());
//    bool useDirectory = !downloadDirectory.isEmpty() && QFileInfo(downloadDirectory).isDir();
//    if (useDirectory)
//        fileName.prepend(downloadDirectory + '/');
//    if (QFile::exists(fileName)) {
//        if (QMessageBox::question(this, tr("Overwrite Existing File"),
//                                  tr("There already exists a file called %1%2."
//                                     " Overwrite?")
//                                          .arg(fileName,
//                                               useDirectory
//                                               ? QString()
//                                               : QStringLiteral(" in the current directory")),
//                                  QMessageBox::Yes | QMessageBox::No,
//                                  QMessageBox::No)
//            == QMessageBox::No) {
//            return;
//        }
//        QFile::remove(fileName);
//    }
//
//    file = openFileForWrite(fileName);
//    if (!file)
//        return;
//
//    downloadButton->setEnabled(false);
//
//    // schedule the request
//    startRequest(newUrl);
}
