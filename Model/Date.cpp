//
// Created by Raluca Michela Buzamurga on 06/04/21.
//

#include "Date.h"
#include<stdexcept>
#include <iostream>

Date::Date(int y, int m, int d){
    year = 0;
    month = 0;
    day = 0;
    setYear(y);
    setMonth(m);
    setDay(d);
}

Date::Date(){
    year=0;
    month=0;
    day=0;
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
        if (y >= 1990)
            year = y;
        else
            throw std::out_of_range("Invalid year");
    }catch(std::out_of_range){
        year = 0;
    }
}

int Date::getMonth() const{
    return month;
}

void Date::setMonth(int m) {
    try {
        if (m >= 0 && m <= 12)
            month = m;
        else
            throw std::out_of_range("Invalid month");
    }catch(std::out_of_range){
        month = 0;
    }
}

int Date::getDay() const{
    return day;
}

void Date::setDay(int d) {
    try {
        if ((d > 31) || (Date::month == 2 && d >= 29 && !Date::isLeap(day)) ||
            (d == 31 && (Date::month == 4 || Date::month == 6 || Date::month == 9 || Date::month == 11)))
            throw std::out_of_range("Invalid day");
        else
            day = d;
    }catch(std::out_of_range){
        day = 0;
    }
}

void Date::setActivityDay(int y, int m, int d) {
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
