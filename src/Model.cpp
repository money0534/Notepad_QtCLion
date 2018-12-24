//
// Created by Shinelon on 2018/12/24.
//

#include "Model.h"

int Model::getNum1() const {
    return num1;
}

void Model::setNum1(int num1) {
    Model::num1 = num1;
}

int Model::getNum2() const {
    return num2;
}

void Model::setNum2(int num2) {
    Model::num2 = num2;
}


void Model::setOpnd(const QString &opnd) {
    Model::opnd = opnd;
}

Model::Model() {
    num1 = num2 = result = 0;
    opnd = "";
}

QString Model::getResult() {
    if ("+" == opnd) {
        result = num1 + num2;
    } else if ("-" == opnd) {
        result = num1 - num2;
    } else if ("*" == opnd) {
        result = num1 * num2;
    } else if ("/" == opnd) {
        if (num2 == 0)
            return "ERROR";
        result = num1 / num2;
    } else {
        result = num1;
    }
    return QString::number(result);
}
