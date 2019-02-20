
#include <QApplication>
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>
#include <iostream>
#include <QDomDocument>
#include <QDomImplementation>
#include <QtXml/QXmlSimpleReader>


/**
 * 命令行分析器
 * 以-p -f -t tvalue new haha运行该程序
 * Edit Configurations | Program arguments : -p -f -t tvalue new haha
 * @param argc
 * @param argv
 * @return
 */


/**
 * 从field.xml加载
 * @param srcPath
 */
 void field2subject(QString &srcPath);

void reverseInput(QString& qString);

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("XmlUtils for UnityDev");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;

    parser.setApplicationDescription("XmlUtils for UnityDev. 1)reverse output. 2)generate subject from field.");
    parser.addHelpOption();
    parser.addVersionOption();
//    parser.addPositionalArgument("source", QCoreApplication::translate("main", "Source file to copy."));
//    parser.addPositionalArgument("destination", QCoreApplication::translate("main", "Destination directory."));

    //c++11 支持
    parser.addOptions({
                              // A boolean option with a single name (-r)
                              {"r", "Reverse lines of the input file."},

                              // An option with a value
                              {{"i", "input"},"Path for input file.","InputPath"}
                      });


    // Process the actual command line arguments given by the user
    parser.process(app);

    //无名参数
    const QStringList args = parser.positionalArguments();
//    qDebug()<<args;

    //带值的-t参数
    QString fValue = parser.value("i");
//    qDebug()<<"input file is "<<fValue;

    bool isReverse = parser.isSet("r");

    if(!isReverse){
        field2subject(fValue);
    } else {
        reverseInput(fValue);
    }
//    qDebug()<<isReverse;

    return EXIT_SUCCESS;
}

void reverseInput(QString& path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QList<QByteArray> lines;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        lines.append(line);
//        qDebug()<<line;
    }
    file.close();

    QStringList arr = path.split('\\', QString::SkipEmptyParts);
    QString name = arr.value(arr.length()-1);

//    qDebug()<<name;

    //输出
    QString outputDir = path.left(path.lastIndexOf("\\"));
    QStringList arr2 = name.split('.',QString::SkipEmptyParts);
    QString outputName=outputDir+"\\"+arr2.value(0)+"-reversed."+arr2.value(arr2.length()-1);

    QFile output(outputName);
    if (!output.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream stream(&output);
    //设置编码
    stream.setCodec("UTF-8");

    for (int j = 0; j < lines.length(); ++j) {
        stream<<lines.value(lines.length()-1-j);
    }
    output.close();

    qDebug()<<"reverse file succeed at: "<<outputName;

}


void createSubject();
//  C:/Users/Shinelon/AppData/LocalLow/DefaultCompany/HahaRobotCoach/Config/field.xml
void field2subject(QString &srcPath){


    QDomDocument doc("field");
    QFile file(srcPath);
    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();

    //获取所有point结点
    QDomNodeList pointNodes = doc.elementsByTagName("point");
//    qDebug()<<pointNodes.length();

    QList<QDomElement> subPointNodes;
    //项目名
    QMap<QString,QString> subEntrys;


    for (int i = 0; i < pointNodes.length(); ++i) {
        QDomElement element = pointNodes.item(i).toElement();
        if(element.hasAttribute("subject")){
            auto subName = element.attribute("subject");
            subPointNodes.append(element);
//            qDebug()<<subName;
            if(!subEntrys.contains(subName)){
                auto subType = element.attribute("type");
                subEntrys.insert(subName,subType);
            }
        }
    }

//    QDomImplementation impl;
//    QDomDocumentType documentType = impl.createDocumentType("xml",QString(),QString());
//    QDomDocument subDoc(documentType);
    QDomDocument subDoc;
    QDomElement root = subDoc.createElement("root");

    QMap<QString, QString>::const_iterator iter = subEntrys.constBegin();
    while (iter != subEntrys.constEnd()) {
        qDebug()<<iter.key()<<","<<iter.value();
        QDomElement subject = subDoc.createElement("subject");
        subject.setAttribute("subject",iter.key());
        subject.setAttribute("type",iter.value());


        for(QDomElement&p:subPointNodes){
            if (p.attribute("subject")==iter.key()){
                subject.appendChild(p);
            }
        }

        root.appendChild(subject);
        ++iter;
    }


    qDebug()<<"convert total subject count: "<<subEntrys.size();
    subDoc.appendChild(root);

    QString outputDir = srcPath.left(srcPath.lastIndexOf("\\"));

    //写入到subjects.xml
    QFile output(outputDir+"\\subjects.xml");
    if (!output.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    //最终subject.xml内容
    QString xml = subDoc.toString();
    output.write(xml.toStdString().c_str());
    output.close();
}