#ifndef FILTERSBUTTERWORTH_H
#define FILTERSBUTTERWORTH_H

#include "FiltersAbstract.h"
#include "constans.h"
#include <complex>

class FiltersButterworth : public FiltersAbstract
{

public:

    FiltersButterworth();
    void SetBaseValue(double , double , int );
    void SetBaseValue(double , double , int ,double);
    void ViewFilters(int number);
    void Calculate();

    double OutputWaveform(double f);
    double OutputWaveformFCHX(double f);

    int flagFilters = 0; // 0 - ФНЧ, 1 - ФВЧ, 2 - ПФ, 3 - ЗФ
};

#endif // FILTERSBUTTERWORTH_H
