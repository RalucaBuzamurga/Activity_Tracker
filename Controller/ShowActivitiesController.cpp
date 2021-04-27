#include "ShowActivitiesController.h"
#include "ui_showactivities.h"


ShowActivities::ShowActivities(QWidget *parent) : QMainWindow(parent), ui(new Ui::ShowActivities){
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(quit()));
    labels = std::vector<QLabel*>();
}

ShowActivities::~ShowActivities()
{
    delete ui;
    for(auto it : labels){
        delete it;
    }
}

void ShowActivities::quit() {
    QWidget::close();
}

void ShowActivities::showAllActivities(ActivityVector activityVector) {
    showActivitiesName(*activityVector.getActivitiesName());
    showActivitiesDate(*activityVector.getActivitiesDate());
    showActivitiesStartTime(*activityVector.getActivitiesStartTime());
    showActivitiesEndTime(*activityVector.getActivitiesEndTime());
}

void ShowActivities::showActivitiesName(const std::vector<std::string>& activitiesName) {

    int i = 80 ;
    for(const auto& it : activitiesName){
        auto* qlabel = new QLabel(this);
        labels.push_back(qlabel);
        QString qstring = QString::fromStdString(it);
        qlabel->setText(qstring);
        qlabel->setGeometry(10, i, 100, 20);
        i=i+30;
    }
}

void ShowActivities::showActivitiesDate(const std::vector<Date>& activitiesDate) {

    int i = 80;
    for(auto it : activitiesDate){
        auto* year = new QLabel(this);
        auto* month = new QLabel(this);
        auto* day = new QLabel(this);

        labels.push_back(year);
        labels.push_back(month);
        labels.push_back(day);

        year->setNum(it.getYear());
        month->setNum(it.getMonth());
        day->setNum(it.getDay());

        year->setGeometry(130, i, 40, 20);
        month->setGeometry(175, i, 20, 20);
        day->setGeometry(200, i, 20, 20);

        i=i+30;

    }
}

void ShowActivities::showActivitiesStartTime(const std::vector<ActivityTime>& activitiesStartTime) {
    int i = 80;

    for(auto it : activitiesStartTime) {
        auto *hour = new QLabel(this);
        auto *minute = new QLabel(this);

        labels.push_back(hour);
        labels.push_back(minute);

        hour->setNum(it.getActivityHour());
        minute->setNum(it.getActivityMinute());

        hour->setGeometry(250, i, 20, 20);
        minute->setGeometry(280, i, 20, 20);

        i=i+30;
    }
}

void ShowActivities::showActivitiesEndTime(const std::vector<ActivityTime>& activitiesEndTime) {
    int i = 80;

    for(auto it :activitiesEndTime){
        auto *hour = new QLabel(this);
        auto *minute = new QLabel(this);

        labels.push_back(hour);
        labels.push_back(minute);

        hour->setNum(it.getActivityHour());
        minute->setNum(it.getActivityMinute());

        hour->setGeometry(340, i, 20, 20);
        minute->setGeometry(370, i, 20, 20);

        i=i+30;
    }
}