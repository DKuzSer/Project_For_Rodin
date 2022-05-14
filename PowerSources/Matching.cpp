#include "Matching.h"
#include "ui_Matching.h"

Matching::Matching(MainpowerSourcesAbstract *parent) :
    ui(new Ui::Matching)
{
    ui->setupUi(this);
    Q_UNUSED(parent);
}

Matching::~Matching()
{
    delete ui;
}
