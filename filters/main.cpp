#include <iostream>
#include <string>
using namespace std;
#include <complex>
#include <vector>
#include <fstream>
const double PI = 3.141592653589793;
using namespace std;
int main()
{
    int R;
    bool q1,q2;
    long double cutoff_frequency, KL, KC;
    cout << "Is filter high pass?[y/n] ";
    cin >> q1;
    cout << "Is filter low pass?[y/n] ";
    cin >> q2;
    cout << "R = ";
    cin >> R;
    cout << endl;
    cout<< "cutoff frequency = ";
    cin >> cutoff_frequency;
    cout << endl;
    KL = R / (2 * PI * cutoff_frequency);
    KC = 1 / (2 * PI * cutoff_frequency * R);
    cout << "KL= " << KL << " uhenry" << endl<< "KC= " << KC  << " picofarad" << endl;
    cout << "Enter the filter order" << endl;
    int n;
    cin>>n;
    if (q2) {
        if (n == 2) {
            long double C1 = KC * 1.414;
            long double  L2 = KL * 1.414;
            cout << "C1 = " << C1 << endl;
            cout << "L2 = " << L2 << endl;
           // vector < long double > amplfreqresp(1200);
            cout << "amplitude frequency response" << endl;// Вывод АЧХ фильтра
            for (double i = 1; i < 4 * cutoff_frequency; i += cutoff_frequency / 200)
            {
                complex<long double> ZL11(0.0, 2 * PI * i * L2); // Импеданс катушки при разных частотах
                complex<long double> ZC11(0.0, -1 / (2 * PI * i * C1));// Импеданс конденсатора при разных частотах
                complex<long double> promegAG11_1 = (ZL11 + ZC11 + (complex<long double>)R) / ZC11;
                complex<long double> AG11_1(promegAG11_1.real(), promegAG11_1.imag()); // параметр матрицы А11
                complex<long double> promegAG12_1 = (complex<long double>)R + ZL11;
                complex<long double>AG12_1(promegAG12_1.real(), promegAG12_1.imag());
                complex<long double> ACHX_nesogl = (complex<long double>)R / ((complex<long double>)R * AG11_1 + AG12_1);
                cout << "ACHX_nesogl = " << abs(ACHX_nesogl) * 2 << " freq = " << i << endl;
                //amplfreqresp.push_back(abs(ACHX_nesogl));
            }
        }   else if (n == 3) {
            long double  C1 = KC;
            long double  L2 = KL * 2;
            long double  C3 = KC;
            cout << " C1 = " << C1 << endl;
            cout << " L2 = " << L2 << endl;
            cout << " C3 = " << C3 << endl;
            cout << "amplitude frequency response" << endl;
            //vector < long double > amplfreqresp(1200);
            for (double i = 1; i < 4 * cutoff_frequency; i += cutoff_frequency / 200)
            {
                complex<long double> ZC1(0.0, -1 / (2 * PI * i * C1));

                complex<long double> ZL2(0.0, 2 * PI * i * L2);

                complex<long double> ZC3(0.0, -1 / (2 * PI * i * C3));

                complex<long double>promegAP11 = ZL2 / ZC3;

                complex<long double> AP11(1 + promegAP11.real(), promegAP11.imag());

                complex<long double>promegAP12 = ZL2 + (complex<long double>)R * (ZL2 + ZC3) / ZC3;

                complex<long double> AP12(promegAP12.real(), promegAP12.imag());

                complex<long double> ACHX_nesogl = (complex<long double>)R / ((complex<long double>)R * AP11 + AP12);

                cout << "ACHX_nesogl = " << abs(ACHX_nesogl) * 2 << " freq = " << i << endl;
                //amplfreqresp.push_back(abs(ACHX_nesogl) * 2);
            }
            cout << "amplitude frequency response" << endl;
          /*  vector < long double > freq(1200);
            for (int i = 1; i < 1201; i++)
            {
                // cout << cutoff_frequency * i / 600 << endl;
                freq.push_back(i);
            }*/
        }
        else {

            cout << "Sorry, we haven't done anything about this order yet" << endl;
        }
    }
    if (q1) {
        if (n == 2) {
            long double L1 = KL / 1.414;
            long double  C2 = KC / 1.414;
            cout << "L1 = " << L1 << endl;
            cout << "C2 = " << C2 << endl;
           // vector < long double > amplfreqresp(1200);
            cout << "amplitude frequency response" << endl;// Вывод АЧХ фильтра
            for (double i = 1; i < 4 * cutoff_frequency; i += cutoff_frequency / 200)
            {
                complex<long double> ZL11(0.0, 2 * PI * i * L1); // Импеданс катушки при разных частотах
                complex<long double> ZC11(0.0, -1 / (2 * PI * i * C2));// Импеданс конденсатора при разных частотах
                complex<long double> promegAG11_1 = (ZC11 + ZL11 + (complex<long double>)R) / ZL11;
                complex<long double> AG11_1(promegAG11_1.real(), promegAG11_1.imag()); // параметр матрицы А11
                complex<long double> promegAG12_1 = (complex<long double>)R + ZC11;
                complex<long double>AG12_1(promegAG12_1.real(), promegAG12_1.imag());
                complex<long double> ACHX_nesogl = (complex<long double>)R / ((complex<long double>)R * AG11_1 + AG12_1);
                cout << "ACHX_nesogl = " << abs(ACHX_nesogl) * 2 << " freq = " << i << endl;
              //  amplfreqresp.push_back(abs(ACHX_nesogl));
            }
            cout << "amplitude frequency response" << endl;
           /* vector < long double > freq(1200);
            for (int i = 1; i < 1201; i++)
            {
                //cout << cutoff_frequency * i / 600<<endl;
                freq.push_back(i);
            }
             ofstream fout;
              fout.open("myFile.txt");
              if (!fout.is_open())
              {
                  cout << "data output error" << endl;
              } else {

                  fout >> ;
                  fout >> ;

              }
              fout.close();*/
        }
        else if (n == 3) {
            long double  L1 = KL;
            long double  C2 = KC / 2;
            long double  L3 = KL;
            cout << " L1 = " << L1 << endl;
            cout << " C2 = " << C2 << endl;
            cout << " L3 = " << L3 << endl;
            cout << "amplitude frequency response" << endl;
          //  vector < long double > amplfreqresp(1200);
            for (double i = 1; i < 4 * cutoff_frequency; i += cutoff_frequency / 200)
            {
                complex<long double> ZL1(0.0, 2 * PI * i * L1);

                complex<long double> ZC2(0.0, -1 / (2 * PI * i * C2));

                complex<long double> ZL3(0.0, 2 * PI * i * L3);

                complex<long double>promegAP11 = ZC2 / ZL3;

                complex<long double> AP11(1 + promegAP11.real(), promegAP11.imag());

                complex<long double>promegAP12 = ZC2 + (complex<long double>)R * (ZC2 + ZL3) / ZL3;

                complex<long double> AP12(promegAP12.real(), promegAP12.imag());

                complex<long double> ACHX_nesogl = (complex<long double>)R / ((complex<long double>)R * AP11 + AP12);

                cout << "ACHX_nesogl = " << abs(ACHX_nesogl) * 2 << " freq = " << i << endl;
               // amplfreqresp.push_back(abs(ACHX_nesogl) * 2);
            }
            cout << "amplitude frequency response" << endl;
            /*vector < long double > freq(1200);
            for (int i = 1; i < 1201; i++)
            {
                // cout << cutoff_frequency * i / 600 << endl;
                freq.push_back(i);
            }*/
        }
        else {

            cout << "Sorry, we haven't done anything about this order yet" << endl;
        }
    }
   // cout << "Amplitude Frequency Response\n";
    return 0;
}
