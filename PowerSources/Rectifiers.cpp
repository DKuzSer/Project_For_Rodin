#include "Rectifiers.h"
#include "ui_Rectifiers.h"

Rectifiers::Rectifiers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rectifiers)
{
    ui->setupUi(this);

    ui->ComboBox_DevicesR->addItem("Однополупериодный", ONEPERIODCIRCUIT);
}

Rectifiers::~Rectifiers()
{
    delete ui;
}
