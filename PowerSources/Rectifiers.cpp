#include "Rectifiers.h"
#include "ui_Rectifiers.h"

#include "RectifiersOnePeriodCircuit.h"


Rectifiers::Rectifiers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rectifiers)
{
    ui->setupUi(this);

    ui->ComboBox_OutPutF->setVisible(false); // установление невидимыми параметра установки фильтра на выходе выпрямителя
    ui->Label_OutPutF->setVisible(false);   // установление невидимыми параметра установки фильтра на выходе выпрямителя

    ui->ComboBox_DevicesR->addItem("Однополупериодный", ONEPERIODCIRCUIT); // добавление однополупериодного выпрямителя в окно устройств
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
            ui->Label_InPut1->setText("f, Гц:");
            ui->DoubleSpinBoxR_InPut1->setVisible(true);

            ui->Label_InPut2->setVisible(true);
            ui->Label_InPut2->setText("I0, А:");
            ui->DoubleSpinBoxR_InPut2->setVisible(true);

            ui->Label_InPut3->setVisible(true);
            ui->Label_InPut3->setText("Iдоп, А:");
            ui->DoubleSpinBoxR_InPut3->setVisible(true);

            ui->Label_InPut4->setVisible(true);
            ui->Label_InPut4->setText("Rн, Ом:");
            ui->DoubleSpinBoxR_InPut4->setVisible(true);

            ui->Label_InPut6->setVisible(false);
            ui->DoubleSpinBoxR_InPut6->setVisible(false);
            //----------------------------------------------

            //настройки выходных данных
            //----------------------------------------------
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("m, шт:");
            ui->DoubleSpinBoxR_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("Uд, В:");
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
    }

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Rectifiers::on_ComboBox_OutPutF_currentIndexChanged(int index)
{
    switch(index) // условие обработки выбора фильтра на выходе выпрямителя
    {
        case 0:
            ui->Label_InPut5->setVisible(true);
            ui->DoubleSpinBoxR_InPut5->setVisible(true);
            ui->Label_InPut5->setText("Kp :");

            object_work->Kp = 1.57;
            ui->DoubleSpinBoxR_InPut5->setValue(object_work->Kp);
            ui->DoubleSpinBoxR_InPut5->setEnabled(false);

            ui->Label_OutPut3->setVisible(false);
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
            ui->Label_InPut5->setText("Kp :");
            ui->DoubleSpinBoxR_InPut5->setEnabled(true);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("C, мкФ:");
            ui->DoubleSpinBoxR_OutPut3->setVisible(true);

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
            ui->Label_InPut5->setText("Kp :");
            ui->DoubleSpinBoxR_InPut5->setEnabled(true);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("L, мГн:");
            ui->DoubleSpinBoxR_OutPut3->setVisible(true);

            mapCircuit.load(":/image/img/ROPCircuit3.jpg");
            mapProperties.load(":/image/img/ROPCircuitProperties.jpg");
            ui->Label_PixMapCircuit->setPixmap(mapCircuit);
            ui->Label_PixMapCircuit->setScaledContents(true);
            ui->Label_PixMapProperties->setPixmap(mapProperties);
            ui->Label_PixMapProperties->setScaledContents(true);

        break;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Rectifiers::on_PushButton_Calculate_clicked()
{
    int index = ui->ComboBox_DevicesR->currentIndex();
    switch(index) // условие обработки выбора устройства
    {
        case ONEPERIODCIRCUIT:

            if(chrt == nullptr)
            {
                chrt = new MyCharts();
                ui->graphicsView->setChart(chrt);
                chrt->setTitle("График");
            }
            else
                chrt->DeleteChart();

            //переписываем в удобный формат
            //--------------------------------------------------
            double value_1 = ui->DoubleSpinBoxR_InPut1->value();
            double value_2 = ui->DoubleSpinBoxR_InPut2->value();
            double value_3 = ui->DoubleSpinBoxR_InPut3->value();
            double value_4 = ui->DoubleSpinBoxR_InPut4->value();
            double value_5 = ui->DoubleSpinBoxR_InPut5->value();

            double freq = value_1;                                      //Копирую в другие переменные, чтобы у нас была
            double Current0 = value_2;                                  // возможность юзать их в рассчетах
            double Current_dop = value_3;                               // так как в дальнейшем они будут принимать другие значения
            double Resistance = value_4;
            double Pulse = value_5;
            //--------------------------------------------------
            int chose = ui->ComboBox_OutPutF->currentIndex();
            object_work->SetBaseValue(value_1, value_2, value_4);       // передаём данные в расчётный класс
            object_work->FFilters(chose);                               // передаём данные флага установки фильтра на выходе
            object_work->Idop = value_3;
            object_work->Kp = value_5;
            object_work->Calculate();

            //переписываем в удобный формат
            //--------------------------------------------------
            value_1 = object_work->m;
            value_2 = object_work->Ud_input;
            if(chose != 0)
            {
                if(chose == 1)
                    value_3 = object_work->C;
                else
                    value_3 = object_work->L;
            }
            //--------------------------------------------------

            ui->DoubleSpinBoxR_OutPut1->setValue(value_1);
            ui->DoubleSpinBoxR_OutPut2->setValue(value_2);
            ui->DoubleSpinBoxR_OutPut3->setValue(value_3);

            //-------------------------------------------------------
            //делаем график

            QLineSeries series;

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
                    if(sqrt(2)*value_2*sin(2*M_PI*freq*i) > 0)
                    {
                        series.append(i, sqrt(2)*value_2*sin(2*M_PI*freq*i));
                    }
                    else
                    {
                        series.append(i, 0);
                    }
                }
                if(chose == 1) // кондер
                {
                    if(sqrt(2)*value_2*sin(2*M_PI*freq*i)<sqrt(2)*value_2*exp(-((i-(T/4)-T*n)/(Resistance*value_3*pow(10,(-6))))) && (T/4<i))
                    {

                        series.append(i, sqrt(2)*value_2*exp(-((i-(T/4)-T*n)/(Resistance*value_3*pow(10,(-6))))));
                    }
                    else
                    {
                        series.append(i, sqrt(2)*value_2*sin(2*M_PI*freq*i));
                    }
                }
                if (chose == 2)   // катушка
                {
                    if(sqrt(2)*value_2*sin(2*M_PI*freq*i)<sqrt(2)*value_2*exp(-((i-(T/4)-T*n)*Resistance/(value_3*pow(10,(-3))))) && (T/4<i))
                    {
                        series.append(i, sqrt(2)*value_2*exp(-((i-(T/4)-T*n)*Resistance)/(value_3*pow(10,(-3)))));
                    }
                    else
                    {
                        series.append(i, sqrt(2)*value_2*sin(2*M_PI*freq*i));
                    }
                }
            }

            chrt->Create2DChart(series.points());
            chrt->PropertiesAxis("X", 0, 2/freq, 11, "%.2lf");
            chrt->PropertiesAxis("Y", -0.5, 1.5*value_2, 11, "%.2lf");

            //-------------------------------------------------------
        break;
    }
}
