#include "MyCharts.h"

MyCharts::MyCharts()
{

}

MyCharts::~MyCharts()
{
    DeleteChart();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MyCharts::Create2DChart(QList<QPointF> series0)
{
    series = new QLineSeries();
    axisX = new QValueAxis;
    axisY = new QValueAxis;
//    for(int i = 0; i < (int)series0.pointsVector().size(); i++)
//    {
//        double x = series->pointsVector()
//        series->append(i,series0[i]);

//    }
    series->append(series0);

    this->addSeries(series);

    this->addAxis(axisX,Qt::AlignBottom);
    this->addAxis(axisY,Qt::AlignLeft);

    series->attachAxis(axisX);
    series->attachAxis(axisY);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MyCharts::PropertiesAxis(QString nameAxis, double rangeLow, double rangeHigh, double count, QString format)
{
    if(nameAxis == "X")
    {
        axisX->setRange(rangeLow, rangeHigh);
        axisX->setTickCount(count);
        axisX->setLabelFormat(format);
    }
    if(nameAxis == "Y")
    {
        axisY->setRange(rangeLow, rangeHigh);
        axisY->setTickCount(count);
        axisY->setLabelFormat(format);
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MyCharts::DeleteChart()
{
    axisX->deleteLater();
    axisY->deleteLater();
    this->removeAllSeries();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
