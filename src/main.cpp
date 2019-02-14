
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
                              {{"c","cfg"}, "Download config files from <CfgUrl>.","CfgUrl"},
                              {{"e","env"}, "Download 3D environment files from <EnvUrl>.","EnvUrl"},
                      });

    // Process the actual command line arguments given by the user
    parser.process(app);

    //带值的参数
    QString aValue = parser.value("a");
    QString cValue = parser.value("c");
    QString eValue = parser.value("e");

//    qDebug()<<"AppValue is "<<aValue;
//    qDebug()<<"CfgValue is "<<cValue;
//    qDebug()<<"EnvValue is "<<eValue;

    auto urlEntity = new EncapUrl;
    urlEntity->appUrl = aValue;
    urlEntity->cfgUrl = cValue;
    urlEntity->envUrl = eValue;

    MainDialog dialog(urlEntity);
    dialog.show();

    return app.exec();
}
