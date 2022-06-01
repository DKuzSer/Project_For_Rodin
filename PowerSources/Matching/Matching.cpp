#include "Matching.h"
#include "ui_Matching.h"

Matching::Matching(MainpowerSourcesAbstract *parent) :
    ui(new Ui::Matching)
  , m_viewM(new SvgView)
{
    ui->setupUi(this);
    Q_UNUSED(parent);
//-------------------------------------------------------------------------------------   
    m_viewM->openFile(":/SVG/SVG/Matching_option1.svg");
    ui->SVG_M->addWidget(m_viewM);

    //const QSize availableSize = QApplication::desktop()->availableGeometry(this).size();
    //resize(m_view->sizeHint().expandedTo(availableSize /4) + QSize(80, 80));
    m_viewM->scale(0.5,0.5); //коэффициенты масштабирования
    m_viewM->setBackgroundBrush(Qt::white);
    m_viewM->setAlignment(Qt::AlignCenter);
    m_viewM->setRenderer(static_cast<SvgView::RendererType>(0));//рендерим наше изображение
    //statusBar()->addPermanentWidget(m_zoomLabel);
    //updateZoomLabel();
    //connect(m_view, &SvgView::zoomChanged, this, &Rectifiers::updateZoomLabel);
//--------------------------------------------------------------------
    ui->Label_InPut1->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_InPut2->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_InPut3->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_InPut4->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_InPut5->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_InPut6->setStyleSheet(style_helper->getLabelStyle());

    ui->Label_OutPut1->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_OutPut2->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_OutPut3->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_OutPut4->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_OutPut5->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_OutPut6->setStyleSheet(style_helper->getLabelStyle());

    ui->Label_Type->setStyleSheet(style_helper->getLabelStyle());
    ui->Label_View->setStyleSheet(style_helper->getLabelStyle());

    ui->groupBox->setStyleSheet(style_helper->getGroupBoxStyle());
    ui->groupBox_2->setStyleSheet(style_helper->getGroupBoxStyle());
//-------------------------------------------------------------------------------------
//    ui->Label_InPut1->setText("Напряжение питания Eк (В)");
//    ui->Label_InPut2->setText("Макс. мощность транзистора (Вт)");
//    ui->Label_OutPut1->setText("Выходное сопротивление транзистора Rвых (Ом)");

    View = new MyChartsView();
    ui->ChartsLayout->addWidget(View);
    View ->setRenderHint(QPainter::Antialiasing);

    ViewFCHX = new MyChartsView();
    ui->ChartsLayout->addWidget(ViewFCHX);
    ViewFCHX ->setRenderHint(QPainter::Antialiasing);

    ui->ComboBox_Type->addItem("Транзистор", TYPEOFCIRCUITMATCHING);

    ui->ComboBox_View->addItem("П-фильтр", PiCIRCUITMATCHING);
    ui->ComboBox_View->addItem("Модифицированный П-фильтр", MODIFPiCIRCUITMATCHING);

//    ui->Label_InPut3->setVisible(false);
//    ui->Label_InPut4->setVisible(false);
//    ui->Label_InPut5->setVisible(false);
//    ui->Label_InPut6->setVisible(false);
//    ui->IntSpinBoxF_InPut3->setVisible(false);
//    ui->DoubleSpinBoxF_InPut4->setVisible(false);
//    ui->DoubleSpinBoxF_InPut5->setVisible(false);
//    ui->DoubleSpinBoxF_InPut6->setVisible(false);

//    ui->Label_OutPut2->setVisible(false);
//    ui->Label_OutPut3->setVisible(false);
//    ui->Label_OutPut4->setVisible(false);
//    ui->Label_OutPut5->setVisible(false);
//    ui->Label_OutPut6->setVisible(false);

//    ui->DoubleSpinBoxF_OutPut2->setVisible(false);
//    ui->DoubleSpinBoxF_OutPut3->setVisible(false);
//    ui->DoubleSpinBoxF_OutPut4->setVisible(false);
//    ui->DoubleSpinBoxF_OutPut5->setVisible(false);
//    ui->DoubleSpinBoxF_OutPut6->setVisible(false);
}

