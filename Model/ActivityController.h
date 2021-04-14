//
// Created by Raluca Michela Buzamurga on 12/04/21.
//

#ifndef ACTIVITYTRACKER_ACTIVITYCONTROLLER_H
#define ACTIVITYTRACKER_ACTIVITYCONTROLLER_H
#include "Activity.h"
#include <vector>
#include "Day.h"


class ActivityController {
private:
    std::vector<Activity> *activityList;
    std::vector<Activity>::iterator it;

public:
    ActivityController();
    void addActivity(const Activity& activity);

    [[nodiscard]] std::vector<Activity> *getActivityList() const;

    std::vector<Activity> getActivitesFromDay(Day day);

    void deleteActivity(const Activity& activity);



    ~ActivityController();
};


#endif //ACTIVITYTRACKER_ACTIVITYCONTROLLER_H
