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
    ui->Label_InPut1->setText("Напряжение питания Eк (В)");
    ui->Label_InPut2->setText("Макс. мощность транзистора (Вт)");
    ui->Label_OutPut1->setText("Выходное сопротивление транзистора Rвых (Ом)");

    View = new MyChartsView();
    ui->ChartsLayout->addWidget(View);
    View ->setRenderHint(QPainter::Antialiasing);

    ViewFCHX = new MyChartsView();
    ui->ChartsLayout->addWidget(ViewFCHX);
    ViewFCHX ->setRenderHint(QPainter::Antialiasing);

    ui->ComboBox_Type->addItem("Транзистор", TYPEOFCIRCUIT);

    ui->ComboBox_View->addItem("П-фильтр", FIRSTCIRCUITMATCHING);
    ui->ComboBox_View->addItem("Модифицированный П-фильтр", SECONDCIRCUITMATCHING);
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
    delete object_works;
    delete chrt;
    delete chrtFCHX;
}

void Matching::on_ComboBox_Type_currentIndexChanged(int index)
{

}

void Matching::on_ComboBox_View_currentIndexChanged(int index)
{
    switch (index)
    {
        case FIRSTCIRCUITMATCHING:

        break;
        case SECONDCIRCUITMATCHING:

        break;
    }
}

void Matching::on_PushButton_Calculate_clicked()
{

}




