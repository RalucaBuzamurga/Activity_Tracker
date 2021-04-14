#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "insertactivitycontroller.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->newActivityButton, SIGNAL(clicked(bool)), this, SLOT(insertActivity()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::insertActivity() {
    auto *insert = new InsertActivityController;
    insert->show();
}

