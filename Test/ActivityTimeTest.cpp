//
// Created by Raluca Michela Buzamurga on 22/04/21.
//

#include "gtest/gtest.h"
#include "Body/ActivityTime.h"


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

    time.setActivityHour(-2);
    ASSERT_EQ(time.getActivityHour(), -1);

    time.setActivityHour(0);
    ASSERT_EQ(time.getActivityHour(), 0);

    time.setActivityHour(15);
    ASSERT_EQ(time.getActivityHour(), 15);
}

TEST_F(ActivityTimeTest, testActivityMinute) {
    ASSERT_EQ(time.getActivityMinute(), -1);

    time.setActivityMinute(60);
    ASSERT_EQ(time.getActivityMinute(), -1);

    time.setActivityMinute(-2);
    ASSERT_EQ(time.getActivityMinute(), -1);

    time.setActivityMinute(0);
    ASSERT_EQ(time.getActivityMinute(), 0);

    time.setActivityMinute(59);
    ASSERT_EQ(time.getActivityMinute(), 59);
}

TEST_F(ActivityTimeTest, setActivityTime) {
    ASSERT_EQ(time.getActivityHour(), -1);
    ASSERT_EQ(time.getActivityMinute(), -1);

    time.setActivityTime(-2, -2);
    ASSERT_EQ(time.getActivityHour(), -1);
    ASSERT_EQ(time.getActivityMinute(), -1);

    time.setActivityTime(24, 60);
    ASSERT_EQ(time.getActivityHour(), -1);
    ASSERT_EQ(time.getActivityMinute(), -1);

    time.setActivityTime(0, 0);
    ASSERT_EQ(time.getActivityHour(), 0);
    ASSERT_EQ(time.getActivityMinute(), 0);

    time.setActivityTime(23, 59);
    ASSERT_EQ(time.getActivityHour(), 23);
    ASSERT_EQ(time.getActivityMinute(), 59);
}

TEST_F(ActivityTimeTest, equalOperatorTest) {
    time.setActivityTime(12, 30);
    time1.setActivityTime(12, 30);
    ASSERT_TRUE(time == time1);

    time.setActivityTime(12, 30);
    time1.setActivityTime(12, 31);
    ASSERT_FALSE(time == time1);

    time.setActivityTime(12, 30);
    time1.setActivityTime(13, 30);
    ASSERT_FALSE(time == time1);
}

TEST_F(ActivityTimeTest, notEqualOperatorTest) {
    time.setActivityTime(12, 30);
    time1.setActivityTime(12, 31);
    ASSERT_TRUE(time != time1);

    time.setActivityTime(12, 30);
    time1.setActivityTime(13, 30);
    ASSERT_TRUE(time != time1);

    time.setActivityTime(12, 30);
    time1.setActivityTime(12, 30);
    ASSERT_FALSE(time != time1);
}

TEST_F(ActivityTimeTest, graterOperatorTest) {
    time.setActivityTime(12, 30);
    time1.setActivityTime(12, 30);
    ASSERT_FALSE(time1 > time);

    time1.setActivityTime(12, 31);
    ASSERT_TRUE(time1 > time);

    time1.setActivityTime(13, 30);
    ASSERT_TRUE(time1 > time);
}

TEST_F(ActivityTimeTest, lessOperatorTest){
    time.setActivityTime(12, 30);
    time1.setActivityTime(12, 30);
    ASSERT_FALSE(time1 < time);

    time1.setActivityTime(12, 29);
    ASSERT_TRUE(time1 < time);

    time1.setActivityTime(11, 30);
    ASSERT_TRUE(time1 < time);
}

TEST_F(ActivityTimeTest, isAcceptableTest) {
    time.setActivityTime(12, 30);
    ASSERT_TRUE(time.isAcceptable());

    time.setActivityTime(12, 60);
    ASSERT_FALSE(time.isAcceptable());

    time.setActivityTime(24, 0);
    ASSERT_FALSE(time.isAcceptable());
}