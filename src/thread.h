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
    WorkerThread(QObject *parent, const QString &zipPath, const QString &decpPath,QIODevice *d) : QThread(
            parent), zipPath(zipPath), decpPath(decpPath),data(d) {}

    Q_OBJECT
    void run() override {
        /* ... here is the expensive or blocking operation ... */

        if(saveToDisk()){
            JlCompress::extractDir(zipPath,decpPath);
            emit resultReady();
        }

    }

    bool saveToDisk(){
        QFile file(zipPath);
        if (!file.open(QIODevice::WriteOnly)) {
            fprintf(stderr, "Could not open %s for writing: %s\n",
                    qPrintable(zipPath),
                    qPrintable(file.errorString()));
            return false;
        }

        file.write(data->readAll());
        file.close();
        return true;
    }

    QString zipPath;
    QString decpPath;
    QIODevice *data;
    signals:
            void resultReady();
};
#endif //MAINTENANCETOOL_THREAD_H
