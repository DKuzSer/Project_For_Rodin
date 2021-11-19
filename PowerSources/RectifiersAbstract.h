#ifndef RECTIFIERSABSTRACT_H
#define RECTIFIERSABSTRACT_H

#include <QObject>

class RectifiersAbstract : public QObject
{
    Q_OBJECT

public:

    RectifiersAbstract();

    virtual void SetBaseValue(double , double , double ){};
    virtual void FFilters(int){};
    virtual void Calculate(){};

//    virtual void SetBaseValue2(double , double , double ){};
//    virtual void FFilters2(int){};
//    virtual void Calculate2(){};

    double f;           // частота входного сигнала
    double I0;          // значение средневыпрямленного тока
    double U0;          // значение средневыпрямленного напряжения
    double Rn;          // значение сопротивления выходной нагрузки
    double Kp;          // коэффициент пульсаций выпрямителя
    double U2m;

    double Ud_input;    // действующее входное напряжение
    double Idop;        // допустимый ток в цепи
    double C;           // значение ёмкости выходного фильтра
    double L;           // значение индуктивности выходного фильтра
    int m;              // количесво диодов в цепи

signals:

};

#endif // RECTIFIERSABSTRACT_H
