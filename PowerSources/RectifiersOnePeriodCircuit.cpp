#include "RectifiersOnePeriodCircuit.h"

RectifiersOnePeriodCircuit::RectifiersOnePeriodCircuit()
{

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RectifiersOnePeriodCircuit::SetBaseValue(double _f, double _I0, double _Rn)
{
    f = _f;
    I0 = _I0;
    Rn = _Rn;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RectifiersOnePeriodCircuit::FFilters(int number)
{
    switch(number)
    {
        case 0:
            flagFilters = 0;
        break;

        case 1:
            flagFilters = 1;
        break;

        case 2:
            flagFilters = 2;
        break;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double RectifiersOnePeriodCircuit::Capacitor(double Rn,double f,double Kp)
{
    return (double)3*1000000/(4*f*Rn*log(1+Kp));
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double RectifiersOnePeriodCircuit::Inductor(double Rn,double f,double Kp)
{
    return (double)(3*1000*Rn)/(4*f*log(1+Kp));
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RectifiersOnePeriodCircuit::Calculate()
{
    m = 1;
    if (I0 > Idop)
        m = I0/Idop; // количесво диодов в цепи иначе 1 по стандарту

    double T = 1/f;
    double omega = 2*PI*f;

    double I2m = fabs((I0*T*omega)/cos((omega*T)/2)); // Максимальное значение тока на вторичной обмотке
    U0 = I0*Rn;                                       // Постоянная составляющая выпрямленного напряжения
    double U2m = I2m*Rn;                              // Максимальное значение напряжения на вторичной обмотке
    Ud_input = U2m/sqrt(2);                           // Действующее значение напряжения на входе

    if(flagFilters != 0)                              // Вычисление C или L выходного фильтра
    {
        U2m = U0*(1+Kp);
        Ud_input = U2m/sqrt(2);
        C = Capacitor(Rn,f,Kp);
        L = Inductor(Rn,f,Kp);
    }
}
