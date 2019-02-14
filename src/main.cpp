
#include <QApplication>
#include <iostream>
#include <QtCore/QCommandLineParser>
#include "maindialog.h"
#include <QDebug>

using namespace std;


int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    QCoreApplication::setApplicationName("MaintenanceTool");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;

    //c++11 支持
    parser.addOptions({
                              // options with a value
                              {{"a","app"}, "Download application from <AppUrl>.","AppUrl"},
                              {{"d","dir"}, "Download application into <AppDir>.","AppDir"},
                      });

    // Process the actual command line arguments given by the user
    parser.process(app);

    //带值的参数
    QString appUrl = parser.value("a");
    QString appPath = parser.value("d");

//    qDebug()<<"appPath is "<<appPath;



    QPair<QString,QString> task(appUrl,appPath);
    MainDialog dialog(task);
    dialog.show();

    return app.exec();
}
