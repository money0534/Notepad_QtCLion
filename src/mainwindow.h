
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QFile>
#include <QTextStream>

QT_BEGIN_NAMESPACE

class QLabel;

namespace Ui {
    class MainWindow;
}

QT_END_NAMESPACE

class Console;

class SettingsDialog;

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void openSerialPort();

    void closeSerialPort();

    void about();

    void writeData(const QByteArray &data);

    void readData();

    void handleError(QSerialPort::SerialPortError error);

    void on_actionOverSpeed_triggered();

    void on_actionLeftFront_triggered();

    void on_actionMidBack_triggered();

    void on_actionResponseOK_triggered();

    void on_actionDataSource_triggered();

    void on_actionSend_triggered();

    void on_actionStop_triggered();

    void on_actionPause_triggered();

    void on_actionRestart_triggered();

    /**
     * 发送一行报文
     */
    void sendMsg();

private:
    void initActionsConnections();

    void serialWrite(QString &cmd);

public:
    void showStatusMessage(const QString &message);

    Ui::MainWindow *m_ui = nullptr;
    QLabel *m_status = nullptr;
    Console *m_console = nullptr;
    SettingsDialog *m_settings = nullptr;
    QSerialPort *m_serial = nullptr;

    QFile* dataSource;//数据源
    QTextStream* stream;//数据源
    int sendInterval = 100;//报文自动发送间隔
    int sendLine = 0;//报文发送的行数，数据源中所在行
    bool isStartWork = false;//是否已开始发送，默认false，点击发送或重新发送后置为true
    bool isPause = false;//是否暂停发送，默认false，点击暂停后置为false
    bool isIntercept = false;//是否终止发送，默认false，点击停止后置为false

    QTimer * timer;//定时器
};

#endif // MAINWINDOW_H
