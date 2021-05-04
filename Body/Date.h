//
// Created by Raluca Michela Buzamurga on 06/04/21.
//

#ifndef ACTIVITYTRACKER_DATE_H
#define ACTIVITYTRACKER_DATE_H

#include "iostream"
#include <ctime>

class Date {

private:
    int year, month, day;
    bool acceptable;

    static bool isLeap(int y);
    static bool checkCurrentDay(int y, int m, int d);

public:
    Date();
    Date(int y, int m, int d);

    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);

    [[nodiscard]] int getYear() const;
    [[nodiscard]] int getMonth() const;
    [[nodiscard]] int getDay() const;

    void setActivityDate(int y, int m, int d);
    [[nodiscard]] std::string getDateString() const;
    [[nodiscard]] bool isAcceptable() const;

    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator<(const Date& other) const;

};

#endif //ACTIVITYTRACKER_DATE_H
