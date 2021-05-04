//
// Created by Raluca Michela Buzamurga on 30/04/21.
//

#include "ActivityList.h"

ActivityList::ActivityList() {
    activityList = std::list<Activity>();
}

void ActivityList::setActivityList(const std::list<Activity>& activitiesToSet) {
    activityList.clear();

    for(const auto& it:activitiesToSet)
        activityList.push_back(it);
}

std::list<Activity> ActivityList::getActivityList() {
    return activityList;
}

void ActivityList::addActivity(const Activity& activity) {
    int flag = 0;

    for (auto it:activityList) {
        if (it == activity)
            flag = 1;
    }

    if (flag == 0)
        activityList.push_back(activity);
}

void ActivityList::deleteActivity(const Activity& activity) {
    activityList.remove(activity);
}

void ActivityList::sort() {

    activityList.sort([](Activity lhs, Activity rhs){
        return lhs>rhs;
    });

}