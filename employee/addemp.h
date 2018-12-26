#ifndef ADDEMP_H
#define ADDEMP_H

#include <QDialog>
#include <QFile>
#include "EmpModel.h"

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

    void on_cbbAge_currentIndexChanged(int arg1);

    void on_cbbDept_currentIndexChanged(const QString &arg1);

    void on_cbPool_stateChanged(int arg1);

    void on_cbBasketball_stateChanged(int arg1);

    void on_cbBadminton_stateChanged(int arg1);

    void on_cbGame_stateChanged(int arg1);

private:
    Ui::AddEmp *ui;

    void writeToFile(EmpModel& model);
};

#endif // ADDEMP_H
