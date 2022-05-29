#ifndef MATCHINGONECIRCUIT_H
#define MATCHINGONECIRCUIT_H

#include "MatchingAbstract.h"
#include <math.h>

class MatchingOneCircuit : public MatchingAbstract
{
public:
    MatchingOneCircuit();

    void SetBaseValue(double , double , double, double, double, double );
    void Calculate(bool);
    void ViewFilters(int number);

    int flagFilters = 0; //0 - П-фильтра    1 - Модифицированный П-фильтр
};

#endif // MATCHINGONECIRCUIT_H
