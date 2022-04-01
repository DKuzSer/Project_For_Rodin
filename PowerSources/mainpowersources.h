#ifndef MAINPOWERSOURCES_H
#define MAINPOWERSOURCES_H

#include <QMainWindow>
#include "MainpowerSourcesAbstract.h"
#include "Rectifiers/Rectifiers.h"
#include "Filters/Filters.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainPowerSources; }
QT_END_NAMESPACE

class MainPowerSources : public QMainWindow
{
    Q_OBJECT

public:
    MainPowerSources(QWidget *parent = nullptr);
    ~MainPowerSources();

    MainpowerSourcesAbstract* object_page1 = nullptr;

private slots:
    void on_PushButton_Calculate_clicked();

    void on_PushButton_Reference_clicked();

    void on_PushButton_Rectifiers_clicked();

    void on_PushButton_Filters_clicked();

    void on_PushButton_Consistent_clicked();

private:
    Ui::MainPowerSources *ui;
};
#endif // MAINPOWERSOURCES_H
