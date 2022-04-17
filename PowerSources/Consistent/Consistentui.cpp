#include "Consistentui.h"
#include "ui_Consistentui.h"

ConsistentUi::ConsistentUi(MainpowerSourcesAbstract *parent):
    ui(new Ui::ConsistentUi)
{
    ui->setupUi(this);
}

ConsistentUi::~ConsistentUi()
{
    delete ui;
}
