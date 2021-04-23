//
// Created by Raluca Michela Buzamurga on 23/04/21.
//

/*
#include "gtest/gtest.h"
#include "Model/ActivityVector.h"
#include <vector>


class ActivityVectorTest : public ::testing::Test{
protected:
    virtual void setUp(){
        activities = ActivityVector();
        date1 = Date(2020, 4, 22);
        date2 = Date(2020, 4, 23);
        time1 = ActivityTime(10, 30);
        time2 = ActivityTime(12, 0);
        time3 = ActivityTime(12, 30);
        activity1 = Activity("Corsa", date1, time1, time2);
        activity2 = Activity("Camminata", date2, time1, time2);
        activity3 = Activity("Camminata", date2, time2, time3);
    }
    ActivityVector activities;
    std::vector<Activity>* tmpVector = new std::vector<Activity>;

    Date date1 ;
    Date date2 ;

    ActivityTime time1 ;
    ActivityTime time2 ;
    ActivityTime time3 ;

    Activity activity1;
    Activity activity2;
    Activity activity3;
};

TEST_F(ActivityVectorTest, addActivityTest){
    activities.addActivity(activity1);
    activities.addActivity(activity2);
    activities.addActivity(activity3);

    tmpVector->push_back(activity1);
    tmpVector->push_back(activity2);
    tmpVector->push_back(activity3);

    ASSERT_EQ(tmpVector, activities);
} */