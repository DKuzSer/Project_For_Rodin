#include "mainpowersources.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainPowerSources Devices;
    Devices.show();
    return a.exec();
}
