
#include <QApplication>
#include <iostream>
#include "maindialog.h"

using namespace std;


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    for(int i=0;i<argc;i++){
        std::cout<<*(argv+i)<<std::endl;
    }

    MainDialog dialog;
    dialog.show();

    return app.exec();
}
