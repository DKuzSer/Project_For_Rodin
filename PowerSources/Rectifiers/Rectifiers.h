#ifndef RECTIFIERS_H
#define RECTIFIERS_H

#include <QWidget>
#include <QPixmap>
#include <QMessageBox>
#include "constans.h"
#include "RectifiersAbstract.h"
#include "MyCharts.h"

namespace Ui {
class Rectifiers;
}

class Rectifiers : public QWidget
{
    Q_OBJECT

public:
    explicit Rectifiers(QWidget *parent = nullptr);
    ~Rectifiers();

    RectifiersAbstract* object_work = nullptr;

    virtual void SetDiodsParameters(std::vector <QString>, std::vector <int>);
    std::vector <QString> names_of_diods;   //список диодов
    std::vector <int> Uobr_max;             //максимально допустимые обратные напряжения на диодах

    QPixmap mapCircuit;
    QPixmap mapProperties;;

private slots:
    void on_ComboBox_DevicesR_currentIndexChanged(int index); // функция обработки выбора устройства

    void on_ComboBox_OutPutF_currentIndexChanged(int index);

    void on_PushButton_Calculate_clicked();

private:
    Ui::Rectifiers *ui;

    MyCharts *chrt = nullptr;
};

#endif // RECTIFIERS_H
