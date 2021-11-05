#ifndef RECTIFIERS_H
#define RECTIFIERS_H

#include <QWidget>
#include "constans.h"

namespace Ui {
class Rectifiers;
}

class Rectifiers : public QWidget
{
    Q_OBJECT

public:
    explicit Rectifiers(QWidget *parent = nullptr);
    ~Rectifiers();

private:
    Ui::Rectifiers *ui;
};

#endif // RECTIFIERS_H
