#include "RectifiersOnePeriodCircuit.h"
#include <ctime>

#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>

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
double RectifiersOnePeriodCircuit::Capacitor(double Rn,double f,double Kp)
{
    return (double)3*1000000/(4*f*Rn*log(1+Kp)); // результат в мкФ
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double RectifiersOnePeriodCircuit::Inductor(double Rn,double f,double Kp)
{
    return (double)(3*1000*Rn)/(4*f*log(1+Kp)); // результат в мГн
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RectifiersOnePeriodCircuit::Calculate()
{
    flagCalculate = false;
    m = 1;
    if (I0 > Idop)
        m = I0/Idop; // количесво диодов в цепи иначе 1 по стандарту

    U0 = I0*Rn;                                       // Постоянная составляющая выпрямленного напряжения
    double U2m = U0*(1+Kp);                           // Максимальное значение напряжения на вторичной обмотке
    Ud_input = U2m/sqrt(2);                           // Действующее значение напряжения на входе

    if(flagFilters == 1)                              // Вычисление C или L выходного фильтра
    {
        Ud_input = U2m/sqrt(2);
        C = Capacitor(Rn,f,Kp);
//        L = Inductor(Rn,f,Kp); привести алгоритм снизу к единой функции
    }

    if(flagFilters == 2)
    {
        //новый алгоритм вычисления:
        U0 = I0*Rn;
        Um_input = U0;
        L = 0;

        double U_peak = U0;
        double I0_calculate = 0;
        double Kp_calculate = 0;

        double accuracy_Um_input = 0.1;
        double accuracy_L = 0.1;

        double start_time = clock();
        double time_program = 0.0;

        while(I0_calculate < I0 || Kp_calculate > Kp)
        {
            L += accuracy_L/100;

            CalculateParameters(&I0_calculate, &Kp_calculate, &U_peak);

            while(U_peak <= U0)
            {
                Um_input += accuracy_Um_input;
                L = 0;

                CalculateParameters(&I0_calculate, &Kp_calculate, &U_peak);
            }
            time_program = clock();
            time_program = time_program - start_time;
            if(time_program > 5000)
            {
                flagCalculate = true;
                break;
            }
        }
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double RectifiersOnePeriodCircuit::OutputInductorCurrentWaveform(double t)
{
    double teta = atan(2*PI*f*L/Rn);
    double step = Um_input*(sin(2*PI*f*t-teta)+sin(teta)*exp(-Rn*t/L))/sqrt(pow(Rn,2)+pow(2*PI*f*L,2));
    if(step >= 0)
        return step;
    else
        return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RectifiersOnePeriodCircuit::CalculateParameters(double* I0_calculate, double* Kp_calculate, double* U_peak)
{
    double T = 1/f;
    double accuracy_t = 0.001;

    double Imax = 0;
    double Imin = 0;
    *I0_calculate = 0;
    for(float time = 0; time < T; time += accuracy_t)
    {
        double step = OutputInductorCurrentWaveform(time);
        if(time != 0)
        {
            if(step > Imax)
            {
                Imax = step;
                Imin = step;
            }
            else
            {
                if(step < Imin)
                {
                    Imin = step;
                }
            }
        }
        *I0_calculate += step * accuracy_t;
    }

    *I0_calculate = (*I0_calculate)/T;
    *Kp_calculate = (Imax - Imin)/2/(*I0_calculate);
    *U_peak = Imax*Rn;
}
