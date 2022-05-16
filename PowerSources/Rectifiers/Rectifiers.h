#ifndef RECTIFIERS_H
#define RECTIFIERS_H

#include "MainpowerSourcesAbstract.h"
#include "constans.h"
#include "RectifiersAbstract.h"
#include "MyCharts.h"
#include "MyChartsView.h"
#include "diod_base.h"
#include "svgview.h"
#include <QtWidgets>
#include <QSvgRenderer>
#include <QPixmap>
#include <QMessageBox>
#include "stylehelper.h"

namespace Ui {
class Rectifiers;
}

class Rectifiers : public MainpowerSourcesAbstract
{
    Q_OBJECT

public:
    explicit Rectifiers(MainpowerSourcesAbstract *parent = nullptr);
    ~Rectifiers();

    RectifiersAbstract* object_work = nullptr;

    void SetDiodsParameters(std::vector <QString>, std::vector <int>, std::vector <double>);
    int Near(QPointF Coords, QLineSeries *series, int Size);
    std::vector <QString> names_of_diods;   //список диодов
    std::vector <int> Uobr_max;             //максимально допустимые обратные напряжения на диодах
    std::vector <double> Ipr;

    MyChartsView* View;

    QPixmap mapCircuit;
    QPixmap mapProperties;

    QGraphicsEllipseItem* ellipceItem;

    bool interactive = false;
    bool hands = false;
    bool flagEllipseItem = false;

private slots:
    void on_ComboBox_DevicesR_currentIndexChanged(int index); // функция обработки выбора устройства

    void on_ComboBox_OutPutF_currentIndexChanged(int index);

    void on_PushButton_Calculate_clicked();

    void CoordinateCursor(QPointF point, int ind);

    void on_PushButton_Interactive_clicked(bool checked);

    void on_PushButton_Hands_clicked(bool checked);

    void on_DoubleSpinBoxOX_valueChanged(double arg1);

    void on_diod_base_clicked();

public slots:
    void diod_base_update(std::vector <QString> _names_of_diods, std::vector <int> _Uobr_max, std::vector <double> _Ipr);

signals:
    void signal_diod_base();

private:
    Ui::Rectifiers *ui;

    MyCharts *chrt = nullptr;

    diod_base* base;

    SvgView* m_view;

    StyleHelper* style_helper = new StyleHelper;
};

#endif // RECTIFIERS_H
