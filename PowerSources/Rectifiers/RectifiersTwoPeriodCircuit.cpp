#include "RectifiersTwoPeriodCircuit.h"

RectifiersTwoPeriodCircuit::RectifiersTwoPeriodCircuit()
{

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RectifiersTwoPeriodCircuit::SetBaseValue(double _f, double _I0, double _Rn)
{
    f = _f;
    I0 = _I0;
    Rn = _Rn;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RectifiersTwoPeriodCircuit::FFilters(int number)
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
void RectifiersTwoPeriodCircuit::Capacitor()
{
    if(Kp == 0.67)                               // проверкана величину ёмкости при выборе вкладки наличия фильтра
    {
        U0 = I0*Rn;
        Um_input = PI*U0/2;
        Ud_input = Um_input/sqrt(2);
        C = 0;
        return;
    }

    //новый алгоритм вычисления:
    U0 = I0*Rn;                                  // средневыпрямленное напряжение
    Um_input = U0;
    C = 0;

    double U_peak = 2*U0;
    double U0_calculate = 0;
    double Kp_calculate = 0;

    double accuracy_Um_input = 0.05;
    double accuracy_C = 0.000001;

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
    }

    Ud_input = Um_input/sqrt(2);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RectifiersTwoPeriodCircuit::Inductor()
{
    if(Kp == 0.67)                                // проверкана величину индуктивности при выборе вкладки наличия фильтра
    {
        U0 = I0*Rn;
        Um_input = PI*U0/2;
        Ud_input = Um_input/sqrt(2);
        L = 0;
        return;
    }

    //новый алгоритм вычисления:
    U0 = I0*Rn;                                   // средневыпрямленное напряжение
    Um_input = U0;
    L = 0;

    double U_peak = U0;
    double I0_calculate = 0;
    double Kp_calculate = 0;

    double accuracy_Um_input = 0.1;
    double accuracy_L = 0.0001;

    double start_time = clock();
    double time_program = 0.0;

    while((I0_calculate < I0) || (abs(Kp_calculate - Kp) > 0.04))
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


        if(time_program > 8000)
        {
            accuracy_Um_input = 0.1;
            accuracy_L = 0.1;
            if(time_program > 25000)
            {
                accuracy_Um_input = 1;
                accuracy_L = 0.1;
            }
            if ((I0_calculate > I0) && (abs(Kp_calculate - Kp) < 0.05))
            {
                accuracy_Um_input = 0.01;
                accuracy_L = 0.001;
            }
        }

        if(time_program > 100000)
        {
            flagCalculate = true;
            break;
        }
    }

    Ud_input = Um_input/sqrt(2);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RectifiersTwoPeriodCircuit::Calculate()
{
    flagCalculate = false;

    U0 = I0*Rn;
    Um_input = PI*U0/2;
    Ud_input = Um_input/sqrt(2);

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
double RectifiersTwoPeriodCircuit::OutputVoltageWaveform(double t)
{
    double T = 1/f;
    int k = (int)(t/T);                        // диапазон периодичности

    if((k*T <= t) && (t <= (k*T + T/2)))       // первая полуволна
    {
        return Um_input*sin(2*PI*f*t);
    }

    if((k*T + T/2 <= t) && (t <= (k*T + T)))   // вторая полуволна
    {
        return -Um_input*sin(2*PI*f*t);
    }

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double RectifiersTwoPeriodCircuit::OutputCapacityVoltageWaveform(double t)
{
    double T = 1/f;

    if(t <= T/4)
    {
        return Um_input*sin(2*PI*f*t);
    }

    else
    {
        int k = (int)((t-T/4)/(T/2));     // диапазон периодичности

        if(((T/4 + k*T/2) <= t) && (t < (3*T/4 + k*T/2)))
        {
            double step1 = Um_input*exp(-(t-T/4-k*T/2)/(Rn*C));
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
double RectifiersTwoPeriodCircuit::OutputInductorCurrentWaveform(double t)
{
    double T = 1/f;
    double help = (t/(T/2));     // диапазон периодичности

    if((help == (int)help) && (help != 0))
        help--;

    int k = (int)help;

    if(k == 0)
    {
        double teta = atan(2*PI*f*L/Rn);
        double step = Um_input*(sin(2*PI*f*(t-k*T/2)-teta)+sin(teta)*exp(-Rn*(t-k*T/2)/L))/sqrt(pow(Rn,2)+pow(2*PI*f*L,2));

        if(step >= 0)
            return step;
        else
            return 0;

        return step;
    }
    else
    {
        double teta = atan(2*PI*f*L/Rn);

        double in_1 = OutputInductorCurrentWaveform(k*T/2);
        double in_2 = (Um_input*(sin(teta))/sqrt(pow(Rn,2)+pow(2*PI*f*L,2)));

        double C = in_1 + in_2;

        double step = C*exp(-Rn*(t-k*T/2)/L) + Um_input*(sin(2*PI*f*(t-k*T/2)-teta))/sqrt(pow(Rn,2)+pow(2*PI*f*L,2));

        if(step < 0)
            step = 0;

        return step;
    }

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RectifiersTwoPeriodCircuit::CalculateCapacityParameters(double* U0_calculate, double* Kp_calculate, double* U_peak)
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
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RectifiersTwoPeriodCircuit::CalculateInductorParameters(double* I0_calculate, double* Kp_calculate, double* U_peak)
{
    double T = 1/f;
    double accuracy_t = T/20;

    double Imax = 0;
    double Imin = 0;
    *I0_calculate = 0;

    if(Kp <= 0.05)
    {
        for(float time = 2*T; time < 3*T; time += accuracy_t)
        {
            double step = OutputInductorCurrentWaveform(time);
            if((T < time) && (time < (7*T/4 - 0.003)))
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
    }

    if(Kp > 0.05)
    {
        for(float time = T; time < 2*T; time += accuracy_t)
        {
            double step = OutputInductorCurrentWaveform(time);
            if((T < time) && (time < 7*T/4))
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
    }


    *I0_calculate = (*I0_calculate)/T;
    *Kp_calculate = (Imax - Imin)/2/(*I0_calculate);
    *U_peak = Imax*Rn;
}
