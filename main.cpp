#include <QApplication>
#include "GUI/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, &argv[0]);
    MainWindow w;

    w.show();
    a.exec();

    return 0;
}