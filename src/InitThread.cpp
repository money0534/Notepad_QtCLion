//
// Created by Shinelon on 2019/1/2.
//

#include "InitThread.h"
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QtCore/QFile>

InitThread::InitThread(QObject *parent, const QString &dataSource, QList<QByteArray> *lines)
        : QThread(parent), dataSource(dataSource), lines(lines) {}

void InitThread::run() {
    /* ... here is the expensive or blocking operation ... */
    QFile file(dataSource);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//        int ret = QMessageBox::critical(this, "错误", "打开文件失败", "确定");
        qDebug()<<"打开文件失败!";
        return;
    }

    qDebug()<<"开始读取";

    //情况之前
    lines->clear();

    //读取到集合
    while (!file.atEnd()){
        QByteArray line = file.readLine();
        lines->append(line);
        qDebug()<<line;
    }

    qDebug()<<"Total Lines:"<<lines->length();
    file.close();

    emit initFinished();
}
