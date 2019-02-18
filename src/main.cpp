
#include <QApplication>
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>



/**
 * 命令行分析器
 * 以-p -f -t tvalue new haha运行该程序
 * Edit Configurations | Program arguments : -p -f -t tvalue new haha
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("my-copy-program");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;

    parser.setApplicationDescription("Test helper");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("source", QCoreApplication::translate("main", "Source file to copy."));
    parser.addPositionalArgument("destination", QCoreApplication::translate("main", "Destination directory."));

    //c++11 支持
    parser.addOptions({
                              // An option with a value
                              {{"t", "target-directory"},
                                      QCoreApplication::translate("main",
                                                                  "Copy all source files into <directory>."),
                                      QCoreApplication::translate("main", "directory")},
                      });


    // Process the actual command line arguments given by the user
    parser.process(app);

    //无名参数
    const QStringList args = parser.positionalArguments();
    qDebug()<<args;

    //带值的-t参数
    QString tValue = parser.value("t");
    qDebug()<<"tValue is "<<tValue;


    return EXIT_SUCCESS;
}
