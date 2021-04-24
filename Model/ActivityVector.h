//
// Created by Raluca Michela Buzamurga on 12/04/21.
//

#ifndef ACTIVITYTRACKER_ACTIVITYVECTOR_H
#define ACTIVITYTRACKER_ACTIVITYVECTOR_H
#include "Activity.h"
#include <vector>
#include "Date.h"


class ActivityVector {
private:
    std::vector<Activity> *activityList;
    std::vector<Activity>::iterator it;

public:
    ActivityVector();
    ActivityVector(ActivityVector const &activityVector);
    void addActivity(const Activity& activity);
    void deleteActivity(const Activity& activity);

    std::vector<std::string>* getActivitiesName();
    std::vector<Date>* getActivitiesDate();
    std::vector<ActivityTime>* getActivitiesStartTime();
    std::vector<ActivityTime>* getActivitiesEndTime();

    [[nodiscard]] std::vector<Activity> *getActivityList() const;
    std::vector<Activity> getActivitesFromDay(Date day);

    ActivityVector *sort();

    ~ActivityVector();
};


#endif //ACTIVITYTRACKER_ACTIVITYVECTOR_H
