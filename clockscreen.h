#ifndef CLOCKSCREEN_H
#define CLOCKSCREEN_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

class ClockScreen : public QWidget
{
    Q_OBJECT
public:
    explicit ClockScreen(QWidget *parent = nullptr);

signals:
public slots:
    void updateTime();
private:

    QLabel* hour1;
    QLabel* hour10;
    QLabel* minute1;
    QLabel* minute10;
    QLabel* colon;
    QLabel* am;
    QLabel* pm;
    bool showColon;
    QTimer* timer;
};

#endif // CLOCKSCREEN_H
