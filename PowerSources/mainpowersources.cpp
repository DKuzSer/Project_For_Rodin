#include "mainpowersources.h"
#include "ui_mainpowersources.h"

MainPowerSources::MainPowerSources(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPowerSources)
{
    ui->setupUi(this);
}

MainPowerSources::~MainPowerSources()
{
    delete ui;
}

void MainPowerSources::on_PushButton_Calculate_clicked()
{
    ui->StackedWidget_Main->setCurrentIndex(1);
}

void MainPowerSources::on_PushButton_Reference_clicked()
{
    ui->StackedWidget_Main->setCurrentIndex(0);
}

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

    ui->horizontalFrame_page1->layout()->addWidget(object_page1);
}

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
