#ifndef MATCHING_H
#define MATCHING_H

#include "MainpowerSourcesAbstract.h"
#include "MatchingAbstract.h"
#include "stylehelper.h"
#include "MyCharts.h"
#include "MyChartsView.h"
#include "constans.h"
#include "svgview.h"

#include "MatchingOneCircuit.h"
#include "MatchingTwoCircuit.h"

namespace Ui {
class Matching;
}

class Matching : public MainpowerSourcesAbstract
{
    Q_OBJECT

public:
    explicit Matching(MainpowerSourcesAbstract *parent = nullptr);
    ~Matching();

    MyChartsView* View;
    MyChartsView* ViewFCHX;

    MatchingAbstract* object_work = nullptr;

    bool isCorrectRin = false;

private slots:
    void on_PushButton_Calculate_clicked();

    void on_ComboBox_Type_currentIndexChanged(int index);

    void on_ComboBox_View_currentIndexChanged(int index);

    void on_Alignment_CheckBox_clicked(bool checked);

private:
    Ui::Matching *ui;

    StyleHelper* style_helper = new StyleHelper;

    MyCharts *chrt = nullptr;
    MyCharts *chrtFCHX = nullptr;

    SvgView *m_viewM;
};

#endif // MATCHING_H
