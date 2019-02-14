#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class MainDialog;
}

/**
 * 下载信息封装
 */
struct EncapUrl{
    QString appUrl;
    QString cfgUrl;
    QString envUrl;
};

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = nullptr);
    explicit MainDialog(QPair<QString,QString>  taskEntity,QWidget *parent = nullptr);
    ~MainDialog();
    void downloadFile(QString url);

private:
    Ui::MainDialog *ui;
    QPair<QString,QString>  taskEntity;
};

#endif // MAINDIALOG_H
