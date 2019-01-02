
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

QT_BEGIN_NAMESPACE

class QLabel;

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class Console;
class SettingsDialog;

class MainWindow : public QMainWindow
{
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

private:
    void initActionsConnections();

    void serialWrite(QString& cmd);

private:
    void showStatusMessage(const QString &message);

    Ui::MainWindow *m_ui = nullptr;
    QLabel *m_status = nullptr;
    Console *m_console = nullptr;
    SettingsDialog *m_settings = nullptr;
    QSerialPort *m_serial = nullptr;

    int sendInterval;//报文自动发送间隔
};

#endif // MAINWINDOW_H
