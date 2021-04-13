//
// Created by Raluca Michela Buzamurga on 09/04/21.
//

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
    if(h>=0 && h<=23)
        hour = h;
    else
        hour = 0;           // To generate out of range exception
}

void ActivityTime::setActivityMinute(int m) {
    if(m>=0 && m<=50)
        minute = m;
    else
        minute = 0;         // To generate out of range exception
}

int ActivityTime::getActivityHour() const {
    return hour;
}

int ActivityTime::getActivityMinute() const {
    return minute;
}


