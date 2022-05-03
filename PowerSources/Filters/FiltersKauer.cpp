#include "FiltersKauer.h"
using namespace std;
FiltersKauer::FiltersKauer()
{

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void FiltersKauer::SetBaseValue(double _f, double _R, int _n)
{
    f = _f;
    R = _R;
    n = _n;

}
void FiltersKauer::SetBaseValue(double _f, double _R, int _n, double _deltaf)
{
    f = _f;
    R = _R;
    n = _n;
    deltaf = _deltaf;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void FiltersKauer::ViewFilters(int number)
{
    switch(number)
    {
        case 0:
        flagFilters = 0; // ФНЧ
        break;

        case 1:
        flagFilters = 1; // ФВЧ
        break;

        case 2:
        flagFilters = 2; // ПФ
        break;

        case 3:
        flagFilters = 3; // ЗФ
        break;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void FiltersKauer::Calculate()
{
    // flagCalculate = false;
    if(flagFilters == 0) // Вычисление ФНЧ
    {
        //новый алгоритм вычисления:
        double KL, KC;

        KL = R / (2 * PI * f);
        KC = 1 / (2 * PI * f * R);


        if(n == 3)
        {
            C1 = KC*1.1395;
            C2 = KC*0.0669;
            L2 = KL*1.0844;
            C3 = KC*1.1395;
        }
    }

    if(flagFilters == 1) // Вычисление ФВЧ
    {
        //новый алгоритм вычисления:
        double KL, KC;
        KL = R / (2 * PI * f);
        KC = 1 / (2 * PI * f * R);
        if(n == 3)
        {
            L1 = KL/1.1395;
            L2 = KL/1.0844;
            C2 = KC/0.0669;
            L3 = KL/1.1395;
        }
    }

    if(flagFilters == 2) // Вычисление ПФ
    {

        double Q=f/deltaf;
        double KL, KC, Omega, delta_f2, f2_, f2, koef1, koef2;
        KL = R / (2 * PI * f);
        KC = 1 / (2 * PI * f * R);
        Omega = 3.7137;
        delta_f2 = Omega * deltaf;

        f2 = (delta_f2/2+ sqrt(delta_f2*delta_f2/4 + f*f));
        f2_= (-delta_f2/2+ sqrt(delta_f2*delta_f2/4 + f*f));

        koef1 = 1 + f*f/(f2*f2);
        koef2 = 1 + f*f/(f2_*f2_);

        if(n == 3)
        {
            C1 = KC * 1.1395 * Q;
            L1 = KL / 1.1395 / Q;
            C2 = KC * 0.0669 * Q * koef1;
            L2 = KL / 0.0669 / Q / koef2;
            C3 = KC * 0.0669 * Q * koef2;
            L3 = KL / 0.0669 / Q / koef1;
            C4 = KC * 1.1395 * Q;
            L4 = KL / 1.1395 / Q;
        }

    }

    if(flagFilters == 3) // Вычисление ЗФ
    {
        double Q=f/deltaf;
        double KL, KC, Omega, delta_f2, f2_, f2, koef1, koef2;
        KL = R / (2 * PI * f);
        KC = 1 / (2 * PI * f * R);

        Omega = 3.7137;
        delta_f2 =  deltaf * Omega;

        f2 = (delta_f2/2+ sqrt(delta_f2*delta_f2/4 + f*f));
        f2_= (-delta_f2/2+ sqrt(delta_f2*delta_f2/4 + f*f));

        koef1 = 1 + f*f/(f2*f2);
        koef2 = 1 + f*f/(f2_*f2_);

        if(n == 3)
        {
            C1 = KC * 1.1395 / Q;
            L1 = KL / 1.1395 * Q;

            C2 = KC * 0.0669 / Q * koef1;
            L2 = KL / 0.0669 * Q / koef2;

            C3 = KC * 0.0669 / Q * koef2;
            L3 = KL / 0.0669 * Q / koef1;

            C4 = KC * 1.1395 / Q;
            L4 = KL / 1.1395 * Q;
        }

    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double FiltersKauer::OutputWaveform(double f)
{
    if(flagFilters == 0)
    {
        if(n == 3)
        {
            complex<double> ZC1(0.0, -1 / (2 * PI * f * C1));
            complex<double> ZL2(0.0, 2 * PI * f * L2);
            complex<double> ZC2(0.0, -1 / (2 * PI * f * C2));
            complex<double> ZC3(0.0, -1 / (2 * PI * f * C3));
            complex<double> Z11=ZC1;
            complex<double> Z33=ZC3;
            complex<double> Z22=ZL2*ZC2/(ZC2+ZL2);

            complex<double> promegAP11 = Z22 / Z33 + R*(Z22+Z11+Z33)/(Z11*Z33);
            complex<double> AP11(1 + promegAP11.real(), promegAP11.imag());
            complex<double> promegAP12 = Z22 + R * (Z22 + Z11) / Z11;
            complex<double> AP12(promegAP12.real(), promegAP12.imag());
            complex<double> ACHX_nesogl = R / (R * AP11 + AP12);

            return abs(ACHX_nesogl) * 2;
        }

    }

    if(flagFilters == 1)
    {
        if(n == 3)
        {
            complex<double> ZL1(0.0, 2 * PI * f * L1);
            complex<double> ZC2(0.0, -1 / (2 * PI * f * C2));
            complex<double> ZL2(0.0, 2 * PI * f * L2);
            complex<double> ZL3(0.0, 2 * PI * f * L3);
            complex<double> Z11=ZL1;
            complex<double> Z33=ZL3;
            complex<double> Z22=ZL2*ZC2/(ZC2+ZL2);

            complex<double> promegAP11 = Z22 / Z33 + R*(Z22+Z11+Z33)/(Z11*Z33);
            complex<double> AP11(1 + promegAP11.real(), promegAP11.imag());
            complex<double> promegAP12 = Z22 + R * (Z22 + Z11) / Z11;
            complex<double> AP12(promegAP12.real(), promegAP12.imag());
            complex<double> ACHX_nesogl = R / (R * AP11 + AP12);

            return abs(ACHX_nesogl) * 2;
        }
    }



    if(flagFilters == 2)
    {
        if(n == 3)
        {
            complex<double> ZC1(0.0, -1 / (2 * PI * f * C1));
            complex<double> ZL1(0.0, 2 * PI * f * L1);
            complex<double> ZL2(0.0, 2 * PI * f * L2);
            complex<double> ZC2(0.0, -1 / (2 * PI * f * C2));
            complex<double> ZC3(0.0, -1 / (2 * PI * f * C3));
            complex<double> ZL3(0.0, 2 * PI * f * L3);
            complex<double> ZC4(0.0, -1 / (2 * PI * f * C4));
            complex<double> ZL4(0.0, 2 * PI * f * L4);

            complex<double> Z11=ZL1*ZC1/(ZC1+ZL1);
            complex<double> Z3=ZL3*ZC3/(ZC3+ZL3);
            complex<double> Z2=ZL2*ZC2/(ZC2+ZL2);
            complex<double> Z22=Z2+Z3;

            complex<double> promegAP11 = Z22 / Z11 + R*(Z22+Z11+Z11)/(Z11*Z11);
            complex<double> AP11(1 + promegAP11.real(), promegAP11.imag());
            complex<double> promegAP12 = Z22 + R * (Z22 + Z11) / Z11;
            complex<double> AP12(promegAP12.real(), promegAP12.imag());
            complex<double> ACHX_nesogl = R / (R * AP11 + AP12);

            return abs(ACHX_nesogl) * 2;
        }
    }
    if(flagFilters == 3)
       {
           if(n == 3)
           {
               complex<double> ZC1(0.0, -1 / (2 * PI * f * C1));
               complex<double> ZL1(0.0, 2 * PI * f * L1);
               complex<double> ZL2(0.0, 2 * PI * f * L2);
               complex<double> ZC2(0.0, -1 / (2 * PI * f * C2));
               complex<double> ZC3(0.0, -1 / (2 * PI * f * C3));
               complex<double> ZL3(0.0, 2 * PI * f * L3);
               complex<double> ZC4(0.0, -1 / (2 * PI * f * C4));
               complex<double> ZL4(0.0, 2 * PI * f * L4);

               complex<double> Z11=ZC1+ZL1;
               complex<double> Z3=ZL3*ZC3/(ZC3+ZL3);
               complex<double> Z2=ZL2*ZC2/(ZC2+ZL2);
               complex<double> Z22=Z2+Z3;

               complex<double> promegAP11 = Z22 / Z11 + R*(Z22+Z11+Z11)/(Z11*Z11);
               complex<double> AP11(1 + promegAP11.real(), promegAP11.imag());
               complex<double> promegAP12 = Z22 + R * (Z22 + Z11) / Z11;
               complex<double> AP12(promegAP12.real(), promegAP12.imag());
               complex<double> ACHX_nesogl = R / (R * AP11 + AP12);

               return abs(ACHX_nesogl) * 2;
           }

   }
return 0;
}
