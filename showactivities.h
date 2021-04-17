#ifndef SHOWACTIVITIES_H
#define SHOWACTIVITIES_H

#include <QMainWindow>
#include "Model/ActivityVector.h"

namespace Ui {
class ShowActivities;
}

class ShowActivities : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShowActivities(QWidget *parent = nullptr);
    void setActivities(ActivityVector activityVector);
    ~ShowActivities();

private:
    Ui::ShowActivities *ui;
    ActivityVector activities;
};

#endif // SHOWACTIVITIES_H