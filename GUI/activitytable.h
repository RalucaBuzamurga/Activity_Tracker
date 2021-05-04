//
// Created by Raluca Michela Buzamurga on 03/05/21.
//

#ifndef ACTIVITYTRACKER_ACTIVITYTABLE_H
#define ACTIVITYTRACKER_ACTIVITYTABLE_H

#include <QDialog>
#include <Body/ActivityList.h>
#include "QStandardItemModel"

QT_BEGIN_NAMESPACE
namespace Ui { class ActivityTable; }
QT_END_NAMESPACE

class ActivityTable : public QDialog {

Q_OBJECT

private:
    Ui::ActivityTable *ui;
    QStandardItemModel *model;

public:
    explicit ActivityTable(QWidget *parent = nullptr);
    void setActivityTable(ActivityList);
    ~ActivityTable() override;

public slots:
    void quit();

};


#endif //ACTIVITYTRACKER_ACTIVITYTABLE_H