#include "clockscreen.h"
#include <ctime>

ClockScreen::ClockScreen(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(800,480);
    setStyleSheet("background-color:black;color:white");
    QFont digitFont("Arial", 200, QFont::Bold);
    QFont ampmFont("Arial", 36, QFont::Bold);
    QFont colonFont("Arial", 150, QFont::Bold);
    hour10 = new QLabel(this);
    hour10->setGeometry(130,70,120,200);
    hour10->setFont(digitFont);

    hour1 = new QLabel(this);
    hour1->setGeometry(260,70,120,200);
    hour1->setFont(digitFont);

    minute10 = new QLabel(this);
    minute10->setGeometry(460,70,120,200);
    minute10->setFont(digitFont);

    minute1 = new QLabel(this);
    minute1->setGeometry(590,70,120,200);
    minute1->setFont(digitFont);

    showColon = true;
    colon = new QLabel(this);
    colon->setText(":");
    colon->setGeometry(390,70,60,200);
    colon->setFont(colonFont);

    am = new QLabel(this);
    am->setVisible(false);
    am->setText("AM");
    am->setGeometry(50, 200, 60,60);
    am->setFont(ampmFont);

    pm = new QLabel(this);
    pm->setVisible(false);
    pm->setText("PM");
    pm->setGeometry(50, 80, 60,60);
    pm->setFont(ampmFont);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
            this, SLOT(updateTime()));
    timer->start(1000);
}

void ClockScreen::updateTime(){
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    if(now->tm_hour > 11){
        am->setVisible(false);
        pm->setVisible(true);
    } else {
        am->setVisible(true);
        pm->setVisible(false);
    }
    minute1->setText(QString::fromStdString(std::to_string(now->tm_min%10)));
    minute10->setText(QString::fromStdString(std::to_string(now->tm_min/10)));

    int hour = now->tm_hour%12;

    hour1->setText(QString::fromStdString(std::to_string(hour%10)));
    hour10->setText(QString::fromStdString(std::to_string(hour/10)));
    if(hour < 10){
        hour10->setVisible(false);
    } else {
        hour10->setVisible(true);
    }

    colon->setVisible(showColon);
    showColon = !showColon;
}
