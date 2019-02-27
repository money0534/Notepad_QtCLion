//
// Created by Shinelon on 2019/2/15.
//

#include <QThread>
#include <libzip/JlCompress.h>


#ifndef MAINTENANCETOOL_THREAD_H
#define MAINTENANCETOOL_THREAD_H
class WorkerThread : public QThread
{

public:
    ~WorkerThread(){

    }

    WorkerThread(QObject *parent, const QString &zipPath, const QString &decpPath,QIODevice *d) : QThread(
            parent), zipPath(zipPath), decpPath(decpPath),data(d) {}

    Q_OBJECT
    void run() override {
        /* ... here is the expensive or blocking operation ... */

        if(saveToDisk()){
            QDir dir(decpPath);

#if 0   //检查清空目录
            //清除目录
            if(dir.removeRecursively()){
                qDebug()<<"清除成功："<<decpPath;
            } else{
                qDebug()<<"清除失败："<<decpPath;
            }
#endif
            if(!dir.exists()){
                qDebug()<<"创建目录："<<decpPath;
                dir.mkpath(decpPath);
            }
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
        //需放在此处 销毁对象
        data->deleteLater();

        return true;
    }

    QString zipPath;
    QString decpPath;
    QIODevice *data;
    signals:
            void resultReady();
};
#endif //MAINTENANCETOOL_THREAD_H
