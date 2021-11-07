#ifndef RECTIFIERS_H
#define RECTIFIERS_H

#include <QWidget>
#include <QPixmap>
#include "constans.h"
#include "RectifiersAbstract.h"

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

    QPixmap mapCircuit;
    QPixmap mapProperties;;

private slots:
    void on_ComboBox_DevicesR_currentIndexChanged(int index); // функция обработки выбора устройства

    void on_ComboBox_OutPutF_currentIndexChanged(int index);

    void on_PushButton_Calculate_clicked();

private:
    Ui::Rectifiers *ui;
};

#endif // RECTIFIERS_H
