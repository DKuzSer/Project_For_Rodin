#ifndef FILTERS_H
#define FILTERS_H

#include <QWidget>
#include "constans.h"

namespace Ui {
class Filters;
}

class Filters : public QWidget
{
    Q_OBJECT

public:
    explicit Filters(QWidget *parent = nullptr);
    ~Filters();

private:
    Ui::Filters *ui;
};

#endif // FILTERS_H
