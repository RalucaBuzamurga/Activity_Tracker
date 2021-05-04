//
// Created by Raluca Michela Buzamurga on 09/04/21.
//

#include "ActivityTime.h"
#include <stdexcept>

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
        if( (h >= 0) && (h <= 23) && (h != -1) ) {
            hour = h;

            if(minute != -1)
                acceptable = true;
        } else {
            throw std::out_of_range("Invalid hour");
        }

    } catch (std::out_of_range &) {
        acceptable = false;
        hour = -1;
    }

}

void ActivityTime::setActivityMinute(int m) {

    try {
        if( (m >= 0) && (m <= 59) && (m != -1) ) {
            minute = m;

            if (hour != -1)
                acceptable = true;
        } else {
            throw std::out_of_range("Invalid minute");
        }

    } catch (std::out_of_range &) {
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

bool ActivityTime::operator==(const ActivityTime &other) const {
    if( (hour == other.hour) && (minute == other.minute) )
        return true;
    else
        return false;
}

bool ActivityTime::operator!=(const ActivityTime &other) const {
    if( (hour != other.hour) || (minute != other.minute) )
        return true;
    else
        return false;
}

bool ActivityTime::isAcceptable() const {
    return acceptable;
}

std::string ActivityTime::getTimeString() {
    std::string time;

    time += std::to_string(hour);
    time += " : ";
    time += std::to_string(minute);

    return time;
}

bool ActivityTime::operator>(const ActivityTime &other) const {
    if( (hour > other.hour) ||
        ((hour == other.hour) && (minute > other.minute)) )
        return true;
    else
        return false;
}

bool ActivityTime::operator<(const ActivityTime &other) const {
    if( (hour < other.hour) ||
        ((hour == other.hour) && (minute < other.minute)) )
        return true;
    else
        return false;
}