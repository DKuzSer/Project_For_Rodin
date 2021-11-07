#ifndef RECTIFIERSONEPERIODCIRCUIT_H
#define RECTIFIERSONEPERIODCIRCUIT_H

#include "RectifiersAbstract.h"
#include "constans.h"
#include <math.h>

class RectifiersOnePeriodCircuit : public RectifiersAbstract
{
public:
    RectifiersOnePeriodCircuit();
    void SetBaseValue(double _f, double _I0, double _Rn);
    void FFilters(int number);
    void Calculate();
    double Inductor(double Rh,double f,double Kp);
    double Capacitor(double Rh,double f,double Kp);

    bool flagFilters = 0; // 0 - нет фильтра, 1 - C фильтр, 2 - L фильтр
};

#endif // RECTIFIERSONEPERIODCIRCUIT_H
