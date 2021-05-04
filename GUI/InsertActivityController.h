#ifndef INSERTACTIVITYCONTROLLER_H
#define INSERTACTIVITYCONTROLLER_H

#include <QMainWindow>
#include "Body/ActivityList.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InsertActivityController; }
QT_END_NAMESPACE

class InsertActivityController : public QMainWindow
{
    Q_OBJECT

private:
    Ui::InsertActivityController *ui;
    ActivityList activities;

public:
    explicit InsertActivityController(QWidget *parent = nullptr);
    ~InsertActivityController() override;
    ActivityList getActivities();

public slots:
    void saveActivity();
    void quit();

};
#endif // INSERTACTIVITYCONTROLLER_H
