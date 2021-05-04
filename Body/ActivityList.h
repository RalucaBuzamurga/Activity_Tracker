//
// Created by Raluca Michela Buzamurga on 30/04/21.
//

#ifndef ACTIVITYTRACKER_ACTIVITYLIST_H
#define ACTIVITYTRACKER_ACTIVITYLIST_H

#include <list>
#include "Activity.h"

class ActivityList {

private:
    std::list<Activity> activityList;

public:
    ActivityList();

    std::list<Activity> getActivityList();
    void setActivityList(const std::list<Activity>& activitiesToSet);

    void addActivity(const Activity&);
    void deleteActivity(const Activity&);
    void sort();
};


#endif //ACTIVITYTRACKER_ACTIVITYLIST_H
