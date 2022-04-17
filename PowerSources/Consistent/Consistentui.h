#ifndef CONSISTENTUI_H
#define CONSISTENTUI_H

#include <QWidget>
#include "MainpowerSourcesAbstract.h"
#include "MyChartsView.h"
#include "MyCharts.h"
#include "constans.h"

namespace Ui {
class ConsistentUi;
}

class ConsistentUi : public MainpowerSourcesAbstract
{
    Q_OBJECT

public:
    explicit ConsistentUi(MainpowerSourcesAbstract *parent = nullptr);
    ~ConsistentUi();

private:
    Ui::ConsistentUi *ui;
};

#endif // CONSISTENTUI_H
