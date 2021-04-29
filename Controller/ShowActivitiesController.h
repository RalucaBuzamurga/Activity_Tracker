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

private:
    Ui::ShowActivities *ui;
    std::vector<QLabel*> labels;

    void showActivitiesName(const std::vector<std::string>&);
    void showActivitiesDate(const std::vector<Date>&);
    void showActivitiesStartTime(const std::vector<ActivityTime>&  activitiesStartTime);
    void showActivitiesEndTime(const std::vector<ActivityTime>& activitiesEndTime);

public:
    explicit ShowActivities(QWidget *parent = nullptr);
    void showAllActivities(ActivityVector activityVector);
    ~ShowActivities() override;

public slots:
    void quit();


};

#endif // SHOWACTIVITIES_H
