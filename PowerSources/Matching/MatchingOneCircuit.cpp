#include "MatchingOneCircuit.h"

MatchingOneCircuit::MatchingOneCircuit()
{

}

void MatchingOneCircuit::ViewFilters(int number)
{
    switch(number)
    {
        case 0:
            flagFilters = 0; // П-фильтр
        break;

        case 1:
            flagFilters = 1; // Модифицированный П-фильтр
        break;
    }
}

void MatchingOneCircuit::SetBaseValue(double _Ek, double _P, double _F, double _Rout, double _Q, double _RinCorrect)
{
    Ek = _Ek;
    P  = _P;
    F  = _F;
    Rh = _Rout;
    Q  = _Q;
    RinCorrect = _RinCorrect;
}

void MatchingOneCircuit::Calculate(bool _isCorrectRin)
{
    if (_isCorrectRin)
    {
        Rin = RinCorrect;
    }else
    {
        Rin = (Ek-0.2)*(Ek-0.2)/(2*P);
    }
    if (flagFilters == 0)
    {
        double l11 = 20./F;

        double ldr = 4*Rin/(2*3.1416*F);
        double ldr1 = 2.5*ldr;

        double Q_temp = 1*15.0;
        double kpd = 1 - (Q_temp/Q)+0.0000001;

        double ntr = Rin/Rh;
        double xc2 = (Rin - kpd * Rh) / (sqrt((ntr * (Q_temp * Q_temp + 1 + kpd * kpd) / kpd) - ntr * ntr - 1) - Q_temp);
        double c2 =  1e6 / (2 * 3.1416 * F  * xc2) ;

        double xc1 = Rin * xc2 / (Q_temp * xc2 - kpd * Rh) ;
        double c1 = 1e6  / (2 * 3.1416 * F * xc1);

        double xl = Rh * xc2 * xc2 * Q_temp / (kpd * (Rh * Rh + xc2 * xc2)) ;
        double l1 = xl / (2 * 3.1416 * F);
        kpd = kpd*100 ;

        C1 = c1;     // индуктивность
        L1 = l1;     // ёмкость
        C2 = c2;     // индуктивность
    }
    if(flagFilters == 1)
    {
        double l11 = 20/F;

        double ldr = 4*Rin/(2*PI*F);
        double ldr1 = 2.5*ldr;

        double Q_temp = 1*15;
        double kpd = 1 - (Q_temp/Q)+0.0000001;

        double ntr = Rh/Rh;
        double xc2 = (Rh - kpd * Rh) / (sqrt((ntr * (Q_temp * Q_temp + 1 + kpd * kpd) / kpd) - ntr * ntr - 1) - Q_temp) ;
        double c2 =  1e6 / (2 * 3.1416 * F  * xc2) ;

        double xc1 = Rh * xc2 / (Q_temp * xc2 - kpd * Rh) ;
        double c1 = 1e6  / (2 * 3.1416 * F * xc1);

        double xl = Rh * xc2 * xc2 * Q_temp / (kpd * (Rh * Rh + xc2 * xc2)) ;
        double l4 = xl / (2 * 3.1416 * F);
        kpd = kpd*kpd*100 ;

        double xc4 = Rh/sqrt(Rh/Rin-1) ;
        double c4 = 1e6  / (2 * 3.1416 * F * xc4);
        double xl1 = Rin*sqrt(Rh/Rin-1) ;
        double l1 = xl1 / (2 * 3.1416 * F);

        c1 = c1 + c4 ;

        C1 = c1;     // индуктивность
        L1 = l1;     // ёмкость
        C2 = c2;     // индуктивность
        L2 = l4;
    }
}



