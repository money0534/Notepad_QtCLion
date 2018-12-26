/********************************************************************************
** Form generated from reading UI file 'queryemp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYEMP_H
#define UI_QUERYEMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QueryEmp
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QComboBox *cbbType;
    QLineEdit *leKey;
    QPushButton *btnQuery;
    QTableView *tableView;

    void setupUi(QDialog *QueryEmp)
    {
        if (QueryEmp->objectName().isEmpty())
            QueryEmp->setObjectName(QString::fromUtf8("QueryEmp"));
        QueryEmp->resize(800, 500);
        verticalLayout = new QVBoxLayout(QueryEmp);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(QueryEmp);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(28);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cbbType = new QComboBox(QueryEmp);
        cbbType->setObjectName(QString::fromUtf8("cbbType"));

        horizontalLayout->addWidget(cbbType);

        leKey = new QLineEdit(QueryEmp);
        leKey->setObjectName(QString::fromUtf8("leKey"));

        horizontalLayout->addWidget(leKey);

        btnQuery = new QPushButton(QueryEmp);
        btnQuery->setObjectName(QString::fromUtf8("btnQuery"));

        horizontalLayout->addWidget(btnQuery);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 6);
        horizontalLayout->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(QueryEmp);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(tableView);


        retranslateUi(QueryEmp);

        QMetaObject::connectSlotsByName(QueryEmp);
    } // setupUi

    void retranslateUi(QDialog *QueryEmp)
    {
        QueryEmp->setWindowTitle(QApplication::translate("QueryEmp", "\345\221\230\345\267\245\346\237\245\350\257\242", nullptr));
        label->setText(QApplication::translate("QueryEmp", "\345\221\230\345\267\245\346\237\245\350\257\242", nullptr));
        btnQuery->setText(QApplication::translate("QueryEmp", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QueryEmp: public Ui_QueryEmp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYEMP_H
