
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"
#include "InitThread.h"

#include <QLabel>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QTimer>
#include <QTextStream>
#include <QProgressDialog>

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
    //创建timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(sendMsg()));
    //创建集合
    lines = new QList<QByteArray>;


}
//! [3]

MainWindow::~MainWindow() {
    delete m_settings;
    delete m_ui;
    delete timer;
    delete lines;

    //Process finished with exit code -1073741819 (0xC0000005)?
//    delete workerThread;
//    delete progressBar;
}

//! [4]
void MainWindow::openSerialPort() {
    const SettingsDialog::Settings p = m_settings->settings();

    //得到发送间隔
    sendInterval = p.sendInterval;
    qDebug() << "sendInterval=" << sendInterval;

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
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6.  Loop Interval : %7ms")
                                  .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                                  .arg(p.stringParity).arg(p.stringStopBits).arg(
                        p.stringFlowControl).arg(p.sendInterval));
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
    //普通文本
//    m_console->putData(data);
    //html内容
    QString html="<font color=\"red\">";
    html+=data;
    html+="</font>";
    qDebug()<<html;
    m_console->appendHtml(html);

}
//! [7]

void MainWindow::on_actionResponseOK_triggered() {
    //上位机接收有问题$丢掉。使用串口工具正常，软件接收问题？
    //上位机判断条件以$OK开头或包含OK=CLIENT
    QString txt = "$OK=CLIENT";
    serialWrite(txt);
}


void MainWindow::serialWrite(QString &cmd) {
    if (!m_serial->isOpen()) {
        QMessageBox::warning(this, "警告", "请配置连接串口后重试！");
        return;
    }
    cmd += "\r\n";
    QByteArray sendCmd = cmd.toLocal8Bit();
    //向串口发送
    m_serial->write(sendCmd);
    //显示到控制台
//    char prefix[] = "--> ";
//    sendCmd.prepend(prefix);
    m_console->putData(sendCmd);
}

/**
 * 模拟旧版刹车指令
 */
void MainWindow::on_actionEventEqBrake_triggered() {
    QString cmd = "$EVENT=BRAKE";
    serialWrite(cmd);
}


/**
 * 模拟超速
 */
void MainWindow::on_actionOverSpeed_triggered() {
    QString cmd = "$EVENT=HS";
    serialWrite(cmd);
}

/**
 * 模拟左前方障碍物
 */
void MainWindow::on_actionLeftFront_triggered() {
    QString cmd = "$EVENT=FL";
    serialWrite(cmd);
}

/**
 * 模拟后方障碍物
 */
