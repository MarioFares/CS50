#include "headers/mainwindow.h"
#include "headers/common.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setStyleSheet(common::openSheet(":/styles/style.qss"));
    w.ensurePolished();
    w.show();
    return a.exec();
}
