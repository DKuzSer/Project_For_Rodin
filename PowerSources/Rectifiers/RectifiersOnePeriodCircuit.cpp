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
void RectifiersOnePeriodCircuit::Capacitor()
{
    if(Kp == 1.57)                               // проверкана величину индуктивности при выборе вкладки наличия фильтра
    {
        U0 = I0*Rn;
        Um_input = PI*U0;
        Ud_input = Um_input/sqrt(2);
        C = 0;
        return;
    }

    //новый алгоритм вычисления:
    U0 = I0*Rn;
    Um_input = U0;
    C = 0;

    double U_peak = 2*U0;
    double U0_calculate = 0;
    double Kp_calculate = 0;

    double accuracy_Um_input = 0.05;
    double accuracy_C = 0.000001;

    double start_time = clock();
    double time_program = 0.0;

    while(Kp_calculate < Kp)
    {
        Um_input += accuracy_Um_input;
        C = 0;

        CalculateCapacityParameters(&U0_calculate, &Kp_calculate, &U_peak);

        while(U0_calculate < U0)
        {
            C += accuracy_C;
            CalculateCapacityParameters(&U0_calculate, &Kp_calculate, &U_peak);
        }

        time_program = clock();
        time_program = time_program - start_time;

        if(time_program > 50000)
        {
            flagCalculate = true;
            break;
        }
    }

    Ud_input = Um_input/sqrt(2);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RectifiersOnePeriodCircuit::Inductor()
{
    if(Kp == 1.57)                               // проверкана величину индуктивности при выборе вкладки наличия фильтра
    {
        U0 = I0*Rn;
        Um_input = PI*U0;
        Ud_input = Um_input/sqrt(2);
        L = 0;
        return;
    }

    //новый алгоритм вычисления:
    U0 = I0*Rn;                             // средневыпрямленное напряжение
    Um_input = U0;
    L = 0;

    double U_peak = U0;
    double I0_calculate = 0;
    double Kp_calculate = 0;

    double accuracy_Um_input = 0.05;
    double accuracy_L = 0.1;

    double start_time = clock();
    double time_program = 0.0;

    while(I0_calculate < I0 || Kp_calculate > Kp)
    {
        L += accuracy_L/100;

        CalculateInductorParameters(&I0_calculate, &Kp_calculate, &U_peak);

        while(U_peak <= U0)
        {
            Um_input += accuracy_Um_input;
            L = 0;

            CalculateInductorParameters(&I0_calculate, &Kp_calculate, &U_peak);
        }

        time_program = clock();
        time_program = time_program - start_time;

        if(time_program > 50000)
        {
            flagCalculate = true;
            break;
        }
    }

    Ud_input = Um_input/sqrt(2);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RectifiersOnePeriodCircuit::Calculate()
{
    flagCalculate = false;
    m = 1;
    if (I0 > Idop)
        m = I0/Idop;                                  // количесво диодов в цепи иначе 1 по стандарту

    U0 = I0*Rn;                                       // Постоянная составляющая выпрямленного напряжения
    Um_input = U0*PI;                                 // Максимальное значение напряжения на вторичной обмотке
    Ud_input = Um_input/sqrt(2);                      // Действующее значение напряжения на входе

    if(flagFilters == 1)                              // Вычисление C выходного фильтра
    {
        //новый алгоритм вычисления:
        Capacitor();
    }

    if(flagFilters == 2)                              // Вычисление L выходного фильтра
    {
        //новый алгоритм вычисления:
        Inductor();
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double RectifiersOnePeriodCircuit::OutputVoltageWaveform(double t)
{
    double T = 1/f;
    int k = (int)(t/T);     // диапазон периодичности

    if((k*T <= t) && (t <= (k*T + T/2)))   // открытый диод
    {
        return Um_input*sin(2*PI*f*t);
    }

    if(((k*T + T/2) < t) && (t <= (k*T + T)))        // закрытый диод
    {
        return 0;
    }

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double RectifiersOnePeriodCircuit::OutputCapacityVoltageWaveform(double t)
{
    double T = 1/f;

    if(t <= T/4)
    {
        return Um_input*sin(2*PI*f*t);
    }

    else
    {
        int k = (int)((t-T/4)/T);     // диапазон периодичности

        if(((T/4 + k*T) <= t) && (t < (5*T/4 + k*T)))
        {
            double step1 = Um_input*exp(-(t-T/4-k*T)/(Rn*C));
            double step2 = OutputVoltageWaveform(t);
            if(step1 > step2)
                return step1;
            else
                return step2;
        }
    }

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double RectifiersOnePeriodCircuit::OutputInductorCurrentWaveform(double t)
{
    double T = 1/f;
    int k = (int)(t/T);     // диапазон периодичности

    double teta = atan(2*PI*f*L/Rn);
    double step = Um_input*(sin(2*PI*f*(t-k*T)-teta)+sin(teta)*exp(-Rn*(t-k*T)/L))/sqrt(pow(Rn,2)+pow(2*PI*f*L,2));
    if(step >= 0)
        return step;
    else
        return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RectifiersOnePeriodCircuit::CalculateInductorParameters(double* I0_calculate, double* Kp_calculate, double* U_peak)
{
    double T = 1/f;
    double accuracy_t = T/20;

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
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RectifiersOnePeriodCircuit::CalculateCapacityParameters(double* U0_calculate, double* Kp_calculate, double* U_peak)
{
    double T = 1/f;
    double accuracy_t = T/20;

    double Umax = 0;
    double Umin = 0;
    *U0_calculate = 0;
    for(float time = T/4; time < 5*T/4; time += accuracy_t)
    {
        double step = OutputCapacityVoltageWaveform(time);
        if(time != 0)
        {
            if(step > Umax)
            {
                Umax = step;
                Umin = step;
            }
            else
            {
                if(step < Umin)
                {
                    Umin = step;
                }
            }
        }
        *U0_calculate += step * accuracy_t;
    }

    *U0_calculate = (*U0_calculate)/T;
    *Kp_calculate = (Umax - Umin)/2/(*U0_calculate);
    *U_peak = Umax;
}
