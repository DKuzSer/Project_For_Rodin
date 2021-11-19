#ifndef RECTIFIERSTWOPERIODCIRCUIT_H
#define RECTIFIERSTWOPERIODCIRCUIT_H

#include "RectifiersAbstract.h"
#include "constans.h"
#include <math.h>

class RectifiersTwoPeriodCircuit : public RectifiersAbstract
{
public:
    RectifiersTwoPeriodCircuit();

    void SetBaseValue(double _f, double _I0, double _Rn);
    void FFilters(int number);
    void Calculate();

    double Inductor(double Rh,double f,double Kp);
    double Capacitor(double Rh,double f,double Kp);

    bool flagFilters = 0; // 0 - РЅРµС‚ С„РёР»СЊС‚СЂР°, 1 - C С„РёР»СЊС‚СЂ, 2 - L С„РёР»СЊС‚СЂ
};

#endif // RECTIFIERSTWOPERIODCIRCUIT_H
