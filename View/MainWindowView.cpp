//
// Created by Raluca Michela Buzamurga on 14/04/21.
//

#include <QApplication>
#include "MainWindowView.h"
#include "Controller/mainwindow.h"

void MainWindowView::showActivity(int argc, char **argv) {
    char** v = &argv[0];

    QApplication a(argc, v);
    MainWindow w;
    w.show();
    a.exec();
}
