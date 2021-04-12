#include "insertactivitycontroller.h"
#include "InsertActivityView.h"
#include "Day.h"

#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    InsertActivityView* insert = new InsertActivityView;
    insert->showActivity(argc, argv);
}
