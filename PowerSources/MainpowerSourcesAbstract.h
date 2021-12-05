#ifndef MAINPOWERSOURCESABSTRACT_H
#define MAINPOWERSOURCESABSTRACT_H

#include <QWidget>

class MainpowerSourcesAbstract : public QWidget
{
    Q_OBJECT
public:
    MainpowerSourcesAbstract();

    virtual void SetDiodsParameters(std::vector <QString>, std::vector <int>){};

signals:

};

#endif // MAINPOWERSOURCESABSTRACT_H
