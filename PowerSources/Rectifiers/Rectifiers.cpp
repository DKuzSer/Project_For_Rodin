#include "Rectifiers.h"
#include "ui_Rectifiers.h"

#include "RectifiersOnePeriodCircuit.h"
#include "RectifiersTwoPeriodCircuit.h"

Rectifiers::Rectifiers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rectifiers)
{
    ui->setupUi(this);

    ui->ComboBox_OutPutF->setVisible(false); // установление невидимыми параметра установки фильтра на выходе выпрямителя
    ui->Label_OutPutF->setVisible(false);   // установление невидимыми параметра установки фильтра на выходе выпрямителя

    ui->ComboBox_DevicesR->addItem("Однополупериодный", ONEPERIODCIRCUIT); // добавление однополупериодного выпрямителя в окно устройств
    ui->ComboBox_DevicesR->addItem("Мостовая схема (схема Греца)", TWOPERIODCIRCUIT);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Rectifiers::~Rectifiers()
{
    delete chrt;
    delete object_work;
    delete ui;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Rectifiers::on_ComboBox_DevicesR_currentIndexChanged(int index)
{
    switch(index) // условие обработки выбора устройства
    {
        case ONEPERIODCIRCUIT:
            if(object_work != nullptr)
            {
                delete object_work;
                object_work = new  RectifiersOnePeriodCircuit();
            }
            else
                object_work = new  RectifiersOnePeriodCircuit();

            ui->ComboBox_OutPutF->setVisible(true);
            ui->Label_OutPutF->setVisible(true);

            //настройки входных данных
            //----------------------------------------------
            ui->Label_InPut1->setVisible(true);
            ui->Label_InPut1->setText("f (Частота напряжения на входе), Гц:");
            ui->DoubleSpinBoxR_InPut1->setVisible(true);

            ui->Label_InPut2->setVisible(true);
            ui->Label_InPut2->setText("I0 (Средний выпрямленный ток на нагрузке), А:");
            ui->DoubleSpinBoxR_InPut2->setVisible(true);

            ui->Label_InPut3->setVisible(true);
            ui->Label_InPut3->setText("Iдоп (Допустимый ток на диоде), А:");
            ui->DoubleSpinBoxR_InPut3->setVisible(true);

            ui->Label_InPut4->setVisible(true);
            ui->Label_InPut4->setText("Rн (Сопротивление нагрузки), Ом:");
            ui->DoubleSpinBoxR_InPut4->setVisible(true);

            ui->Label_InPut6->setVisible(false);
            ui->DoubleSpinBoxR_InPut6->setVisible(false);
            //----------------------------------------------

            //настройки выходных данных
            //----------------------------------------------
            ui->DoubleSpinBoxR_OutPut1->setEnabled(true);
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("m (Количество диодов), шт:");
            ui->DoubleSpinBoxR_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("Uд (Действующее напряжение на вторичной обмотке), В:");
            ui->DoubleSpinBoxR_OutPut2->setVisible(true);

            ui->Label_OutPut3->setVisible(false);
            ui->DoubleSpinBoxR_OutPut3->setVisible(false);
            ui->Label_OutPut4->setVisible(false);
            ui->DoubleSpinBoxR_OutPut4->setVisible(false);
            ui->Label_OutPut5->setVisible(false);
            ui->DoubleSpinBoxR_OutPut5->setVisible(false);
            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxR_OutPut6->setVisible(false);
            //----------------------------------------------

            ui->ComboBox_OutPutF->clear();
            ui->ComboBox_OutPutF->addItem("Нет", 0);
            ui->ComboBox_OutPutF->addItem("C фильтр", 1);
            ui->ComboBox_OutPutF->addItem("L фильтр", 2);

        break;

        case TWOPERIODCIRCUIT:
            if(object_work != nullptr)
            {
                delete object_work;
                object_work = new  RectifiersTwoPeriodCircuit();
            }
            else
                object_work = new  RectifiersTwoPeriodCircuit();

            ui->ComboBox_OutPutF->setVisible(true);
            ui->Label_OutPutF->setVisible(true);

            //настройки входных данных
            //----------------------------------------------
            ui->Label_InPut1->setVisible(true);
            ui->Label_InPut1->setText("f (Частота напряжения на входе), Гц:");
            ui->DoubleSpinBoxR_InPut1->setVisible(true);

            ui->Label_InPut2->setVisible(true);
            ui->Label_InPut2->setText("I0 (Средний выпрямленный ток на нагрузке), А:");
            ui->DoubleSpinBoxR_InPut2->setVisible(true);

            ui->Label_InPut3->setVisible(true);
            ui->Label_InPut3->setText("Iдоп (Допустимый ток на диоде), А:");
            ui->DoubleSpinBoxR_InPut3->setVisible(true);

            ui->Label_InPut4->setVisible(true);
            ui->Label_InPut4->setText("Rн (Сопротивление нагрузки), Ом:");
            ui->DoubleSpinBoxR_InPut4->setVisible(true);

            ui->Label_InPut6->setVisible(false);
            ui->DoubleSpinBoxR_InPut6->setVisible(false);
            //----------------------------------------------

            //настройки выходных данных
            //----------------------------------------------
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("m (Количество диодов), шт:");
            ui->DoubleSpinBoxR_OutPut1->setVisible(true);
            ui->DoubleSpinBoxR_OutPut1->setValue(4);
            ui->DoubleSpinBoxR_OutPut1->setEnabled(false);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("Uд (Действующее напряжение на вторичной обмотке), В:");
            ui->DoubleSpinBoxR_OutPut2->setVisible(true);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("Uобр (Обратное напряжение на диоде), В:");
            ui->DoubleSpinBoxR_OutPut3->setVisible(true);

            ui->Label_OutPut4->setVisible(false);
             ui->Label_OutPut4->setText("Iд (Ток на диоде), А:");
            ui->DoubleSpinBoxR_OutPut4->setVisible(false);

            ui->Label_OutPut5->setVisible(false);
            ui->DoubleSpinBoxR_OutPut5->setVisible(false);
            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxR_OutPut6->setVisible(false);
            //----------------------------------------------

            ui->ComboBox_OutPutF->clear();
            ui->ComboBox_OutPutF->addItem("Нет", 0);
            ui->ComboBox_OutPutF->addItem("C фильтр", 1);
            ui->ComboBox_OutPutF->addItem("L фильтр", 2);

    break;
    }

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Rectifiers::on_ComboBox_OutPutF_currentIndexChanged(int index)
{
    int index2 = ui->ComboBox_DevicesR->currentIndex();

    if (index2 == ONEPERIODCIRCUIT)// условие обработки выбора устройства
    {
            switch(index) // условие обработки выбора фильтра на выходе выпрямителя
            {
                case 0:
                    ui->Label_InPut5->setVisible(true);
                    ui->DoubleSpinBoxR_InPut5->setVisible(true);
                    ui->Label_InPut5->setText("Kp (Коэффициент пульсаций):");

                    object_work->Kp = 1.57;
                    ui->DoubleSpinBoxR_InPut5->setValue(object_work->Kp);
                    ui->DoubleSpinBoxR_InPut5->setEnabled(false);

                    ui->Label_OutPut3->setVisible(false);
                    ui->DoubleSpinBoxR_OutPut1->setEnabled(false);
                    ui->DoubleSpinBoxR_OutPut2->setEnabled(false);
                    ui->DoubleSpinBoxR_OutPut3->setVisible(false);

                    mapCircuit.load(":/image/img/ROPCircuit1.jpg");
                    mapProperties.load(":/image/img/ROPCircuitProperties.jpg");
                    ui->Label_PixMapCircuit->setPixmap(mapCircuit);
                    ui->Label_PixMapCircuit->setScaledContents(true);
                    ui->Label_PixMapProperties->setPixmap(mapProperties);
                    ui->Label_PixMapProperties->setScaledContents(true);

                break;

                case 1:
                    ui->Label_InPut5->setVisible(true);
                    ui->DoubleSpinBoxR_InPut5->setVisible(true);
                    ui->Label_InPut5->setText("Kp (Коэффициент пульсаций):");
                    ui->DoubleSpinBoxR_InPut5->setMaximum(1.57);
                    ui->DoubleSpinBoxR_InPut5->setMinimum(0);
                    ui->DoubleSpinBoxR_InPut5->setEnabled(true);

                    ui->Label_OutPut3->setVisible(true);
                    ui->Label_OutPut3->setText("C, мкФ:");
                    ui->DoubleSpinBoxR_OutPut3->setVisible(true);
                    ui->DoubleSpinBoxR_OutPut1->setEnabled(false);
                    ui->DoubleSpinBoxR_OutPut2->setEnabled(false);
                    ui->DoubleSpinBoxR_OutPut3->setEnabled(false);

                    mapCircuit.load(":/image/img/ROPCircuit2.jpg");
                    mapProperties.load(":/image/img/ROPCircuitProperties.jpg");
                    ui->Label_PixMapCircuit->setPixmap(mapCircuit);
                    ui->Label_PixMapCircuit->setScaledContents(true);
                    ui->Label_PixMapProperties->setPixmap(mapProperties);
                    ui->Label_PixMapProperties->setScaledContents(true);

                break;

                case 2:
                    ui->Label_InPut5->setVisible(true);
                    ui->DoubleSpinBoxR_InPut5->setVisible(true);
                    ui->Label_InPut5->setText("Kp (Коэффициент пульсаций):");
                    ui->DoubleSpinBoxR_InPut5->setMaximum(1.57);
                    ui->DoubleSpinBoxR_InPut5->setMinimum(0);
                    ui->DoubleSpinBoxR_InPut5->setEnabled(true);

                    ui->Label_OutPut3->setVisible(true);
                    ui->Label_OutPut3->setText("L, мГн:");
                    ui->DoubleSpinBoxR_OutPut3->setVisible(true);
                    ui->DoubleSpinBoxR_OutPut1->setEnabled(false);
                    ui->DoubleSpinBoxR_OutPut2->setEnabled(false);
                    ui->DoubleSpinBoxR_OutPut3->setEnabled(false);

                    mapCircuit.load(":/image/img/ROPCircuit3.jpg");
                    mapProperties.load(":/image/img/ROPCircuitProperties.jpg");
                    ui->Label_PixMapCircuit->setPixmap(mapCircuit);
                    ui->Label_PixMapCircuit->setScaledContents(true);
                    ui->Label_PixMapProperties->setPixmap(mapProperties);
                    ui->Label_PixMapProperties->setScaledContents(true);

                break;
        }
    }
    if (index2 == TWOPERIODCIRCUIT)
    {
        switch(index)
        {
            case 0:
                ui->Label_InPut5->setVisible(true);
                ui->DoubleSpinBoxR_InPut5->setVisible(true);
                ui->Label_InPut5->setText("Kp (Коэффициент пульсаций):");

                object_work->Kp = 0.667;
                ui->DoubleSpinBoxR_InPut5->setValue(object_work->Kp);
                ui->DoubleSpinBoxR_InPut5->setEnabled(false);

                ui->Label_OutPut3->setVisible(false);
                ui->DoubleSpinBoxR_OutPut3->setVisible(false);
                ui->DoubleSpinBoxR_OutPut1->setEnabled(false);
                ui->DoubleSpinBoxR_OutPut2->setEnabled(false);
                ui->DoubleSpinBoxR_OutPut3->setEnabled(false);

            break;

            case 1:
                ui->Label_InPut5->setVisible(true);
                ui->DoubleSpinBoxR_InPut5->setVisible(true);
                ui->Label_InPut5->setText("Kp (Коэффициент пульсаций):");
                ui->DoubleSpinBoxR_InPut5->setMaximum(0.667);
                ui->DoubleSpinBoxR_InPut5->setMinimum(0);
                ui->DoubleSpinBoxR_InPut5->setEnabled(true);

                ui->Label_OutPut3->setVisible(true);
                ui->Label_OutPut3->setText("C, мкФ:");
                ui->DoubleSpinBoxR_OutPut3->setVisible(true);
                ui->DoubleSpinBoxR_OutPut1->setEnabled(false);
                ui->DoubleSpinBoxR_OutPut2->setEnabled(false);
                ui->DoubleSpinBoxR_OutPut3->setEnabled(false);

            break;

            case 2:
                ui->Label_InPut5->setVisible(true);
                ui->DoubleSpinBoxR_InPut5->setVisible(true);
                ui->Label_InPut5->setText("Kp (Коэффициент пульсаций):");
                ui->DoubleSpinBoxR_InPut5->setMaximum(0.667);
                ui->DoubleSpinBoxR_InPut5->setMinimum(0);
                ui->DoubleSpinBoxR_InPut5->setEnabled(true);

                ui->Label_OutPut3->setVisible(true);
                ui->Label_OutPut3->setText("L, мГн:");
                ui->DoubleSpinBoxR_OutPut3->setVisible(true);
                ui->DoubleSpinBoxR_OutPut1->setEnabled(false);
                ui->DoubleSpinBoxR_OutPut2->setEnabled(false);
                ui->DoubleSpinBoxR_OutPut3->setEnabled(false);

            break;
        }
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Rectifiers::on_PushButton_Calculate_clicked()
{
    int index = ui->ComboBox_DevicesR->currentIndex();
    if (index == TWOPERIODCIRCUIT)
    {
        if(chrt == nullptr)
        {
            chrt = new MyCharts();
            ui->graphicsView->setChart(chrt);
            chrt->setTitle("Выходное напряжение на нагрузке");
            chrt->legend()->hide();
        }
        else
            chrt->DeleteChart();

        double value_1 = ui->DoubleSpinBoxR_InPut1->value();
        double value_2 = ui->DoubleSpinBoxR_InPut2->value();
        double value_3 = ui->DoubleSpinBoxR_InPut3->value();
        double value_4 = ui->DoubleSpinBoxR_InPut4->value();
        double value_5 = ui->DoubleSpinBoxR_InPut5->value();

        double freq = value_1; //Копирую в другие переменные
        double Resistance = value_4;

        int chose = ui->ComboBox_OutPutF->currentIndex();
        object_work->SetBaseValue(value_1, value_2, value_4);        // передаём данные в расчётный класс
        object_work->FFilters(chose);                                // передаём данные флага установки фильтра на выходе
        object_work->Idop = value_3;
        object_work->Kp = value_5;
        object_work->Calculate();

        //переписываем в удобный формат
        //--------------------------------------------------

        value_2 = object_work->Ud_input;
        if(chose != 0)
        {
            if(chose == 1)
                value_3 = object_work->C;
            if(chose == 2)
                value_3 = object_work->L;
        }
        //--------------------------------------------------


        ui->DoubleSpinBoxR_OutPut2->setValue(value_2);
        ui->DoubleSpinBoxR_OutPut3->setValue(value_3);

        //-------------------------------------------------------

        QLineSeries series; //без фильтров

        double T = 1./freq;
        double n = 0; //счетчик для задания условия переодичности
        for (double i = 0.0; i <= 2.*T; i = i + 0.00001)
        {
            if (5*T/4 < i && i < 5*T/4+0.00001)
            {
                n=n+1.0;
            }

            if(chose == 0) // без катушки и кондера
            {
                series.append(i*1000, fabs(sqrt(2)*value_2*sin(2*M_PI*freq*i)));
            }
            if(chose == 1) // кондер
            {
                if(sqrt(2)*value_2*sin(2*M_PI*freq*i)<sqrt(2)*value_2*exp(-((i-(T/4)-T*n)/(Resistance*value_3*pow(10,(-6))))) && (T/4<i))
                {

                    series.append(i*1000, sqrt(2)*value_2*exp(-((i-(T/4)-T*n)/(Resistance*value_3*pow(10,(-6))))));
                }
                else
                {
                    series.append(i*1000, sqrt(2)*value_2*sin(2*M_PI*freq*i));
                }
            }
            if (chose == 2)   // катушка
            {
                if(sqrt(2)*value_2*sin(2*M_PI*freq*i)<sqrt(2)*value_2*exp(-((i-(T/4)-T*n)*Resistance/(value_3*pow(10,(-3))))) && (T/4<i))
                {
                    series.append(i*1000, sqrt(2)*value_2*exp(-((i-(T/4)-T*n)*Resistance)/(value_3*pow(10,(-3)))));
                }
                else
                {
                    series.append(i*1000, sqrt(2)*value_2*sin(2*M_PI*freq*i));
                }
            }
        }

        chrt->Create2DChart(series.points());
        chrt->PropertiesAxis("X", 0, 2/freq, 11, "%.2lf");
        chrt->PropertiesAxis("Y", -0.5, 1.5*value_2, 11, "%.2lf");

        //-------------------------------------------------------
    }
    if (index == ONEPERIODCIRCUIT) // условие обработки выбора устройства
    {
        if(chrt == nullptr)
        {
            chrt = new MyCharts();
            ui->graphicsView->setChart(chrt);
            chrt->setTitle("Выходное напряжение на нагрузке");
            chrt->legend()->hide();
        }
        else if(object_work->flagCalculate == false)
        {
            chrt->DeleteChart();
        }

        //переписываем в удобный формат
        //--------------------------------------------------
        double value_1 = ui->DoubleSpinBoxR_InPut1->value();
        double value_2 = ui->DoubleSpinBoxR_InPut2->value();
        double value_3 = ui->DoubleSpinBoxR_InPut3->value();
        double value_4 = ui->DoubleSpinBoxR_InPut4->value();
        double value_5 = ui->DoubleSpinBoxR_InPut5->value();


        double freq = value_1; //Копирую в другие переменные
        double Resistance = value_4;
        double Uaverage = Resistance * value_2;
        //--------------------------------------------------
        int chose = ui->ComboBox_OutPutF->currentIndex();
        object_work->SetBaseValue(value_1, value_2, value_4);        // передаём данные в расчётный класс
        object_work->FFilters(chose);                                // передаём данные флага установки фильтра на выходе
        object_work->Idop = value_3;
        object_work->Kp = value_5;
        object_work->Calculate();

        if(object_work->flagCalculate == true)
        {
            QMessageBox::information(this,"Ошибка","Данные параметры нельзя реализовать");
            return;
        }

        //переписываем в удобный формат
        //--------------------------------------------------
        value_1 = object_work->m;
        value_2 = object_work->Ud_input;
        if(chose != 0)
        {
            if(chose == 1)
                value_3 = object_work->C*1000000;
            else
                value_3 = object_work->L*1000; // приведение к мГн
        }
        //--------------------------------------------------

        ui->DoubleSpinBoxR_OutPut1->setValue(value_1);
        ui->DoubleSpinBoxR_OutPut2->setValue(value_2);
        ui->DoubleSpinBoxR_OutPut3->setValue(value_3);

        //-------------------------------------------------------
        //делаем график

        QLineSeries series;
        QLineSeries series_average;

        double T = 1./freq;
        for (float i = 0.0; i <= 2.*T; i += 0.00001)
        {
            if(chose == 0)    // без катушки и кондера
            {
                series.append(i*1000, object_work->OutputVoltageWaveform(i));
                series_average.append(i*1000, Uaverage);
            }

            if(chose == 1)    // кондер
            {
                series.append(i*1000, object_work->OutputCapacityVoltageWaveform(i));
                series_average.append(i*1000, Uaverage);
            }

            if (chose == 2)   // катушка
            {
                series.append(i*1000, object_work->OutputInductorCurrentWaveform(i)*Resistance);
                series_average.append(i*1000, Uaverage);
            }
        }

        double max = 0;
        for(int i = 0; i < series.pointsVector().size(); i++)
        {
            double step = series.pointsVector().at(i).y();
            if(step > max)
            {
                max = step;
            }
        }

        chrt->Create2DChart(series.points());
        chrt->PropertiesAxis("X", 0, 2/freq*1000, 11, "%.2lf");
        chrt->PropertiesAxis("Y", -0.2, 1.5*max, 11, "%.2lf");
        chrt->SetNameAxis("Время, мс", "Напряжение, В");
        chrt->AddSeries2DChart(series_average.points(), "Среднее напряжение");

        //-------------------------------------------------------
    }
}