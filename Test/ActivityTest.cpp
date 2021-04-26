//
// Created by Raluca Michela Buzamurga on 26/04/21.
//

#include "gtest/gtest.h"
#include "Model/Activity.h"

class ActivityTest : public ::testing::Test{
protected:
    virtual void setUp(){
        activity1 = Activity();
        activity2 = Activity();
    }
    Activity activity1;
    Activity activity2;

    Date date1 = Date(2020, 4, 21);
    Date date2 = Date(2020, 4, 22);

    ActivityTime time1 = ActivityTime(12, 30);
    ActivityTime time2 = ActivityTime(13, 30);
    ActivityTime time3 = ActivityTime(14, 30);
};

TEST_F(ActivityTest, isEqualTest){
    activity1.setActivity("Camminata", date1, time1, time3);
    activity2.setActivity("Camminata", date1, time1, time3);
    ASSERT_TRUE(activity1.isEqual(activity2));

    activity2.setActivity("Camminata", date1, time1, time2);
    ASSERT_FALSE(activity1.isEqual(activity2));
}

TEST_F(ActivityTest, isDayEqualTest){
    activity1.setActivity("Camminata", date1, time1, time3);
    activity2.setActivity("Corsa", date1, time2, time3);

    ASSERT_TRUE(activity1.isDayEqual(activity2));
    activity2.setActivity("Corsa", date2, time2, time3);
    ASSERT_FALSE(activity1.isDayEqual(activity2));
}

TEST_F(ActivityTest, isStartTimeEqual){
    activity1.setActivity("Camminata", date1, time1, time3);
    activity2.setActivity("Corsa", date2, time1, time2);

    ASSERT_TRUE(activity1.isStartTimeEqual(activity2));
    activity2.setActivity("Corsa", date2, time2, time3);
    ASSERT_FALSE(activity1.isStartTimeEqual(activity2));
}