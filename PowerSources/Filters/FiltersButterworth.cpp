#include "FiltersButterworth.h"

using namespace std;
FiltersButterworth::FiltersButterworth()
{

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void FiltersButterworth::SetBaseValue(double _f, double _R, int _n)
{
    f = _f;
    R = _R;
    n = _n;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void FiltersButterworth::ViewFilters(int number)
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
void FiltersButterworth::Calculate()
{
//    flagCalculate = false;

    if(flagFilters == 0)                              // Вычисление ФНЧ
    {
        //новый алгоритм вычисления:
        double KL, KC;
        KL = R / (2 * PI * f);
        KC = 1 / (2 * PI * f * R);
        if(n == 2)
        {
            C1 = KC * 1.414;
            L1 = KL * 1.414;
        }
        if(n == 3)
        {
            C1 = KC;
            L1 = KL * 2;
            C2 = KC;
        }
    }

    if(flagFilters == 1)                              // Вычисление ФВЧ
    {
        //новый алгоритм вычисления:
        double KL, KC;
        KL = R / (2 * PI * f);
        KC = 1 / (2 * PI * f * R);
        if(n == 2)
        {
            L1 = KL / 1.414;
            C1 = KC / 1.414;
        }
        if(n == 3)
        {
            L1 = KL;
            C1 = KC / 2;
            L2 = KL;
        }
    }

    if(flagFilters == 2)                              // Вычисление ПФ
    {
        //новый алгоритм вычисления:

    }

    if(flagFilters == 3)                              // Вычисление ЗФ
    {
        //новый алгоритм вычисления:

    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double FiltersButterworth::OutputWaveform(double f)
{
    if(flagFilters == 0)
    {
        if(n == 2)
        {
            complex<double> ZL11(0.0, 2 * PI * f * L1);                        // Импеданс катушки при разных частотах
            complex<double> ZC11(0.0, -1 / (2 * PI * f * C1));                 // Импеданс конденсатора при разных частотах
            complex<double> promegAG11_1 = (ZL11 + ZC11 + R) / ZC11;
            complex<double> AG11_1(promegAG11_1.real(), promegAG11_1.imag());  // параметр матрицы А11
            complex<double> promegAG12_1 = R + ZL11;
            complex<double> AG12_1(promegAG12_1.real(), promegAG12_1.imag());
            complex<double> ACHX_nesogl = R / (R * AG11_1 + AG12_1);

            return abs(ACHX_nesogl) * 2;
        }
        if(n == 3)
        {
            complex<double> ZC1(0.0, -1 / (2 * PI * f * C1));
            complex<double> ZL2(0.0, 2 * PI * f * L1);
            complex<double> ZC3(0.0, -1 / (2 * PI * f * C2));
            complex<double> promegAP11 = ZL2 / ZC3;
            complex<double> AP11(1 + promegAP11.real(), promegAP11.imag());
            complex<double> promegAP12 = ZL2 + R * (ZL2 + ZC3) / ZC3;
            complex<double> AP12(promegAP12.real(), promegAP12.imag());
            complex<double> ACHX_nesogl = R / (R * AP11 + AP12);

            return abs(ACHX_nesogl) * 2;
        }
        if(n == 2)
        {

        }
        if(n == 4)
        {

        }
        if(n == 5)
        {

        }
        if(n == 6)
        {

        }
    }

    if(flagFilters == 1)
    {
        if(n == 2)
        {
            complex<double> ZL11(0.0, 2 * PI * f * L1); // Импеданс катушки при разных частотах
            complex<double> ZC11(0.0, -1 / (2 * PI * f * C1));// Импеданс конденсатора при разных частотах
            complex<double> promegAG11_1 = (ZC11 + ZL11 + R) / ZL11;
            complex<double> AG11_1(promegAG11_1.real(), promegAG11_1.imag()); // параметр матрицы А11
            complex<double> promegAG12_1 = R + ZC11;
            complex<double> AG12_1(promegAG12_1.real(), promegAG12_1.imag());
            complex<double> ACHX_nesogl = R / (R * AG11_1 + AG12_1);

            return abs(ACHX_nesogl) * 2;
        }
        if(n == 3)
        {
            complex<double> ZL1(0.0, 2 * PI * f * L1);
            complex<double> ZC2(0.0, -1 / (2 * PI * f * C1));
            complex<double> ZL3(0.0, 2 * PI * f * L2);
            complex<double> promegAP11 = ZC2 / ZL3;
            complex<double> AP11(1 + promegAP11.real(), promegAP11.imag());
            complex<double> promegAP12 = ZC2 + R * (ZC2 + ZL3) / ZL3;
            complex<double> AP12(promegAP12.real(), promegAP12.imag());
            complex<double> ACHX_nesogl = R / (R * AP11 + AP12);

            return abs(ACHX_nesogl) * 2;
        }
        if(n == 2)
        {

        }
        if(n == 4)
        {

        }
        if(n == 5)
        {

        }
        if(n == 6)
        {

        }
    }
    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double FiltersButterworth::OutputWaveformFCHX(double f)
{
    if(flagFilters == 0)
    {
        if(n == 2)
        {
            complex<double> ZL11(0.0, 2 * PI * f * L1);                        // Импеданс катушки при разных частотах
            complex<double> ZC11(0.0, -1 / (2 * PI * f * C1));                 // Импеданс конденсатора при разных частотах
            complex<double> promegAG11_1 = (ZL11 + ZC11 + R) / ZC11;
            complex<double> AG11_1(promegAG11_1.real(), promegAG11_1.imag());  // параметр матрицы А11
            complex<double> promegAG12_1 = R + ZL11;
            complex<double> AG12_1(promegAG12_1.real(), promegAG12_1.imag());
            complex<double> ACHX_nesogl = R / (R * AG11_1 + AG12_1);

            return arg(ACHX_nesogl) * 180/PI;
        }
        if(n == 3)
        {
            complex<double> ZC1(0.0, -1 / (2 * PI * f * C1));
            complex<double> ZL2(0.0, 2 * PI * f * L1);
            complex<double> ZC3(0.0, -1 / (2 * PI * f * C2));
            complex<double> promegAP11 = ZL2 / ZC3;
            complex<double> AP11(1 + promegAP11.real(), promegAP11.imag());
            complex<double> promegAP12 = ZL2 + R * (ZL2 + ZC3) / ZC3;
            complex<double> AP12(promegAP12.real(), promegAP12.imag());
            complex<double> ACHX_nesogl = R / (R * AP11 + AP12);

            return arg(ACHX_nesogl) * 180/PI;
        }
        if(n == 2)
        {

        }
        if(n == 4)
        {

        }
        if(n == 5)
        {

        }
        if(n == 6)
        {

        }
    }

    if(flagFilters == 1)
    {
        if(n == 2)
        {
            complex<double> ZL11(0.0, 2 * PI * f * L1); // Импеданс катушки при разных частотах
            complex<double> ZC11(0.0, -1 / (2 * PI * f * C1));// Импеданс конденсатора при разных частотах
            complex<double> promegAG11_1 = (ZC11 + ZL11 + R) / ZL11;
            complex<double> AG11_1(promegAG11_1.real(), promegAG11_1.imag()); // параметр матрицы А11
            complex<double> promegAG12_1 = R + ZC11;
            complex<double> AG12_1(promegAG12_1.real(), promegAG12_1.imag());
            complex<double> ACHX_nesogl = R / (R * AG11_1 + AG12_1);
            double phase = arg(ACHX_nesogl) * 180/PI;
            return phase;
        }
        if(n == 3)
        {
            complex<double> ZL1(0.0, 2 * PI * f * L1);
            complex<double> ZC2(0.0, -1 / (2 * PI * f * C1));
            complex<double> ZL3(0.0, 2 * PI * f * L2);
            complex<double> promegAP11 = ZC2 / ZL3;
            complex<double> AP11(1 + promegAP11.real(), promegAP11.imag());
            complex<double> promegAP12 = ZC2 + R * (ZC2 + ZL3) / ZL3;
            complex<double> AP12(promegAP12.real(), promegAP12.imag());
            complex<double> ACHX_nesogl = R / (R * AP11 + AP12);

            return arg(ACHX_nesogl) * 180/PI;
        }
        if(n == 2)
        {

        }
        if(n == 4)
        {

        }
        if(n == 5)
        {

        }
        if(n == 6)
        {

        }
    }
    return 0;
}
