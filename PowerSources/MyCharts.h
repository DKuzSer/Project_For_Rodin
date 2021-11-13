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

    void Create2DChart(QList<QPointF>);
    void PropertiesAxis(QString nameAxis, double rangeLow, double rangeHigh, double count, QString format);
    void DeleteChart();

};

#endif // MYCHARTS_H
