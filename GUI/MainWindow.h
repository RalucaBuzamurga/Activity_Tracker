#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "InsertActivityController.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    InsertActivityController *insertActivityGUI;
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

public slots:
    void insertActivity();
    void showActivities();
};

#endif // MAINWINDOW_H
