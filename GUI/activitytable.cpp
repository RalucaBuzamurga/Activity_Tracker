//
// Created by Raluca Michela Buzamurga on 03/05/21.
//

#include "activitytable.h"
#include "ui_ActivityTable.h"

ActivityTable::ActivityTable(QWidget *parent) : QDialog(parent), ui(new Ui::ActivityTable) {
    ui->setupUi(this);

    model = new QStandardItemModel(0,4,this);
    ui->tableView->setModel(model);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nome"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Data"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Inizio"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Fine"));

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(quit()));
}

ActivityTable::~ActivityTable() {
    delete ui;
    delete model;       // Quando viene distrutto il model, automaticamente viene distrutto anche tutto il suo contenuto
}

void ActivityTable::setActivityTable(ActivityList activities) {
    int index = 0;

    for(auto it:activities.getActivityList()) {

        QString name = QString::fromStdString(it.getName());
        QString date = QString::fromStdString(it.getDate().getDateString());
        QString startTime = QString::fromStdString(it.getStartTime().getTimeString());
        QString endTime = QString::fromStdString(it.getEndTime().getTimeString());

        model->setItem(index, 0, new QStandardItem(name));
        model->setItem(index, 1, new QStandardItem(date));
        model->setItem(index, 2, new QStandardItem(startTime));
        model->setItem(index, 3, new QStandardItem(endTime));

        ++index;
    }
}

void ActivityTable::quit() {
    QWidget::close();
}