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

/*
 * Il metodo sort riordina le attività in base al giorno (mostrando prima le attività più recenti)
 * Se il giorno è lo stesso, le riordina in base all'ora d'inizio (in ordine decrescente)
 * Se sia il giorno che l'ora d'inizio sono gli stessi, le riordina in base all'ora di fine (in ordine decrescente
 * mostra quindi l'attività durata di più in caso fosse iniziata alla stessa ora di un'altra)
 */

ActivityVector *ActivityVector::sort() {

    for(auto it = activityList->begin(); it<activityList->end()-1; ++it) {
        for (auto itr = it + 1; itr < activityList->end(); ++itr) {
            if (itr->getDay().isGraterThan(it->getDay()))
                std::swap(*itr, *it);
            else if (itr->isDayEqual(*it) && (itr->getStartTime().isGraterThan(it->getStartTime())))
                std::swap(*itr, *it);
            else if (itr->isDayEqual(*it) && (itr->isStartTimeEqual(*it)) &&
                     (itr->getEndTime().isGraterThan(it->getEndTime())))
                std::swap(*itr, *it);
        }
    }
    return this;
}


        /*      DESTRUCTOR      */

ActivityVector::~ActivityVector() {
    delete activityList;
}