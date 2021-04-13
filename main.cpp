#include "insertactivitycontroller.h"
#include "InsertActivityView.h"
#include "Day.h"

#include <iostream>
#include <QApplication>
#include "ActivityController.h"
#include "Activity.h"
#include "Day.h"
#include "ActivityTime.h"
#include <vector>
#include <iterator>

int main(int argc, char *argv[])
{
    //InsertActivityView* insert = new InsertActivityView;
    //insert->showActivity(argc, argv);

    Day day = Day(2021, 10, 4);
    ActivityTime time = ActivityTime(12, 34);
    Activity activity = Activity("Corsa", day, time, time);

    ActivityController act = ActivityController();
    act.addActivity(activity);
    act.addActivity(activity);

    std::vector<Activity> activ = std::vector<Activity>();
    activ = act.getActivitesFromDay(day);

    for (std::vector<Activity>::iterator it = activ.begin(); it<activ.end(); ++it){
        std::cout << it->getName();
    }

}
