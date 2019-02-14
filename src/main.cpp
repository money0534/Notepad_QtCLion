
#include <QApplication>

//不显示控制台
//#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//    Notepad Editor;
//    Editor.show();

    return app.exec();
}
