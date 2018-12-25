#ifndef ADDEMP_H
#define ADDEMP_H

#include <QDialog>

namespace Ui {
class AddEmp;
}

class AddEmp : public QDialog
{
    Q_OBJECT

public:
    explicit AddEmp(QWidget *parent = nullptr);
    ~AddEmp();

private slots:
    void on_btnConfirm_clicked();

    void on_btnCancel_clicked();

    void on_rbMale_toggled(bool checked);

    void on_rbFemale_toggled(bool checked);

private:
    Ui::AddEmp *ui;
};

#endif // ADDEMP_H
