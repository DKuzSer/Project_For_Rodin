#ifndef RECTIFIERSONEPERIODCIRCUIT_H
#define RECTIFIERSONEPERIODCIRCUIT_H

#include "RectifiersAbstract.h"
#include "constans.h"
#include <QMessageBox>
#include <ctime>
#include <math.h>

class RectifiersOnePeriodCircuit : public RectifiersAbstract
{
public:
    RectifiersOnePeriodCircuit();

    void SetBaseValue(double _f, double _I0, double _Rn);
    void FFilters(int number);
    void Calculate();

    void Inductor();
    void Capacitor();

    double OutputVoltageWaveform(double t);

    double OutputCapacityVoltageWaveform(double t);
    void CalculateCapacityParameters(double* I0_calculate, double* Kp_calculate, double* U_peak);

    double OutputInductorCurrentWaveform(double t);
    void CalculateInductorParameters(double* I0_calculate, double* Kp_calculate, double* U_peak);

    int flagFilters = 0; // 0 - нет фильтра, 1 - C фильтр, 2 - L фильтр
};

#endif // RECTIFIERSONEPERIODCIRCUIT_H
