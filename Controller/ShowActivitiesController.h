#ifndef SHOWACTIVITIES_H
#define SHOWACTIVITIES_H

#include <QMainWindow>
#include <QLabel>
#include "Model/ActivityVector.h"

namespace Ui {
class ShowActivities;
}

class ShowActivities : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShowActivities(QWidget *parent = nullptr);
    void showAllActivities(ActivityVector activityVector);
    ~ShowActivities() override;

public slots:
    void quit();

private:
    Ui::ShowActivities *ui;
    void showActivitiesName(std::vector<std::string>);
    void showActivitiesDate(std::vector<Date>);
    void showActivitiesStartTime(std::vector<ActivityTime>  activitiesStartTime);
    void showActivitiesEndTime(std::vector<ActivityTime> activitiesEndTime);
    ActivityVector activities;
};

#endif // SHOWACTIVITIES_H
