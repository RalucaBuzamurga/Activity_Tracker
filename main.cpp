#include "Controller/insertactivitycontroller.h"
#include "View/InsertActivityView.h"
#include "Model/Date.h"

#include <iostream>
#include <QApplication>
#include "Model/ActivityVector.h"
#include "Model/Activity.h"
#include "Model/Date.h"
#include "Model/ActivityTime.h"
#include <vector>
#include <iterator>

int main(int argc, char *argv[])
{
    InsertActivityView* insert = new InsertActivityView;
    insert->showActivity(argc, argv);





}
