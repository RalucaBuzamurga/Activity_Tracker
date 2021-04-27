#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "InsertActivityController.h"
#include "ShowActivitiesController.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    insert = new InsertActivityController;
    ui->setupUi(this);
    created = false;
    connect(ui->newActivityButton, SIGNAL(clicked(bool)), this, SLOT(insertActivity()));
    connect(ui->showActivitiesButton, SIGNAL(clicked(bool)), this, SLOT(showActivities()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete insert;
    if (created)
        delete activities;
}

void MainWindow::insertActivity() {
    insert->show();
}

void MainWindow::showActivities() {
    activities = new ShowActivities;
    created = true;
    activities->showAllActivities(*insert->getActivities());
    activities->show();
}