//
// Created by Shinelon on 2019/2/22.
//

#ifndef MAINTENANCETOOL_PROGRESSDIALOG_H
#define MAINTENANCETOOL_PROGRESSDIALOG_H
#include <QDialog>
#include <QProgressDialog>
#include <QtCore/QUrl>


class ProgressDialog : public QProgressDialog {
    Q_OBJECT

public:
    explicit ProgressDialog(const QUrl &url, QWidget *parent = nullptr);

public slots:
    void networkReplyProgress(qint64 bytesRead, qint64 totalBytes);
};


#endif //MAINTENANCETOOL_PROGRESSDIALOG_H
