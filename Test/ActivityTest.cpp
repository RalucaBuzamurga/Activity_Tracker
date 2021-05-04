//
// Created by Raluca Michela Buzamurga on 26/04/21.
//

#include "gtest/gtest.h"
#include "Body/Activity.h"

class ActivityTest : public ::testing::Test {
protected:
    void SetUp() override {
        activity1 = Activity("Camminata", date1, time1, time3);
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

TEST_F(ActivityTest, isEqualTest) {
    activity2.setActivity("Camminata", date1, time1, time3);
    ASSERT_TRUE(activity1==activity2);

    activity2.setActivity("Camminata", date1, time1, time2);
    ASSERT_FALSE(activity1==activity2);
}

TEST_F(ActivityTest, notEqualTest) {
    activity2.setActivity("Camminata", date1, time1, time2);
    ASSERT_TRUE(activity1 != activity2);

    activity2.setActivity("Camminata", date1, time2, time3);
    ASSERT_TRUE(activity1 != activity2);

    activity2.setActivity("Camminata", date2, time1, time3);
    ASSERT_TRUE(activity1 != activity2);

    activity2.setActivity("Corsa", date2, time1, time3);
    ASSERT_TRUE(activity1 != activity2);

    activity2.setActivity("Camminata", date1, time1, time3);
    ASSERT_FALSE(activity1!=activity2);
}