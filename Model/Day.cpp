//
// Created by Raluca Michela Buzamurga on 06/04/21.
//

#include "Day.h"
#include<stdexcept>
#include <iostream>

Day::Day(int y, int m, int d){
    year = 0;
    month = 0;
    day = 0;
    setYear(y);
    setMonth(m);
    setDay(d);
}

Day::Day(){
    year=0;
    month=0;
    day=0;
}


bool Day::isLeap(int y) {
    if( ((y/400)%2 == 0) || ((y/4)%2 == 0 && (y/100)%2 !=0) )
        return true;
    else
        return false;
}

int Day::getYear() const{
    return year;
}

void Day::setYear(int y) {
    try {
        if (y >= 1990)
            year = y;
        else
            throw std::out_of_range("Invalid year");
    }catch(std::out_of_range){
        std::cout << "Invalid year here";
    }
}

int Day::getMonth() const{
    return month;
}

void Day::setMonth(int m) {
    try {
        if (m >= 0 && m <= 12)
            month = m;
        else
            throw std::out_of_range("Invalid month");
    }catch(std::out_of_range){
        std::cout << "Invalid month here";
    }
}

int Day::getDay() const{
    return day;
}

void Day::setDay(int d) {
    try {
        if ((d > 31) || (Day::month == 2 && d >= 29 && !Day::isLeap(day)) ||
            (d == 31 && (Day::month == 4 || Day::month == 6 || Day::month == 9 || Day::month == 11)))
            throw std::out_of_range("Invalid day");
        else
            day = d;
    }catch(std::out_of_range){
        std::cout << "Invalid day here";
    }
}

void Day::setActivityDay(int y, int m, int d) {
    Day::setYear(y);
    Day::setMonth(m);
    Day::setDay(d);
}

bool Day::isEqual(Day d) const {
    if(d.getYear()==this->getYear() && d.getMonth() == this->getMonth() && d.getDay() == this->getDay())
        return true;
    else
        return false;
}
