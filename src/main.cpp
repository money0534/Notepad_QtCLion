/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the documentation of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QApplication>
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>

#include <QPushButton>
#include <QWidget>
#include <iostream>
#include "notepad.h"
#include "calculator.h"
#include "employee/mainpage.h"
#include "MyEventWidget.h"
#include <windows.h>
#include <QtWidgets/QLabel>


/**
 * 命令行分析器
 * 以-p -f -t tvalue new haha运行该程序
 * Edit Configurations | Program arguments : -p -f -t tvalue new haha
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("my-copy-program");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;

    parser.setApplicationDescription("Test helper");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("source", QCoreApplication::translate("main", "Source file to copy."));
    parser.addPositionalArgument("destination", QCoreApplication::translate("main", "Destination directory."));

    //c++11 支持
    parser.addOptions({
                              // A boolean option with a single name (-p)
                              {"p",
                                      QCoreApplication::translate("main",
                                                                  "Show progress during copy")},
                              // A boolean option with multiple names (-f, --force)
                              {{"f", "force"},
                                      QCoreApplication::translate("main",
                                                                  "Overwrite existing files.")},
                              // An option with a value
                              {{"t", "target-directory"},
                                      QCoreApplication::translate("main",
                                                                  "Copy all source files into <directory>."),
                                      QCoreApplication::translate("main", "directory")},
                      });

    //标准方式 c++11代替之
#if 0
// A boolean option with a single name (-p)
    QCommandLineOption showProgressOption("p", QCoreApplication::translate("main", "Show progress during copy"));
    parser.addOption(showProgressOption);

    // A boolean option with multiple names (-f, --force)
    QCommandLineOption forceOption(QStringList() << "f" << "force",
                                   QCoreApplication::translate("main", "Overwrite existing files."));
    parser.addOption(forceOption);

    // An option with a value
    QCommandLineOption targetDirectoryOption(QStringList() << "t" << "target-directory",
                                             QCoreApplication::translate("main", "Copy all source files into <directory>."),
                                             QCoreApplication::translate("main", "directory"));
    parser.addOption(targetDirectoryOption);
#endif

    // Process the actual command line arguments given by the user
    parser.process(app);

    //无名参数
    const QStringList args = parser.positionalArguments();
    qDebug()<<args;

    //带值的-t参数
    QString tValue = parser.value("t");
    qDebug()<<"tValue is "<<tValue;

    bool pSet = parser.isSet("p");
    bool fSet = parser.isSet("f");
    qDebug()<<"pSet="<<pSet<<",fSet="<<fSet;


    return EXIT_SUCCESS;
}

int main2(int argc, char *argv[]) {

    //dos窗口还是会一闪而过
//    FreeConsole();

    //创建QApplication对象
    QApplication app(argc, argv);

    //使用 preprocessor
#if 0
    //计算器程序
    Calculator notepad;

#elif 1
    //资源引用
    QLabel notepad;
    notepad.resize(400, 300);
    //:表示资源引用方式；路径引用直接引用.qrc中的路径
    notepad.setPixmap(QPixmap(":/images/pencil.png"));

#elif 1
    //自定义组件 重载消息函数
    MyEventWidget notepad;
#elif 1
    //记事本
    Notepad notepad;

#elif 0
    //员工管理
    MainPage notepad;

#endif
    notepad.show();

//    QWidget w;
//    w.setWindowTitle("HelloWorld");
//
//    QPushButton btn;
//    btn.setText("Close");
//    btn.setParent(&w);
//
//    QObject::connect(&btn,SIGNAL(clicked()),&w,SLOT(close()));
//
//
//    w.show();

    //enter main event loop
    //http://doc.qt.io/qt-5/qapplication.html#exec
    return app.exec();
}
