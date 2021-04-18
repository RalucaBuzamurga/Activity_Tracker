#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Model/ActivityVector.h>
#include "insertactivitycontroller.h"
#include "ShowActivitiesController.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

public slots:
    void insertActivity();
    void showActivities();

private:
    InsertActivityController *insert;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
