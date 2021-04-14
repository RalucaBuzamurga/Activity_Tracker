//
// Created by Raluca Michela Buzamurga on 12/04/21.
//

#include "ActivityController.h"
#include <vector>

ActivityController::ActivityController() {
    activityList = new std::vector<Activity>;
}


        /*      GETTER AND SETTER       */

std::vector<Activity> *ActivityController::getActivityList() const {
    return activityList;
}


        /*      METHODS     */

void ActivityController::addActivity(const Activity& activity) {
    int flag = 0;
    for (it = activityList->begin(); it < activityList->end(); ++it){
        if(it->isEqual(activity))
            flag = 1;
    }
    if(flag == 0)
        activityList->insert(activityList->end(), activity);
}

std::vector<Activity> ActivityController::getActivitesFromDay(Day day) {
    auto *activities = new std::vector<Activity>;

    for(it = activityList->begin(); it < activityList->end(); ++it){
        if(it->getDay().isEqual(day)){
            activities->insert(activities->end(), *it);
        }
    }
    return *activities;
}

        /*      DESTRUCTOR      */

ActivityController::~ActivityController() {
    delete activityList;
}

void ActivityController::deleteActivity(const Activity& activity) {
    it = activityList->begin();
    int flag = 0;
    while(it<activityList->end()){
        if(it->isEqual(activity)){
            activityList->erase(it);
            flag = 1;
        }
       if(flag==1)
           it = activityList->end();
       ++it;
    }
}

