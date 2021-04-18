//
// Created by Raluca Michela Buzamurga on 18/04/21.
//

#ifndef ACTIVITYTRACKER_SHOWACTIVITIESVIEW_H
#define ACTIVITYTRACKER_SHOWACTIVITIESVIEW_H


#include <vector>
#include <QLabel>
#include <Model/Date.h>
#include <Model/ActivityTime.h>

class ShowActivitiesView {
public:
    void showActivitiesName(std::vector<std::string>){}
    void showActivitiesDate(std::vector<Date>){}
    void showActivitiesStartTime(std::vector<ActivityTime>){}
    void showActivitiesEndTime(std::vector<ActivityTime>){}

};


#endif //ACTIVITYTRACKER_SHOWACTIVITIESVIEW_H
