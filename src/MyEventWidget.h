//
// Created by Shinelon on 2018/12/29.
//

#ifndef NOTEPAD_MYEVENTWIDGET_H
#define NOTEPAD_MYEVENTWIDGET_H


#include <QtWidgets/QWidget>
#include <QMouseEvent>

class MyEventWidget : public QWidget{

    Q_OBJECT
public:
    explicit MyEventWidget(QWidget *parent=0);

    /**
     * 通常不截获event事件，而是使用更具体的事件
     * @param e
     * @return
     */
    bool event(QEvent *)override;

protected:
    /**
     * 重写鼠标按下事件
     * @param event
     */
    void mousePressEvent(QMouseEvent *event) override;

};


#endif //NOTEPAD_MYEVENTWIDGET_H
