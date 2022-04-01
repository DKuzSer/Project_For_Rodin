#ifndef CONSISTENT_H
#define CONSISTENT_H
#include "MainpowerSourcesAbstract.h"
#include "MyChartsView.h"
#include "MyCharts.h"
#include "constans.h"

class Consistent : public MainpowerSourcesAbstract
{

    Q_OBJECT

public:
    explicit Consistent(MainpowerSourcesAbstract);
    ~Consistent();
};

#endif // CONSISTENT_H
