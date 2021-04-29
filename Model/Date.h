//
// Created by Raluca Michela Buzamurga on 06/04/21.
//

#ifndef ACTIVITYTRACKER_DATE_H
#define ACTIVITYTRACKER_DATE_H


class Date {
private:
    int year, month, day;
    static bool isLeap(int y);
    bool acceptable;

public:

    Date();
    Date(int y, int m, int d);

    [[nodiscard]] int getYear() const;
    [[nodiscard]] int getMonth() const;
    [[nodiscard]] int getDay() const;

    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);

    void setActivityDay(int y, int m, int d);
    [[nodiscard]] bool isEqual(Date d) const;
    bool isGraterThan(Date d) const;
    bool isAcceptable() const;
};

#endif //ACTIVITYTRACKER_DATE_H
