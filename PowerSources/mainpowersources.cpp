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
