//
// Created by Raluca Michela Buzamurga on 06/04/21.
//

#ifndef ACTIVITYTRACKER_DATE_H
#define ACTIVITYTRACKER_DATE_H


class Date {
private:
    int year, month, day;
    static bool isLeap(int y);

public:

    Date();
    Date(int y, int m, int d);

    [[nodiscard]] int getYear() const;
    void setYear(int y);

    [[nodiscard]] int getMonth() const;
    void setMonth(int m);

    [[nodiscard]] int getDay() const;
    void setDay(int d);

    void setActivityDay(int y, int m, int d);
    [[nodiscard]] bool isEqual(Date d) const;

};

#endif //ACTIVITYTRACKER_DATE_H
