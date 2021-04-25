//
// Created by Raluca Michela Buzamurga on 12/04/21.
//

#include "ActivityVector.h"
#include <vector>

ActivityVector::ActivityVector() {
    activityList = new std::vector<Activity>;
}

ActivityVector::ActivityVector(ActivityVector const &activityVector) {
    activityList = new std::vector<Activity>;
    for (auto itr = activityVector.getActivityList()->begin(); itr<activityVector.getActivityList()->end(); ++itr){
        activityList->push_back(*itr);
    }
}


        /*      GETTER AND SETTER       */

std::vector<Activity> *ActivityVector::getActivityList() const {
    return activityList;
}

std::vector<std::string> *ActivityVector::getActivitiesName() {
    auto* activitiesName = new std::vector<std::string>;
    for(auto itr = activityList->begin(); itr<activityList->end(); ++itr){
        activitiesName->push_back(itr->getName());
    }
    return activitiesName;
}

std::vector<Date> *ActivityVector::getActivitiesDate() {
    auto* activitiesDate = new std::vector<Date>;
    for(auto itr = activityList->begin(); itr<activityList->end(); ++itr){
        activitiesDate->push_back(itr->getDay());
    }
    return activitiesDate;
}

std::vector<ActivityTime> *ActivityVector::getActivitiesStartTime() {
    auto* activitiesStartTime = new std::vector<ActivityTime>;
    for(auto itr = activityList->begin(); itr<activityList->end(); ++itr){
        activitiesStartTime->push_back(itr->getStartTime());
    }
    return activitiesStartTime;
}

std::vector<ActivityTime> *ActivityVector::getActivitiesEndTime() {
    auto* activitiesEndTime = new std::vector<ActivityTime>;
    for(auto itr = activityList->begin(); itr<activityList->end(); ++itr){
        activitiesEndTime->push_back(itr->getEndTime());
    }
    return activitiesEndTime;
}


        /*      METHODS     */

void ActivityVector::addActivity(const Activity& activity) {
    int flag = 0;
    for (it = activityList->begin(); it < activityList->end(); ++it){
        if(it->isEqual(activity))
            flag = 1;
    }
    if(flag == 0)
        activityList->insert(activityList->end(), activity);
}

void ActivityVector::deleteActivity(const Activity& activity) {
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

ActivityVector *ActivityVector::sort() {

    for(auto it = activityList->begin(); it<activityList->end(); ++it){
        for(auto itr=it; itr<activityList->end(); ++itr){
            if(itr->getDay().getYear() > it->getDay().getYear()){
                std::swap(*itr, *it);
            }
            else
            if(itr->getDay().getYear() == it->getDay().getYear() && itr->getDay().getMonth() > it->getDay().getMonth()){
                std::swap(*itr, *it);
            }
            else
            if(itr->getDay().getYear() == it->getDay().getYear() && itr->getDay().getMonth() == itr->getDay().getMonth() && itr->getDay().getDay() > it->getDay().getDay()){
                std::swap(*itr, *it);
            }
        }
    }
    return this;
}



        /*      DESTRUCTOR      */

ActivityVector::~ActivityVector() {
    delete activityList;
}










