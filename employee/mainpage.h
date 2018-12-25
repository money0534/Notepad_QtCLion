#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include "addemp.h"

namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();

private slots:
    void on_actionadd_triggered();

    void on_actionqueryEmp_triggered();

    void on_actionabout_triggered();

private:
    Ui::MainPage *ui;
    AddEmp * addEmp;
};

#endif // MAINPAGE_H
