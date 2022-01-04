#include "MyChartsView.h"

MyChartsView::MyChartsView()
{

}

void MyChartsView::mouseMoveEvent(QMouseEvent *event)
{
    int ind = -1;
    QPointF a = event->pos();
    emit signalCoordinateCursor(a, ind);
}
