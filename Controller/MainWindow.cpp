#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "InsertActivityController.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    insert = new InsertActivityController;
    ui->setupUi(this);
    connect(ui->newActivityButton, SIGNAL(clicked(bool)), this, SLOT(insertActivity()));
    connect(ui->showActivitiesButton, SIGNAL(clicked(bool)), this, SLOT(showActivities()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete insert;
}

void MainWindow::insertActivity() {
    insert->show();
}

void MainWindow::showActivities() {
    auto* activities = new ShowActivities();
    activities->showAllActivities(*insert->getActivities());
    activities->show();
}