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
    [[nodiscard]] int getActivityMinute() const;


    void setActivityHour(int h);
    void setActivityMinute(int m);
    void setActivityTime(int h, int m);

    [[nodiscard]] bool isEqual(ActivityTime time) const;
    [[nodiscard]] bool isGraterThan(ActivityTime time) const;
    [[nodiscard]] bool isAcceptable() const;

};

#endif //ACTIVITYTRACKER_ACTIVITYTIME_H
