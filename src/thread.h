//
// Created by Shinelon on 2019/2/15.
//

#include <QThread>
#include <lib/JlCompress.h>


#ifndef MAINTENANCETOOL_THREAD_H
#define MAINTENANCETOOL_THREAD_H
class WorkerThread : public QThread
{

public:
    WorkerThread(QObject *parent, const QString &zipPath, const QString &decpPath) : QThread(
            parent), zipPath(zipPath), decpPath(decpPath) {}

    Q_OBJECT
    void run() override {
        QString result;
        /* ... here is the expensive or blocking operation ... */

        JlCompress::extractDir(zipPath,decpPath);

        emit resultReady();
    }

    QString zipPath;
    QString decpPath;
    signals:
            void resultReady();
};
#endif //MAINTENANCETOOL_THREAD_H
