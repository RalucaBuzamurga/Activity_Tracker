//
// Created by Raluca Michela Buzamurga on 09/04/21.
//

#include <stdexcept>
#include "ActivityTime.h"

ActivityTime::ActivityTime() {
    hour=0;
    minute=0;
}

ActivityTime::ActivityTime(int h, int m) {
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
        hour = 0;
    }
}

void ActivityTime::setActivityMinute(int m) {
    try {
        if (m >= 0 && m <= 59)
            minute = m;
        else
            throw std::out_of_range("Invalid minute");
    }catch(std::out_of_range){
        minute = 0;
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

bool ActivityTime::isGraterEqual(ActivityTime time) const {
    if(hour >= time.hour || (hour == time.hour && minute >= time.minute))
        return true;
    else
        return false;
}

