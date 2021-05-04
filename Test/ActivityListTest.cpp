//
// Created by Raluca Michela Buzamurga on 30/04/21.
//

#include "gtest/gtest.h"
#include "Body/ActivityList.h"
#include "Body/Activity.h"
#include "Body/Date.h"
#include "Body/ActivityTime.h"
#include <list>

class ActivityListTest : public ::testing::Test {

protected:
    virtual void SetUp() {
        activityList = ActivityList();
        tmpList = std::list<Activity>();

        activityList.addActivity(activity1);
        activityList.addActivity(activity3);

        tmpList.push_back(activity1);
        tmpList.push_back(activity3);
    }

    ActivityList activityList;
    std::list<Activity> tmpList;

    Date date1 = Date(2021, 4, 11);
    Date date2 = Date(2021, 3, 12);

    ActivityTime time1 = ActivityTime(12, 30);
    ActivityTime time2 = ActivityTime(13, 30);
    ActivityTime time3 = ActivityTime(14, 30);

    Activity activity1 = Activity("Corsa", date1, time1, time2);
    Activity activity2 = Activity("Camminata", date1, time2, time3);
    Activity activity3 = Activity("Corsa", date2, time1, time3);
};

TEST_F(ActivityListTest, addActivityTest) {

    activityList.addActivity(activity2);
    ASSERT_NE(activityList.getActivityList(), tmpList);

    tmpList.push_back(activity2);
    ASSERT_EQ(activityList.getActivityList(), tmpList);
}

TEST_F(ActivityListTest, deleteActivityTest) {

    activityList.deleteActivity(activity1);
    ASSERT_NE(activityList.getActivityList(), tmpList);

    tmpList.remove(activity1);
    ASSERT_EQ(activityList.getActivityList(), tmpList);
}