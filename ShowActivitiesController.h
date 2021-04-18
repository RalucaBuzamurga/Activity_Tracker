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
    std::vector<std::string>* activitiesName;
    std::vector<Date>* activitiesDate;
    std::vector<ActivityTime>* activitiesStartTime;
    std::vector<ActivityTime>* activitiesEndTime;
    Ui::ShowActivities *ui;
    ActivityVector activities;
};

#endif // SHOWACTIVITIES_H
