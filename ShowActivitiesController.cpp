#include "ShowActivitiesController.h"
#include "ui_showactivities.h"
#include "ShowActivitiesView.h"

ShowActivities::ShowActivities(QWidget *parent) : QMainWindow(parent), ui(new Ui::ShowActivities){

    ShowActivitiesView* showActivities = new ShowActivitiesView;
    activities = ActivityVector();

    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(quit()));
}

ShowActivities::~ShowActivities()
{
    delete ui;
}

void ShowActivities::quit() {
    QWidget::close();
}

void ShowActivities::showAllActivities(ActivityVector activityVector) {
    activities = activityVector;

    activitiesName = new std::vector<std::string>;
    activitiesDate = new std::vector<Date>;
    activitiesStartTime = new std::vector<ActivityTime>;
    activitiesEndTime = new std::vector<ActivityTime>;

    for(auto it = activities.getActivityList()->begin(); it<activities.getActivityList()->end(); ++it) {
        activitiesName->push_back(it->getName());
        activitiesDate->push_back(it->getDay());
        activitiesStartTime->push_back(it->getStartTime());
        activitiesStartTime->push_back(it->getEndTime());
    }
}