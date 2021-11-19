#ifndef MYCHARTS_H
#define MYCHARTS_H

#include <QtCharts>

class MyCharts : public QChart
{
public:
    MyCharts();
    ~MyCharts();

    QLineSeries* series = nullptr;
    QValueAxis* axisX = nullptr;
    QValueAxis* axisY = nullptr;

    void Create2DChart(QList<QPointF>);                                                                             // создание графика 2D
    void PropertiesAxis(QString nameAxis, double rangeLow, double rangeHigh, double count, QString format);         // свойства осей
    void DeleteChart();                                                                                             // удаление графика

};

#endif // MYCHARTS_H
