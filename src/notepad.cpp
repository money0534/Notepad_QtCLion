#include "notepad.h"
#include "ui_notepad.h"
#include <QDebug>
#include <QLineEdit>

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);

    //信号与槽绑定方式一
    connect(ui->btnLogin,SIGNAL(clicked()),this,SLOT(login()));
    //使用设计师绑定
//    connect(ui->btnCancel,SIGNAL(clicked()),this,SLOT(closeSelf()));

    //设置回显模式。Password密码，NoEcho无回显，Normal默认，PasswordEchoOnEdit
    ui->etPwd->setEchoMode(QLineEdit::EchoMode::Password);
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::login() {
    //静态区，函数调用结束后的值保留。
    static int clickCount = 0;
    QString account  = ui->etAccount->text();
    QString pwd  = ui->etPwd->text();

    if("admin"==account&&"12345"==pwd){

        qDebug()<<"登录成功！";
    }else{
        clickCount++;
        if(clickCount>3){
            //解除绑定
            disconnect(ui->btnLogin,SIGNAL(clicked()),this,SLOT(login()));
        }
        qDebug()<<"登录失败！";
    }
}

void Notepad::closeSelf() {

    close();
}


void Notepad::on_btnCancel_clicked()
{
    qDebug()<<"on_btnCancel_clicked()";
    close();
}

/**
 * 输入文本变化事件
 * @param arg1
 */
void Notepad::on_etAccount_textChanged(const QString &arg1)
{
    qDebug()<<arg1;
}
