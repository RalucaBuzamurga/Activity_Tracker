//
// Created by Raluca Michela Buzamurga on 04/04/21.
//


#include <utility>
#include "Activity.h"
using namespace std;

Activity::Activity() {
    activityName="";
    ActivityTime defaultTime(0, 0);
    Date defaultDay(0, 0, 0 );
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

const std::string Activity::getName(){
    return activityName;
}
void Activity::setName(std::string name){
    activityName = std::move(name);
}

const Date Activity::getDay(){
    return activityDay;
}
void Activity::setDay(Date day) {
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

bool Activity::isDayEqual(Activity activity) {
    if(activityDay.isEqual(activity.getDay()))
        return true;
    else
        return false;
}

bool Activity::isEqual(Activity activity) {
    if(activityDay.isEqual(activity.getDay()) && startTime.isEqual(activity.getStartTime()) &&
        endTime.isEqual(activity.getEndTime()) && activityName == activity.getName())
    {
        return true;
    }
    else
        return false;
}

void Activity::setActivity(Activity act) {
    activityName=act.activityName;
    activityDay=act.activityDay;
    startTime=act.startTime;
    endTime=act.endTime;
}