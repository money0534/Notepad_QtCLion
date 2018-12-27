
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"

#include <QLabel>
#include <QMessageBox>
#include <QDebug>

//! [0]
MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        m_ui(new Ui::MainWindow),
        m_status(new QLabel),
        m_console(new Console),
        m_settings(new SettingsDialog),
//! [1]
        m_serial(new QSerialPort(this))
//! [1]
{
//! [0]
    m_ui->setupUi(this);
    m_console->setEnabled(false);
    setCentralWidget(m_console);

    m_ui->actionConnect->setEnabled(true);
    m_ui->actionDisconnect->setEnabled(false);
    m_ui->actionQuit->setEnabled(true);
    m_ui->actionConfigure->setEnabled(true);

    m_ui->statusBar->addWidget(m_status);

    initActionsConnections();

    connect(m_serial, &QSerialPort::errorOccurred, this, &MainWindow::handleError);

//! [2]
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);
//! [2]
    connect(m_console, &Console::getData, this, &MainWindow::writeData);
//! [3]
}
//! [3]

MainWindow::~MainWindow() {
    delete m_settings;
    delete m_ui;
}

//! [4]
void MainWindow::openSerialPort() {
    const SettingsDialog::Settings p = m_settings->settings();
    m_serial->setPortName(p.name);
    m_serial->setBaudRate(p.baudRate);
    m_serial->setDataBits(p.dataBits);
    m_serial->setParity(p.parity);
    m_serial->setStopBits(p.stopBits);
    m_serial->setFlowControl(p.flowControl);
    if (m_serial->open(QIODevice::ReadWrite)) {
        m_console->setEnabled(true);
        m_console->setLocalEchoEnabled(p.localEchoEnabled);
        m_ui->actionConnect->setEnabled(false);
        m_ui->actionDisconnect->setEnabled(true);
        m_ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                                  .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                                  .arg(p.stringParity).arg(p.stringStopBits).arg(
                        p.stringFlowControl));
    } else {
        QMessageBox::critical(this, tr("Error"), m_serial->errorString());

        showStatusMessage(tr("Open error"));
    }
}
//! [4]

//! [5]
void MainWindow::closeSerialPort() {
    if (m_serial->isOpen())
        m_serial->close();
    m_console->setEnabled(false);
    m_ui->actionConnect->setEnabled(true);
    m_ui->actionDisconnect->setEnabled(false);
    m_ui->actionConfigure->setEnabled(true);
    showStatusMessage(tr("Disconnected"));
}
//! [5]

void MainWindow::about() {
    QMessageBox::about(this, tr("关于 防碰撞模拟终端"),
                       tr("模拟防碰撞刹车，通过串口与机器人教练交互。"));
}

//! [6]
void MainWindow::writeData(const QByteArray &data) {
    m_serial->write(data);
}
//! [6]

//! [7]
void MainWindow::readData() {
    QByteArray data = m_serial->readAll();

    qDebug() << "data received:" << data;
    m_console->putData(data);
}
//! [7]

void MainWindow::on_actionResponseOK_triggered()
{
    QString txt = "$OK";
    serialWrite(txt);
}


void MainWindow::serialWrite(QString &cmd) {
    if(!m_serial->isOpen()){
        QMessageBox::warning(this,"警告","请配置连接串口后重试！");
        return;
    }
    cmd+="\r\n";
    QByteArray sendCmd = cmd.toLocal8Bit();
    //向串口发送
    m_serial->write(sendCmd);
    //显示到控制台
    char prefix[] = "--> ";
    sendCmd.prepend(prefix);
    m_console->putData(sendCmd);
}

/**
 * 模拟超速
 */
void MainWindow::on_actionOverSpeed_triggered()
{
    QString cmd="$EVENT=HS";
    serialWrite(cmd);
}

/**
 * 模拟左前方障碍物
 */
void MainWindow::on_actionLeftFront_triggered()
{
    QString cmd="$EVENT=FL";
    serialWrite(cmd);
}

/**
 * 模拟后方障碍物
 */
void MainWindow::on_actionMidBack_triggered()
{
    QString cmd="$EVENT=BM";

    serialWrite(cmd);
}

//! [8]
void MainWindow::handleError(QSerialPort::SerialPortError error) {
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString());
        closeSerialPort();
    }
}
//! [8]

void MainWindow::initActionsConnections() {
    connect(m_ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    connect(m_ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(m_ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    connect(m_ui->actionConfigure, &QAction::triggered, m_settings, &SettingsDialog::show);
    connect(m_ui->actionClear, &QAction::triggered, m_console, &Console::clear);
    connect(m_ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
//    connect(m_ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
}

void MainWindow::showStatusMessage(const QString &message) {
    m_status->setText(message);
}





