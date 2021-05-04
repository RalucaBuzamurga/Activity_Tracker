//
// Created by Raluca Michela Buzamurga on 06/04/21.
//

#include "Date.h"
#include <stdexcept>

Date::Date(int y, int m, int d) {
    year = 0;
    month = 0;
    day = 0;
    acceptable = true;

    setYear(y);
    setMonth(m);
    setDay(d);

    if(acceptable && !checkCurrentDay(year, month, day))
        acceptable = false;
}

Date::Date() {
    year = 0;
    month = 0;
    day = 0;
    acceptable = false;
}

bool Date::isLeap(int y) {
    if( ((y / 400) % 2 == 0) || ( ((y / 4) % 2 == 0) && ((y / 100) % 2 != 0)) )
        return true;

    else
        return false;
}

bool Date::checkCurrentDay(int y, int m, int d) {
    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);

    if( ( y < now->tm_year + 1900) ||
        (y == now->tm_year + 1900) && ( (m < now->tm_mon + 1) || ( (m == now->tm_mon + 1) && (d <= now->tm_mday) )))
        return true;

    else
        return false;
}


void Date::setYear(int y) {

    try {
        if(y > 1990) {
            year = y;

            if( (month != 0) && (day != 0) )
                acceptable = true;
        }

        else {
            throw std::out_of_range("Invalid year");
        }
    } catch (std::out_of_range &) {
        year = 0;
        acceptable = false;
    }

}

void Date::setMonth(int m) {

    try {
        if( (m > 0) && (m <= 12) ) {
            month = m;

            if( (year != 0) && (day != 0) )
                acceptable = true;
        }

        else
            throw std::out_of_range("Invalid month");
    } catch (std::out_of_range &) {
        month = 0;
        acceptable = false;
    }

}

void Date::setDay(int d) {

    try {
        if( (d > 31 || d < 1) ||
            (month == 2 && d > 28 && !isLeap(year)) ||
            ( (d == 31) && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11) ) )
            throw std::out_of_range("Invalid day");

        else
            day = d;

        if(year != 0 && month != 0) {;
            acceptable = true;
        }
    } catch (std::out_of_range &) {
        day = 0;
        acceptable = false;
    }
}

void Date::setActivityDate(int y, int m, int d) {
    acceptable = true;

    setYear(y);
    setMonth(m);
    setDay(d);

    if(acceptable && !checkCurrentDay(y, m, d) )
        acceptable = false;
}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

std::string Date::getDateString() const {
    std::string date;

    date += std::to_string(year);
    date += " / ";
    date += std::to_string(month);
    date += " / ";
    date += std::to_string(day);

    return date;
}

bool Date::isAcceptable() const {
    return acceptable;
}

bool Date::operator==(const Date &other) const {
    if( (other.getYear() == year) && (other.getMonth() == month) && (other.getDay() == day) )
        return true;

    else
        return false;
}

bool Date::operator!=(const Date &other) const {
    if( (other.getYear() != year) || (other.getMonth() != month) || (other.getDay() != day) )
        return true;

    else
        return false;
}

bool Date::operator>(const Date &other) const {
    if( (year > other.getYear()) ||
        ( (year == other.getYear()) && ( (month > other.getMonth()) || ( (month == other.getMonth()) && (day > other.getDay()) ))))
        return true;

    else
        return false;
}

bool Date::operator<(const Date &other) const {
    if( year < other.getYear() ||
        ( (year == other.getYear()) && ( (month < other.getMonth()) || ( (month == other.getMonth()) && (day < other.getDay()) ))))
        return true;

    else
        return false;
}