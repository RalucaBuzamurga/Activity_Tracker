//
// Created by Raluca Michela Buzamurga on 06/04/21.
//

#include "Date.h"
#include<stdexcept>

Date::Date(int y, int m, int d){
    year = 0;
    month = 0;
    day = 0;
    acceptable = true;
    setYear(y);
    setMonth(m);
    setDay(d);
}

Date::Date(){
    year = 0;
    month = 0;
    day = 0;
    acceptable = false;
}


bool Date::isLeap(int y) {
    if( ((y/400)%2 == 0) || ((y/4)%2 == 0 && (y/100)%2 !=0) )
        return true;
    else
        return false;
}

int Date::getYear() const{
    return year;
}

void Date::setYear(int y) {
    try {
        if (y >= 1990) {
            year = y;
            if(month != 0 && day != 0)
                acceptable = true;
        }
        else
            throw std::out_of_range("Invalid year");
    }catch(std::out_of_range&){
        acceptable = false;
        year = 0;
    }
}

int Date::getMonth() const{
    return month;
}

void Date::setMonth(int m) {
    try {
        if (m >= 0 && m <= 12 && m != 0) {
            month = m;
            if (year != 0 && day != 0)
                acceptable = true;
        }
        else
            throw std::out_of_range("Invalid month");
    }catch(std::out_of_range&){
        acceptable = false;
        month = 0;
    }
}

int Date::getDay() const{
    return day;
}

void Date::setDay(int d) {
    try {
        if ((d > 31) || (d < 1) || (Date::month == 2 && d > 28 && !Date::isLeap(year)) ||
            (d == 31 && (Date::month == 2 || Date::month == 4 || Date::month == 6 || Date::month == 9 || Date::month == 11)))
            throw std::out_of_range("Invalid day");
        else {
            day = d;
            if(year != 0 && month != 0)
                acceptable = true;
        }
    }catch(std::out_of_range&){
        acceptable = false;
        day = 0;
    }
}

void Date::setActivityDay(int y, int m, int d) {
    acceptable = true;
    Date::setYear(y);
    Date::setMonth(m);
    Date::setDay(d);
}

bool Date::isEqual(Date d) const {
    if(d.getYear()==this->getYear() && d.getMonth() == this->getMonth() && d.getDay() == this->getDay())
        return true;
    else
        return false;
}

bool Date::isGraterThan(Date d) const{
    if(year > d.getYear() || (year == d.getYear() && month > d.getMonth()) || (year == d.getYear() && month == d.getMonth() && day > d.getDay()))
        return true;
    else
        return false;
}

bool Date::isAcceptable() const {
    return acceptable;
}