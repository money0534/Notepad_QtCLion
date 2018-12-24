#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::Calculator) {
    ui->setupUi(this);
    model = new Model;
    tmp = "";
}

Calculator::~Calculator() {
    delete ui;
    delete model;
}

/**
 * 显示到LCD
 */
void Calculator::display() {
    int result = tmp.toInt();
    ui->lcdNumber->display(result);
}

void Calculator::on_btn1_clicked() {
    tmp += ui->btn1->text();
    display();
}

void Calculator::on_btn2_clicked() {
    tmp += ui->btn2->text();
    display();
}

void Calculator::on_btn3_clicked() {
    tmp += ui->btn3->text();
    display();
}

void Calculator::on_btn4_clicked() {
    tmp += ui->btn4->text();
    display();
}

void Calculator::on_btn5_clicked() {
    tmp += ui->btn5->text();
    display();
}

void Calculator::on_btn6_clicked() {
    tmp += ui->btn6->text();
    display();
}

void Calculator::on_btn7_clicked() {
    tmp += ui->btn7->text();
    display();
}

void Calculator::on_btn8_clicked() {
    tmp += ui->btn8->text();
    display();
}

void Calculator::on_btn9_clicked() {
    tmp += ui->btn9->text();
    display();
}

void Calculator::on_btn0_clicked() {
    if (""!=tmp){
        tmp += ui->btn0->text();
        display();
    }
}

void Calculator::on_btnClear_clicked() {
    tmp="";
//    model->setNum1(0);
//    model->setNum2(0);
    ui->lcdNumber->display(0);

}

void Calculator::on_btnEq_clicked() {
    model->setNum2(tmp.toInt());
    ui->lcdNumber->display(model->getResult());
}

void Calculator::on_btnPlus_clicked() {
    model->setNum1(tmp.toInt());
    tmp="";
    model->setOpnd(ui->btnPlus->text());
}

void Calculator::on_btnMinus_clicked() {
    model->setNum1(tmp.toInt());
    tmp="";
    model->setOpnd(ui->btnMinus->text());
}

void Calculator::on_btnMulti_clicked() {
    model->setNum1(tmp.toInt());
    tmp="";
    model->setOpnd(ui->btnMulti->text());

}

void Calculator::on_btnDivide_clicked() {
    model->setNum1(tmp.toInt());
    tmp="";
    model->setOpnd(ui->btnDivide->text());
}

