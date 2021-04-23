#include "ShowActivitiesController.h"
#include "ui_showactivities.h"


ShowActivities::ShowActivities(QWidget *parent) : QMainWindow(parent), ui(new Ui::ShowActivities){


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
    activities = ActivityVector(activityVector);
    showActivitiesName(*activityVector.getActivitiesName());
    showActivitiesDate(*activityVector.getActivitiesDate());
    showActivitiesStartTime(*activityVector.getActivitiesStartTime());
    showActivitiesEndTime(*activityVector.getActivitiesEndTime());
}

void ShowActivities::showActivitiesName(std::vector<std::string> activitiesName) {

    int i = 10 ;
    for(auto it = activitiesName.begin(); it<activitiesName.end(); ++it){
        auto* qlabel = new QLabel(this);
        QString qstring = QString::fromStdString(*it);
        qlabel->setText(qstring);
        qlabel->setGeometry(10, i, 80, 10);
        i=i+30;
    }
}

void ShowActivities::showActivitiesDate(std::vector<Date> activitiesDate) {

    int i = 10;
    for(auto it = activitiesDate.begin(); it<activitiesDate.end(); ++it){
        auto* year = new QLabel(this);
        auto* month = new QLabel(this);
        auto* day = new QLabel(this);

        year->setNum(it->getYear());
        month->setNum(it->getMonth());
        day->setNum(it->getDay());

        year->setGeometry(100, i, 40, 10);
        month->setGeometry(150, i, 40, 10);
        day->setGeometry(200, i, 40, 10);

        i=i+30;
    }
}

void ShowActivities::showActivitiesStartTime(std::vector<ActivityTime> activitiesStartTime) {
    int i = 10;

    for(auto it = activitiesStartTime.begin(); it<activitiesStartTime.end(); ++it) {
        auto *hour = new QLabel(this);
        auto *minute = new QLabel(this);

        hour->setNum(it->getActivityHour());
        minute->setNum(it->getActivityMinute());

        hour->setGeometry(250, i, 30, 10);
        minute->setGeometry(290, i, 30, 10);

        i=i+30;
    }


}

void ShowActivities::showActivitiesEndTime(std::vector<ActivityTime> activitiesEndTime) {
    int i = 10;

    for(auto it = activitiesEndTime.begin(); it<activitiesEndTime.end(); ++it){
        auto *hour = new QLabel(this);
        auto *minute = new QLabel(this);

        hour->setNum(it->getActivityHour());
        minute->setNum(it->getActivityMinute());

        hour->setGeometry(340, i, 30, 10);
        minute->setGeometry(380, i, 30, 10);

        i=i+30;
    }
}
