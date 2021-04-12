//
// Created by Raluca Michela Buzamurga on 04/04/21.
//

#ifndef ACTIVITYTRACKER_ACTIVITY_H
#define ACTIVITYTRACKER_ACTIVITY_H

#include <iostream>
#include "Day.h"
#include "ActivityTime.h"

class Activity {
private:
    std::string activityName;
    Day activityDay;
    ActivityTime startTime, endTime;

public:

    Activity();
    Activity(std::string name, Day day, ActivityTime start, ActivityTime end);

    void setName(std::string name);
    void setStartTime(ActivityTime start);
    void setEndTime(ActivityTime end);
    void setDay(Day day);

    std::string getName();
    ActivityTime getStartTime();
    ActivityTime getEndTime();
    Day getDay();
};


#endif //ACTIVITYTRACKER_ACTIVITY_H
