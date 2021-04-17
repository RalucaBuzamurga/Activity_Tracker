#include "showactivities.h"
#include "ui_showactivities.h"

ShowActivities::ShowActivities(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowActivities)
{
    activities = ActivityVector();
    ui->setupUi(this);
}

ShowActivities::~ShowActivities()
{
    delete ui;
}

void ShowActivities::setActivities(ActivityVector activityVector) {
    activities = activityVector;
}


