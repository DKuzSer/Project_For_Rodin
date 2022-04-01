#ifndef FILTERS_H
#define FILTERS_H

#include "MainpowerSourcesAbstract.h"
#include "MyChartsView.h"
#include "MyCharts.h"
#include "FiltersAbstract.h"
#include "constans.h"

namespace Ui {
class Filters;
}

class Filters : public MainpowerSourcesAbstract
{
    Q_OBJECT

public:
    explicit Filters(MainpowerSourcesAbstract);
    ~Filters();

    MyChartsView* View;
    MyChartsView* ViewFCHX;

    FiltersAbstract* object_work = nullptr;

private slots:
    void on_ComboBox_Type_currentIndexChanged(int index);

    void on_ComboBox_View_currentIndexChanged(int index);

    void on_IntSpinBoxF_InPut3_valueChanged(int arg1);

    void on_PushButton_Calculate_clicked();

private:
    Ui::Filters *ui;

    MyCharts *chrt = nullptr;
    MyCharts *chrtFCHX = nullptr;
};

#endif // FILTERS_H
