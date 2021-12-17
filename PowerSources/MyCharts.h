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

    bool flagChart = true;

    void Create2DChart(QList<QPointF>);                                                                             // создание графика 2D
    void AddSeries2DChart(QList<QPointF> series0, QString nameSeries);                                              // добавление серии к графику
    void PropertiesAxis(QString nameAxis, double rangeLow, double rangeHigh, double count, QString format);         // свойства осей
    void SetNameAxis(QString nameAxisX, QString nameAxisY);                                                         // имена осей
    void DeleteChart();                                                                                             // удаление графика

};

#endif // MYCHARTS_H
