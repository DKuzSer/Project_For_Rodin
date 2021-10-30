#include "Rectifiers.h"
#include "ui_Rectifiers.h"

Rectifiers::Rectifiers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rectifiers)
{
    ui->setupUi(this);
}

Rectifiers::~Rectifiers()
{
    delete ui;
}
