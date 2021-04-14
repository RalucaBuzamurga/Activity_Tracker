#include "insertactivitycontroller.h"
#include "./ui_insertactivitycontroller.h"

InsertActivityController::InsertActivityController(QWidget *parent): QMainWindow(parent), ui(new Ui::InsertActivityController)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(saveActivityName()));
}

InsertActivityController::~InsertActivityController()
{
    delete ui;
}

std::string InsertActivityController::saveActivityName() {
    QString qstring = ui->lineEdit->text();
    std::string activityName = qstring.toStdString();
    return activityName;
}

