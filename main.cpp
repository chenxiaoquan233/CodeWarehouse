#include "mainwindow.h"
#include "config.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    config conf;

    w.setConfig(&conf);
    w.init();
    w.show();
    return a.exec();
}
