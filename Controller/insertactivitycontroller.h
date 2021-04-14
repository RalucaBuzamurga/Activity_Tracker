#ifndef INSERTACTIVITYCONTROLLER_H
#define INSERTACTIVITYCONTROLLER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class InsertActivityController; }
QT_END_NAMESPACE

class InsertActivityController : public QMainWindow
{
    Q_OBJECT

public:
    InsertActivityController(QWidget *parent = nullptr);
    ~InsertActivityController();
public slots:
    std::string saveActivityName();

private:
    Ui::InsertActivityController *ui;
};
#endif // INSERTACTIVITYCONTROLLER_H
