/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *parametersBox;
    QGridLayout *gridLayout_2;
    QLabel *baudRateLabel;
    QComboBox *baudRateBox;
    QLabel *dataBitsLabel;
    QComboBox *dataBitsBox;
    QLabel *parityLabel;
    QComboBox *parityBox;
    QLabel *stopBitsLabel;
    QComboBox *stopBitsBox;
    QLabel *flowControlLabel;
    QComboBox *flowControlBox;
    QGroupBox *selectBox;
    QGridLayout *gridLayout;
    QComboBox *serialPortInfoListBox;
    QLabel *descriptionLabel;
    QLabel *manufacturerLabel;
    QLabel *serialNumberLabel;
    QLabel *locationLabel;
    QLabel *vidLabel;
    QLabel *pidLabel;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *applyButton;
    QGroupBox *additionalOptionsGroupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *localEchoCheckBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *leSendInterval;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
        SettingsDialog->resize(419, 366);
        gridLayout_3 = new QGridLayout(SettingsDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        parametersBox = new QGroupBox(SettingsDialog);
        parametersBox->setObjectName(QString::fromUtf8("parametersBox"));
        gridLayout_2 = new QGridLayout(parametersBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        baudRateLabel = new QLabel(parametersBox);
        baudRateLabel->setObjectName(QString::fromUtf8("baudRateLabel"));

        gridLayout_2->addWidget(baudRateLabel, 0, 0, 1, 1);

        baudRateBox = new QComboBox(parametersBox);
        baudRateBox->setObjectName(QString::fromUtf8("baudRateBox"));

        gridLayout_2->addWidget(baudRateBox, 0, 1, 1, 1);

        dataBitsLabel = new QLabel(parametersBox);
        dataBitsLabel->setObjectName(QString::fromUtf8("dataBitsLabel"));

        gridLayout_2->addWidget(dataBitsLabel, 1, 0, 1, 1);

        dataBitsBox = new QComboBox(parametersBox);
        dataBitsBox->setObjectName(QString::fromUtf8("dataBitsBox"));

        gridLayout_2->addWidget(dataBitsBox, 1, 1, 1, 1);

        parityLabel = new QLabel(parametersBox);
        parityLabel->setObjectName(QString::fromUtf8("parityLabel"));

        gridLayout_2->addWidget(parityLabel, 2, 0, 1, 1);

        parityBox = new QComboBox(parametersBox);
        parityBox->setObjectName(QString::fromUtf8("parityBox"));

        gridLayout_2->addWidget(parityBox, 2, 1, 1, 1);

        stopBitsLabel = new QLabel(parametersBox);
        stopBitsLabel->setObjectName(QString::fromUtf8("stopBitsLabel"));

        gridLayout_2->addWidget(stopBitsLabel, 3, 0, 1, 1);

        stopBitsBox = new QComboBox(parametersBox);
        stopBitsBox->setObjectName(QString::fromUtf8("stopBitsBox"));

        gridLayout_2->addWidget(stopBitsBox, 3, 1, 1, 1);

        flowControlLabel = new QLabel(parametersBox);
        flowControlLabel->setObjectName(QString::fromUtf8("flowControlLabel"));

        gridLayout_2->addWidget(flowControlLabel, 4, 0, 1, 1);

        flowControlBox = new QComboBox(parametersBox);
        flowControlBox->setObjectName(QString::fromUtf8("flowControlBox"));

        gridLayout_2->addWidget(flowControlBox, 4, 1, 1, 1);


        gridLayout_3->addWidget(parametersBox, 0, 1, 1, 1);

        selectBox = new QGroupBox(SettingsDialog);
        selectBox->setObjectName(QString::fromUtf8("selectBox"));
        gridLayout = new QGridLayout(selectBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        serialPortInfoListBox = new QComboBox(selectBox);
        serialPortInfoListBox->setObjectName(QString::fromUtf8("serialPortInfoListBox"));

        gridLayout->addWidget(serialPortInfoListBox, 0, 0, 1, 1);

        descriptionLabel = new QLabel(selectBox);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));

        gridLayout->addWidget(descriptionLabel, 1, 0, 1, 1);

        manufacturerLabel = new QLabel(selectBox);
        manufacturerLabel->setObjectName(QString::fromUtf8("manufacturerLabel"));

        gridLayout->addWidget(manufacturerLabel, 2, 0, 1, 1);

        serialNumberLabel = new QLabel(selectBox);
        serialNumberLabel->setObjectName(QString::fromUtf8("serialNumberLabel"));

        gridLayout->addWidget(serialNumberLabel, 3, 0, 1, 1);

        locationLabel = new QLabel(selectBox);
        locationLabel->setObjectName(QString::fromUtf8("locationLabel"));

        gridLayout->addWidget(locationLabel, 4, 0, 1, 1);

        vidLabel = new QLabel(selectBox);
        vidLabel->setObjectName(QString::fromUtf8("vidLabel"));

        gridLayout->addWidget(vidLabel, 5, 0, 1, 1);

        pidLabel = new QLabel(selectBox);
        pidLabel->setObjectName(QString::fromUtf8("pidLabel"));

        gridLayout->addWidget(pidLabel, 6, 0, 1, 1);


        gridLayout_3->addWidget(selectBox, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(96, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        applyButton = new QPushButton(SettingsDialog);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));

        horizontalLayout->addWidget(applyButton);


        gridLayout_3->addLayout(horizontalLayout, 2, 0, 1, 2);

        additionalOptionsGroupBox = new QGroupBox(SettingsDialog);
        additionalOptionsGroupBox->setObjectName(QString::fromUtf8("additionalOptionsGroupBox"));
        verticalLayout = new QVBoxLayout(additionalOptionsGroupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        localEchoCheckBox = new QCheckBox(additionalOptionsGroupBox);
        localEchoCheckBox->setObjectName(QString::fromUtf8("localEchoCheckBox"));
        localEchoCheckBox->setChecked(true);

        verticalLayout->addWidget(localEchoCheckBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(additionalOptionsGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        leSendInterval = new QLineEdit(additionalOptionsGroupBox);
        leSendInterval->setObjectName(QString::fromUtf8("leSendInterval"));

        horizontalLayout_2->addWidget(leSendInterval);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 7);

        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout_3->addWidget(additionalOptionsGroupBox, 1, 0, 1, 2);


        retranslateUi(SettingsDialog);

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Settings", nullptr));
        parametersBox->setTitle(QApplication::translate("SettingsDialog", "Select Parameters", nullptr));
        baudRateLabel->setText(QApplication::translate("SettingsDialog", "BaudRate:", nullptr));
        dataBitsLabel->setText(QApplication::translate("SettingsDialog", "Data bits:", nullptr));
        parityLabel->setText(QApplication::translate("SettingsDialog", "Parity:", nullptr));
        stopBitsLabel->setText(QApplication::translate("SettingsDialog", "Stop bits:", nullptr));
        flowControlLabel->setText(QApplication::translate("SettingsDialog", "Flow control:", nullptr));
        selectBox->setTitle(QApplication::translate("SettingsDialog", "Select Serial Port", nullptr));
        descriptionLabel->setText(QApplication::translate("SettingsDialog", "Description:", nullptr));
        manufacturerLabel->setText(QApplication::translate("SettingsDialog", "Manufacturer:", nullptr));
        serialNumberLabel->setText(QApplication::translate("SettingsDialog", "Serial number:", nullptr));
        locationLabel->setText(QApplication::translate("SettingsDialog", "Location:", nullptr));
        vidLabel->setText(QApplication::translate("SettingsDialog", "Vendor ID:", nullptr));
        pidLabel->setText(QApplication::translate("SettingsDialog", "Product ID:", nullptr));
        applyButton->setText(QApplication::translate("SettingsDialog", "Apply", nullptr));
        additionalOptionsGroupBox->setTitle(QApplication::translate("SettingsDialog", "Additional options", nullptr));
        localEchoCheckBox->setText(QApplication::translate("SettingsDialog", "Local echo", nullptr));
        label->setText(QApplication::translate("SettingsDialog", "\345\217\221\351\200\201\351\227\264\351\232\224\357\274\210\345\217\257\351\200\211\357\274\211\357\274\232", nullptr));
        leSendInterval->setText(QApplication::translate("SettingsDialog", "100", nullptr));
        leSendInterval->setPlaceholderText(QApplication::translate("SettingsDialog", "\346\212\245\346\226\207\345\217\221\351\200\201\351\227\264\351\232\224\357\274\214\351\273\230\350\256\244100ms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
