/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLCDNumber *lcdNumber;
    QGridLayout *gridLayout;
    QPushButton *btn8;
    QPushButton *btn2;
    QPushButton *btnPlus;
    QPushButton *btn9;
    QPushButton *btn3;
    QPushButton *btn1;
    QPushButton *btn0;
    QPushButton *btnEq;
    QPushButton *btnDivide;
    QPushButton *btn5;
    QPushButton *btn7;
    QPushButton *btnClear;
    QPushButton *btn4;
    QPushButton *btn6;
    QPushButton *btnMinus;
    QPushButton *btnMulti;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QString::fromUtf8("Calculator"));
        Calculator->resize(417, 600);
        Calculator->setMinimumSize(QSize(417, 600));
        Calculator->setMaximumSize(QSize(417, 600));
        centralwidget = new QWidget(Calculator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setStyleSheet(QString::fromUtf8("background-color: rgb(174, 182, 255);"));
        lcdNumber->setSmallDecimalPoint(true);
        lcdNumber->setDigitCount(9);
        lcdNumber->setMode(QLCDNumber::Dec);
        lcdNumber->setProperty("intValue", QVariant(0));

        verticalLayout->addWidget(lcdNumber);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        btn8 = new QPushButton(centralwidget);
        btn8->setObjectName(QString::fromUtf8("btn8"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn8->sizePolicy().hasHeightForWidth());
        btn8->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(18);
        btn8->setFont(font);

        gridLayout->addWidget(btn8, 2, 1, 1, 2);

        btn2 = new QPushButton(centralwidget);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        sizePolicy.setHeightForWidth(btn2->sizePolicy().hasHeightForWidth());
        btn2->setSizePolicy(sizePolicy);
        btn2->setFont(font);

        gridLayout->addWidget(btn2, 0, 1, 1, 2);

        btnPlus = new QPushButton(centralwidget);
        btnPlus->setObjectName(QString::fromUtf8("btnPlus"));
        sizePolicy.setHeightForWidth(btnPlus->sizePolicy().hasHeightForWidth());
        btnPlus->setSizePolicy(sizePolicy);
        btnPlus->setFont(font);

        gridLayout->addWidget(btnPlus, 0, 4, 1, 1);

        btn9 = new QPushButton(centralwidget);
        btn9->setObjectName(QString::fromUtf8("btn9"));
        sizePolicy.setHeightForWidth(btn9->sizePolicy().hasHeightForWidth());
        btn9->setSizePolicy(sizePolicy);
        btn9->setFont(font);

        gridLayout->addWidget(btn9, 2, 3, 1, 1);

        btn3 = new QPushButton(centralwidget);
        btn3->setObjectName(QString::fromUtf8("btn3"));
        sizePolicy.setHeightForWidth(btn3->sizePolicy().hasHeightForWidth());
        btn3->setSizePolicy(sizePolicy);
        btn3->setFont(font);

        gridLayout->addWidget(btn3, 0, 3, 1, 1);

        btn1 = new QPushButton(centralwidget);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        sizePolicy.setHeightForWidth(btn1->sizePolicy().hasHeightForWidth());
        btn1->setSizePolicy(sizePolicy);
        btn1->setFont(font);

        gridLayout->addWidget(btn1, 0, 0, 1, 1);

        btn0 = new QPushButton(centralwidget);
        btn0->setObjectName(QString::fromUtf8("btn0"));
        sizePolicy.setHeightForWidth(btn0->sizePolicy().hasHeightForWidth());
        btn0->setSizePolicy(sizePolicy);
        btn0->setFont(font);

        gridLayout->addWidget(btn0, 3, 1, 1, 2);

        btnEq = new QPushButton(centralwidget);
        btnEq->setObjectName(QString::fromUtf8("btnEq"));
        sizePolicy.setHeightForWidth(btnEq->sizePolicy().hasHeightForWidth());
        btnEq->setSizePolicy(sizePolicy);
        btnEq->setFont(font);

        gridLayout->addWidget(btnEq, 3, 3, 1, 1);

        btnDivide = new QPushButton(centralwidget);
        btnDivide->setObjectName(QString::fromUtf8("btnDivide"));
        sizePolicy.setHeightForWidth(btnDivide->sizePolicy().hasHeightForWidth());
        btnDivide->setSizePolicy(sizePolicy);
        btnDivide->setFont(font);

        gridLayout->addWidget(btnDivide, 3, 4, 1, 1);

        btn5 = new QPushButton(centralwidget);
        btn5->setObjectName(QString::fromUtf8("btn5"));
        sizePolicy.setHeightForWidth(btn5->sizePolicy().hasHeightForWidth());
        btn5->setSizePolicy(sizePolicy);
        btn5->setFont(font);

        gridLayout->addWidget(btn5, 1, 1, 1, 2);

        btn7 = new QPushButton(centralwidget);
        btn7->setObjectName(QString::fromUtf8("btn7"));
        sizePolicy.setHeightForWidth(btn7->sizePolicy().hasHeightForWidth());
        btn7->setSizePolicy(sizePolicy);
        btn7->setFont(font);

        gridLayout->addWidget(btn7, 2, 0, 1, 1);

        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        sizePolicy.setHeightForWidth(btnClear->sizePolicy().hasHeightForWidth());
        btnClear->setSizePolicy(sizePolicy);
        btnClear->setFont(font);

        gridLayout->addWidget(btnClear, 3, 0, 1, 1);

        btn4 = new QPushButton(centralwidget);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        sizePolicy.setHeightForWidth(btn4->sizePolicy().hasHeightForWidth());
        btn4->setSizePolicy(sizePolicy);
        btn4->setFont(font);

        gridLayout->addWidget(btn4, 1, 0, 1, 1);

        btn6 = new QPushButton(centralwidget);
        btn6->setObjectName(QString::fromUtf8("btn6"));
        sizePolicy.setHeightForWidth(btn6->sizePolicy().hasHeightForWidth());
        btn6->setSizePolicy(sizePolicy);
        btn6->setFont(font);

        gridLayout->addWidget(btn6, 1, 3, 1, 1);

        btnMinus = new QPushButton(centralwidget);
        btnMinus->setObjectName(QString::fromUtf8("btnMinus"));
        sizePolicy.setHeightForWidth(btnMinus->sizePolicy().hasHeightForWidth());
        btnMinus->setSizePolicy(sizePolicy);
        btnMinus->setFont(font);

        gridLayout->addWidget(btnMinus, 1, 4, 1, 1);

        btnMulti = new QPushButton(centralwidget);
        btnMulti->setObjectName(QString::fromUtf8("btnMulti"));
        sizePolicy.setHeightForWidth(btnMulti->sizePolicy().hasHeightForWidth());
        btnMulti->setSizePolicy(sizePolicy);
        btnMulti->setFont(font);

        gridLayout->addWidget(btnMulti, 2, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 8);
        Calculator->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Calculator);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 417, 26));
        Calculator->setMenuBar(menubar);
        statusbar = new QStatusBar(Calculator);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Calculator->setStatusBar(statusbar);

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QApplication::translate("Calculator", "\350\256\241\347\256\227\345\231\250", nullptr));
        btn8->setText(QApplication::translate("Calculator", "8", nullptr));
        btn2->setText(QApplication::translate("Calculator", "2", nullptr));
        btnPlus->setText(QApplication::translate("Calculator", "+", nullptr));
        btn9->setText(QApplication::translate("Calculator", "9", nullptr));
        btn3->setText(QApplication::translate("Calculator", "3", nullptr));
        btn1->setText(QApplication::translate("Calculator", "1", nullptr));
        btn0->setText(QApplication::translate("Calculator", "0", nullptr));
        btnEq->setText(QApplication::translate("Calculator", "=", nullptr));
        btnDivide->setText(QApplication::translate("Calculator", "/", nullptr));
        btn5->setText(QApplication::translate("Calculator", "5", nullptr));
        btn7->setText(QApplication::translate("Calculator", "7", nullptr));
        btnClear->setText(QApplication::translate("Calculator", "c", nullptr));
        btn4->setText(QApplication::translate("Calculator", "4", nullptr));
        btn6->setText(QApplication::translate("Calculator", "6", nullptr));
        btnMinus->setText(QApplication::translate("Calculator", "-", nullptr));
        btnMulti->setText(QApplication::translate("Calculator", "*", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
