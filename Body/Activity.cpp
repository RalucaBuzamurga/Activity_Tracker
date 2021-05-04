//
// Created by Raluca Michela Buzamurga on 04/04/21.
//

#include "Activity.h"

using namespace std;

Activity::Activity() {
    ActivityTime defaultTime = ActivityTime();
    Date defaultDay = Date();

    setName("");
    setStartTime(defaultTime);
    setEndTime(defaultTime);
    setDay(defaultDay);
}

Activity::Activity(std::string name, Date day, ActivityTime start, ActivityTime end) {
    activityName = std::move(name);
    activityDay = day;
    startTime = start;
    endTime = end;
}

void Activity::setName(std::string name) {
    activityName = std::move(name);
}

void Activity::setDay(Date day) {
    activityDay = day;
}

void Activity::setStartTime(ActivityTime start) {
    startTime = start;
}

void Activity::setEndTime(ActivityTime end) {
    endTime = end;
}

std::string Activity::getName() {
    return activityName;
}

Date Activity::getDate() {
    return activityDay;
}

ActivityTime Activity::getStartTime() {
    return startTime;
}

ActivityTime Activity::getEndTime() {
    return endTime;
}

void Activity::setActivity(std::string name, Date day, ActivityTime start, ActivityTime end) {
    activityName = std::move(name);
    activityDay = day;
    startTime = start;
    endTime = end;
}

bool Activity::operator==(const Activity &other) const {

    if ( (activityDay == other.activityDay) && (startTime == other.startTime) && (endTime == other.endTime) && (activityName == other.activityName) )
        return true;

    else
        return false;
}

bool Activity::operator!=(const Activity &other) const {
    if ( (activityDay != other.activityDay) || (startTime != other.startTime) || (endTime != other.endTime) || (activityName != other.activityName) )
        return true;

    else
        return false;
}

bool Activity::operator>(const Activity &other) const {
    if( (activityDay>other.activityDay) || ( (activityDay==other.activityDay) && (startTime>other.startTime)) )
        return true;
    else
        return false;
}