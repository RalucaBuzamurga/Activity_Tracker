//
// Created by Raluca Michela Buzamurga on 23/04/21.
//

#include "gtest/gtest.h"
#include "Body/Date.h"

class DateTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        date1 = Date(2020, 4, 22);
        date2 = Date();
    }

    Date date1;
    Date date2;
};

TEST_F(DateTest, setYearTest) {
    date2.setYear(1900);
    ASSERT_EQ(date2.getYear(), 0);

    date2.setYear(2021);
    ASSERT_EQ(date2.getYear(), 2021);

}

TEST_F(DateTest, setMonthTest) {
    date2.setMonth(-1);
    ASSERT_EQ(date2.getMonth(), 0);

    date2.setMonth(13);
    ASSERT_EQ(date2.getMonth(), 0);

    date2.setMonth(1);
    ASSERT_EQ(date2.getMonth(), 1);

    date2.setMonth(12);
    ASSERT_EQ(date2.getMonth(), 12);

}

TEST_F(DateTest, setDayTest){
    date2.setDay(-1);
    ASSERT_EQ(date2.getDay(), 0);

    date2.setDay(32);
    ASSERT_EQ(date2.getDay(), 0);

    date2.setDay(1);
    ASSERT_EQ(date2.getDay(), 1);

    date2.setDay(31);
    ASSERT_EQ(date2.getDay(), 31);

}

TEST_F(DateTest, setDateTest) {

    date2.setActivityDate(-1, -1, -1);
    ASSERT_EQ(date2.getYear(), 0);
    ASSERT_EQ(date2.getMonth(), 0);
    ASSERT_EQ(date2.getDay(), 0);

    date2.setActivityDate(1800, 11, 3);
    ASSERT_EQ(date2.getYear(), 0);
    ASSERT_EQ(date2.getMonth(), 11);
    ASSERT_EQ(date2.getDay(), 3);

    date2.setActivityDate(2021, 13, 3);
    ASSERT_EQ(date2.getYear(), 2021);
    ASSERT_EQ(date2.getMonth(), 0);
    ASSERT_EQ(date2.getDay(), 3);

    date2.setActivityDate(2013, 5, 32);
    ASSERT_EQ(date2.getYear(), 2013);
    ASSERT_EQ(date2.getMonth(), 5);
    ASSERT_EQ(date2.getDay(), 0);

    date2.setActivityDate(2021, 2, 29);
    ASSERT_EQ(date2.getYear(), 2021);
    ASSERT_EQ(date2.getMonth(), 2);
    ASSERT_EQ(date2.getDay(), 0);

    date2.setActivityDate(2021, 4, 22);
    ASSERT_EQ(date2.getYear(), 2021);
    ASSERT_EQ(date2.getMonth(), 4);
    ASSERT_EQ(date2.getDay(), 22);

}

TEST_F(DateTest, equalOperatorTest) {

    date2.setActivityDate(2020, 4, 23);
    ASSERT_FALSE(date2==date1);

    date2.setActivityDate(2020, 3, 22);
    ASSERT_FALSE(date2==date1);

    date2.setActivityDate(2019, 4, 22);
    ASSERT_FALSE(date2==date1);

    date2.setActivityDate(2020, 4, 22);
    ASSERT_TRUE(date2==date1);
}

TEST_F(DateTest, notEqualOperatorTest) {

    date2.setActivityDate(2020, 4, 22);
    ASSERT_FALSE(date2!=date1);

    date2.setActivityDate(2020, 4, 23);
    ASSERT_TRUE(date2!=date1);

    date2.setActivityDate(2020, 3, 22);
    ASSERT_TRUE(date2!=date1);

    date2.setActivityDate(2019, 4, 22);
    ASSERT_TRUE(date2!=date1);
}

TEST_F(DateTest, graterOperatorTest) {

    date2.setActivityDate(2020, 4, 23);
    ASSERT_TRUE(date2>date1);

    date2.setActivityDate(2020, 5, 22);
    ASSERT_TRUE(date2 > date1);

    date2.setActivityDate(2021, 4, 22);
    ASSERT_TRUE(date2 > date1);
}

TEST_F(DateTest, lessOperatorTest) {

    date2.setActivityDate(2020, 4, 21);
    ASSERT_TRUE(date2<date1);

    date2.setActivityDate(2020, 3, 22);
    ASSERT_TRUE(date2 < date1);

    date2.setActivityDate(2019, 4, 22);
    ASSERT_TRUE(date2 < date1);
}

TEST_F(DateTest, isAcceptableTest) {

    date2.setActivityDate(2020, 2, 28);
    ASSERT_TRUE(date2.isAcceptable());

    date2.setActivityDate(2020, 2, 31);
    ASSERT_FALSE(date2.isAcceptable());

    date2.setActivityDate(2020, 13, 2);
    ASSERT_FALSE(date2.isAcceptable());

    date2.setActivityDate(2020, 3, 123);
    ASSERT_FALSE(date2.isAcceptable());

    date2.setActivityDate(1800, 2, 3);
    ASSERT_FALSE(date2.isAcceptable());
}

TEST_F(DateTest, getDateStringTest){
    std::string str("2020 / 4 / 22");
    ASSERT_EQ(str, date1.getDateString());

    str = "2020/4/22";
    ASSERT_NE(date1.getDateString(), str);
}