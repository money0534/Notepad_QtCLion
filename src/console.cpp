
#include "console.h"

#include <QScrollBar>
#include <QDebug>

Console::Console(QWidget *parent) :
        QPlainTextEdit(parent) {
    document()->setMaximumBlockCount(100);
    QPalette p = palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::green);
    setPalette(p);
    //不请求焦点
    setFocusPolicy(Qt::NoFocus);
//彻底禁用事件，不响应鼠标及键盘
    setEnabled(false);
}

void Console::putData(const QByteArray &data) {
    insertPlainText(data);


    QScrollBar *bar = verticalScrollBar();
    bar->setValue(bar->maximum());
}

void Console::setLocalEchoEnabled(bool set) {
    m_localEchoEnabled = set;
}

void Console::keyPressEvent(QKeyEvent *e) {
    qDebug() << "键盘事件：" << e->key();

//    switch (e->key()) {
//    case Qt::Key_Backspace:
//    case Qt::Key_Left:
//    case Qt::Key_Right:
//    case Qt::Key_Up:
//    case Qt::Key_Down:
//        break;
//    default:
//        if (m_localEchoEnabled)
//            QPlainTextEdit::keyPressEvent(e);
//        emit getData(e->text().toLocal8Bit());
//    }
}

void Console::mousePressEvent(QMouseEvent *e) {
    Q_UNUSED(e)
    //不给焦点
//    setFocus();
}

void Console::mouseDoubleClickEvent(QMouseEvent *e) {
    Q_UNUSED(e)
}

void Console::contextMenuEvent(QContextMenuEvent *e) {
    Q_UNUSED(e)
}
