/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QAction *actionClear;
    QAction *actionQuit;
    QAction *actionOverSpeed;
    QAction *actionLeftFront;
    QAction *actionMidBack;
    QAction *actionResponseOK;
    QAction *actionDataSource;
    QAction *actionSend;
    QAction *actionStop;
    QAction *actionPause;
    QAction *actionRestart;
    QAction *actionEventEqBrake;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menuBar;
    QMenu *menuCalls;
    QMenu *menuTools;
    QMenu *menuHelp;
    QMenu *menuSimulation;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 800);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../resources/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon1);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon2);
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QString::fromUtf8("actionConfigure"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure->setIcon(icon3);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon4);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon5);
        actionOverSpeed = new QAction(MainWindow);
        actionOverSpeed->setObjectName(QString::fromUtf8("actionOverSpeed"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/overspeed.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOverSpeed->setIcon(icon6);
        actionLeftFront = new QAction(MainWindow);
        actionLeftFront->setObjectName(QString::fromUtf8("actionLeftFront"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/obs_front.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLeftFront->setIcon(icon7);
        actionMidBack = new QAction(MainWindow);
        actionMidBack->setObjectName(QString::fromUtf8("actionMidBack"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/obs_back.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMidBack->setIcon(icon8);
        actionResponseOK = new QAction(MainWindow);
        actionResponseOK->setObjectName(QString::fromUtf8("actionResponseOK"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/respok.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionResponseOK->setIcon(icon9);
        actionDataSource = new QAction(MainWindow);
        actionDataSource->setObjectName(QString::fromUtf8("actionDataSource"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/ds.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDataSource->setIcon(icon10);
        actionSend = new QAction(MainWindow);
        actionSend->setObjectName(QString::fromUtf8("actionSend"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSend->setIcon(icon11);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon12);
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon13);
        actionRestart = new QAction(MainWindow);
        actionRestart->setObjectName(QString::fromUtf8("actionRestart"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/restart.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRestart->setIcon(icon14);
        actionEventEqBrake = new QAction(MainWindow);
        actionEventEqBrake->setObjectName(QString::fromUtf8("actionEventEqBrake"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/brake.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEventEqBrake->setIcon(icon15);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        menuCalls = new QMenu(menuBar);
        menuCalls->setObjectName(QString::fromUtf8("menuCalls"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuSimulation = new QMenu(menuBar);
        menuSimulation->setObjectName(QString::fromUtf8("menuSimulation"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCalls->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuSimulation->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuCalls->addAction(actionConnect);
        menuCalls->addAction(actionDisconnect);
        menuCalls->addSeparator();
        menuCalls->addAction(actionQuit);
        menuTools->addAction(actionConfigure);
        menuTools->addAction(actionClear);
        menuHelp->addAction(actionAbout);
        menuSimulation->addAction(actionEventEqBrake);
        menuSimulation->addAction(actionOverSpeed);
        menuSimulation->addAction(actionLeftFront);
        menuSimulation->addAction(actionMidBack);
        menuSimulation->addSeparator();
        menuSimulation->addAction(actionResponseOK);
        menu->addAction(actionDataSource);
        menu->addAction(actionSend);
        menu->addAction(actionStop);
        menu->addAction(actionPause);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addAction(actionConfigure);
        mainToolBar->addAction(actionClear);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionEventEqBrake);
        mainToolBar->addAction(actionOverSpeed);
        mainToolBar->addAction(actionLeftFront);
        mainToolBar->addAction(actionMidBack);
        mainToolBar->addAction(actionResponseOK);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionDataSource);
        mainToolBar->addAction(actionSend);
        mainToolBar->addAction(actionStop);
        mainToolBar->addAction(actionPause);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\351\230\262\347\242\260\346\222\236\346\250\241\346\213\237\347\273\210\347\253\257", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "About program", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Alt+A", nullptr));
#endif // QT_NO_SHORTCUT
        actionConnect->setText(QApplication::translate("MainWindow", "C&onnect", nullptr));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("MainWindow", "Connect to serial port", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionConnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionDisconnect->setText(QApplication::translate("MainWindow", "&Disconnect", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDisconnect->setToolTip(QApplication::translate("MainWindow", "Disconnect from serial port", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionDisconnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_NO_SHORTCUT
        actionConfigure->setText(QApplication::translate("MainWindow", "&Configure", nullptr));
#ifndef QT_NO_TOOLTIP
        actionConfigure->setToolTip(QApplication::translate("MainWindow", "Configure serial port", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionConfigure->setShortcut(QApplication::translate("MainWindow", "Alt+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionClear->setText(QApplication::translate("MainWindow", "C&lear", nullptr));
#ifndef QT_NO_TOOLTIP
        actionClear->setToolTip(QApplication::translate("MainWindow", "Clear data", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionClear->setShortcut(QApplication::translate("MainWindow", "Alt+L", nullptr));
#endif // QT_NO_SHORTCUT
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionOverSpeed->setText(QApplication::translate("MainWindow", "\346\250\241\346\213\237\350\266\205\351\200\237", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOverSpeed->setToolTip(QApplication::translate("MainWindow", "\346\250\241\346\213\237\350\266\205\351\200\237", nullptr));
#endif // QT_NO_TOOLTIP
        actionLeftFront->setText(QApplication::translate("MainWindow", "\346\250\241\346\213\237\345\267\246\345\211\215\346\226\271\351\232\234\347\242\215\347\211\251", nullptr));
#ifndef QT_NO_TOOLTIP
        actionLeftFront->setToolTip(QApplication::translate("MainWindow", "\346\250\241\346\213\237\345\267\246\345\211\215\346\226\271\351\232\234\347\242\215\347\211\251", nullptr));
#endif // QT_NO_TOOLTIP
        actionMidBack->setText(QApplication::translate("MainWindow", "\346\250\241\346\213\237\346\255\243\345\220\216\346\226\271\351\232\234\347\242\215\347\211\251", nullptr));
#ifndef QT_NO_TOOLTIP
        actionMidBack->setToolTip(QApplication::translate("MainWindow", "\346\250\241\346\213\237\345\267\246\345\211\215\346\226\271\351\232\234\347\242\215\347\211\251", nullptr));
#endif // QT_NO_TOOLTIP
        actionResponseOK->setText(QApplication::translate("MainWindow", "\345\223\215\345\272\224OK", nullptr));
#ifndef QT_NO_TOOLTIP
        actionResponseOK->setToolTip(QApplication::translate("MainWindow", "\345\223\215\345\272\224OK", nullptr));
#endif // QT_NO_TOOLTIP
        actionDataSource->setText(QApplication::translate("MainWindow", "DataSource", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDataSource->setToolTip(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\225\260\346\215\256\346\272\220", nullptr));
#endif // QT_NO_TOOLTIP
        actionSend->setText(QApplication::translate("MainWindow", "Send", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSend->setToolTip(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\217\221\351\200\201", nullptr));
#endif // QT_NO_TOOLTIP
        actionStop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
#ifndef QT_NO_TOOLTIP
        actionStop->setToolTip(QApplication::translate("MainWindow", "\345\201\234\346\255\242\345\217\221\351\200\201", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionStop->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionPause->setText(QApplication::translate("MainWindow", "Pause", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPause->setToolTip(QApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
#endif // QT_NO_TOOLTIP
        actionRestart->setText(QApplication::translate("MainWindow", "Restart", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRestart->setToolTip(QApplication::translate("MainWindow", "\351\207\215\346\226\260\345\217\221\351\200\201", nullptr));
#endif // QT_NO_TOOLTIP
        actionEventEqBrake->setText(QApplication::translate("MainWindow", "EventEqBrake", nullptr));
#ifndef QT_NO_TOOLTIP
        actionEventEqBrake->setToolTip(QApplication::translate("MainWindow", "\346\250\241\346\213\237\346\227\247\347\211\210\345\210\271\350\275\246$EVENT=BRAKE", nullptr));
#endif // QT_NO_TOOLTIP
        menuCalls->setTitle(QApplication::translate("MainWindow", "Calls", nullptr));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        menuSimulation->setTitle(QApplication::translate("MainWindow", "\345\212\250\344\275\234", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\344\273\277\347\234\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H