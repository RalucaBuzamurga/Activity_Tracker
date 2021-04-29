#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Model/ActivityVector.h>
#include "InsertActivityController.h"
#include "ShowActivitiesController.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    InsertActivityController *insert;
    ShowActivities* activities;
    Ui::MainWindow *ui;
    bool created;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

public slots:
    void insertActivity();
    void showActivities();


};

#endif // MAINWINDOW_H
