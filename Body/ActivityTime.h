//
// Created by Raluca Michela Buzamurga on 09/04/21.
//

#ifndef ACTIVITYTRACKER_ACTIVITYTIME_H
#define ACTIVITYTRACKER_ACTIVITYTIME_H

#include <iostream>

class ActivityTime {

private:
    int hour;
    int minute;
    bool acceptable;

public:
    ActivityTime();
    ActivityTime(int h, int m);

    void setActivityHour(int h);
    void setActivityMinute(int m);

    [[nodiscard]] int getActivityHour() const;
    [[nodiscard]] int getActivityMinute() const;

    void setActivityTime(int h, int m);
    [[nodiscard]] bool isAcceptable() const;
    std::string getTimeString();

    bool operator==(const ActivityTime& other) const;
    bool operator!=(const ActivityTime& other) const;
    bool operator>(const ActivityTime& other) const;
    bool operator<(const ActivityTime& other) const;

};

#endif //ACTIVITYTRACKER_ACTIVITYTIME_H
