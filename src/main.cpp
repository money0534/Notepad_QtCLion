
#include <QApplication>
#include "maindialog.h"

//不显示控制台
//#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainDialog dialog;
    dialog.show();

    return app.exec();
}
