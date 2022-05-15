#ifndef MAINPOWERSOURCES_H
#define MAINPOWERSOURCES_H

#include <QMainWindow>
#include "MainpowerSourcesAbstract.h"
#include "Rectifiers/Rectifiers.h"
#include "Filters/Filters.h"
#include "Matching/Matching.h"
#include "stylehelper.h"

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

    void HoldPushButton(QToolButton*);

    void HoldClearLeftPushButton();

    void HoldClearTopPushButton();

    void HoldTopPushButton(QToolButton* button);

    void HoldLeftPushButton(QToolButton* button);

private slots:
    void on_PushButton_Calculate_clicked();

    void on_PushButton_Reference_clicked();

    void on_PushButton_Rectifiers_clicked();

    void on_PushButton_Filters_clicked();

    void on_PushButton_Data_clicked();

    void on_PushButton_Tables_clicked();

    void on_PushButton_Matching_clicked();

private:
    Ui::MainPowerSources *ui;
    StyleHelper *obj;
};
#endif // MAINPOWERSOURCES_H
