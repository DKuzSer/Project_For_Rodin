#ifndef FILTERSCHEBISHEV_H
#define FILTERSCHEBISHEV_H

#include "FiltersAbstract.h"
#include "constans.h"
#include <complex>

class FiltersCHEBISHEV : public FiltersAbstract
{

public:

    FiltersCHEBISHEV();
    void SetBaseValue(double , double , int );
    void SetBaseValue(double , double , int ,double);
    void ViewFilters(int number);
    void Calculate();

    double OutputWaveform(double f);

    int flagFilters = 0; // 0 - ФНЧ, 1 - ФВЧ, 2 - ПФ, 3 - ЗФ
};

#endif // FILTERSCHEBISHEV_H
