#include "mainpowersources.h"
#include "ui_mainpowersources.h"
//some test shit
MainPowerSources::MainPowerSources(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPowerSources)
{
    ui->setupUi(this);
    ui->centralwidget->setStyleSheet("QMainWindow{"
                                     "background-color: rgba(36, 41, 67,85);"
                                     "}");
    ui->PushButton_Data->setStyleSheet(obj->getToolButtonsStyle());
    ui->PushButton_Tables->setStyleSheet(obj->getToolButtonsStyle());
    ui->PushButton_Calculate->setStyleSheet("QToolButton{"
                                            "background-color:rgb(80, 255, 163);"
                                            "border:2px solid rgb(255, 255, 255);"
                                            "color:rgb(0, 0, 0);"
                                            "border-radius:5px;"
                                            "}");
    ui->PushButton_Reference->setStyleSheet(obj->getToolButtonsStyle());
    ui->PushButton_Rectifiers->setStyleSheet(obj->getToolButtonsStyle());
    ui->PushButton_Filters->setStyleSheet(obj->getToolButtonsStyle());
    ui->PushButton_Matching->setStyleSheet(obj->getToolButtonsStyle());
    ui->Frame_SettingCalculate->setStyleSheet(obj->getFrameStyle());
    ui->frame->setStyleSheet(obj->getFrameStyle());
    ui->label1_NameProject->setStyleSheet(obj->getLabelStyle());
    ui->label2_NameProject->setStyleSheet(obj->getLabelStyle());
    ui->label->setStyleSheet("QLabel{"
                             "border:none;"
                             "background-color:none;"
                             "}");
    ui->Frame_UsingData->setStyleSheet(obj->getFrameStyle());
    ui->StackedWidget_Main->setStyleSheet("QStackedWidget{"
                                          "border:1px solid rgb(255, 255, 255);"
                                          "}");
    ui->horizontalFrame_page1->setStyleSheet("QFrame{"
                                             "background-color:none;"
                                             "border:0.5px solid rgb(255, 255, 255);"
                                             "background-color: rgba(54, 61, 100, 100);"
                                             "}");
    ui->horizontalFrame_2->setStyleSheet("QFrame{"
                                         "background-color:none;"
                                         "border:0.5px solid rgb(255, 255, 255);"
                                         "background-color: rgba(54, 61, 100, 100);"
                                         "}");
    ui->statusbar->showMessage("Разработчики программы: Дмитрий Кузищин ( kuzds321@gmail.com ) , Гилев Михаил ( mishagilevfgh@e1.ru ) , Слепцов Денис ( denis.slepczov@inbox.ru )");
    ui->statusbar->setStyleSheet("QStatusBar{"
                                 "color:rgb(255,255,255);"
                                 "}");
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
MainPowerSources::~MainPowerSources()
{
    delete ui;
    delete obj;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MainPowerSources::on_PushButton_Calculate_clicked()
{
    ui->StackedWidget_Main->setCurrentIndex(1);
    HoldTopPushButton(ui->PushButton_Calculate);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MainPowerSources::on_PushButton_Reference_clicked()
{
    ui->StackedWidget_Main->setCurrentIndex(0);
    HoldTopPushButton(ui->PushButton_Reference);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MainPowerSources::on_PushButton_Rectifiers_clicked()
{
    HoldLeftPushButton(ui->PushButton_Rectifiers);
    if(object_page1 == nullptr)
    {
        object_page1 = new Rectifiers;
    }
    else
    {
        delete object_page1;
        object_page1 = new Rectifiers;
    }

    std::vector <QString> names_of_diods;   //список диодов
    std::vector <int> Uobr_max;             //максимально допустимые обратные напряжения на диодах
    std::vector <double> Ipr;               //максимальный прямой ток на диоде
    QStringList list;
    if(names_of_diods.size() != 0)
    {
        QMessageBox::information(this,"Error","Files uploaded");
        names_of_diods.clear();
        Uobr_max.clear();
        Ipr.clear();
    }
    QFile mFile(":/Diods/Diode_brands");
    if (!mFile.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::information(this,"Error","Could not open file for Reading");
        return;
    }

    QTextStream in(&mFile);
    while(!in.atEnd())
        {
            QString sz = in.readLine();
            list = sz.split("\t");
            names_of_diods.push_back(list.at(0));
            Uobr_max.push_back(list.at(1).toDouble());
            Ipr.push_back(list.at(2).toDouble());
        }
    mFile.close();
    object_page1->SetDiodsParameters(names_of_diods, Uobr_max, Ipr);

    ui->horizontalFrame_page1->layout()->addWidget(object_page1);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MainPowerSources::on_PushButton_Filters_clicked()
{
    HoldLeftPushButton(ui->PushButton_Filters);
    if(object_page1 == nullptr)
    {
        object_page1 = new Filters;
    }
    else
    {
        delete object_page1;
        object_page1 = new Filters;
    }

    ui->horizontalFrame_page1->layout()->addWidget(object_page1);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MainPowerSources::on_PushButton_Matching_clicked()
{
    HoldLeftPushButton(ui->PushButton_Matching);
    if(object_page1 == nullptr)
    {
        object_page1 = new Matching;
    }
    else
    {
        delete object_page1;
        object_page1 = new Matching;
    }

    ui->horizontalFrame_page1->layout()->addWidget(object_page1);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MainPowerSources::on_PushButton_Data_clicked()
{
    HoldLeftPushButton(ui->PushButton_Data);
}


void MainPowerSources::on_PushButton_Tables_clicked()
{
    HoldLeftPushButton(ui->PushButton_Tables);
}

void MainPowerSources::HoldTopPushButton(QToolButton* button)
{
    HoldClearTopPushButton();
    button->setStyleSheet("QToolButton{"
                          "background-color:rgb(80, 255, 163);"
                          "border:2px solid rgb(255, 255, 255);"
                          "color:rgb(0, 0, 0);"
                          "border-radius:5px;"
                          "}");
}

void MainPowerSources::HoldLeftPushButton(QToolButton* button)
{
    HoldClearLeftPushButton();
    button->setStyleSheet("QToolButton{"
                          "background-color:rgb(80, 255, 163);"
                          "border:2px solid rgb(255, 255, 255);"
                          "color:rgb(0, 0, 0);"
                          "border-radius:5px;"
                          "}");
}

void MainPowerSources::HoldClearLeftPushButton()
{
    ui->PushButton_Data->setStyleSheet(obj->getToolButtonsStyle());
    ui->PushButton_Tables->setStyleSheet(obj->getToolButtonsStyle());
    ui->PushButton_Rectifiers->setStyleSheet(obj->getToolButtonsStyle());
    ui->PushButton_Filters->setStyleSheet(obj->getToolButtonsStyle());
    ui->PushButton_Matching->setStyleSheet(obj->getToolButtonsStyle());
}

void MainPowerSources::HoldClearTopPushButton()
{
    ui->PushButton_Calculate->setStyleSheet(obj->getToolButtonsStyle());
    ui->PushButton_Reference->setStyleSheet(obj->getToolButtonsStyle());
}

