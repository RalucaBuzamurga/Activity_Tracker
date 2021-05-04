#include "InsertActivityController.h"
#include "./ui_insertactivitycontroller.h"

InsertActivityController::InsertActivityController(QWidget *parent): QMainWindow(parent), ui(new Ui::InsertActivityController) {
    activities = ActivityList();
    ui->setupUi(this);

    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveActivity()));
    connect(ui->saveButton, SIGNAL(clicked(bool)), this, SLOT(quit()));
    connect(ui->backButton, SIGNAL(clicked(bool)), this, SLOT(quit()));
}

InsertActivityController::~InsertActivityController() {
    delete ui;
}

void InsertActivityController::saveActivity() {

    QString name = ui->nameEdit->text();
    QString year = ui->yearEdit->text();
    QString month = ui->monthEdit->text();
    QString day = ui->dayEdit->text();
    QString startHour = ui->startHour->text();
    QString startMinute = ui->startMinute->text();
    QString endHour = ui->endHour->text();
    QString endMinute = ui->endMinute->text();

    Date date = Date(year.toInt(), month.toInt(), day.toInt());
    ActivityTime startTime = ActivityTime(startHour.toInt(), startMinute.toInt());
    ActivityTime endTime = ActivityTime(endHour.toInt(), endMinute.toInt());

    Activity toAddActivity = Activity(name.toStdString(), date, startTime, endTime);

    if(date.isAcceptable() && startTime.isAcceptable() && endTime.isAcceptable() && endTime>startTime) {
        activities.addActivity(toAddActivity);
    }

}

void InsertActivityController::quit() {
    QWidget::close();
}

ActivityList InsertActivityController::getActivities() {
    activities.sort();
    return activities;
}