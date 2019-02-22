#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QStatusBar>
#include <QQueue>
#include "Task.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnCancel_clicked();

    void on_btnDownload_clicked();

    void on_cbApp_toggled(bool checked);

    void on_cbCfg_toggled(bool checked);

    void on_tbAppPath_clicked();

    void on_tbCfgPath_clicked();

    void on_tbScenePath_clicked();

    void on_cbScene_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    QFileDialog *fileDialog;
    //下载任务队列
    QQueue<Task> * tasks;
    //状态栏更新状态
    void showStatus(QString status);

public:
    bool isAppChecked;//App选中
    bool isCfgChecked;//Cfg选中
    bool isSceneChecked;//Scene选中
    QString appPath;
    QString cfgPath;
    QString scenePath;
};

#endif // MAINWINDOW_H
