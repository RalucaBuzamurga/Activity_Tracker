#include "InsertActivityController.h"
#include "./ui_insertactivitycontroller.h"


InsertActivityController::InsertActivityController(QWidget *parent): QMainWindow(parent), ui(new Ui::InsertActivityController) {
    activities = new ActivityVector;
    ui->setupUi(this);

    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveActivity()));
    connect(ui->saveButton, SIGNAL(clicked(bool)), this, SLOT(quit()));
    connect(ui->backButton, SIGNAL(clicked(bool)), this, SLOT(quit()));
}

InsertActivityController::~InsertActivityController() {
    delete activities;
    delete ui;
}

void InsertActivityController::saveActivity() {

    QString name = ui->nameEdit->text();

    QString year = ui->yearEdit->text();
    QString month = ui->monthEdit->text();
    QString day = ui->dayEdit->text();
    Date date = Date(year.toInt(), month.toInt(), day.toInt());

    QString startHour = ui->startHour->text();
    QString startMinute = ui->startMinute->text();
    ActivityTime startTime = ActivityTime(startHour.toInt(), startMinute.toInt());

    QString endHour = ui->endHour->text();
    QString endMinute = ui->endMinute->text();
    ActivityTime endTime = ActivityTime(endHour.toInt(), endMinute.toInt());

    if(date.isAcceptable() && startTime.isAcceptable() && endTime.isAcceptable() && endTime.isGraterThan(startTime)) {
        Activity toAddActivity = Activity(name.toStdString(), date, startTime, endTime);
        activities->addActivity(toAddActivity);
    }
}

void InsertActivityController::quit() {
    QWidget::close();
}

ActivityVector* InsertActivityController::getActivities() {
    if(!activities->getActivityList()->empty())
        activities->sort();

    return activities;
}