#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include "Model.h"

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_btn7_clicked();

    void on_btn8_clicked();

    void on_btn9_clicked();

    void on_btn0_clicked();

    void on_btnClear_clicked();

    void on_btnEq_clicked();

    void on_btnPlus_clicked();

    void on_btnMinus_clicked();

    void on_btnMulti_clicked();

    void on_btnDivide_clicked();

private:
    Ui::Calculator *ui;
    Model * model;//数据实体
    QString tmp;

    void display();
};

#endif // CALCULATOR_H
