//
// Created by Raluca Michela Buzamurga on 09/04/21.
//

#ifndef ACTIVITYTRACKER_ACTIVITYTIME_H
#define ACTIVITYTRACKER_ACTIVITYTIME_H


class ActivityTime {
private:
    int hour;
    int minute;

public:
    ActivityTime();
    ActivityTime(int h, int m);

    int getActivityHour() const;
    void setActivityHour(int h);

    int getActivityMinute() const;
    void setActivityMinute(int m);

    void setActivityTime(int h, int m);

};


#endif //ACTIVITYTRACKER_ACTIVITYTIME_H
