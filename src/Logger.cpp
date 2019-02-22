//
// Created by Shinelon on 2019/2/22.
//

#include "Logger.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Logger::Logger(const QString &format) : format(format) {

}

void Logger::write(QString line) {
//    QDateTime date(QDate::currentDate());
    QString timestamp = QDateTime::currentDateTime().toString(format);
    qDebug()<<timestamp<<" "<<line;

    QDir dir("log");
    if(!dir.exists()){
        bool ret = dir.mkpath("log");
        qDebug()<<"创建路径："<<"log"<<" "<<ret;
    }
    QFile file("log/update.log");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;


    QTextStream out(&file);
    out<<timestamp << " " <<line << "\n";
    file.close();
}

Logger::~Logger() {

}
