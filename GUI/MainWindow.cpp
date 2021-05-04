#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "InsertActivityController.h"
#include "Body/ActivityList.h"
#include "activitytable.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    insertActivityGUI = new InsertActivityController;
    ui->setupUi(this);
    connect(ui->newActivityButton, SIGNAL(clicked(bool)), this, SLOT(insertActivity()));
    connect(ui->showActivitiesButton, SIGNAL(clicked(bool)), this, SLOT(showActivities()));
}

MainWindow::~MainWindow() {
    delete ui;
    delete insertActivityGUI;
}

void MainWindow::insertActivity() {
    insertActivityGUI->show();
}

void MainWindow::showActivities() {
    auto* showActivitiesGUI = new ActivityTable;

    showActivitiesGUI->setAttribute(Qt::WA_DeleteOnClose);
    showActivitiesGUI->setActivityTable(insertActivityGUI->getActivities());
    showActivitiesGUI->open();
}