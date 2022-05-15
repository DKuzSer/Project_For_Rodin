#include "Filters.h"
#include "ui_Filters.h"

Filters::Filters(MainpowerSourcesAbstract *parent) :
    ui(new Ui::Filters)
{
    Q_UNUSED(parent);
    ui->setupUi(this);

    View = new MyChartsView();
    ui->ChartsLayout->addWidget(View);
    View ->setRenderHint(QPainter::Antialiasing);

    ViewFCHX = new MyChartsView();
    ui->ChartsLayout->addWidget(ViewFCHX);
    ViewFCHX ->setRenderHint(QPainter::Antialiasing);

    ui->ComboBox_Type->addItem("Баттерворта", BUTTERWORTH);
    ui->ComboBox_Type->addItem("Чебышева", CHEBISHEV);
    ui->ComboBox_View->addItem("ФНЧ", FNCH); // добавление ФНЧ
    ui->ComboBox_View->addItem("ФВЧ", FVCH); // добавление ФВЧ
    ui->ComboBox_View->addItem("ПФ", PF);    // добавление ПФ
    ui->ComboBox_View->addItem("ЗФ", ZF);    // добавление ЗФ

    //------------------------------------------------------------------
    ui->Label_InPut1->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_InPut2->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_InPut3->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_InPut4->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_InPut5->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_InPut6->setStyleSheet(style_helper->getLabelStyle());

    ui->Label_OutPut1->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_OutPut2->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_OutPut3->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_OutPut4->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_OutPut5->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_OutPut6->setStyleSheet(style_helper->getLabelStyle());

    ui->groupBox->setStyleSheet(style_helper->getGroupBoxStyle());
    ui->groupBox_2->setStyleSheet(style_helper->getGroupBoxStyle());

    ui->Label_Type->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_View->setStyleSheet(style_helper->getLabelStyle());
    //------------------------------------------------------------------
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Filters::~Filters()
{
    delete chrt;
    delete View;
    delete ViewFCHX;
    delete object_work;
    delete ui;
    delete style_helper;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Filters::on_ComboBox_Type_currentIndexChanged(int index)
{
    switch(index) // условие обработки выбора устройства
    {
        case BUTTERWORTH:
            if(object_work != nullptr)
            {
                delete object_work;
                object_work = new  FiltersButterworth();
            }
            else
                object_work = new  FiltersButterworth();

//            ui->ComboBox_OutPutF->setVisible(true);
//            ui->Label_OutPutF->setVisible(true);

            //настройки входных данных
            //----------------------------------------------
            ui->Label_InPut1->setVisible(true);
            ui->Label_InPut1->setText("f (Частота среза), Гц:");
            ui->DoubleSpinBoxF_InPut1->setVisible(true);

            ui->Label_InPut2->setVisible(true);
            ui->Label_InPut2->setText("R (Сопротивление нагрузки), Ом:");
            ui->DoubleSpinBoxF_InPut2->setVisible(true);

            ui->Label_InPut3->setVisible(true);
            ui->Label_InPut3->setText("n (порядок):");
            ui->IntSpinBoxF_InPut3->setVisible(true);

            ui->Label_InPut4->setVisible(true);
            ui->Label_InPut4->setText("df (полоса фильтра), Гц:");
            ui->DoubleSpinBoxF_InPut4->setVisible(true);

            ui->Label_InPut5->setVisible(false);
//            ui->Label_InPut5->setText("Rн (Сопротивление нагрузки), Ом:");
            ui->DoubleSpinBoxF_InPut5->setVisible(false);

            ui->Label_InPut6->setVisible(false);
//            ui->Label_InPut6->setText("Uн (Напряжение на нагрузке), В:");
            ui->DoubleSpinBoxF_InPut6->setVisible(false);
            //----------------------------------------------

            //настройки выходных данных
            //----------------------------------------------
            if(ui->IntSpinBoxF_InPut3->value() == 2)
            {
                ui->Label_OutPut1->setVisible(true);
                ui->Label_OutPut1->setText("С1 (Ёмкость), мкФ:");
                ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
                ui->DoubleSpinBoxF_OutPut1->setVisible(true);

                ui->Label_OutPut2->setVisible(true);
                ui->Label_OutPut2->setText("L1 (Индуктивность), Гн:");
                ui->DoubleSpinBoxF_OutPut2->setVisible(true);
                ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

                ui->Label_OutPut3->setVisible(false);
                ui->DoubleSpinBoxF_OutPut3->setVisible(false);
                ui->Label_OutPut4->setVisible(false);
                ui->DoubleSpinBoxF_OutPut4->setVisible(false);
                ui->Label_OutPut5->setVisible(false);
                ui->DoubleSpinBoxF_OutPut5->setVisible(false);
                ui->Label_OutPut6->setVisible(false);
                ui->DoubleSpinBoxF_OutPut6->setVisible(false);
            }
            //----------------------------------------------
        break;

        case CHEBISHEV:
            if(object_work != nullptr)
            {
                delete object_work;
                object_work = new  FiltersCHEBISHEV();
            }
            else
                object_work = new  FiltersCHEBISHEV();
            //            ui->ComboBox_OutPutF->setVisible(true);
            //            ui->Label_OutPutF->setVisible(true);

            //настройки входных данных
            //----------------------------------------------
            ui->Label_InPut1->setVisible(true);
            ui->Label_InPut1->setText("f (Частота среза), Гц:");
            ui->DoubleSpinBoxF_InPut1->setVisible(true);

            ui->Label_InPut2->setVisible(true);
            ui->Label_InPut2->setText("R (Сопротивление нагрузки), Ом:");
            ui->DoubleSpinBoxF_InPut2->setVisible(true);

            ui->Label_InPut3->setVisible(true);
            ui->Label_InPut3->setText("n (порядок):");
            ui->IntSpinBoxF_InPut3->setVisible(true);

            ui->Label_InPut4->setVisible(true);
            ui->Label_InPut4->setText("df (полоса фильтра), Гц:");
            ui->DoubleSpinBoxF_InPut4->setVisible(true);

            ui->Label_InPut5->setVisible(false);
//          ui->Label_InPut5->setText("Rн (Сопротивление нагрузки), Ом:");
            ui->DoubleSpinBoxF_InPut5->setVisible(false);

            ui->Label_InPut6->setVisible(false);
    //            ui->Label_InPut6->setText("Uн (Напряжение на нагрузке), В:");
            ui->DoubleSpinBoxF_InPut6->setVisible(false);
            //----------------------------------------------

            //настройки выходных данных
            //----------------------------------------------
            if(ui->IntSpinBoxF_InPut3->value() == 2)
            {
                ui->Label_OutPut1->setVisible(true);
                ui->Label_OutPut1->setText("С1 (Ёмкость), мкФ:");
                ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
                ui->DoubleSpinBoxF_OutPut1->setVisible(true);

                ui->Label_OutPut2->setVisible(true);
                ui->Label_OutPut2->setText("L1 (Индуктивность), Гн:");
                ui->DoubleSpinBoxF_OutPut2->setVisible(true);
                ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

                ui->Label_OutPut3->setVisible(false);
                ui->DoubleSpinBoxF_OutPut3->setVisible(false);
                ui->Label_OutPut4->setVisible(false);
                ui->DoubleSpinBoxF_OutPut4->setVisible(false);
                ui->Label_OutPut5->setVisible(false);
                ui->DoubleSpinBoxF_OutPut5->setVisible(false);
                ui->Label_OutPut6->setVisible(false);
                ui->DoubleSpinBoxF_OutPut6->setVisible(false);
            }
            //----------------------------------------------
        break;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Filters::on_ComboBox_View_currentIndexChanged(int index)
{
    if(index == FNCH)
    {
        ui->IntSpinBoxF_InPut3->setMinimum(2);
        if(ui->IntSpinBoxF_InPut3->value() == 2)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(false);
            ui->DoubleSpinBoxF_OutPut3->setVisible(false);
            ui->Label_OutPut4->setVisible(false);
            ui->DoubleSpinBoxF_OutPut4->setVisible(false);
            ui->Label_OutPut5->setVisible(false);
            ui->DoubleSpinBoxF_OutPut5->setVisible(false);
            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxF_OutPut6->setVisible(false);
        }
        if(ui->IntSpinBoxF_InPut3->value() == 3)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("С2 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(false);
            ui->DoubleSpinBoxF_OutPut4->setVisible(false);
            ui->Label_OutPut5->setVisible(false);
            ui->DoubleSpinBoxF_OutPut5->setVisible(false);
            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxF_OutPut6->setVisible(false);
        }
        if(ui->IntSpinBoxF_InPut3->value() == 4)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("С2 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(true);
            ui->Label_OutPut4->setText("L2 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut4->setVisible(true);
            ui->DoubleSpinBoxF_OutPut4->setEnabled(false);

            ui->Label_OutPut5->setVisible(false);
            ui->DoubleSpinBoxF_OutPut5->setVisible(false);
            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxF_OutPut6->setVisible(false);
        }
        if(ui->IntSpinBoxF_InPut3->value() == 5)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("С2 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(true);
            ui->Label_OutPut4->setText("L2 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut4->setVisible(true);
            ui->DoubleSpinBoxF_OutPut4->setEnabled(false);

            ui->Label_OutPut5->setVisible(true);
            ui->Label_OutPut5->setText("С3 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut5->setVisible(true);
            ui->DoubleSpinBoxF_OutPut5->setEnabled(false);

            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxF_OutPut6->setVisible(false);
        }
        if(ui->IntSpinBoxF_InPut3->value() == 6)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("С2 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(true);
            ui->Label_OutPut4->setText("L2 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut4->setVisible(true);
            ui->DoubleSpinBoxF_OutPut4->setEnabled(false);

            ui->Label_OutPut5->setVisible(true);
            ui->Label_OutPut5->setText("С3 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut5->setVisible(true);
            ui->DoubleSpinBoxF_OutPut5->setEnabled(false);

            ui->Label_OutPut6->setVisible(true);
            ui->Label_OutPut6->setText("L3 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut6->setVisible(true);
            ui->DoubleSpinBoxF_OutPut6->setEnabled(false);
        }
    }

    if(index == FVCH)
    {
        ui->IntSpinBoxF_InPut3->setMinimum(2);
        if(ui->IntSpinBoxF_InPut3->value() == 2)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(false);
            ui->DoubleSpinBoxF_OutPut3->setVisible(false);
            ui->Label_OutPut4->setVisible(false);
            ui->DoubleSpinBoxF_OutPut4->setVisible(false);
            ui->Label_OutPut5->setVisible(false);
            ui->DoubleSpinBoxF_OutPut5->setVisible(false);
            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxF_OutPut6->setVisible(false);
        }
        if(ui->IntSpinBoxF_InPut3->value() == 3)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("L2 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(false);
            ui->DoubleSpinBoxF_OutPut4->setVisible(false);
            ui->Label_OutPut5->setVisible(false);
            ui->DoubleSpinBoxF_OutPut5->setVisible(false);
            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxF_OutPut6->setVisible(false);
        }
        if(ui->IntSpinBoxF_InPut3->value() == 4)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("L2 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(true);
            ui->Label_OutPut4->setText("С2 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut4->setVisible(true);
            ui->DoubleSpinBoxF_OutPut4->setEnabled(false);

            ui->Label_OutPut5->setVisible(false);
            ui->DoubleSpinBoxF_OutPut5->setVisible(false);
            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxF_OutPut6->setVisible(false);
        }
        if(ui->IntSpinBoxF_InPut3->value() == 5)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("L2 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(true);
            ui->Label_OutPut4->setText("С2 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut4->setVisible(true);
            ui->DoubleSpinBoxF_OutPut4->setEnabled(false);

            ui->Label_OutPut5->setVisible(true);
            ui->Label_OutPut5->setText("L3 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut5->setVisible(true);
            ui->DoubleSpinBoxF_OutPut5->setEnabled(false);

            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxF_OutPut6->setVisible(false);
        }
        if(ui->IntSpinBoxF_InPut3->value() == 6)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("L2 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(true);
            ui->Label_OutPut4->setText("С2 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut4->setVisible(true);
            ui->DoubleSpinBoxF_OutPut4->setEnabled(false);

            ui->Label_OutPut5->setVisible(true);
            ui->Label_OutPut5->setText("L3 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut5->setVisible(true);
            ui->DoubleSpinBoxF_OutPut5->setEnabled(false);

            ui->Label_OutPut6->setVisible(true);
            ui->Label_OutPut6->setText("C3 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut6->setVisible(true);
            ui->DoubleSpinBoxF_OutPut6->setEnabled(false);
        }
    }

    if(index == PF)
    {
        ui->IntSpinBoxF_InPut3->setMinimum(3);
        if(ui->IntSpinBoxF_InPut3->value() == 3)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("С2 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(true);
            ui->Label_OutPut4->setText("L2 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut4->setVisible(true);
            ui->DoubleSpinBoxF_OutPut4->setEnabled(false);

            ui->Label_OutPut5->setVisible(true);
            ui->Label_OutPut5->setText("C3 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut5->setVisible(true);
            ui->DoubleSpinBoxF_OutPut5->setEnabled(false);

            ui->Label_OutPut6->setVisible(true);
            ui->Label_OutPut6->setText("L3 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut6->setVisible(true);
            ui->DoubleSpinBoxF_OutPut6->setEnabled(false);
        }
    }

    if(index == ZF)
    {
        ui->IntSpinBoxF_InPut3->setMinimum(3);
        if(ui->IntSpinBoxF_InPut3->value() == 3)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("L2 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(true);
            ui->Label_OutPut4->setText("С2 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut4->setVisible(true);
            ui->DoubleSpinBoxF_OutPut4->setEnabled(false);

            ui->Label_OutPut5->setVisible(true);
            ui->Label_OutPut5->setText("L3 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut5->setVisible(true);
            ui->DoubleSpinBoxF_OutPut5->setEnabled(false);

            ui->Label_OutPut6->setVisible(true);
            ui->Label_OutPut6->setText("C3 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut6->setVisible(true);
            ui->DoubleSpinBoxF_OutPut6->setEnabled(false);
        }
    }

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Filters::on_IntSpinBoxF_InPut3_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    if(ui->ComboBox_View->currentIndex() == FNCH)
    {
        if(ui->IntSpinBoxF_InPut3->value() == 2)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(false);
            ui->DoubleSpinBoxF_OutPut3->setVisible(false);
            ui->Label_OutPut4->setVisible(false);
            ui->DoubleSpinBoxF_OutPut4->setVisible(false);
            ui->Label_OutPut5->setVisible(false);
            ui->DoubleSpinBoxF_OutPut5->setVisible(false);
            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxF_OutPut6->setVisible(false);
        }
        if(ui->IntSpinBoxF_InPut3->value() == 3)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("С2 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(false);
            ui->DoubleSpinBoxF_OutPut4->setVisible(false);
            ui->Label_OutPut5->setVisible(false);
            ui->DoubleSpinBoxF_OutPut5->setVisible(false);
            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxF_OutPut6->setVisible(false);
        }
        if(ui->IntSpinBoxF_InPut3->value() == 4)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("С2 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(true);
            ui->Label_OutPut4->setText("L2 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut4->setVisible(true);
            ui->DoubleSpinBoxF_OutPut4->setEnabled(false);

            ui->Label_OutPut5->setVisible(false);
            ui->DoubleSpinBoxF_OutPut5->setVisible(false);
            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxF_OutPut6->setVisible(false);
        }
        if(ui->IntSpinBoxF_InPut3->value() == 5)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("С2 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(true);
            ui->Label_OutPut4->setText("L2 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut4->setVisible(true);
            ui->DoubleSpinBoxF_OutPut4->setEnabled(false);

            ui->Label_OutPut5->setVisible(true);
            ui->Label_OutPut5->setText("С3 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut5->setVisible(true);
            ui->DoubleSpinBoxF_OutPut5->setEnabled(false);

            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxF_OutPut6->setVisible(false);
        }
        if(ui->IntSpinBoxF_InPut3->value() == 6)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("С2 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(true);
            ui->Label_OutPut4->setText("L2 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut4->setVisible(true);
            ui->DoubleSpinBoxF_OutPut4->setEnabled(false);

            ui->Label_OutPut5->setVisible(true);
            ui->Label_OutPut5->setText("С3 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut5->setVisible(true);
            ui->DoubleSpinBoxF_OutPut5->setEnabled(false);

            ui->Label_OutPut6->setVisible(true);
            ui->Label_OutPut6->setText("L3 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut6->setVisible(true);
            ui->DoubleSpinBoxF_OutPut6->setEnabled(false);
        }
    }

    if(ui->ComboBox_View->currentIndex() == FVCH)
    {
        if(ui->IntSpinBoxF_InPut3->value() == 2)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(false);
            ui->DoubleSpinBoxF_OutPut3->setVisible(false);
            ui->Label_OutPut4->setVisible(false);
            ui->DoubleSpinBoxF_OutPut4->setVisible(false);
            ui->Label_OutPut5->setVisible(false);
            ui->DoubleSpinBoxF_OutPut5->setVisible(false);
            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxF_OutPut6->setVisible(false);
        }
        if(ui->IntSpinBoxF_InPut3->value() == 3)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("L2 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(false);
            ui->DoubleSpinBoxF_OutPut4->setVisible(false);
            ui->Label_OutPut5->setVisible(false);
            ui->DoubleSpinBoxF_OutPut5->setVisible(false);
            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxF_OutPut6->setVisible(false);
        }
        if(ui->IntSpinBoxF_InPut3->value() == 4)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("L2 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(true);
            ui->Label_OutPut4->setText("С2 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut4->setVisible(true);
            ui->DoubleSpinBoxF_OutPut4->setEnabled(false);

            ui->Label_OutPut5->setVisible(false);
            ui->DoubleSpinBoxF_OutPut5->setVisible(false);
            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxF_OutPut6->setVisible(false);
        }
        if(ui->IntSpinBoxF_InPut3->value() == 5)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("L2 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(true);
            ui->Label_OutPut4->setText("С2 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut4->setVisible(true);
            ui->DoubleSpinBoxF_OutPut4->setEnabled(false);

            ui->Label_OutPut5->setVisible(true);
            ui->Label_OutPut5->setText("L3 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut5->setVisible(true);
            ui->DoubleSpinBoxF_OutPut5->setEnabled(false);

            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxF_OutPut6->setVisible(false);
        }
        if(ui->IntSpinBoxF_InPut3->value() == 6)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("L2 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(true);
            ui->Label_OutPut4->setText("С2 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut4->setVisible(true);
            ui->DoubleSpinBoxF_OutPut4->setEnabled(false);

            ui->Label_OutPut5->setVisible(true);
            ui->Label_OutPut5->setText("L3 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut5->setVisible(true);
            ui->DoubleSpinBoxF_OutPut5->setEnabled(false);

            ui->Label_OutPut6->setVisible(true);
            ui->Label_OutPut6->setText("C3 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut6->setVisible(true);
            ui->DoubleSpinBoxF_OutPut6->setEnabled(false);
        }
    }

    if(ui->ComboBox_View->currentIndex() == PF)
    {
        if(ui->IntSpinBoxF_InPut3->value() == 3)
        {
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(true);
            ui->Label_OutPut2->setText("С1 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(true);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(true);
            ui->Label_OutPut3->setText("L2 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut3->setVisible(true);
            ui->DoubleSpinBoxF_OutPut3->setEnabled(false);

            ui->Label_OutPut4->setVisible(true);
            ui->Label_OutPut4->setText("С2 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut4->setVisible(true);
            ui->DoubleSpinBoxF_OutPut4->setEnabled(false);

            ui->Label_OutPut5->setVisible(true);
            ui->Label_OutPut5->setText("L3 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut5->setVisible(true);
            ui->DoubleSpinBoxF_OutPut5->setEnabled(false);

            ui->Label_OutPut6->setVisible(true);
            ui->Label_OutPut6->setText("C3 (Ёмкость), мкФ:");
            ui->DoubleSpinBoxF_OutPut6->setVisible(true);
            ui->DoubleSpinBoxF_OutPut6->setEnabled(false);
        }
    }

    if(ui->ComboBox_View->currentIndex() == ZF)
    {
        // место для будующей реализации
    }

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Filters::on_PushButton_Calculate_clicked()
{
    int index = ui->ComboBox_Type->currentIndex();

    if (index == BUTTERWORTH)
    {
        if(chrt == nullptr)
        {
            chrt = new MyCharts();
            View->setChart(chrt);
            chrt->setTitle("АЧХ");
            chrt->legend()->hide();

            chrtFCHX = new MyCharts();
            ViewFCHX->setChart(chrtFCHX);
            chrtFCHX->setTitle("ФЧХ");
            chrtFCHX->legend()->hide();

//            interactive = false;
//            hands = false;
//            ui->PushButton_Interactive->setEnabled(true);
//            ui->PushButton_Hands->setEnabled(true);
//            ui->DoubleSpinBoxOX->setEnabled(false);
//            ui->DoubleSpinBoxOY->setEnabled(false);
//            ui->DoubleSpinBoxOX->setValue(0.0);
//            ui->DoubleSpinBoxOY->setValue(0.0);

        }
        else if(chrt->flagChart == true)
        {
            chrt->DeleteChart();
            chrtFCHX->DeleteChart();

//            interactive = false;
//            hands = false;
//            ui->PushButton_Interactive->setEnabled(true);
//            ui->PushButton_Hands->setEnabled(true);
//            ui->DoubleSpinBoxOX->setEnabled(false);
//            ui->DoubleSpinBoxOY->setEnabled(false);
//            ui->DoubleSpinBoxOX->setValue(0.0);
//            ui->DoubleSpinBoxOY->setValue(0.0);

//            if(flagEllipseItem)
//            {
//                delete ellipceItem;
//                flagEllipseItem = false;
//            }

        }

        //--------------------------------------------------
        double freq = ui->DoubleSpinBoxF_InPut1->value();         //Частота среза
        double Resistance = ui->DoubleSpinBoxF_InPut2->value();   //Сопротивление нагрузки
        int n = ui->IntSpinBoxF_InPut3->value();                  //Порядок
        double deltaf =ui->DoubleSpinBoxF_InPut4->value();        //Полоса частот
        //--------------------------------------------------

        int chose = ui->ComboBox_View->currentIndex();
           switch(chose)
           {
                case 0 :
                object_work->SetBaseValue(freq, Resistance, n);
                break;

                case 1 :
                object_work->SetBaseValue(freq, Resistance, n);
                break;

                case 2 :
                object_work->SetBaseValue(freq, Resistance, n, deltaf);
                break;

                case 3 :
                object_work->SetBaseValue(freq, Resistance, n, deltaf);
                break;

            }// передаём данные в расчётный класс
        object_work->ViewFilters(chose);                          // передаём данные флага установки фильтра на выходе
        object_work->Calculate();

//        if(object_work->flagCalculate == true)
//        {
//            QMessageBox::information(this,"Ошибка","Данные параметры нельзя реализовать");
//            chrt->flagChart = false;
//            return;
//        }

        //переписываем в удобный формат
        //--------------------------------------------------

        double value_1 = object_work->C1;
        double value_2 = object_work->L1;
        double value_3 = object_work->C2;
        double value_4 = object_work->L2;
        double value_5 = object_work->C3;
        double value_6 = object_work->L3;

        if(chose == 0)
        {
            switch(n) // условие обработки выбора порядка
            {
                case 2:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_2);
                break;

                case 3:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_3);
                break;

                case 4:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_3);
                    ui->DoubleSpinBoxF_OutPut4->setValue(value_4);
                break;

                case 5:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_3);
                    ui->DoubleSpinBoxF_OutPut4->setValue(value_4);
                    ui->DoubleSpinBoxF_OutPut5->setValue(value_5);
                break;

                case 6:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_3);
                    ui->DoubleSpinBoxF_OutPut4->setValue(value_4);
                    ui->DoubleSpinBoxF_OutPut5->setValue(value_5);
                    ui->DoubleSpinBoxF_OutPut6->setValue(value_6);
                break;
            }

        }

        if(chose == 1)
        {
            switch(n) // условие обработки выбора порядка
            {
                case 2:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_1);
                break;

                case 3:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_4);
                break;

                case 4:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_4);
                    ui->DoubleSpinBoxF_OutPut4->setValue(value_3);
                break;

                case 5:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_4);
                    ui->DoubleSpinBoxF_OutPut4->setValue(value_3);
                    ui->DoubleSpinBoxF_OutPut5->setValue(value_6);
                break;

                case 6:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_4);
                    ui->DoubleSpinBoxF_OutPut4->setValue(value_3);
                    ui->DoubleSpinBoxF_OutPut5->setValue(value_6);
                    ui->DoubleSpinBoxF_OutPut6->setValue(value_5);
                break;
            }
        }

        if(chose == 2)
        {
            switch(n)
            {
                case 3:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_3);
                    ui->DoubleSpinBoxF_OutPut4->setValue(value_4);
                    ui->DoubleSpinBoxF_OutPut5->setValue(value_5);
                    ui->DoubleSpinBoxF_OutPut6->setValue(value_6);
                break;
            }
        }

        if(chose == 3)
        {
            switch(n)
            {
                case 3:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_4);
                    ui->DoubleSpinBoxF_OutPut4->setValue(value_3);
                    ui->DoubleSpinBoxF_OutPut5->setValue(value_6);
                    ui->DoubleSpinBoxF_OutPut6->setValue(value_5);
                break;
            }
        }

//        if(chose == 1)
//        {
//            if(value_3 > 10000)
//            {
//                value_3 = value_3/1000;
//                ui->Label_OutPut3->setText("C, мФ:");
//            }
//            else
//            {
//                ui->Label_OutPut3->setText("C, мкФ:");
//            }
//        }


        QLineSeries series;
        QLineSeries seriesFCHX;

        for (double i = 0.01; i < 4 * freq; i += freq / 200)
        {
            if(chose == 0)    // ФНЧ
            {
                series.append(i, object_work->OutputWaveform(i));
            }

            if(chose == 1)    // ФВЧ
            {
                series.append(i, object_work->OutputWaveform(i));
            }

            if (chose == 2)   // ПФ
            {
                series.append(i, object_work->OutputWaveform(i));
            }

            if (chose == 3)   // ЗФ
            {
                series.append(i, object_work->OutputWaveform(i));
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
        chrt->series->setName("АЧХ");
        chrt->PropertiesAxis("X", 0, (int)(4 * freq), 11, "%.2lf");
        chrt->PropertiesAxis("Y", 0, 1.5*max, 11, "%.2lf");
        chrt->SetNameAxis("Частота, Гц", "Значение АЧХ");
        chrt->flagChart = true;

        for (double i = 0.01; i < 4 * freq; i += freq / 200)
        {
            if(chose == 0)    // ФНЧ
            {
                seriesFCHX.append(i, object_work->OutputWaveformFCHX(i));
            }

            if(chose == 1)    // ФВЧ
            {
                seriesFCHX.append(i, object_work->OutputWaveformFCHX(i));
            }

            if (chose == 2)   // ПФ
            {
                seriesFCHX.append(i, object_work->OutputWaveformFCHX(i));
            }

            if (chose == 3)   // ЗФ
            {
                seriesFCHX.append(i, object_work->OutputWaveformFCHX(i));
            }
        }

        max = 0;
        double min = 0;

        for(int i = 0; i < seriesFCHX.pointsVector().size(); i++)
        {
            double step = seriesFCHX.pointsVector().at(i).y();
            if(step > max)
            {
                max = step;
            }
            if(step < min)
            {
                min = step;
            }
        }

        chrtFCHX->Create2DChart(seriesFCHX.points());
        chrtFCHX->series->setName("ФЧХ");
        chrtFCHX->PropertiesAxis("X", 0, (int)(4 * freq), 11, "%.2lf");
        chrtFCHX->PropertiesAxis("Y", -1.5*min, 1.5*max, 11, "%.2lf");
        chrtFCHX->SetNameAxis("Частота, Гц", "Значение ФЧХ");
        chrtFCHX->flagChart = true;
        //-------------------------------------------------------
    }

    if (index == CHEBISHEV)
    {
        if(chrt == nullptr)
        {
            chrt = new MyCharts();
            View->setChart(chrt);
            chrt->setTitle("АЧХ");

//            interactive = false;
//            hands = false;
//            ui->PushButton_Interactive->setEnabled(true);
//            ui->PushButton_Hands->setEnabled(true);
//            ui->DoubleSpinBoxOX->setEnabled(false);
//            ui->DoubleSpinBoxOY->setEnabled(false);
//            ui->DoubleSpinBoxOX->setValue(0.0);
//            ui->DoubleSpinBoxOY->setValue(0.0);
        }
        else if(chrt->flagChart == true)
        {
            chrt->DeleteChart();

//            interactive = false;
//            hands = false;
//            ui->PushButton_Interactive->setEnabled(true);
//            ui->PushButton_Hands->setEnabled(true);
//            ui->DoubleSpinBoxOX->setEnabled(false);
//            ui->DoubleSpinBoxOY->setEnabled(false);
//            ui->DoubleSpinBoxOX->setValue(0.0);
//            ui->DoubleSpinBoxOY->setValue(0.0);

//            if(flagEllipseItem)
//            {
//                delete ellipceItem;
//                flagEllipseItem = false;
//            }
        }

        //--------------------------------------------------
        double freq = ui->DoubleSpinBoxF_InPut1->value();         //Частота среза
        double Resistance = ui->DoubleSpinBoxF_InPut2->value();   //Сопротивление нагрузки
        int n = ui->IntSpinBoxF_InPut3->value();                  //Порядок
        double deltaf =ui->DoubleSpinBoxF_InPut4->value();        //Полоса частот
        //--------------------------------------------------

        int chose = ui->ComboBox_View->currentIndex();
           switch(chose)
           {
                case 0 :
                object_work->SetBaseValue(freq, Resistance, n);
                break;

                case 1 :
                object_work->SetBaseValue(freq, Resistance, n);
                break;

                case 2 :
                object_work->SetBaseValue(freq, Resistance, n, deltaf);
                break;

                case 3 :
                object_work->SetBaseValue(freq, Resistance, n, deltaf);
                break;

            }// передаём данные в расчётный класс
        object_work->ViewFilters(chose);                          // передаём данные флага установки фильтра на выходе
        object_work->Calculate();

//        if(object_work->flagCalculate == true)
//        {
//            QMessageBox::information(this,"Ошибка","Данные параметры нельзя реализовать");
//            chrt->flagChart = false;
//            return;
//        }

        //переписываем в удобный формат
        //--------------------------------------------------

        double value_1 = object_work->C1;
        double value_2 = object_work->L1;
        double value_3 = object_work->C2;
        double value_4 = object_work->L2;
        double value_5 = object_work->C3;
        double value_6 = object_work->L3;

        if(chose == 0)
        {
            switch(n) // условие обработки выбора порядка
            {
                case 2:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_2);
                break;

                case 3:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_3);
                break;

                case 4:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_3);
                    ui->DoubleSpinBoxF_OutPut4->setValue(value_4);
                break;

                case 5:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_3);
                    ui->DoubleSpinBoxF_OutPut4->setValue(value_4);
                    ui->DoubleSpinBoxF_OutPut5->setValue(value_5);
                break;

                case 6:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_3);
                    ui->DoubleSpinBoxF_OutPut4->setValue(value_4);
                    ui->DoubleSpinBoxF_OutPut5->setValue(value_5);
                    ui->DoubleSpinBoxF_OutPut6->setValue(value_6);
                break;
            }

        }

        if(chose == 1)
        {
            switch(n) // условие обработки выбора порядка
            {
                case 2:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_1);
                break;

                case 3:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_4);
                break;

                case 4:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_4);
                    ui->DoubleSpinBoxF_OutPut4->setValue(value_3);
                break;

                case 5:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_4);
                    ui->DoubleSpinBoxF_OutPut4->setValue(value_3);
                    ui->DoubleSpinBoxF_OutPut5->setValue(value_6);
                break;

                case 6:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_4);
                    ui->DoubleSpinBoxF_OutPut4->setValue(value_3);
                    ui->DoubleSpinBoxF_OutPut5->setValue(value_6);
                    ui->DoubleSpinBoxF_OutPut6->setValue(value_5);
                break;
            }
        }

        if(chose == 2)
        {
            switch(n)
            {
                case 3:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_3);
                    ui->DoubleSpinBoxF_OutPut4->setValue(value_4);
                    ui->DoubleSpinBoxF_OutPut5->setValue(value_5);
                    ui->DoubleSpinBoxF_OutPut6->setValue(value_6);
                break;
            }
        }

        if(chose == 3)
        {
            switch(n)
            {
                case 3:
                    ui->DoubleSpinBoxF_OutPut1->setValue(value_2);
                    ui->DoubleSpinBoxF_OutPut2->setValue(value_1);
                    ui->DoubleSpinBoxF_OutPut3->setValue(value_4);
                    ui->DoubleSpinBoxF_OutPut4->setValue(value_3);
                    ui->DoubleSpinBoxF_OutPut5->setValue(value_6);
                    ui->DoubleSpinBoxF_OutPut6->setValue(value_5);
                break;
            }
        }

//        if(chose == 1)
//        {
//            if(value_3 > 10000)
//            {
//                value_3 = value_3/1000;
//                ui->Label_OutPut3->setText("C, мФ:");
//            }
//            else
//            {
//                ui->Label_OutPut3->setText("C, мкФ:");
//            }
//        }


        QLineSeries series;
        QLineSeries seriesFCHX;

        for (double i = 0.01; i < 4 * freq; i += freq / 200)
        {
            if(chose == 0)    // ФНЧ
            {
                series.append(i, object_work->OutputWaveform(i));
            }

            if(chose == 1)    // ФВЧ
            {
                series.append(i, object_work->OutputWaveform(i));
            }

            if (chose == 2)   // ПФ
            {
                series.append(i, object_work->OutputWaveform(i));
            }

            if (chose == 3)   // ЗФ
            {
                series.append(i, object_work->OutputWaveform(i));
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
        chrt->series->setName("АЧХ");
        chrt->PropertiesAxis("X", 0, (int)(4 * freq), 11, "%.2lf");
        chrt->PropertiesAxis("Y", 0, 1.5*max, 11, "%.2lf");
        chrt->SetNameAxis("Частота, Гц", "Значение АЧХ");
        chrt->flagChart = true;

        //-------------------------------------------------------
    }
}
