#include "Rectifiers.h"
#include "ui_Rectifiers.h"

#include "RectifiersOnePeriodCircuit.h"
#include "RectifiersTwoPeriodCircuit.h"

Rectifiers::Rectifiers(MainpowerSourcesAbstract *parent) :
    ui(new Ui::Rectifiers)
{
    ui->setupUi(this);

    base = new diod_base();

    View = new MyChartsView();
    ui->ChartsLayout->addWidget(View);
    View ->setRenderHint(QPainter::Antialiasing);

    ui->ComboBox_OutPutF->setVisible(false); // установление невидимыми параметра установки фильтра на выходе выпрямителя
    ui->Label_OutPutF->setVisible(false);   // установление невидимыми параметра установки фильтра на выходе выпрямителя

    ui->ComboBox_DevicesR->addItem("Однополупериодный", ONEPERIODCIRCUIT); // добавление однополупериодного выпрямителя в окно устройств
    ui->ComboBox_DevicesR->addItem("Мостовая схема (схема Греца)", TWOPERIODCIRCUIT);

    ui->DoubleSpinBoxOX->setEnabled(false);
    ui->DoubleSpinBoxOY->setEnabled(false);

    connect(View,&MyChartsView::signalCoordinateCursor,this,&Rectifiers::CoordinateCursor);

    connect(this,&Rectifiers::signal_diod_base,base,&diod_base::slot_diod_base);

    connect(base,&diod_base::signal_data_update,this,&Rectifiers::diod_base_update);
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Rectifiers::~Rectifiers()
{
    delete chrt;
    delete View;
    delete object_work;
    delete ui;
    delete base;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Rectifiers::SetDiodsParameters(std::vector <QString> _names_of_diods, std::vector <int> _Uobr_max, std::vector <double> _Ipr)
{
    names_of_diods = _names_of_diods;
    Uobr_max = _Uobr_max;
    Ipr = _Ipr;
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

            ui->Label_InPut3->setVisible(false);
            ui->Label_InPut3->setText("Iдоп (Допустимый ток на диоде), А:");
            ui->DoubleSpinBoxR_InPut3->setVisible(false);

            ui->Label_InPut4->setVisible(false);
            ui->Label_InPut4->setText("Rн (Сопротивление нагрузки), Ом:");
            ui->DoubleSpinBoxR_InPut4->setVisible(false);

            ui->Label_InPut6->setVisible(true);
            ui->Label_InPut6->setText("Uн (Напряжение на нагрузке), В:");
            ui->DoubleSpinBoxR_InPut6->setVisible(true);
            //----------------------------------------------

            //настройки выходных данных
            //----------------------------------------------
            ui->DoubleSpinBoxR_OutPut1->setEnabled(false);
            ui->Label_OutPut1->setVisible(false);
            ui->Label_OutPut1->setText("m (Количество диодов), шт:");
            ui->DoubleSpinBoxR_OutPut1->setVisible(false);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("Uд (Действующее напряжение на вторичной обмотке), В:");
            ui->DoubleSpinBoxR_OutPut2->setVisible(true);

            ui->Label_OutPut3->setVisible(false);
            ui->DoubleSpinBoxR_OutPut3->setVisible(false);
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

            ui->Label_InPut3->setVisible(false);
            ui->Label_InPut3->setText("Iдоп (Допустимый ток на диоде), А:");
            ui->DoubleSpinBoxR_InPut3->setVisible(false);

            ui->Label_InPut4->setVisible(false);
            ui->Label_InPut4->setText("Rн (Сопротивление нагрузки), Ом:");
            ui->DoubleSpinBoxR_InPut4->setVisible(false);

            ui->Label_InPut6->setVisible(true);
            ui->Label_InPut6->setText("Uн (Напряжение на нагрузке), В:");
            ui->DoubleSpinBoxR_InPut6->setVisible(true);
            //----------------------------------------------

            //настройки выходных данных
            //----------------------------------------------
            ui->Label_OutPut1->setVisible(false);
            ui->Label_OutPut1->setText("m (Количество диодов), шт:");
            ui->DoubleSpinBoxR_OutPut1->setVisible(false);
            ui->DoubleSpinBoxR_OutPut1->setValue(4);
            ui->DoubleSpinBoxR_OutPut1->setEnabled(false);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("Uд (Действующее напряжение на вторичной обмотке), В:");
            ui->DoubleSpinBoxR_OutPut2->setVisible(true);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("Uобр (Обратное напряжение на диоде), В:");
            ui->DoubleSpinBoxR_OutPut3->setVisible(true);
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
                    ui->DoubleSpinBoxR_InPut5->setMaximum(1.57);

                    object_work->Kp = 1.57;
                    ui->DoubleSpinBoxR_InPut5->setValue(object_work->Kp);
                    ui->DoubleSpinBoxR_InPut5->setEnabled(false);

                    ui->Label_OutPut3->setVisible(false);
                    ui->DoubleSpinBoxR_OutPut1->setEnabled(false);
                    ui->DoubleSpinBoxR_OutPut2->setEnabled(false);
                    ui->DoubleSpinBoxR_OutPut3->setVisible(false);

                    ui->Label_PixMapCircuit->setMaximumHeight(380);
                    ui->Label_PixMapCircuit->setMinimumHeight(380);
                    mapCircuit.load(":/image/img/ROPCircuit1.jpg");
                    ui->Label_PixMapCircuit->setPixmap(mapCircuit);
                    ui->Label_PixMapCircuit->setScaledContents(true);

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

                    ui->Label_PixMapCircuit->setMaximumHeight(380);
                    ui->Label_PixMapCircuit->setMinimumHeight(380);
                    mapCircuit.load(":/image/img/ROPCircuit2.jpg");
                    ui->Label_PixMapCircuit->setPixmap(mapCircuit);
                    ui->Label_PixMapCircuit->setScaledContents(true);

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

                    ui->Label_PixMapCircuit->setMaximumHeight(380);
                    ui->Label_PixMapCircuit->setMinimumHeight(380);
                    mapCircuit.load(":/image/img/ROPCircuit3.jpg");
                    ui->Label_PixMapCircuit->setPixmap(mapCircuit);
                    ui->Label_PixMapCircuit->setScaledContents(true);

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

                ui->Label_PixMapCircuit->setMaximumHeight(450);
                ui->Label_PixMapCircuit->setMinimumHeight(450);
                ui->Label_PixMapCircuit->setMinimumWidth(700);
                ui->Label_PixMapCircuit->setMaximumWidth(700);
                mapCircuit.load(":/image/img/RTPCircuit1.jpg");
                ui->Label_PixMapCircuit->setPixmap(mapCircuit);
                ui->Label_PixMapCircuit->setScaledContents(true);

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

                ui->Label_PixMapCircuit->setMaximumHeight(400);
                ui->Label_PixMapCircuit->setMinimumHeight(400);
                ui->Label_PixMapCircuit->setMinimumWidth(750);
                ui->Label_PixMapCircuit->setMaximumWidth(750);
                mapCircuit.load(":/image/img/RTPCircuit2.jpg");
                ui->Label_PixMapCircuit->setPixmap(mapCircuit);
                ui->Label_PixMapCircuit->setScaledContents(true);

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

                ui->Label_PixMapCircuit->setMaximumHeight(400);
                ui->Label_PixMapCircuit->setMinimumHeight(400);
                ui->Label_PixMapCircuit->setMinimumWidth(750);
                ui->Label_PixMapCircuit->setMaximumWidth(750);
                mapCircuit.load(":/image/img/RTPCircuit3.jpg");
                ui->Label_PixMapCircuit->setPixmap(mapCircuit);
                ui->Label_PixMapCircuit->setScaledContents(true);
            break;
        }
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Rectifiers::on_PushButton_Calculate_clicked()
{
    ui->list_of_diods->clear();
    int index = ui->ComboBox_DevicesR->currentIndex();

    if (index == TWOPERIODCIRCUIT)
    {
        if(chrt == nullptr)
        {
            chrt = new MyCharts();
            View->setChart(chrt);
            chrt->setTitle("Выходное напряжение на нагрузке");

            interactive = false;
            hands = false;
            ui->PushButton_Interactive->setEnabled(true);
            ui->PushButton_Hands->setEnabled(true);
            ui->DoubleSpinBoxOX->setEnabled(false);
            ui->DoubleSpinBoxOY->setEnabled(false);
            ui->DoubleSpinBoxOX->setValue(0.0);
            ui->DoubleSpinBoxOY->setValue(0.0);
        }
        else if(chrt->flagChart == true)
        {
            chrt->DeleteChart();

            interactive = false;
            hands = false;
            ui->PushButton_Interactive->setEnabled(true);
            ui->PushButton_Hands->setEnabled(true);
            ui->DoubleSpinBoxOX->setEnabled(false);
            ui->DoubleSpinBoxOY->setEnabled(false);
            ui->DoubleSpinBoxOX->setValue(0.0);
            ui->DoubleSpinBoxOY->setValue(0.0);

            if(flagEllipseItem)
            {
                delete ellipceItem;
                flagEllipseItem = false;
            }
        }

        //--------------------------------------------------
        double value_1 = ui->DoubleSpinBoxR_InPut1->value(); //Частота
        double value_2 = ui->DoubleSpinBoxR_InPut2->value(); //Средний ток на нагрузке
        double value_3 = ui->DoubleSpinBoxR_InPut3->value(); //Допустимый ток на диоде
        double value_6 = ui->DoubleSpinBoxR_InPut6->value(); //Напряжение на нагрузке
        double value_4 = double(value_6/value_2);            //Сопротивление нагрузки
        double value_5 = ui->DoubleSpinBoxR_InPut5->value(); //Коэффициент пульсаций

        double freq = value_1; //Копирую в другие переменные
        double I0123 = value_2;
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
            chrt->flagChart = false;
            return;
        }

        //переписываем в удобный формат
        //--------------------------------------------------

        value_2 = object_work->Ud_input;

        for (int i = 0;i < (int)names_of_diods.size();i++)
        {
            if((Uobr_max.at(i) > (2*value_2)) and (Ipr.at(i) > I0123)) // с запасом в 100% по просьбе Родина
            {
                ui->list_of_diods->addItem(names_of_diods.at(i), i);
            }
        }

        if(chose != 0)
        {
            if(chose == 1)
                value_3 = object_work->C*1000000;   // приведение к мкФ
            else
                value_3 = object_work->L*1000;      // приведение к мГн
        }

        if(chose == 1)
        {
            if(value_3 > 10000)
            {
                value_3 = value_3/1000;
                ui->Label_OutPut3->setText("C, мФ:");
            }
            else
            {
                ui->Label_OutPut3->setText("C, мкФ:");
            }
        }

        //--------------------------------------------------

        ui->DoubleSpinBoxR_OutPut2->setValue(value_2);
        ui->DoubleSpinBoxR_OutPut3->setValue(value_3);

        //-------------------------------------------------------

        QLineSeries series;   //без фильтров
        QLineSeries series_average;

        double T = 1./freq;

        for (float i = 0.0; i <= 2.*T; i = i + 0.00001)
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
        chrt->series->setName("Напряжение на нагрузке");
        chrt->PropertiesAxis("X", 0, 2/freq*1000, 11, "%.2lf");
        chrt->PropertiesAxis("Y", 0, 1.5*max, 11, "%.2lf");
        chrt->SetNameAxis("Время, мс", "Напряжение, В");
        chrt->AddSeries2DChart(series_average.points(), "Среднее значение напряжения на нагрузке");
        chrt->flagChart = true;

        //-------------------------------------------------------
    }
    if (index == ONEPERIODCIRCUIT) // условие обработки выбора устройства
    {
        if(chrt == nullptr)
        {
            chrt = new MyCharts();
            View->setChart(chrt);
            chrt->setTitle("Выходное напряжение на нагрузке");

            interactive = false;
            hands = false;
            ui->PushButton_Interactive->setEnabled(true);
            ui->PushButton_Hands->setEnabled(true);
            ui->DoubleSpinBoxOX->setEnabled(false);
            ui->DoubleSpinBoxOY->setEnabled(false);
            ui->DoubleSpinBoxOX->setValue(0.0);
            ui->DoubleSpinBoxOY->setValue(0.0);
        }
        else if(chrt->flagChart == true)
        {
            chrt->DeleteChart();

            interactive = false;
            hands = false;
            ui->PushButton_Interactive->setEnabled(true);
            ui->PushButton_Hands->setEnabled(true);
            ui->DoubleSpinBoxOX->setEnabled(false);
            ui->DoubleSpinBoxOY->setEnabled(false);
            ui->DoubleSpinBoxOX->setValue(0.0);
            ui->DoubleSpinBoxOY->setValue(0.0);

            if(flagEllipseItem)
            {
                delete ellipceItem;
                flagEllipseItem = false;
            }
        }

        //переписываем в удобный формат
        //--------------------------------------------------
        double value_1 = ui->DoubleSpinBoxR_InPut1->value(); //Частота
        double value_2 = ui->DoubleSpinBoxR_InPut2->value(); //Средний ток на нагрузке
        double value_3 = ui->DoubleSpinBoxR_InPut3->value(); //Допустимый ток на диоде
        double value_6 = ui->DoubleSpinBoxR_InPut6->value(); //Напряжение на нагрузке
        double value_4 = double(value_6/value_2);            //Сопротивление нагрузки
        double value_5 = ui->DoubleSpinBoxR_InPut5->value(); //Коэффициент пульсаций

        double freq = value_1; //Копирую в другие переменные
        double I0123 = value_2;
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
            chrt->flagChart = false;
            return;
        }

        //переписываем в удобный формат
        //--------------------------------------------------
        value_1 = object_work->m;
        value_2 = object_work->Ud_input;

        for (int i = 0;i < (int)names_of_diods.size(); i++)
        {
            if((Uobr_max.at(i) > (2*value_2)) and (Ipr.at(i) > (2*I0123)))
            {
                ui->list_of_diods->addItem(names_of_diods.at(i), i);
            }
        }

        if(chose != 0)
        {
            if(chose == 1)
                value_3 = object_work->C*1000000;
            else
                value_3 = object_work->L*1000; // приведение к мГн
        }

        if(chose == 1)
        {
            if(value_3 > 10000)
            {
                value_3 = value_3/1000;
                ui->Label_OutPut3->setText("C, мФ:");
            }
            else
            {
                ui->Label_OutPut3->setText("C, мкФ:");
            }
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

        ui->DoubleSpinBoxOX->setMinimum(0.0);
        ui->DoubleSpinBoxOX->setMaximum(2.*T*1000);

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
        chrt->series->setName("Напряжение на нагрузке");
        chrt->PropertiesAxis("X", 0, 2/freq*1000, 11, "%.2lf");
        chrt->PropertiesAxis("Y", 0, 1.5*max, 11, "%.2lf");
        chrt->SetNameAxis("Время, мс", "Напряжение, В");
        chrt->AddSeries2DChart(series_average.points(), "Среднее значение напряжения на нагрузке");
        chrt->flagChart = true;

        //-------------------------------------------------------
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Rectifiers::CoordinateCursor(QPointF point, int ind)
{
    if((interactive == false) || (chrt == nullptr))
    {
        return;
    }

    if (chrt->flagChart == true)
    {
        QPointF Coords = chrt->mapToValue(point, chrt->series);
        QPointF ellipcePoint = {0.0,0.0};
        int bestIndex = 0;
        if(ind < 0)
        {
            bestIndex = Near(Coords, chrt->series, chrt->series->pointsVector().size());
            ellipcePoint = chrt->mapToPosition(chrt->series->at(bestIndex), chrt->series);
            ui->DoubleSpinBoxOX->setValue(chrt->series->at(bestIndex).x());
            ui->DoubleSpinBoxOY->setValue(chrt->series->at(bestIndex).y());
        }

        if(flagEllipseItem)
        {
            delete ellipceItem;
            flagEllipseItem = false;
        }
        ellipceItem = new QGraphicsEllipseItem(chrt);

        ellipceItem->setRect(-5,-5,10,10);
        ellipceItem->setBrush(Qt::red);

        ellipceItem->setPos(ellipcePoint);

        flagEllipseItem = true;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Rectifiers::on_PushButton_Interactive_clicked(bool checked)
{
    Q_UNUSED(checked);
    interactive = true;
    hands = false;
    ui->PushButton_Interactive->setEnabled(false);
    ui->PushButton_Hands->setEnabled(true);
    ui->DoubleSpinBoxOX->setEnabled(false);

    if(flagEllipseItem)
    {
        delete ellipceItem;
        flagEllipseItem = false;
    }

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Rectifiers::on_PushButton_Hands_clicked(bool checked)
{
    Q_UNUSED(checked);
    interactive = false;
    hands = true;
    ui->PushButton_Interactive->setEnabled(true);
    ui->PushButton_Hands->setEnabled(false);
    ui->DoubleSpinBoxOX->setEnabled(true);

    if(flagEllipseItem)
    {
        delete ellipceItem;
        flagEllipseItem = false;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int Rectifiers::Near(QPointF Coords, QLineSeries *series, int Size)
{
    double x = Coords.x();
    int index = 0;
    double delta = 999.0;
    for(int i = 0; i < Size; i++)
    {
        if(abs(x - series->at(i).x()) < delta)
        {
            index = i;
            delta = abs(x - series->at(i).x());
        }
    }
    return index;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Rectifiers::on_DoubleSpinBoxOX_valueChanged(double CodeElement)
{
    if((hands == false) || (chrt == nullptr))
    {
        return;
    }

    ui->DoubleSpinBoxOX->setSingleStep(0.01);
    int index = 0;
    QPointF ellipcePointAmplitude = {0.0 , 0.0};

    if (chrt->flagChart == true)
    {
        index = ((CodeElement)/0.01);

        if(flagEllipseItem)
        {
            delete ellipceItem;
            flagEllipseItem = false;
        }

        ellipcePointAmplitude = chrt->mapToPosition(chrt->series->at(index),chrt->series);

        ellipceItem = new QGraphicsEllipseItem(chrt);
        ellipceItem->setRect(-5,-5,10,10);
        ellipceItem->setBrush(Qt::red);

        ellipceItem->setPos(ellipcePointAmplitude);

        ui->DoubleSpinBoxOY->setValue(chrt->series->at(index).y());

        flagEllipseItem = true;
    }

}

void Rectifiers::on_diod_base_clicked()
{
    base->show();
    emit signal_diod_base();
}

void Rectifiers::diod_base_update(std::vector <QString> _names_of_diods, std::vector <int> _Uobr_max, std::vector <double> _Ipr)
{
    names_of_diods = _names_of_diods;
    Uobr_max = _Uobr_max;
    Ipr = _Ipr;
}
