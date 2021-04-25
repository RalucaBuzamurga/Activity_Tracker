//
// Created by Raluca Michela Buzamurga on 23/04/21.
//


#include "gtest/gtest.h"
#include "Model/ActivityVector.h"
#include <vector>


class ActivityVectorTest : public ::testing::Test{
protected:

    ActivityVector* activities;
    std::vector<Activity>* activities1;
    std::vector<Date>* dates;
    std::vector<ActivityTime>* startTimes;
    std::vector<ActivityTime>* endTimes;

    Date date1 = Date(2020, 4, 21);
    Date date2 = Date(2020, 4, 22);

    ActivityTime time1 = ActivityTime(12, 30);
    ActivityTime time2 = ActivityTime(13, 30);
    ActivityTime time3 = ActivityTime(14, 30);

    Activity activity1 = Activity("Corsa", date1, time1, time2);
    Activity activity2 = Activity("Camminata", date2, time1, time2);
    Activity activity3 = Activity("Corsa", date2, time2, time3);

    void SetUp() override{
        activities= new ActivityVector;
        activities1 = new std::vector<Activity>;

        activities->addActivity(activity1);
        activities->addActivity(activity2);
        activities->addActivity(activity3);

        dates = activities->getActivitiesDate();
        startTimes = activities->getActivitiesStartTime();
        endTimes = activities->getActivitiesEndTime();
    }

    void TearDown() override{
        delete activities;
        delete activities1;
        delete dates;
        delete startTimes;
        delete endTimes;
    }
};

TEST_F(ActivityVectorTest, addActivityTest) {
    activities1->push_back(activity1);
    activities1->push_back(activity2);
    activities1->push_back(activity3);

    ASSERT_EQ(activities->getActivityList()->size(), activities1->size());
    auto it = activities->getActivityList()->begin();
    auto itr = activities1->begin();

    while(it < activities->getActivityList()->end() && itr < activities1->end()){
        ASSERT_TRUE(it->isEqual(*itr));
        ++it;
        ++itr;
    }
}

TEST_F(ActivityVectorTest, deleteActivityTest){
    activities1->push_back(activity1);
    activities1->push_back(activity2);
    activities1->push_back(activity3);

    activities->deleteActivity(activity1);
    activities1->erase(activities1->begin());

    auto it = activities->getActivityList()->begin();
    auto itr = activities1->begin();

    while(it < activities->getActivityList()->end() && itr < activities1->end()){
        ASSERT_TRUE(it->isEqual(*itr));
        ++it;
        ++itr;
    }
}

TEST_F(ActivityVectorTest, copyConstructorTest){

    ActivityVector activities3 = ActivityVector(*activities);
    ASSERT_EQ(activities3.getActivityList()->size(), 3);
    auto it = activities->getActivityList()->begin();
    auto itr = activities3.getActivityList()->begin();

    while(it < activities->getActivityList()->end() && itr < activities3.getActivityList()->end()){
        ASSERT_TRUE(it->isEqual(*itr));
        ++it;
        ++itr;
    }
}

TEST_F(ActivityVectorTest, getActivitiesNameTest){
    auto names = std::vector<std::string>();
    names.emplace_back("Corsa");
    names.emplace_back("Camminata");
    names.emplace_back("Corsa");

    auto it = activities->getActivityList()->begin();
    auto itr = names.begin();
    while(it < activities->getActivityList()->end() && itr < names.end()){
        EXPECT_TRUE(it->getName() == *itr);
        ++it;
        ++itr;
    }
}

TEST_F(ActivityVectorTest, getActivitiesDateTest){
    auto date = std::vector<Date>();
    date.push_back(date1);
    date.push_back(date2);
    date.push_back(date2);

    auto it = dates->begin();
    auto itr = date.begin();

    while(it < dates->end() && itr < date.end()){
        ASSERT_TRUE(itr->isEqual(*it));
        ++it;
        ++itr;
    }
}

TEST_F(ActivityVectorTest, getActivitiesStartTimeTest){
    auto startTime = std::vector<ActivityTime>();
    startTime.push_back(time1);
    startTime.push_back(time1);
    startTime.push_back(time2);


    auto it = startTime.begin();
    auto itr = startTimes->begin();

    while(it<startTime.end() && itr<startTimes->end()){
        ASSERT_TRUE(itr->isEqual(*it));
        ++it;
        ++itr;
    }
}

TEST_F(ActivityVectorTest, getActivitiesEndTimeTest){
    auto endTime = std::vector<ActivityTime>();
    endTime.push_back(time2);
    endTime.push_back(time2);
    endTime.push_back(time3);

    auto it = endTime.begin();
    auto itr = endTimes->begin();

    while(it < endTime.end() && itr < endTimes->end()){
        ASSERT_TRUE(itr->isEqual(*it));
        ++it;
        ++itr;
    }
}

TEST_F(ActivityVectorTest, sortTest){
    activities1->push_back(activity2);
    activities1->push_back(activity3);
    activities1->push_back(activity1);

    activities->sort();

    auto it = activities->getActivityList()->begin();
    auto itr = activities1->begin();

    while(it < activities->getActivityList()->end() && itr < activities1->end()){
        ASSERT_TRUE(it->isEqual(*itr));
        ++it;
        ++itr;
    }
}