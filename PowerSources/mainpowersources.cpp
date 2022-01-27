#include "mainpowersources.h"
#include "ui_mainpowersources.h"

MainPowerSources::MainPowerSources(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPowerSources)
{
    ui->setupUi(this);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
MainPowerSources::~MainPowerSources()
{
    delete ui;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MainPowerSources::on_PushButton_Calculate_clicked()
{
    ui->StackedWidget_Main->setCurrentIndex(1);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MainPowerSources::on_PushButton_Reference_clicked()
{
    ui->StackedWidget_Main->setCurrentIndex(0);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MainPowerSources::on_PushButton_Rectifiers_clicked()
{
    if(object_page1 == nullptr)
    {
        object_page1 = new Rectifiers;
    }
    else
    {
        delete object_page1;
        object_page1 = new Rectifiers;
    }

    std::vector <QString> names_of_diods;   //список диодов
    std::vector <int> Uobr_max;             //максимально допустимые обратные напряжения на диодах
    std::vector <double> Ipr;               //максимальный прямой ток на диоде
    QStringList list;
    if(names_of_diods.size() != 0)
    {
        QMessageBox::information(this,"Error","Files uploaded");
        names_of_diods.clear();
        Uobr_max.clear();
        Ipr.clear();
    }
    QFile mFile(":/Diods/Diods.txt");
    if (!mFile.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::information(this,"Error","Could not open file for Reading");
        return;
    }

    QTextStream in(&mFile);
    while(!in.atEnd())
        {
            QString sz = in.readLine();
            list = sz.split("\t");
            names_of_diods.push_back(list.at(0));
            Uobr_max.push_back(list.at(1).toDouble());
            Ipr.push_back(list.at(2).toDouble());
        }
    mFile.close();
    object_page1->SetDiodsParameters(names_of_diods, Uobr_max, Ipr);

    ui->horizontalFrame_page1->layout()->addWidget(object_page1);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MainPowerSources::on_PushButton_Filters_clicked()
{
    if(object_page1 == nullptr)
    {
        object_page1 = new Filters;
    }
    else
    {
        delete object_page1;
        object_page1 = new Filters;
    }

    ui->horizontalFrame_page1->layout()->addWidget(object_page1);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
