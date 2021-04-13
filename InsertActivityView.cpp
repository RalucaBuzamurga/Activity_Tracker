//
// Created by Raluca Michela Buzamurga on 12/04/21.
//

#include <QApplication>
#include "InsertActivityView.h"
#include "insertactivitycontroller.h"


void InsertActivityView::showActivity(int argc, char *argv[]) {

    int c=1;
    char** v = &argv[0];

    QApplication a(argc, argv);
    InsertActivityController w;
    w.show();
    a.exec();
}
