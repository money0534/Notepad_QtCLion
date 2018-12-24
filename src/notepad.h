#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

namespace Ui {
class Notepad;
}

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = nullptr);
    ~Notepad();

    //定义槽函数
private slots:

    void login();
    void closeSelf();

private:
    Ui::Notepad *ui;
};

#endif // NOTEPAD_H
