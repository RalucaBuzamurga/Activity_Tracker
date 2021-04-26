//
// Created by Raluca Michela Buzamurga on 09/04/21.
//

#include <stdexcept>
#include "ActivityTime.h"

ActivityTime::ActivityTime() {
    hour = -1;
    minute = -1;
    acceptable = false;
}

ActivityTime::ActivityTime(int h, int m) {
    hour = -1;
    minute = -1;
    acceptable = true;
    setActivityHour(h);
    setActivityMinute(m);
}

void ActivityTime::setActivityTime(int h, int m) {
    acceptable = true;
    setActivityHour(h);
    setActivityMinute(m);
}

void ActivityTime::setActivityHour(int h) {
    try {
        if (h >= 0 && h <= 23)
            hour = h;
        else
            throw std::out_of_range("Invalid hour");
    }catch(std::out_of_range&){
        acceptable = false;
        hour = -1;
    }
}

void ActivityTime::setActivityMinute(int m) {
    try {
        if (m >= 0 && m <= 59)
            minute = m;
        else
            throw std::out_of_range("Invalid minute");
    }catch(std::out_of_range&){
        acceptable = false;
        minute = -1;
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

bool ActivityTime::isGraterThan(ActivityTime time) const {
    if(hour > time.hour || (hour == time.hour && minute > time.minute))
        return true;
    else
        return false;
}

bool ActivityTime::isAcceptable() const {
    return acceptable;
}