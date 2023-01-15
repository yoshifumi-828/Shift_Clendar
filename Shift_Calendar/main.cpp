#include "ShiftCalendar.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Shift_Calendar w;
    w.show();
    return a.exec();
}
