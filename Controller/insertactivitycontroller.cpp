#include "insertactivitycontroller.h"
#include "./ui_insertactivitycontroller.h"


InsertActivityController::InsertActivityController(QWidget *parent): QMainWindow(parent), ui(new Ui::InsertActivityController)
{
    activities = new ActivityVector;
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(saveActivity()));
}

InsertActivityController::~InsertActivityController()
{
    delete ui;
}

ActivityVector InsertActivityController::saveActivity() {

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

    Activity toAddActivity = Activity(name.toStdString(), date, startTime, endTime);
    activities->addActivity(toAddActivity);

    return *activities;
}

