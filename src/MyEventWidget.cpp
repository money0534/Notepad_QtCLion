//
// Created by Shinelon on 2018/12/29.
//

#include <QtCore/QEvent>
#include <QMouseEvent>
#include <QtCore/QDebug>
#include "MyEventWidget.h"

MyEventWidget::MyEventWidget(QWidget *parent) : QWidget(parent) {}


bool MyEventWidget::event(QEvent *e) {

//    if(e->type()==QEvent::MouseButtonPress){
//        qDebug()<<"Mouse Clicked";
//强转为QMouseEvent类型
//        QMouseEvent* evt = (QMouseEvent*)e;
//    }

    return QWidget::event(e);
}

//member access into incomplete type
//没有包含头文件
void MyEventWidget::mousePressEvent(QMouseEvent *event) {

    //点击位置
//    event->pos();
    qDebug()<<event->pos();

    if (event->button() == Qt::MouseButton::LeftButton) {
        qDebug()<<"左键";
    }else if (event->button() == Qt::MouseButton::RightButton) {
        qDebug()<<"右键";
    }
    QWidget::mousePressEvent(event);
}

//void MyEventWidget::mouseEvent(QMouseEvent *) {
//
//
//}
