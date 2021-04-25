//
// Created by Raluca Michela Buzamurga on 04/04/21.
//

#ifndef ACTIVITYTRACKER_ACTIVITY_H
#define ACTIVITYTRACKER_ACTIVITY_H

#include <iostream>
#include "Date.h"
#include "ActivityTime.h"

class Activity {
private:
    std::string activityName;
    Date activityDay;
    ActivityTime startTime, endTime;

public:

    Activity();
    Activity(std::string name, Date day, ActivityTime start, ActivityTime end);

    void setName(std::string name);
    void setStartTime(ActivityTime start);
    void setEndTime(ActivityTime end);
    void setDay(Date day);
    void setActivity(Activity);

    const std::string getName();
    ActivityTime getStartTime();
    ActivityTime getEndTime();
    const Date getDay();
    bool isDayEqual(Activity activity);
    bool isEqual(Activity activity);
    bool isStartTimeEqual(Activity activity);
};


#endif //ACTIVITYTRACKER_ACTIVITY_H
