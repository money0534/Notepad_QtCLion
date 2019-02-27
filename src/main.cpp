
#include <QApplication>
#include <iostream>
#include <QtCore/QCommandLineParser>
#include "maindialog.h"
#include "mainwindow.h"
#include "PlayAudio.h"
#include <QDebug>

using namespace std;


/**
 * MaintenanceTool.exe -a http://hhzn.img.exueche.com/robotcoach/哈哈智能驾校.zip -d D:/Unity/Projects/哈哈智能驾校
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    //打包发布增加库路径
    //参见 https://stackoverflow.com/questions/21268558/application-failed-to-start-because-it-could-not-find-or-load-the-qt-platform-pl/22982039
    QApplication::addLibraryPath("./");
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



    //{}结束后MainWindow生命周期结束，这里通过new在堆上申请内存
    if(appUrl.isEmpty()||appPath.isEmpty()){
//        dialog.showMsg("无更新内容");
        //启动手动下载程序
        MainWindow * window = new MainWindow;
        window->show();
//        qDebug()<<"启动手动下载";
    } else{
        //启动更新程序
        MainDialog * dialog = new MainDialog(appUrl,appPath);
        dialog->show();
        dialog->startDownload();
    }


    play_audio();
    return app.exec();
}
