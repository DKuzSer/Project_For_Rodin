#ifndef MATCHINGABSTRACT_H
#define MATCHINGABSTRACT_H

#include <QObject>
#include "constans.h"

class MatchingAbstract : public QObject
{
    Q_OBJECT
public:
    MatchingAbstract();

    virtual void SetBaseValue(double , double , double, double, double , double ){};
    virtual void Calculate(bool){};
    virtual void ViewFilters(int){};

    double Ek;
    double P;
    double F;
    double Rh;    //сопротивление нагрузки
    double Q;
    double RinCorrect;

    double Rin = 0.0;     // сопротивление на выходе транхистора
    double C1 = 0.0;     // индуктивность
    double L1 = 0.0;     // ёмкость
    double C2 = 0.0;     // индуктивность
    double L2 = 0.0;
};

#endif // MATCHINGABSTRACT_H
