#ifndef FILTERSABSTRACT_H
#define FILTERSABSTRACT_H

#include <QObject>

class FiltersAbstract : public QObject
{
    Q_OBJECT

public:

    FiltersAbstract();

    virtual void SetBaseValue(double , double , double ){};
    virtual void Calculate(){};

signals:

};

#endif // FILTERSABSTRACT_H
