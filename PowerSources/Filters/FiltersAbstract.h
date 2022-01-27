#ifndef FILTERSABSTRACT_H
#define FILTERSABSTRACT_H

#include <QObject>

class FiltersAbstract : public QObject
{
    Q_OBJECT

public:

    FiltersAbstract();

    virtual void SetBaseValue(double , double , int ){};
    virtual void SetBaseValue(double , double , int , double){};
    virtual void ViewFilters(int){};
    virtual void Calculate(){};

    virtual double OutputWaveform(double){return 0;};
    virtual double OutputWaveformFCHX(double){return 0;};

    double f;          // частота среза
    double R;          // сопротивление нагрузки
    int n;             // порядок
    double deltaf;      //полоса

    double C1 = 0;     // ёмкость
    double L1 = 0;     // индуктивность
    double C2 = 0;     // ёмкость
    double L2 = 0;     // индуктивность
    double C3 = 0;     // ёмкость
    double L3 = 0;     // индуктивность

signals:

};

#endif // FILTERSABSTRACT_H
