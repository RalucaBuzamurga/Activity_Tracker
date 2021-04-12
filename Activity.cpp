//
// Created by Raluca Michela Buzamurga on 04/04/21.
//


#include <utility>
#include "Activity.h"
using namespace std;

Activity::Activity() {
    activityName="";
    ActivityTime defaultTime(0, 0);
    Day defaultDay(0, 0, 0 );
    setStartTime(defaultTime);
    setEndTime(defaultTime);
    setDay(defaultDay);
}

Activity::Activity(std::string name, Day day, ActivityTime start, ActivityTime end) {
    activityName = std::move(name);
    activityDay = day;
    startTime = start;
    endTime = end;
}

std::string Activity::getName(){
    return activityName;
}
void Activity::setName(std::string name){
    activityName = std::move(name);
}

Day Activity::getDay(){
    return activityDay;
}
void Activity::setDay(Day day) {
    activityDay = day;
}

ActivityTime Activity::getStartTime(){
    return startTime;
}
void Activity::setStartTime(ActivityTime start) {
    startTime=start;
}

ActivityTime Activity::getEndTime(){
    return endTime;
}
void Activity::setEndTime(ActivityTime end) {
    endTime=end;
}