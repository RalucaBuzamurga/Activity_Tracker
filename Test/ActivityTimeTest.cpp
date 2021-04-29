//
// Created by Raluca Michela Buzamurga on 22/04/21.
//

#include "gtest/gtest.h"
#include "Model/ActivityTime.h"


class ActivityTimeTest : public ::testing::Test {
protected:
    virtual void setUp() {
        time = ActivityTime();
        time1 = ActivityTime();
    }

    ActivityTime time;
    ActivityTime time1;
};

TEST_F(ActivityTimeTest, testActivityHour) {
    ASSERT_EQ(time.getActivityHour(), -1);
    time.setActivityHour(24);
    ASSERT_EQ(time.getActivityHour(), -1);
    time.setActivityHour(15);
    ASSERT_EQ(time.getActivityHour(), 15);
}

TEST_F(ActivityTimeTest, testActivityMinute) {
    ASSERT_EQ(time.getActivityMinute(), -1);
    time.setActivityMinute(60);
    ASSERT_EQ(time.getActivityMinute(), -1);
    time.setActivityMinute(59);
    ASSERT_EQ(time.getActivityMinute(), 59);
}

TEST_F(ActivityTimeTest, setActivityTime) {
    time.setActivityTime(-1, 128);
    ASSERT_EQ(time.getActivityHour(), -1);
    ASSERT_EQ(time.getActivityMinute(), -1);
    time.setActivityTime(24, 60);
    ASSERT_EQ(time.getActivityHour(), -1);
    ASSERT_EQ(time.getActivityMinute(), -1);
    time.setActivityTime(23, 59);
    ASSERT_EQ(time.getActivityHour(), 23);
    ASSERT_EQ(time.getActivityMinute(), 59);
}

TEST_F(ActivityTimeTest, isEqualTest) {
    time.setActivityTime(12, 30);
    time1.setActivityTime(12, 30);
    ASSERT_TRUE(time.isEqual(time1));
}

TEST_F(ActivityTimeTest, isGraterThan) {
    time.setActivityTime(12, 30);
    time1.setActivityTime(12, 31);
    ASSERT_TRUE(time1.isGraterThan(time));

    time1.setActivityTime(12, 31);
    ASSERT_TRUE(time1.isGraterThan(time));

    time1.setActivityTime(13, 30);
    ASSERT_TRUE(time1.isGraterThan(time));
}

TEST_F(ActivityTimeTest, isAcceptable) {
    time.setActivityTime(12, 30);
    ASSERT_TRUE(time.isAcceptable());
    time.setActivityTime(12, 60);
    ASSERT_FALSE(time.isAcceptable());
    time.setActivityTime(24, 00);
    ASSERT_FALSE(time.isAcceptable());
}