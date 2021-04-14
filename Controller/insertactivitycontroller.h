#ifndef INSERTACTIVITYCONTROLLER_H
#define INSERTACTIVITYCONTROLLER_H

#include <QMainWindow>
#include "Model/ActivityVector.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InsertActivityController; }
QT_END_NAMESPACE

class InsertActivityController : public QMainWindow
{
    Q_OBJECT

public:
    explicit InsertActivityController(QWidget *parent = nullptr);
    ~InsertActivityController() override;
public slots:
    ActivityVector saveActivity();
    void quit();

private:
    Ui::InsertActivityController *ui;
    ActivityVector* activities;
};
#endif // INSERTACTIVITYCONTROLLER_H
