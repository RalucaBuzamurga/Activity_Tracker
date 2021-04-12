//
// Created by Raluca Michela Buzamurga on 06/04/21.
//

#ifndef ACTIVITYTRACKER_DAY_H
#define ACTIVITYTRACKER_DAY_H


class Day {
private:
    int year, month, day;
    static bool isLeap(int y);

public:

    Day();
    Day(int y, int m, int d);

    int getYear() const;
    void setYear(int y);

    int getMonth() const;
    void setMonth(int m);

    int getDay() const;
    void setDay(int d);

    void setActivityDay(int y, int m, int d);
};

#endif //ACTIVITYTRACKER_DAY_H
