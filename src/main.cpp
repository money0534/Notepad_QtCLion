
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include "mainwindow.h"


int main(int argc, char *argv[]) {


    //创建QApplication对象
    QApplication app(argc, argv);

    MainWindow w;
    w.show();

    return app.exec();
}
