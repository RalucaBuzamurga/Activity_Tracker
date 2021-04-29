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

public:
    ActivityVector();
    ActivityVector(ActivityVector const &activityVector);

    std::vector<std::string>* getActivitiesName();
    std::vector<Date>* getActivitiesDate();
    std::vector<ActivityTime>* getActivitiesStartTime();
    std::vector<ActivityTime>* getActivitiesEndTime();
    [[nodiscard]] std::vector<Activity> *getActivityList() const;

    void addActivity(const Activity& activity);
    void deleteActivity(const Activity& activity);

    ActivityVector* sort();

    ~ActivityVector();

};

#endif //ACTIVITYTRACKER_ACTIVITYVECTOR_H
