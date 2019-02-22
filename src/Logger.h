//
// Created by Shinelon on 2019/2/22.
//

#ifndef MAINTENANCETOOL_LOGGER_H
#define MAINTENANCETOOL_LOGGER_H

#include <QString>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QDir>

/**
 * Description: 操作日志记录
 *
 * @author liuzongze
 * Created on 2019/2/22 10:27
 */
class Logger {

public:
    void write(QString line);

    virtual ~Logger();

    QString format;

    Logger(const QString &format);
};


#endif //MAINTENANCETOOL_LOGGER_H
