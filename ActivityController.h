//
// Created by Raluca Michela Buzamurga on 12/04/21.
//

#ifndef ACTIVITYTRACKER_ACTIVITYCONTROLLER_H
#define ACTIVITYTRACKER_ACTIVITYCONTROLLER_H
#include "Activity.h"
#include <vector>
#include "Day.h"


class ActivityController {
private:
    std::vector<Activity> *activityList;
    std::vector<Activity>::iterator it;

public:
    ActivityController();
    void addActivity(Activity activity);

    void setActivityList(std::vector<Activity> *activityList);
    std::vector<Activity> getActivitesFromDay(Day day);
    //void deleteActivity(Activity activity);       to be implemented

    std::vector<Activity> *getActivityList() const;

    ~ActivityController();
};


#endif //ACTIVITYTRACKER_ACTIVITYCONTROLLER_H
