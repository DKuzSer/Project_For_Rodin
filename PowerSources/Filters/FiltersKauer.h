#ifndef FILTERSKAUER_H
#define FILTERSKAUER_H

#include "FiltersAbstract.h"
#include "constans.h"
#include <complex>
class FiltersKauer : public FiltersAbstract
{
public:

    FiltersKauer();
    void SetBaseValue(double , double , int );
    void SetBaseValue(double , double , int ,double);
    void ViewFilters(int number);
    void Calculate();

    double OutputWaveform(double f);

    int flagFilters = 0; // 0 - ФНЧ, 1 - ФВЧ, 2 - ПФ, 3 - ЗФ
};

#endif // FILTERSKAUER_H

