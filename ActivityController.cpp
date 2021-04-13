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
void ActivityController::setActivityList(std::vector<Activity> *activityList) {
    ActivityController::activityList = activityList;
}


        /*      METHODS     */

void ActivityController::addActivity(Activity activity) {
    activityList->insert(activityList->end(), activity);
}

std::vector<Activity> ActivityController::getActivitesFromDay(Day day) {
    auto *activities = new std::vector<Activity>;

    for(it = activityList->begin(); it < activityList->end(); ++it){
        if(it->getDay().getYear() == day.getYear() && it->getDay().getMonth() == day.getMonth() && it->getDay().getDay() == day.getDay()){
            activities->insert(activities->end(), *it);
        }
    }
    return *activities;
}

        /*      DESTRUCTOR      */

ActivityController::~ActivityController() {
    delete activityList;
}