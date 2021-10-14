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

