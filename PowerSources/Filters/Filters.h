#ifndef FILTERS_H
#define FILTERS_H

#include "MainpowerSourcesAbstract.h"
#include "constans.h"

namespace Ui {
class Filters;
}

class Filters : public MainpowerSourcesAbstract
{
    Q_OBJECT

public:
    explicit Filters(MainpowerSourcesAbstract *parent = nullptr);
    ~Filters();

private:
    Ui::Filters *ui;
};

#endif // FILTERS_H
