#ifndef DIOD_BASE_H
#define DIOD_BASE_H

#include <QWidget>
#include <QTableWidgetItem>

namespace Ui {
class diod_base;
}

class diod_base : public QWidget
{
    Q_OBJECT

public:
    explicit diod_base(QWidget *parent = nullptr);
    ~diod_base();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

public slots:
    void slot_diod_base();

signals:
    void signal_data_update(std::vector <QString>,std::vector <int>,std::vector <double>);

private:
    Ui::diod_base *ui;
    QTableWidgetItem* ID;

    std::vector <QString> names_of_diods;   //список диодов
    std::vector <int> Uobr_max;             //максимально допустимые обратные напряжения на диодах
    std::vector <double> Ipr;
};

#endif // DIOD_BASE_H
