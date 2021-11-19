#include "RectifiersTwoPeriodCircuit.h"

RectifiersTwoPeriodCircuit::RectifiersTwoPeriodCircuit()
{

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RectifiersTwoPeriodCircuit::SetBaseValue2(double _f, double _I0, double _Rn)
{
    f = _f;
    I0 = _I0;
    Rn = _Rn;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RectifiersTwoPeriodCircuit::FFilters2(int number)
{
    switch(number)
    {
        case 0:
            flagFilters = 0; // нет фильтра
        break;

        case 1:
            flagFilters = 1; // С фильтр
        break;

        case 2:
            flagFilters = 2; // L фильтр
        break;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double RectifiersTwoPeriodCircuit::Capacitor2(double Rn,double f,double Kp)
{
    return (double)1000000*((Kp*1.73-1)/(4*f*Rn*Kp*1.73)); // результат в мкФ
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double RectifiersTwoPeriodCircuit::Inductor2(double Rn,double f,double Kp)
{
    return (double)1000*((Rn/(4*PI*f))*sqrt(pow((0.667/Kp),2)-1)); // результат в мГн
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RectifiersTwoPeriodCircuit::Calculate2()
{

    double T = 1/f;
    double omega = 2*PI*f;

    U0 = I0*Rn;
    U2m = PI*U0/sqrt(8);
    Ud_input = U2m/sqrt(2);

    double Uobr = sqrt(2)*U2m;

    double Iobr = PI*I0/2;

    if(flagFilters != 0)                              // Вычисление C или L выходного фильтра
    {
        U2m = U0*(1+Kp);
        Ud_input = U2m/sqrt(2);
        C = Capacitor2(Rn,f,Kp);
        L = Inductor2(Rn,f,Kp);
    }
}
