#include "Matching.h"
#include "ui_Matching.h"

Matching::Matching(MainpowerSourcesAbstract *parent) :
    ui(new Ui::Matching)
{
    ui->setupUi(this);
    Q_UNUSED(parent);
//-------------------------------------------------------------------------------------
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

    ui->Label_Type->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_View->setStyleSheet(style_helper->getLabelStyle());

    ui->groupBox->setStyleSheet(style_helper->getGroupBoxStyle());
    ui->groupBox_2->setStyleSheet(style_helper->getGroupBoxStyle());
//-------------------------------------------------------------------------------------
//    ui->Label_InPut1->setText("Напряжение питания Eк (В)");
//    ui->Label_InPut2->setText("Макс. мощность транзистора (Вт)");
//    ui->Label_OutPut1->setText("Выходное сопротивление транзистора Rвых (Ом)");

    View = new MyChartsView();
    ui->ChartsLayout->addWidget(View);
    View ->setRenderHint(QPainter::Antialiasing);

    ViewFCHX = new MyChartsView();
    ui->ChartsLayout->addWidget(ViewFCHX);
    ViewFCHX ->setRenderHint(QPainter::Antialiasing);

    ui->ComboBox_Type->addItem("Транзистор", TYPEOFCIRCUITMATCHING);

    ui->ComboBox_View->addItem("П-фильтр", PiCIRCUITMATCHING);
    ui->ComboBox_View->addItem("Модифицированный П-фильтр", MODIFPiCIRCUITMATCHING);

//    ui->Label_InPut3->setVisible(false);
//    ui->Label_InPut4->setVisible(false);
//    ui->Label_InPut5->setVisible(false);
//    ui->Label_InPut6->setVisible(false);
//    ui->IntSpinBoxF_InPut3->setVisible(false);
//    ui->DoubleSpinBoxF_InPut4->setVisible(false);
//    ui->DoubleSpinBoxF_InPut5->setVisible(false);
//    ui->DoubleSpinBoxF_InPut6->setVisible(false);

//    ui->Label_OutPut2->setVisible(false);
//    ui->Label_OutPut3->setVisible(false);
//    ui->Label_OutPut4->setVisible(false);
//    ui->Label_OutPut5->setVisible(false);
//    ui->Label_OutPut6->setVisible(false);

//    ui->DoubleSpinBoxF_OutPut2->setVisible(false);
//    ui->DoubleSpinBoxF_OutPut3->setVisible(false);
//    ui->DoubleSpinBoxF_OutPut4->setVisible(false);
//    ui->DoubleSpinBoxF_OutPut5->setVisible(false);
//    ui->DoubleSpinBoxF_OutPut6->setVisible(false);
}

Matching::~Matching()
{    
    delete ui;
    delete style_helper;
    delete View;
    delete ViewFCHX;
    delete object_work;
//    delete chrt;
//    delete chrtFCHX;
}

void Matching::on_ComboBox_Type_currentIndexChanged(int index)
{
    switch(index) // условие обработки выбора устройства
    {
        case TYPEOFCIRCUITMATCHING:
            if(object_work != nullptr)
            {
                delete object_work;
                object_work = new  MatchingOneCircuit();
            }
            else
                object_work = new  MatchingOneCircuit();

            //настройки входных данных
            //----------------------------------------------
            ui->Label_InPut1->setVisible(true);
            ui->Label_InPut1->setText("Ек (Напряжение питания), В:");
            ui->DoubleSpinBoxF_InPut1->setVisible(true);

            ui->Label_InPut2->setVisible(true);
            ui->Label_InPut2->setText("P (Макс. мощность транзистора), Вт:");
            ui->DoubleSpinBoxF_InPut2->setVisible(true);

            ui->Label_InPut3->setVisible(true);
            ui->Label_InPut3->setText("F (Частота), Гц:");
            ui->IntSpinBoxF_InPut3->setVisible(true);

            ui->Label_InPut4->setVisible(true);
            ui->Label_InPut4->setText("Rвых (сопротивление нагрузки), Ом:");
            ui->DoubleSpinBoxF_InPut4->setVisible(true);

            ui->Label_InPut5->setVisible(true);
            ui->Label_InPut5->setText("Q (Добротность катушки):");
            ui->DoubleSpinBoxF_InPut5->setVisible(true);

            ui->Label_InPut6->setVisible(false);
            ui->Label_InPut6->setText("Uн (Напряжение на нагрузке), В:");
            ui->DoubleSpinBoxF_InPut6->setVisible(false);
            //----------------------------------------------

            //настройки выходных данных
            //----------------------------------------------
            ui->Label_OutPut1->setVisible(true);
            ui->Label_OutPut1->setText("Rвх (Выходное сопротивление транзистора), Ом");
            ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
            ui->DoubleSpinBoxF_OutPut1->setVisible(true);

            ui->Label_OutPut2->setVisible(false);
            ui->Label_OutPut2->setText("L1 (Индуктивность), Гн:");
            ui->DoubleSpinBoxF_OutPut2->setVisible(false);
            ui->DoubleSpinBoxF_OutPut2->setEnabled(false);

            ui->Label_OutPut3->setVisible(false);
            ui->DoubleSpinBoxF_OutPut3->setVisible(false);
            ui->Label_OutPut4->setVisible(false);
            ui->DoubleSpinBoxF_OutPut4->setVisible(false);
            ui->Label_OutPut5->setVisible(false);
            ui->DoubleSpinBoxF_OutPut5->setVisible(false);
            ui->Label_OutPut6->setVisible(false);
            ui->DoubleSpinBoxF_OutPut6->setVisible(false);
            //----------------------------------------------
        break;
    }
}

void Matching::on_ComboBox_View_currentIndexChanged(int index)
{
    switch (index)
    {
        case PiCIRCUITMATCHING:

        break;
        case MODIFPiCIRCUITMATCHING:

        break;
    }
}

void Matching::on_PushButton_Calculate_clicked()
{

}




