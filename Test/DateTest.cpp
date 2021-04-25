//
// Created by Raluca Michela Buzamurga on 23/04/21.
//

#include "gtest/gtest.h"
#include "Model/Date.h"

class DateTest : public ::testing::Test{
protected:
    virtual void setUp(){
        date = Date();
        date1 = Date();
    }
    Date date;
    Date date1;
};

TEST_F(DateTest, leapYearTest){
    date.setActivityDay(2020, 2, 29);
    ASSERT_EQ(date.getYear(), 2020);
    ASSERT_EQ(date.getMonth(), 2);
    ASSERT_EQ(date.getDay(), 29);
}

TEST_F(DateTest, setDateTest){
    date.setActivityDay(2020, 4, 22);
    ASSERT_EQ(date.getYear(), 2020);
    ASSERT_EQ(date.getMonth(), 4);
    ASSERT_EQ(date.getDay(), 22);

    date.setActivityDay(2013, 5, 32);
    ASSERT_EQ(date.getYear(), 2013);
    ASSERT_EQ(date.getMonth(), 5);
    ASSERT_EQ(date.getDay(),  0);

    date.setActivityDay(0, 0, 0);
    ASSERT_EQ(date.getYear(), 0);
    ASSERT_EQ(date.getMonth(), 0);
    ASSERT_EQ(date.getDay(),  0);
}

TEST_F(DateTest, setterTests){
    date.setYear(1800);
    ASSERT_EQ(date.getYear(), 0);
    date.setMonth(13);
    ASSERT_EQ(date.getMonth(), 0);
    date.setDay(13);
    ASSERT_EQ(date.getDay(), 13);
}

TEST_F(DateTest, isEqualTest){
    date.setActivityDay(2020, 4, 22);
    date1.setActivityDay(2020, 4, 22);
    ASSERT_TRUE(date.isEqual(date1));
}

TEST_F(DateTest, isGraterThanTest){
    date.setActivityDay(2020, 2, 12);
    date1.setActivityDay(2020, 2, 13);
    ASSERT_TRUE(date1.isGraterThan(date));
    date1.setActivityDay(2021, 2, 13);
    ASSERT_TRUE(date1.isGraterThan(date));
    date1.setActivityDay(2020, 3, 12);
    ASSERT_TRUE(date1.isGraterThan(date));
}