Matching::~Matching()
{    
    delete ui;
    delete style_helper;
    delete View;
    delete ViewFCHX;
    delete object_work;
//    delete m_viewM;
//    delete chrt;
//    delete chrtFCHX;
}

void Matching::on_ComboBox_Type_currentIndexChanged(int index)
{
    switch(index) // условие обработки выбора устройства
    {
        case TYPEOFCIRCUITMATCHING:
            if(object_work != nullptr)
            {
                delete object_work;
                object_work = new  MatchingOneCircuit();
            }
            else
                object_work = new  MatchingOneCircuit();

            //настройки входных данных
            //----------------------------------------------
            //________Редактирование замечаний______________
            ui->ComboBox_Type->setVisible(false);
            ui->Label_Type->setVisible(false);
            //----------------------------------------------
            ui->Label_InPut1->setVisible(true);
            ui->Label_InPut1->setText("Ек (Напряжение питания), В:");
            ui->DoubleSpinBoxF_InPut1->setVisible(true);

            ui->Label_InPut2->setVisible(true);
            ui->Label_InPut2->setText("P (Макс. мощность транзистора), Вт:");
            ui->DoubleSpinBoxF_InPut2->setVisible(true);

            ui->Label_InPut3->setVisible(true);
            ui->Label_InPut3->setText("F (Частота), МГц:");
            ui->DoubleSpinBoxF_InPut3->setVisible(true);

            ui->Label_InPut4->setVisible(true);
            ui->Label_InPut4->setText("Rн (Сопротивление нагрузки), Ом:");
            ui->DoubleSpinBoxF_InPut4->setVisible(true);

            ui->Label_InPut5->setVisible(true);
            ui->Label_InPut5->setText("Q (Добротность катушки L3):");
            ui->DoubleSpinBoxF_InPut5->setVisible(true);

            ui->Label_InPut6->setVisible(false);
            ui->Label_InPut6->setText("Uн (Напряжение на нагрузке), В:");
            ui->DoubleSpinBoxF_InPut6->setVisible(false);
            //----------------------------------------------
            //корректировка 29.05.2022 не ссы, все нормально, я отвечаю
            //ui->Label_InPut2->setVisible(false);
            //ui->DoubleSpinBoxF_InPut2->setVisible(false);
            //


        break;
    }
}

