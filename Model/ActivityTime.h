//
// Created by Raluca Michela Buzamurga on 09/04/21.
//

#ifndef ACTIVITYTRACKER_ACTIVITYTIME_H
#define ACTIVITYTRACKER_ACTIVITYTIME_H

class ActivityTime {

private:
    int hour;
    int minute;
    bool acceptable;

public:
    ActivityTime();
    ActivityTime(int h, int m);

    [[nodiscard]] int getActivityHour() const;
    void setActivityHour(int h);

    [[nodiscard]] int getActivityMinute() const;
    void setActivityMinute(int m);

    void setActivityTime(int h, int m);

    [[nodiscard]] bool isEqual(ActivityTime time) const;
    bool isGraterEqual(ActivityTime time) const;
    bool isAcceptable();
    void setAcceeptable(bool accept);

};


#endif //ACTIVITYTRACKER_ACTIVITYTIME_H
