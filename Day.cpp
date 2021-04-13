//
// Created by Raluca Michela Buzamurga on 06/04/21.
//

#include "Day.h"

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
    if(y >= 1990)
        year = y;
    else
        year=0;            // to generate exception
}

int Day::getMonth() const{
    return month;
}

void Day::setMonth(int m) {
    if(m>=0 && m<=12)
        month = m;
    else
        month = 0;         // To generate exception
}

int Day::getDay() const{
    return day;
}

void Day::setDay(int d) {
    if ((d>31) || (Day::month == 2 && d>=29 && !Day::isLeap(day)) || (d==31 && (Day::month == 4 || Day::month == 6 || Day::month == 9 || Day::month==11)))
        day=0;
    else
        day=d;
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
