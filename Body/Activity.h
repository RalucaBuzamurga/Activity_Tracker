//
// Created by Raluca Michela Buzamurga on 04/04/21.
//

#ifndef ACTIVITYTRACKER_ACTIVITY_H
#define ACTIVITYTRACKER_ACTIVITY_H

#include "Date.h"
#include "ActivityTime.h"
#include <iostream>

class Activity {

private:
    std::string activityName;
    Date activityDay;
    ActivityTime startTime, endTime;

public:
    Activity();
    Activity(std::string name, Date day, ActivityTime start, ActivityTime end);

    void setName(std::string name);
    void setStartTime(ActivityTime start);
    void setEndTime(ActivityTime end);
    void setDay(Date day);
    void setActivity(std::string name, Date day, ActivityTime start, ActivityTime end);

    std::string getName();
    ActivityTime getStartTime();
    ActivityTime getEndTime();
    Date getDate();

    bool operator==(const Activity& other) const;
    bool operator!=(const Activity& other) const;

    /* L'operatore > è utilizzato nel metodo sort() della classe ActivityList
     * per effettuare l'ordinamento della lista di attività
     * in ordine decrescente in base a data e ora
     */

    bool operator>(const Activity& other) const;
};

#endif //ACTIVITYTRACKER_ACTIVITY_H