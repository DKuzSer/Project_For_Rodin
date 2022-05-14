#ifndef MATCHING_H
#define MATCHING_H

#include <QWidget>
#include "MainpowerSourcesAbstract.h"

namespace Ui {
class Matching;
}

class Matching : public MainpowerSourcesAbstract
{
    Q_OBJECT

public:
    explicit Matching(MainpowerSourcesAbstract *parent = nullptr);
    ~Matching();

private:
    Ui::Matching *ui;
};

#endif // MATCHING_H