void MainWindow::on_actionMidBack_triggered() {
    QString cmd = "$EVENT=BM";

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
    //绑定退出事件 终止发送
    connect(m_ui->actionDisconnect, &QAction::triggered, this,
            &MainWindow::on_actionStop_triggered);
    connect(m_ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(m_ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    connect(m_ui->actionConfigure, &QAction::triggered, m_settings, &SettingsDialog::show);
    connect(m_ui->actionClear, &QAction::triggered, m_console, &Console::clear);
//    connect(m_ui->actionStop, &QAction::triggered, m_console, &Console::clear);
    connect(m_ui->actionDataSource, &QAction::triggered, m_console, &Console::clear);
    connect(m_ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
//    connect(m_ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
}

void MainWindow::showStatusMessage(const QString &message) {
    m_status->setText(message);
}


//打开文件数据源
void MainWindow::on_actionDataSource_triggered() {
    //会默认打开当前路径 exe所在路径；过滤文本文件
    QString temp = QFileDialog::getOpenFileName(this, tr("选择数据源"), "",

                                                    tr("Text Files (*.txt *.log)"));
    //为空
    if (nullptr == temp) {
        qDebug() << "用户取消";
        return;
    }

    //或 打开了同一个文件
    if (dataSource == temp) {
        return;
    }

    dataSource = temp;
    qDebug() << "打开文件：" << temp;

    //Process finished with exit code -1073741819 (0xC0000005) nullptr
#if 1

    QFile file(dataSource);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        int ret = QMessageBox::critical(this, "错误", "打开文件失败", "确定");
        qDebug() << "打开文件失败!";
        return;
    }

    qDebug() << "开始读取";

    //情况之前
    lines->clear();

    //读取到集合
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        lines->append(line);
        qDebug() << line;
    }

    qDebug() << "Total Lines:" << lines->length();
    file.close();


    //从0开始计
    sendLine = 0;
    //窗口显示当前数据源路径
    setWindowTitle(tr("%1 共%2行\n").arg(dataSource).arg(lines->length()));
//    setWindowTitle(dataSource);
//    m_console->insertPlainText(tr("%1 初始化成功，共 %2 行。\n").arg(dataSource).arg(lines->length()));
//    qDebug()<<tr("%1 初始化成功，共 %2 行。\n").arg(dataSource).arg(lines->length());

#endif
    //线程方式初始化
#if 0
    progressBar = new QProgressDialog("初始化数据源...","取消",0,0,this);
    //模态窗口 获取焦点后外部无法交互
    progressBar->setWindowModality(Qt::WindowModal);
    progressBar->show();

    //同界面跳转时的show()调用，必须在堆上创建对象，否则方法调用结束后对象被销毁
    workerThread = new InitThread(nullptr,dataSource,lines);
    connect(workerThread, SIGNAL(initFinished()), this, SLOT(onDataSourceReady()));
    workerThread->start();
#endif
}


void MainWindow::sendMsg() {

    int length = lines->length();

    QByteArray line = lines->value(sendLine);
    double pct = 100 * (sendLine + 1) / (double) length;
    //以非科学计数法保留两位小数
    QByteArray pctStr = QByteArray::number(pct, 'f', 2);
    m_serial->write(line);

    //显示到控制台
//    char prefix[] = "% --> ";
    char prefix[] = "% ";
    line.prepend(prefix);
    line.prepend(pctStr);
    m_console->putData(line);
//    qDebug()<<line;


    sendLine++;
    if (sendLine > length - 1) {
        sendLine = 0;
    }
}

/**
 * 发送按钮
 */
void MainWindow::on_actionSend_triggered() {
    if (!m_serial->isOpen()) {
        qDebug() << "未打开串口";
        QMessageBox::warning(this, "警告", "未打开串口", "确定");
        return;
    }

    if (dataSource == nullptr) {
        qDebug() << "未配置数据源";
        QMessageBox::warning(this, "警告", "未配置数据源", "确定");
        return;
    }

    //sendInterval,dataSource
    //初始化发送
    if (!isSending) {
        timer->start(sendInterval);
        isSending = true;
        //禁用选择数据源按钮
        m_ui->actionDataSource->setEnabled(false);
    }
}

/**
 * 停止发送
 */
void MainWindow::on_actionStop_triggered() {
//    isIntercept = true;
    sendLine = 0;//归零
    isSending = false;
    timer->stop();
    //启用选择数据源按钮
    m_ui->actionDataSource->setEnabled(true);
}

/**
 * 暂停
 */
void MainWindow::on_actionPause_triggered() {
    isSending = false;
    timer->stop();
}

void MainWindow::onDataSourceReady() {
    qDebug() << "数据源初始化完成";


    delete workerThread;
    if (progressBar != nullptr)
        progressBar->close();
    delete progressBar;
    //从0开始计
    sendLine = 0;
    //窗口显示当前数据源路径
    setWindowTitle(/*"防碰撞模拟终端 "+*/dataSource);
//    char tip[] = "初始化成功！\n";
//    m_console->putData(tip);
        m_console->insertPlainText(tr("%1 初始化成功，共 %2 行。\n").arg(dataSource).arg(lines->length()));

}

//不使用
void MainWindow::on_actionRestart_triggered() {

}



