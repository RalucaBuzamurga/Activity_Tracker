
#include <iterator>
#include <Model/ActivityVector.h>
#include "Model/Date.h"
#include "Model/ActivityTime.h"
#include "View/MainWindowView.h"
#include "Model/Activity.h"


int main(int argc, char *argv[])
{

    ActivityVector activities = ActivityVector();

    Date date = Date(2020, 4, 12);
    Date date1 = Date(2021, 4, 2);

    ActivityTime time1 = ActivityTime(12, 30);
    ActivityTime time2 = ActivityTime(13, 30);

    Activity act = Activity("Corsa", date, time1, time2);
    Activity act1 = Activity("camminata", date1, time1, time2);
    activities.addActivity(act);
    activities.addActivity(act1);

    std::cout << "Before";
    for(auto it = activities.getActivityList()->begin(); it < activities.getActivityList()->end(); ++it){
        std::cout << " " << it->getDay().getYear();
    }
    std::cout << "After";
    activities.sort();
    for(auto it = activities.getActivityList()->begin(); it < activities.getActivityList()->end(); ++it){
        std::cout << " " << it->getDay().getYear();
    }

    /*Activity tmpAct = Activity();
    std::cout << "\nBefore: " << act.getDay().getYear();
    std::cout << " " << act1.getDay().getYear();

    tmpAct.setActivity(act1);
    act1.setActivity(act);
    act.setActivity(tmpAct);

    std::cout << "\nAfter: " << act.getDay().getYear();
    std::cout << " " << act1.getDay().getYear();*/

    /*std::cout << "\nBefore";
    for(auto it = activities.getActivityList()->begin(); it < activities.getActivityList()->end(); ++it){
        std::cout << " " << it->getDay().getYear();
    }
    activities.swap(act1, act);
    std::cout << "\nAfter";
    for(auto it = activities.getActivityList()->begin(); it < activities.getActivityList()->end(); ++it){
        std::cout << " " << it->getDay().getYear();
    }*/

    MainWindowView* window = new MainWindowView;
    window->showActivity(argc, argv);

    return 0;
}

