#include "showactivities.h"
#include "ui_showactivities.h"

ShowActivities::ShowActivities(QWidget *parent) : QMainWindow(parent), ui(new Ui::ShowActivities)
{

    activities = ActivityVector();
    labels = std::vector<QLabel>();
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(quit()));
}

ShowActivities::~ShowActivities()
{
    delete ui;
}

void ShowActivities::setActivities(ActivityVector activityVector) {
    activities = activityVector;

    int i = 10;

    for (auto it = activityVector.getActivityList()->begin(); it<activityVector.getActivityList()->end(); ++it){
        QLabel *toAddLabel = new QLabel(this);
        std::cout << it->getName() << "\n";
        QString qstr = QString::fromStdString(it->getName());
        toAddLabel->setText(qstr);
        toAddLabel->setGeometry(10, i, 50, 10);
        i=i+30;
    }
}

void ShowActivities::quit() {
    QWidget::close();
}


