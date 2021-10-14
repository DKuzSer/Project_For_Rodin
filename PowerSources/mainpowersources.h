#ifndef MAINPOWERSOURCES_H
#define MAINPOWERSOURCES_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainPowerSources; }
QT_END_NAMESPACE

class MainPowerSources : public QMainWindow
{
    Q_OBJECT

public:
    MainPowerSources(QWidget *parent = nullptr);
    ~MainPowerSources();

private:
    Ui::MainPowerSources *ui;
};
#endif // MAINPOWERSOURCES_H
