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
    void addActivity(const Activity& activity);

    [[nodiscard]] std::vector<Activity> *getActivityList() const;

    std::vector<Activity> getActivitesFromDay(Date day);

    void deleteActivity(const Activity& activity);



    ~ActivityVector();
};


#endif //ACTIVITYTRACKER_ACTIVITYVECTOR_H
