#include "Transmitter_Output_Stage.h"
#include "ui_Transmitter_Output_Stage.h"

Transmitter_Output_Stage::Transmitter_Output_Stage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transmitter_Output_Stage)
{
    ui->setupUi(this);
}

Transmitter_Output_Stage::~Transmitter_Output_Stage()
{
    delete ui;
}
