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
    series->append(series0);

    this->addSeries(series);

    this->addAxis(axisX,Qt::AlignBottom);
    this->addAxis(axisY,Qt::AlignLeft);

    series->attachAxis(axisX);
    series->attachAxis(axisY);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MyCharts::AddSeries2DChart(QList<QPointF> series0, QString nameSeries)
{
    QLineSeries* seriesAdd = new QLineSeries();
    seriesAdd->append(series0);
    seriesAdd->setName(nameSeries);

    this->addSeries(seriesAdd);
    seriesAdd->attachAxis(axisX);
    seriesAdd->attachAxis(axisY);
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
void MyCharts::SetNameAxis(QString nameAxisX, QString nameAxisY)
{
    axisX->setTitleText(nameAxisX);
    axisY->setTitleText(nameAxisY);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MyCharts::DeleteChart()
{
    axisX->deleteLater();
    axisY->deleteLater();
    this->removeAllSeries();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
