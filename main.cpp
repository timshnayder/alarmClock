#include <QApplication>
#include <QPushButton>
#include "clockscreen.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    ClockScreen clock;
    clock.show();

    return app.exec();
}