void Matching::on_ComboBox_View_currentIndexChanged(int index)
{
    int indexType = ui->ComboBox_Type->currentIndex();

    switch (index)
    {
        if(indexType == TYPEOFCIRCUITMATCHING)
        {
            case PiCIRCUITMATCHING:
                //настройки выходных данных
                //----------------------------------------------
                ui->Label_OutPut1->setVisible(true);
                ui->Label_OutPut1->setText("Rвх (Выходное сопротивление транзистора), Ом");
                ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
                ui->DoubleSpinBoxF_OutPut1->setVisible(true);

                ui->Label_OutPut2->setVisible(true);
                ui->Label_OutPut2->setText("С4 (Ёмкость), пФ:");
                ui->DoubleSpinBoxF_OutPut2->setEnabled(false);
                ui->DoubleSpinBoxF_OutPut2->setVisible(true);

                ui->Label_OutPut3->setVisible(true);
                ui->Label_OutPut3->setText("L3 (Индуктивность), мкГн:");
                ui->DoubleSpinBoxF_OutPut3->setEnabled(false);
                ui->DoubleSpinBoxF_OutPut3->setVisible(true);

                ui->Label_OutPut4->setVisible(true);
                ui->Label_OutPut4->setText("С5 (Ёмкость), пФ:");
                ui->DoubleSpinBoxF_OutPut4->setEnabled(false);
                ui->DoubleSpinBoxF_OutPut4->setVisible(true);

                ui->Label_OutPut5->setVisible(false);
                ui->DoubleSpinBoxF_OutPut5->setVisible(false);
                ui->Label_OutPut6->setVisible(false);
                ui->DoubleSpinBoxF_OutPut6->setVisible(false);

                m_viewM->openFile(":/SVG/SVG/Matching_option1.svg");
                m_viewM->scale(0.5,0.5); //коэффициенты масштабирования
                m_viewM->setBackgroundBrush(Qt::white);
                m_viewM->setAlignment(Qt::AlignCenter);
                m_viewM->setRenderer(static_cast<SvgView::RendererType>(0));//рендерим наше изображение
                //----------------------------------------------
            break;

            case MODIFPiCIRCUITMATCHING:
                //настройки выходных данных
                //----------------------------------------------
                ui->Label_OutPut1->setVisible(true);
                ui->Label_OutPut1->setText("Rвх (Выходное сопротивление транзистора), Ом");
                ui->DoubleSpinBoxF_OutPut1->setEnabled(false);
                ui->DoubleSpinBoxF_OutPut1->setVisible(true);

                ui->Label_OutPut2->setVisible(true);
                ui->Label_OutPut2->setText("С4 (Ёмкость), пФ:");
                ui->DoubleSpinBoxF_OutPut2->setEnabled(false);
                ui->DoubleSpinBoxF_OutPut2->setVisible(true);

                ui->Label_OutPut3->setVisible(true);
                ui->Label_OutPut3->setText("L3 (Индуктивность), мкГн:");
                ui->DoubleSpinBoxF_OutPut3->setEnabled(false);
                ui->DoubleSpinBoxF_OutPut3->setVisible(true);

                ui->Label_OutPut4->setVisible(true);
                ui->Label_OutPut4->setText("С5 (Ёмкость), пФ:");
                ui->DoubleSpinBoxF_OutPut4->setEnabled(false);
                ui->DoubleSpinBoxF_OutPut4->setVisible(true);

                ui->Label_OutPut5->setVisible(true);
                ui->Label_OutPut5->setText("L4 (Индуктивность), мкГн:");
                ui->DoubleSpinBoxF_OutPut5->setEnabled(false);
                ui->DoubleSpinBoxF_OutPut5->setVisible(true);


                ui->Label_OutPut6->setVisible(false);
                ui->DoubleSpinBoxF_OutPut6->setVisible(false);

                m_viewM->openFile(":/SVG/SVG/Matching_option2.svg");
                m_viewM->scale(0.5,0.5); //коэффициенты масштабирования
                m_viewM->setBackgroundBrush(Qt::white);
                m_viewM->setAlignment(Qt::AlignCenter);
                m_viewM->setRenderer(static_cast<SvgView::RendererType>(0));//рендерим наше изображение
                //----------------------------------------------
            break;
        }
    }
}

