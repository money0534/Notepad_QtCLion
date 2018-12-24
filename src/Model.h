//
// Created by Shinelon on 2018/12/24.
//

#include <QString>
#ifndef NOTEPAD_MODEL_H
#define NOTEPAD_MODEL_H


class Model {
public:
    Model();

    int getNum1() const;

    void setNum1(int num1);

    int getNum2() const;

    void setNum2(int num2);

    void setOpnd(const QString &opnd);


     QString getResult() ;

private:
    int num1;
    int num2;
    int result;
    //操作符
    QString opnd;
};


#endif //NOTEPAD_MODEL_H
