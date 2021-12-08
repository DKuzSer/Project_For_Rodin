#include "Filters.h"
#include "ui_Filters.h"

Filters::Filters(MainpowerSourcesAbstract *parent) :
    ui(new Ui::Filters)
{
    ui->setupUi(this);

    ui->ComboBox_DevicesF->addItem("Баттерворта", BUTTERWORTH);
}

Filters::~Filters()
{
    delete ui;
}