void Matching::on_PushButton_Calculate_clicked()
{
    int index = ui->ComboBox_Type->currentIndex();

    if (index == TYPEOFCIRCUITMATCHING)
    {
        if(chrt == nullptr)
        {
            chrt = new MyCharts();
            View->setChart(chrt);
            chrt->setTitle("АЧХ");
            chrt->legend()->hide();

            chrtFCHX = new MyCharts();
            ViewFCHX->setChart(chrtFCHX);
            chrtFCHX->setTitle("ФЧХ");
            chrtFCHX->legend()->hide();

//            interactive = false;
//            hands = false;
//            ui->PushButton_Interactive->setEnabled(true);
//            ui->PushButton_Hands->setEnabled(true);
//            ui->DoubleSpinBoxOX->setEnabled(false);
//            ui->DoubleSpinBoxOY->setEnabled(false);
//            ui->DoubleSpinBoxOX->setValue(0.0);
//            ui->DoubleSpinBoxOY->setValue(0.0);

        }
        else if(chrt->flagChart == true)
        {
            chrt->DeleteChart();
            chrtFCHX->DeleteChart();

//            interactive = false;
//            hands = false;
//            ui->PushButton_Interactive->setEnabled(true);
//            ui->PushButton_Hands->setEnabled(true);
//            ui->DoubleSpinBoxOX->setEnabled(false);
//            ui->DoubleSpinBoxOY->setEnabled(false);
//            ui->DoubleSpinBoxOX->setValue(0.0);
//            ui->DoubleSpinBoxOY->setValue(0.0);

//            if(flagEllipseItem)
//            {
//                delete ellipceItem;
//                flagEllipseItem = false;
//            }

        }

        //--------------------------------------------------
        double Ek = ui->DoubleSpinBoxF_InPut1->value();           //Напряжение питания
        double P = ui->DoubleSpinBoxF_InPut2->value();            //Максимальная мощность на транзисторе
        double F = ui->DoubleSpinBoxF_InPut3->value();            //Частота МГц
        double Rout = ui->DoubleSpinBoxF_InPut4->value();         //Сопротивление нагрузки
        double Q = ui->DoubleSpinBoxF_InPut5->value();            //Добротность катушки
        double RinCorrect = ui->doubleSpinBoxInPutCorrect->value();
        //--------------------------------------------------

        int chose = ui->ComboBox_View->currentIndex();
           switch(chose)
           {
                case 0 :
                    object_work->SetBaseValue(Ek, P, F, Rout, Q, RinCorrect);
                break;

                case 1 :
                    object_work->SetBaseValue(Ek, P, F, Rout, Q, RinCorrect);
                break;
            }

        // передаём данные в расчётный класс
        object_work->ViewFilters(chose);                          // передаём данные флага установки фильтра на выходе
        object_work->Calculate(isCorrectRin);

//        if(object_work->flagCalculate == true)
//        {
//            QMessageBox::information(this,"Ошибка","Данные параметры нельзя реализовать");
//            chrt->flagChart = false;
//            return;
//        }

        //переписываем в удобный формат
        //--------------------------------------------------

        double value_1 = object_work->Rin;
        double value_2 = object_work->C1;
        double value_3 = object_work->L1;
        double value_4 = object_work->C2;
        double value_5 = object_work->L2;

        if(value_2 > 10000)
        {
            value_2 = value_2/1000;
            ui->Label_OutPut2->setText("C4 (Ёмкость), нФ:");
        }
        else
        {
            ui->Label_OutPut2->setText("C4 (Ёмкость), пФ:");
        }

        if(value_4 > 10000)
        {
            value_4 = value_4/1000;
            ui->Label_OutPut4->setText("C5 (Ёмкость), нФ:");
        }
        else
        {
            ui->Label_OutPut4->setText("C5 (Ёмкость), пФ:");
        }

        switch(chose) // установка полученный значений для отображения в GUI
        {
            case 0:
                ui->DoubleSpinBoxF_OutPut1->setValue(value_1);
                ui->DoubleSpinBoxF_OutPut2->setValue(value_2);
                ui->DoubleSpinBoxF_OutPut3->setValue(value_3);
                ui->DoubleSpinBoxF_OutPut4->setValue(value_4);
            break;

            case 1:
                ui->DoubleSpinBoxF_OutPut1->setValue(value_1);
                ui->DoubleSpinBoxF_OutPut2->setValue(value_2);
                ui->DoubleSpinBoxF_OutPut3->setValue(value_3);
                ui->DoubleSpinBoxF_OutPut4->setValue(value_4);
                ui->DoubleSpinBoxF_OutPut5->setValue(value_5);
            break;
        }



//        if(chose == 1)
//        {
//            if(value_3 > 10000)
//            {
//                value_3 = value_3/1000;
//                ui->Label_OutPut3->setText("C, мФ:");
//            }
//            else
//            {
//                ui->Label_OutPut3->setText("C, мкФ:");
//            }
//        }

        //-------------------------------------------------------
    }
}

void Matching::on_Alignment_CheckBox_clicked(bool checked)
{
    isCorrectRin = checked;
}

