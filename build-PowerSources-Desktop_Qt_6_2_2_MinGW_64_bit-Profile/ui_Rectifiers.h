/********************************************************************************
** Form generated from reading UI file 'Rectifiers.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECTIFIERS_H
#define UI_RECTIFIERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rectifiers
{
public:
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_10;
    QTabWidget *TabWidget;
    QWidget *Tab_PageCircuit;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QLabel *Label_PixMapCircuit;
    QWidget *Tab_PageChart;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *ChartsLayout;
    QVBoxLayout *verticalLayout_12;
    QGroupBox *GroupBox_InPut;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *Label_InPut1;
    QLabel *Label_InPut2;
    QLabel *Label_InPut3;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QDoubleSpinBox *DoubleSpinBoxR_InPut1;
    QDoubleSpinBox *DoubleSpinBoxR_InPut2;
    QDoubleSpinBox *DoubleSpinBoxR_InPut3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *Label_InPut6;
    QLabel *Label_InPut5;
    QLabel *Label_InPut4;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QDoubleSpinBox *DoubleSpinBoxR_InPut6;
    QDoubleSpinBox *DoubleSpinBoxR_InPut5;
    QDoubleSpinBox *DoubleSpinBoxR_InPut4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *ComboBox_DevicesR;
    QHBoxLayout *horizontalLayout_7;
    QLabel *Label_OutPutF;
    QComboBox *ComboBox_OutPutF;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *PushButton_Interactive;
    QPushButton *PushButton_Hands;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout;
    QDoubleSpinBox *DoubleSpinBoxOY;
    QDoubleSpinBox *DoubleSpinBoxOX;
    QGroupBox *GroupBox_OutPut;
    QGridLayout *gridLayout_3;
    QPushButton *PushButton_Calculate;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_8;
    QLabel *Label_OutPut1;
    QLabel *Label_OutPut2;
    QLabel *Label_OutPut3;
    QVBoxLayout *verticalLayout_7;
    QDoubleSpinBox *DoubleSpinBoxR_OutPut1;
    QDoubleSpinBox *DoubleSpinBoxR_OutPut2;
    QDoubleSpinBox *DoubleSpinBoxR_OutPut3;
    QLabel *label_2;
    QComboBox *list_of_diods;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Rectifiers)
    {
        if (Rectifiers->objectName().isEmpty())
            Rectifiers->setObjectName(QString::fromUtf8("Rectifiers"));
        Rectifiers->setWindowModality(Qt::NonModal);
        Rectifiers->resize(767, 606);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Rectifiers->sizePolicy().hasHeightForWidth());
        Rectifiers->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(72, 101, 113, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(120, 144, 156, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        Rectifiers->setPalette(palette);
        Rectifiers->setContextMenuPolicy(Qt::DefaultContextMenu);
        Rectifiers->setWindowOpacity(1.000000000000000);
        Rectifiers->setToolTipDuration(-1);
        Rectifiers->setLayoutDirection(Qt::LeftToRight);
        gridLayout_8 = new QGridLayout(Rectifiers);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        TabWidget = new QTabWidget(Rectifiers);
        TabWidget->setObjectName(QString::fromUtf8("TabWidget"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        TabWidget->setPalette(palette1);
        TabWidget->setStyleSheet(QString::fromUtf8(""));
        Tab_PageCircuit = new QWidget();
        Tab_PageCircuit->setObjectName(QString::fromUtf8("Tab_PageCircuit"));
        Tab_PageCircuit->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 144, 156)"));
        gridLayout_6 = new QGridLayout(Tab_PageCircuit);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        Label_PixMapCircuit = new QLabel(Tab_PageCircuit);
        Label_PixMapCircuit->setObjectName(QString::fromUtf8("Label_PixMapCircuit"));
        Label_PixMapCircuit->setMaximumSize(QSize(700, 400));
        Label_PixMapCircuit->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 144, 156)"));

        gridLayout_5->addWidget(Label_PixMapCircuit, 0, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);

        TabWidget->addTab(Tab_PageCircuit, QString());
        Tab_PageChart = new QWidget();
        Tab_PageChart->setObjectName(QString::fromUtf8("Tab_PageChart"));
        Tab_PageChart->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 144, 156)"));
        horizontalLayout_8 = new QHBoxLayout(Tab_PageChart);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        ChartsLayout = new QVBoxLayout();
        ChartsLayout->setObjectName(QString::fromUtf8("ChartsLayout"));

        horizontalLayout_8->addLayout(ChartsLayout);

        TabWidget->addTab(Tab_PageChart, QString());

        horizontalLayout_10->addWidget(TabWidget);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        GroupBox_InPut = new QGroupBox(Rectifiers);
        GroupBox_InPut->setObjectName(QString::fromUtf8("GroupBox_InPut"));
        gridLayout_4 = new QGridLayout(GroupBox_InPut);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        Label_InPut1 = new QLabel(GroupBox_InPut);
        Label_InPut1->setObjectName(QString::fromUtf8("Label_InPut1"));

        verticalLayout_5->addWidget(Label_InPut1);

        Label_InPut2 = new QLabel(GroupBox_InPut);
        Label_InPut2->setObjectName(QString::fromUtf8("Label_InPut2"));

        verticalLayout_5->addWidget(Label_InPut2);

        Label_InPut3 = new QLabel(GroupBox_InPut);
        Label_InPut3->setObjectName(QString::fromUtf8("Label_InPut3"));

        verticalLayout_5->addWidget(Label_InPut3);


        horizontalLayout_3->addLayout(verticalLayout_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        DoubleSpinBoxR_InPut1 = new QDoubleSpinBox(GroupBox_InPut);
        DoubleSpinBoxR_InPut1->setObjectName(QString::fromUtf8("DoubleSpinBoxR_InPut1"));
        DoubleSpinBoxR_InPut1->setMaximum(10000.000000000000000);
        DoubleSpinBoxR_InPut1->setValue(50.000000000000000);

        verticalLayout_4->addWidget(DoubleSpinBoxR_InPut1);

        DoubleSpinBoxR_InPut2 = new QDoubleSpinBox(GroupBox_InPut);
        DoubleSpinBoxR_InPut2->setObjectName(QString::fromUtf8("DoubleSpinBoxR_InPut2"));

        verticalLayout_4->addWidget(DoubleSpinBoxR_InPut2);

        DoubleSpinBoxR_InPut3 = new QDoubleSpinBox(GroupBox_InPut);
        DoubleSpinBoxR_InPut3->setObjectName(QString::fromUtf8("DoubleSpinBoxR_InPut3"));

        verticalLayout_4->addWidget(DoubleSpinBoxR_InPut3);


        horizontalLayout_3->addLayout(verticalLayout_4);


        gridLayout_2->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        Label_InPut6 = new QLabel(GroupBox_InPut);
        Label_InPut6->setObjectName(QString::fromUtf8("Label_InPut6"));

        verticalLayout_3->addWidget(Label_InPut6);

        Label_InPut5 = new QLabel(GroupBox_InPut);
        Label_InPut5->setObjectName(QString::fromUtf8("Label_InPut5"));

        verticalLayout_3->addWidget(Label_InPut5);

        Label_InPut4 = new QLabel(GroupBox_InPut);
        Label_InPut4->setObjectName(QString::fromUtf8("Label_InPut4"));

        verticalLayout_3->addWidget(Label_InPut4);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        DoubleSpinBoxR_InPut6 = new QDoubleSpinBox(GroupBox_InPut);
        DoubleSpinBoxR_InPut6->setObjectName(QString::fromUtf8("DoubleSpinBoxR_InPut6"));
        DoubleSpinBoxR_InPut6->setMinimum(1.000000000000000);
        DoubleSpinBoxR_InPut6->setMaximum(10000.000000000000000);
        DoubleSpinBoxR_InPut6->setValue(1.000000000000000);

        verticalLayout_2->addWidget(DoubleSpinBoxR_InPut6);

        DoubleSpinBoxR_InPut5 = new QDoubleSpinBox(GroupBox_InPut);
        DoubleSpinBoxR_InPut5->setObjectName(QString::fromUtf8("DoubleSpinBoxR_InPut5"));
        DoubleSpinBoxR_InPut5->setSingleStep(0.100000000000000);

        verticalLayout_2->addWidget(DoubleSpinBoxR_InPut5);

        DoubleSpinBoxR_InPut4 = new QDoubleSpinBox(GroupBox_InPut);
        DoubleSpinBoxR_InPut4->setObjectName(QString::fromUtf8("DoubleSpinBoxR_InPut4"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(DoubleSpinBoxR_InPut4->sizePolicy().hasHeightForWidth());
        DoubleSpinBoxR_InPut4->setSizePolicy(sizePolicy1);
        DoubleSpinBoxR_InPut4->setMinimum(0.000000000000000);
        DoubleSpinBoxR_InPut4->setMaximum(10000.000000000000000);
        DoubleSpinBoxR_InPut4->setValue(1.000000000000000);

        verticalLayout_2->addWidget(DoubleSpinBoxR_InPut4);


        horizontalLayout_2->addLayout(verticalLayout_2);


        gridLayout_2->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(GroupBox_InPut);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        ComboBox_DevicesR = new QComboBox(GroupBox_InPut);
        ComboBox_DevicesR->setObjectName(QString::fromUtf8("ComboBox_DevicesR"));

        horizontalLayout_4->addWidget(ComboBox_DevicesR);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        Label_OutPutF = new QLabel(GroupBox_InPut);
        Label_OutPutF->setObjectName(QString::fromUtf8("Label_OutPutF"));

        horizontalLayout_7->addWidget(Label_OutPutF);

        ComboBox_OutPutF = new QComboBox(GroupBox_InPut);
        ComboBox_OutPutF->setObjectName(QString::fromUtf8("ComboBox_OutPutF"));

        horizontalLayout_7->addWidget(ComboBox_OutPutF);


        gridLayout_2->addLayout(horizontalLayout_7, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 1, 0, 1, 1);


        verticalLayout_12->addWidget(GroupBox_InPut);

        groupBox = new QGroupBox(Rectifiers);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_7 = new QGridLayout(groupBox);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        PushButton_Interactive = new QPushButton(groupBox);
        PushButton_Interactive->setObjectName(QString::fromUtf8("PushButton_Interactive"));

        horizontalLayout_9->addWidget(PushButton_Interactive);

        PushButton_Hands = new QPushButton(groupBox);
        PushButton_Hands->setObjectName(QString::fromUtf8("PushButton_Hands"));

        horizontalLayout_9->addWidget(PushButton_Hands);


        gridLayout->addLayout(horizontalLayout_9, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_6->addWidget(label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_6->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        DoubleSpinBoxOY = new QDoubleSpinBox(groupBox);
        DoubleSpinBoxOY->setObjectName(QString::fromUtf8("DoubleSpinBoxOY"));

        verticalLayout->addWidget(DoubleSpinBoxOY);

        DoubleSpinBoxOX = new QDoubleSpinBox(groupBox);
        DoubleSpinBoxOX->setObjectName(QString::fromUtf8("DoubleSpinBoxOX"));

        verticalLayout->addWidget(DoubleSpinBoxOX);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout, 0, 0, 1, 1);


        verticalLayout_12->addWidget(groupBox);

        GroupBox_OutPut = new QGroupBox(Rectifiers);
        GroupBox_OutPut->setObjectName(QString::fromUtf8("GroupBox_OutPut"));
        gridLayout_3 = new QGridLayout(GroupBox_OutPut);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        PushButton_Calculate = new QPushButton(GroupBox_OutPut);
        PushButton_Calculate->setObjectName(QString::fromUtf8("PushButton_Calculate"));

        gridLayout_3->addWidget(PushButton_Calculate, 2, 0, 1, 1);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        Label_OutPut1 = new QLabel(GroupBox_OutPut);
        Label_OutPut1->setObjectName(QString::fromUtf8("Label_OutPut1"));

        verticalLayout_8->addWidget(Label_OutPut1);

        Label_OutPut2 = new QLabel(GroupBox_OutPut);
        Label_OutPut2->setObjectName(QString::fromUtf8("Label_OutPut2"));

        verticalLayout_8->addWidget(Label_OutPut2);

        Label_OutPut3 = new QLabel(GroupBox_OutPut);
        Label_OutPut3->setObjectName(QString::fromUtf8("Label_OutPut3"));

        verticalLayout_8->addWidget(Label_OutPut3);


        horizontalLayout_5->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        DoubleSpinBoxR_OutPut1 = new QDoubleSpinBox(GroupBox_OutPut);
        DoubleSpinBoxR_OutPut1->setObjectName(QString::fromUtf8("DoubleSpinBoxR_OutPut1"));

        verticalLayout_7->addWidget(DoubleSpinBoxR_OutPut1);

        DoubleSpinBoxR_OutPut2 = new QDoubleSpinBox(GroupBox_OutPut);
        DoubleSpinBoxR_OutPut2->setObjectName(QString::fromUtf8("DoubleSpinBoxR_OutPut2"));
        DoubleSpinBoxR_OutPut2->setMaximum(10000.000000000000000);

        verticalLayout_7->addWidget(DoubleSpinBoxR_OutPut2);

        DoubleSpinBoxR_OutPut3 = new QDoubleSpinBox(GroupBox_OutPut);
        DoubleSpinBoxR_OutPut3->setObjectName(QString::fromUtf8("DoubleSpinBoxR_OutPut3"));
        DoubleSpinBoxR_OutPut3->setMaximum(10000.000000000000000);
        DoubleSpinBoxR_OutPut3->setSingleStep(1.000000000000000);

        verticalLayout_7->addWidget(DoubleSpinBoxR_OutPut3);


        horizontalLayout_5->addLayout(verticalLayout_7);

        horizontalLayout_5->setStretch(0, 1);

        verticalLayout_11->addLayout(horizontalLayout_5);

        label_2 = new QLabel(GroupBox_OutPut);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_11->addWidget(label_2);

        list_of_diods = new QComboBox(GroupBox_OutPut);
        list_of_diods->setObjectName(QString::fromUtf8("list_of_diods"));

        verticalLayout_11->addWidget(list_of_diods);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));

        horizontalLayout_6->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));

        horizontalLayout_6->addLayout(verticalLayout_10);


        verticalLayout_11->addLayout(horizontalLayout_6);


        gridLayout_3->addLayout(verticalLayout_11, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 1, 0, 1, 1);


        verticalLayout_12->addWidget(GroupBox_OutPut);


        horizontalLayout_10->addLayout(verticalLayout_12);

        horizontalLayout_10->setStretch(0, 2);

        gridLayout_8->addLayout(horizontalLayout_10, 0, 0, 1, 1);


        retranslateUi(Rectifiers);

        TabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Rectifiers);
    } // setupUi

    void retranslateUi(QWidget *Rectifiers)
    {
        Rectifiers->setWindowTitle(QCoreApplication::translate("Rectifiers", "Form", nullptr));
        Label_PixMapCircuit->setText(QCoreApplication::translate("Rectifiers", "TextLabel", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(Tab_PageCircuit), QCoreApplication::translate("Rectifiers", "\320\241\321\205\320\265\320\274\320\260", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(Tab_PageChart), QCoreApplication::translate("Rectifiers", "\320\223\321\200\320\260\321\204\320\270\320\272", nullptr));
        GroupBox_InPut->setTitle(QCoreApplication::translate("Rectifiers", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265:", nullptr));
        Label_InPut1->setText(QCoreApplication::translate("Rectifiers", "TextLabel", nullptr));
        Label_InPut2->setText(QCoreApplication::translate("Rectifiers", "TextLabel", nullptr));
        Label_InPut3->setText(QCoreApplication::translate("Rectifiers", "TextLabel", nullptr));
        Label_InPut6->setText(QCoreApplication::translate("Rectifiers", "TextLabel", nullptr));
        Label_InPut5->setText(QCoreApplication::translate("Rectifiers", "TextLabel", nullptr));
        Label_InPut4->setText(QCoreApplication::translate("Rectifiers", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("Rectifiers", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\262\321\213\320\277\321\200\321\217\320\274\320\270\321\202\320\265\320\273\321\214:", nullptr));
        Label_OutPutF->setText(QCoreApplication::translate("Rectifiers", "\320\235\320\260\320\273\320\270\321\207\320\270\320\265 \321\204\320\270\320\273\321\214\321\202\321\200\320\260:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Rectifiers", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\260 \320\264\320\260\320\275\320\275\321\213\321\205 \320\263\321\200\320\260\321\204\320\270\320\272\320\260:", nullptr));
        PushButton_Interactive->setText(QCoreApplication::translate("Rectifiers", "\320\230\320\275\321\202\320\265\321\200\320\260\320\272\321\202\320\270\320\262\320\275\321\213\320\271", nullptr));
        PushButton_Hands->setText(QCoreApplication::translate("Rectifiers", "\320\240\321\203\321\207\320\275\320\276\320\271", nullptr));
        label_3->setText(QCoreApplication::translate("Rectifiers", "OY:", nullptr));
        label_4->setText(QCoreApplication::translate("Rectifiers", "OX:", nullptr));
        GroupBox_OutPut->setTitle(QCoreApplication::translate("Rectifiers", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213:", nullptr));
        PushButton_Calculate->setText(QCoreApplication::translate("Rectifiers", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \321\200\320\260\321\201\321\207\321\221\321\202", nullptr));
        Label_OutPut1->setText(QCoreApplication::translate("Rectifiers", "TextLabel", nullptr));
        Label_OutPut2->setText(QCoreApplication::translate("Rectifiers", "TextLabel", nullptr));
        Label_OutPut3->setText(QCoreApplication::translate("Rectifiers", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Rectifiers", "\320\237\320\276\320\264\321\205\320\276\320\264\321\217\321\211\320\270\320\265 \320\264\320\270\320\276\320\264\321\213:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Rectifiers: public Ui_Rectifiers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECTIFIERS_H
