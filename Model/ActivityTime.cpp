//
// Created by Raluca Michela Buzamurga on 09/04/21.
//

#include <stdexcept>
#include <iostream>
#include "ActivityTime.h"

ActivityTime::ActivityTime() {
    hour=0;
    minute=0;
}

ActivityTime::ActivityTime(int h, int m) {
    hour=0;
    minute=0;
    setActivityTime(h, m);
}

void ActivityTime::setActivityTime(int h, int m) {
    setActivityHour(h);
    setActivityMinute(m);
}

void ActivityTime::setActivityHour(int h) {
    try {
        if (h >= 0 && h <= 23)
            hour = h;
        else
            throw std::out_of_range("Invalid hour");
    }catch(std::out_of_range){
        std::cout << "Invalidi hour here";
    }
}

void ActivityTime::setActivityMinute(int m) {
    try {
        if (m >= 0 && m <= 50)
            minute = m;
        else
            throw std::out_of_range("Invalid minute");
    }catch(std::out_of_range){
        std::cout << "Invalid minute here";
    }
}

int ActivityTime::getActivityHour() const {
    return hour;
}

int ActivityTime::getActivityMinute() const {
    return minute;
}

bool ActivityTime::isEqual(ActivityTime time) const {
    if(time.getActivityHour() == this->hour && time.getActivityMinute() == this->minute)
        return true;
    else
        return false;
}


