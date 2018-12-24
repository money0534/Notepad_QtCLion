/********************************************************************************
** Form generated from reading UI file 'notepad.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPAD_H
#define UI_NOTEPAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Notepad
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *title;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *etAccount;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *etPwd;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnLogin;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Notepad)
    {
        if (Notepad->objectName().isEmpty())
            Notepad->setObjectName(QString::fromUtf8("Notepad"));
        Notepad->resize(400, 600);
        Notepad->setMinimumSize(QSize(400, 600));
        Notepad->setMaximumSize(QSize(400, 600));
        Notepad->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(Notepad);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        title = new QLabel(centralwidget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(30);
        title->setFont(font);
        title->setStyleSheet(QString::fromUtf8("background-color:gray;\n"
"color: rgb(0, 255, 0);\n"
""));
        title->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(title);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_2->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        etAccount = new QLineEdit(centralwidget);
        etAccount->setObjectName(QString::fromUtf8("etAccount"));

        horizontalLayout->addWidget(etAccount);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 8);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        etPwd = new QLineEdit(centralwidget);
        etPwd->setObjectName(QString::fromUtf8("etPwd"));

        horizontalLayout_2->addWidget(etPwd);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 8);

        verticalLayout->addLayout(horizontalLayout_2);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnLogin = new QPushButton(centralwidget);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));

        horizontalLayout_3->addWidget(btnLogin);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btnCancel = new QPushButton(centralwidget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_3->addWidget(btnCancel);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 6);
        horizontalLayout_3->setStretch(2, 2);

        verticalLayout_2->addLayout(horizontalLayout_3);

        Notepad->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Notepad);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 26));
        Notepad->setMenuBar(menubar);
        statusbar = new QStatusBar(Notepad);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Notepad->setStatusBar(statusbar);

        retranslateUi(Notepad);

        QMetaObject::connectSlotsByName(Notepad);
    } // setupUi

    void retranslateUi(QMainWindow *Notepad)
    {
        Notepad->setWindowTitle(QApplication::translate("Notepad", "MainWindow", nullptr));
        title->setText(QApplication::translate("Notepad", "QQ2019", nullptr));
        label->setText(QApplication::translate("Notepad", "\350\264\246\345\217\267\357\274\232", nullptr));
        label_2->setText(QApplication::translate("Notepad", "\345\257\206\347\240\201\357\274\232", nullptr));
        checkBox->setText(QApplication::translate("Notepad", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        btnLogin->setText(QApplication::translate("Notepad", "\347\231\273\351\231\206", nullptr));
        btnCancel->setText(QApplication::translate("Notepad", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Notepad: public Ui_Notepad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPAD_H
