#ifndef MYCHARTSVIEW_H
#define MYCHARTSVIEW_H

#include <QtCharts>

class MyChartsView : public QChartView
{
    Q_OBJECT

public:
    MyChartsView();

public slots:
    void mouseMoveEvent(QMouseEvent *event) override; //override - переопределение метода так, чтобы
    //он имел индентичную сигнатуру с методом класса предка, но предоставлял иное поведение

signals:
    void signalCoordinateCursor(QPointF, int ind);

};

#endif // MYCHARTSVIEW_H
