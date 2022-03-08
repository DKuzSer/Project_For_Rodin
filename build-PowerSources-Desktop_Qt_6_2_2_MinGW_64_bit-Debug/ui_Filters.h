/********************************************************************************
** Form generated from reading UI file 'Filters.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERS_H
#define UI_FILTERS_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Filters
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QVBoxLayout *ChartsLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Label_Type;
    QComboBox *ComboBox_Type;
    QHBoxLayout *horizontalLayout_7;
    QLabel *Label_View;
    QComboBox *ComboBox_View;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *Label_InPut1;
    QLabel *Label_InPut2;
    QLabel *Label_InPut3;
    QVBoxLayout *verticalLayout_4;
    QDoubleSpinBox *DoubleSpinBoxF_InPut1;
    QDoubleSpinBox *DoubleSpinBoxF_InPut2;
    QSpinBox *IntSpinBoxF_InPut3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *Label_InPut4;
    QLabel *Label_InPut5;
    QLabel *Label_InPut6;
    QVBoxLayout *verticalLayout_2;
    QDoubleSpinBox *DoubleSpinBoxF_InPut4;
    QDoubleSpinBox *DoubleSpinBoxF_InPut5;
    QDoubleSpinBox *DoubleSpinBoxF_InPut6;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_14;
    QLabel *Label_Output8;
    QLabel *Label_Output7;
    QVBoxLayout *verticalLayout_13;
    QDoubleSpinBox *DoubleSpinBoxF_OutPut7;
    QDoubleSpinBox *DoubleSpinBoxF_OutPut8;
    QPushButton *PushButton_Calculate;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_9;
    QLabel *Label_OutPut1;
    QLabel *Label_OutPut2;
    QLabel *Label_OutPut3;
    QVBoxLayout *verticalLayout_8;
    QDoubleSpinBox *DoubleSpinBoxF_OutPut1;
    QDoubleSpinBox *DoubleSpinBoxF_OutPut2;
    QDoubleSpinBox *DoubleSpinBoxF_OutPut3;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_11;
    QLabel *Label_OutPut4;
    QLabel *Label_OutPut5;
    QLabel *Label_OutPut6;
    QVBoxLayout *verticalLayout_10;
    QDoubleSpinBox *DoubleSpinBoxF_OutPut4;
    QDoubleSpinBox *DoubleSpinBoxF_OutPut5;
    QDoubleSpinBox *DoubleSpinBoxF_OutPut6;

    void setupUi(QWidget *Filters)
    {
        if (Filters->objectName().isEmpty())
            Filters->setObjectName(QString::fromUtf8("Filters"));
        Filters->resize(723, 645);
        gridLayout = new QGridLayout(Filters);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(Filters);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        ChartsLayout = new QVBoxLayout();
        ChartsLayout->setObjectName(QString::fromUtf8("ChartsLayout"));

        gridLayout_4->addLayout(ChartsLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(Filters);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        Label_Type = new QLabel(groupBox);
        Label_Type->setObjectName(QString::fromUtf8("Label_Type"));

        horizontalLayout_4->addWidget(Label_Type);

        ComboBox_Type = new QComboBox(groupBox);
        ComboBox_Type->setObjectName(QString::fromUtf8("ComboBox_Type"));

        horizontalLayout_4->addWidget(ComboBox_Type);


        verticalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        Label_View = new QLabel(groupBox);
        Label_View->setObjectName(QString::fromUtf8("Label_View"));

        horizontalLayout_7->addWidget(Label_View);

        ComboBox_View = new QComboBox(groupBox);
        ComboBox_View->setObjectName(QString::fromUtf8("ComboBox_View"));

        horizontalLayout_7->addWidget(ComboBox_View);


        verticalLayout_7->addLayout(horizontalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        Label_InPut1 = new QLabel(groupBox);
        Label_InPut1->setObjectName(QString::fromUtf8("Label_InPut1"));

        verticalLayout_5->addWidget(Label_InPut1);

        Label_InPut2 = new QLabel(groupBox);
        Label_InPut2->setObjectName(QString::fromUtf8("Label_InPut2"));

        verticalLayout_5->addWidget(Label_InPut2);

        Label_InPut3 = new QLabel(groupBox);
        Label_InPut3->setObjectName(QString::fromUtf8("Label_InPut3"));

        verticalLayout_5->addWidget(Label_InPut3);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        DoubleSpinBoxF_InPut1 = new QDoubleSpinBox(groupBox);
        DoubleSpinBoxF_InPut1->setObjectName(QString::fromUtf8("DoubleSpinBoxF_InPut1"));
        DoubleSpinBoxF_InPut1->setMinimum(0.010000000000000);
        DoubleSpinBoxF_InPut1->setMaximum(1000000000.000000000000000);

        verticalLayout_4->addWidget(DoubleSpinBoxF_InPut1);

        DoubleSpinBoxF_InPut2 = new QDoubleSpinBox(groupBox);
        DoubleSpinBoxF_InPut2->setObjectName(QString::fromUtf8("DoubleSpinBoxF_InPut2"));
        DoubleSpinBoxF_InPut2->setMinimum(0.010000000000000);
        DoubleSpinBoxF_InPut2->setMaximum(10000.000000000000000);

        verticalLayout_4->addWidget(DoubleSpinBoxF_InPut2);

        IntSpinBoxF_InPut3 = new QSpinBox(groupBox);
        IntSpinBoxF_InPut3->setObjectName(QString::fromUtf8("IntSpinBoxF_InPut3"));
        IntSpinBoxF_InPut3->setMinimum(2);
        IntSpinBoxF_InPut3->setMaximum(6);

        verticalLayout_4->addWidget(IntSpinBoxF_InPut3);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        Label_InPut4 = new QLabel(groupBox);
        Label_InPut4->setObjectName(QString::fromUtf8("Label_InPut4"));

        verticalLayout_3->addWidget(Label_InPut4);

        Label_InPut5 = new QLabel(groupBox);
        Label_InPut5->setObjectName(QString::fromUtf8("Label_InPut5"));

        verticalLayout_3->addWidget(Label_InPut5);

        Label_InPut6 = new QLabel(groupBox);
        Label_InPut6->setObjectName(QString::fromUtf8("Label_InPut6"));

        verticalLayout_3->addWidget(Label_InPut6);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        DoubleSpinBoxF_InPut4 = new QDoubleSpinBox(groupBox);
        DoubleSpinBoxF_InPut4->setObjectName(QString::fromUtf8("DoubleSpinBoxF_InPut4"));
        DoubleSpinBoxF_InPut4->setMaximum(1000.000000000000000);

        verticalLayout_2->addWidget(DoubleSpinBoxF_InPut4);

        DoubleSpinBoxF_InPut5 = new QDoubleSpinBox(groupBox);
        DoubleSpinBoxF_InPut5->setObjectName(QString::fromUtf8("DoubleSpinBoxF_InPut5"));
        DoubleSpinBoxF_InPut5->setMaximum(1000.000000000000000);

        verticalLayout_2->addWidget(DoubleSpinBoxF_InPut5);

        DoubleSpinBoxF_InPut6 = new QDoubleSpinBox(groupBox);
        DoubleSpinBoxF_InPut6->setObjectName(QString::fromUtf8("DoubleSpinBoxF_InPut6"));
        DoubleSpinBoxF_InPut6->setMaximum(1000.000000000000000);

        verticalLayout_2->addWidget(DoubleSpinBoxF_InPut6);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_6->addLayout(horizontalLayout_2);


        verticalLayout_7->addLayout(verticalLayout_6);


        gridLayout_2->addLayout(verticalLayout_7, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Filters);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        Label_Output8 = new QLabel(groupBox_2);
        Label_Output8->setObjectName(QString::fromUtf8("Label_Output8"));

        verticalLayout_14->addWidget(Label_Output8);

        Label_Output7 = new QLabel(groupBox_2);
        Label_Output7->setObjectName(QString::fromUtf8("Label_Output7"));

        verticalLayout_14->addWidget(Label_Output7);


        horizontalLayout_8->addLayout(verticalLayout_14);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        DoubleSpinBoxF_OutPut7 = new QDoubleSpinBox(groupBox_2);
        DoubleSpinBoxF_OutPut7->setObjectName(QString::fromUtf8("DoubleSpinBoxF_OutPut7"));
        DoubleSpinBoxF_OutPut7->setDecimals(7);
        DoubleSpinBoxF_OutPut7->setMaximum(1000000.000000000000000);

        verticalLayout_13->addWidget(DoubleSpinBoxF_OutPut7);

        DoubleSpinBoxF_OutPut8 = new QDoubleSpinBox(groupBox_2);
        DoubleSpinBoxF_OutPut8->setObjectName(QString::fromUtf8("DoubleSpinBoxF_OutPut8"));
        DoubleSpinBoxF_OutPut8->setDecimals(7);
        DoubleSpinBoxF_OutPut8->setMaximum(1000000.000000000000000);

        verticalLayout_13->addWidget(DoubleSpinBoxF_OutPut8);


        horizontalLayout_8->addLayout(verticalLayout_13);


        gridLayout_3->addLayout(horizontalLayout_8, 1, 0, 1, 1);

        PushButton_Calculate = new QPushButton(groupBox_2);
        PushButton_Calculate->setObjectName(QString::fromUtf8("PushButton_Calculate"));

        gridLayout_3->addWidget(PushButton_Calculate, 2, 0, 1, 1);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        Label_OutPut1 = new QLabel(groupBox_2);
        Label_OutPut1->setObjectName(QString::fromUtf8("Label_OutPut1"));

        verticalLayout_9->addWidget(Label_OutPut1);

        Label_OutPut2 = new QLabel(groupBox_2);
        Label_OutPut2->setObjectName(QString::fromUtf8("Label_OutPut2"));

        verticalLayout_9->addWidget(Label_OutPut2);

        Label_OutPut3 = new QLabel(groupBox_2);
        Label_OutPut3->setObjectName(QString::fromUtf8("Label_OutPut3"));

        verticalLayout_9->addWidget(Label_OutPut3);


        horizontalLayout_5->addLayout(verticalLayout_9);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        DoubleSpinBoxF_OutPut1 = new QDoubleSpinBox(groupBox_2);
        DoubleSpinBoxF_OutPut1->setObjectName(QString::fromUtf8("DoubleSpinBoxF_OutPut1"));
        DoubleSpinBoxF_OutPut1->setDecimals(7);
        DoubleSpinBoxF_OutPut1->setMaximum(1000000.000000000000000);

        verticalLayout_8->addWidget(DoubleSpinBoxF_OutPut1);

        DoubleSpinBoxF_OutPut2 = new QDoubleSpinBox(groupBox_2);
        DoubleSpinBoxF_OutPut2->setObjectName(QString::fromUtf8("DoubleSpinBoxF_OutPut2"));
        DoubleSpinBoxF_OutPut2->setDecimals(7);
        DoubleSpinBoxF_OutPut2->setMaximum(1000000.000000000000000);

        verticalLayout_8->addWidget(DoubleSpinBoxF_OutPut2);

        DoubleSpinBoxF_OutPut3 = new QDoubleSpinBox(groupBox_2);
        DoubleSpinBoxF_OutPut3->setObjectName(QString::fromUtf8("DoubleSpinBoxF_OutPut3"));
        DoubleSpinBoxF_OutPut3->setDecimals(7);
        DoubleSpinBoxF_OutPut3->setMaximum(1000000.000000000000000);

        verticalLayout_8->addWidget(DoubleSpinBoxF_OutPut3);


        horizontalLayout_5->addLayout(verticalLayout_8);


        verticalLayout_12->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        Label_OutPut4 = new QLabel(groupBox_2);
        Label_OutPut4->setObjectName(QString::fromUtf8("Label_OutPut4"));

        verticalLayout_11->addWidget(Label_OutPut4);

        Label_OutPut5 = new QLabel(groupBox_2);
        Label_OutPut5->setObjectName(QString::fromUtf8("Label_OutPut5"));

        verticalLayout_11->addWidget(Label_OutPut5);

        Label_OutPut6 = new QLabel(groupBox_2);
        Label_OutPut6->setObjectName(QString::fromUtf8("Label_OutPut6"));

        verticalLayout_11->addWidget(Label_OutPut6);


        horizontalLayout_6->addLayout(verticalLayout_11);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        DoubleSpinBoxF_OutPut4 = new QDoubleSpinBox(groupBox_2);
        DoubleSpinBoxF_OutPut4->setObjectName(QString::fromUtf8("DoubleSpinBoxF_OutPut4"));
        DoubleSpinBoxF_OutPut4->setDecimals(7);
        DoubleSpinBoxF_OutPut4->setMaximum(1000000.000000000000000);

        verticalLayout_10->addWidget(DoubleSpinBoxF_OutPut4);

        DoubleSpinBoxF_OutPut5 = new QDoubleSpinBox(groupBox_2);
        DoubleSpinBoxF_OutPut5->setObjectName(QString::fromUtf8("DoubleSpinBoxF_OutPut5"));
        DoubleSpinBoxF_OutPut5->setDecimals(7);
        DoubleSpinBoxF_OutPut5->setMaximum(1000000.000000000000000);

        verticalLayout_10->addWidget(DoubleSpinBoxF_OutPut5);

        DoubleSpinBoxF_OutPut6 = new QDoubleSpinBox(groupBox_2);
        DoubleSpinBoxF_OutPut6->setObjectName(QString::fromUtf8("DoubleSpinBoxF_OutPut6"));
        DoubleSpinBoxF_OutPut6->setDecimals(7);
        DoubleSpinBoxF_OutPut6->setMaximum(1000000.000000000000000);

        verticalLayout_10->addWidget(DoubleSpinBoxF_OutPut6);


        horizontalLayout_6->addLayout(verticalLayout_10);


        verticalLayout_12->addLayout(horizontalLayout_6);


        gridLayout_3->addLayout(verticalLayout_12, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(Filters);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Filters);
    } // setupUi

    void retranslateUi(QWidget *Filters)
    {
        Filters->setWindowTitle(QCoreApplication::translate("Filters", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Filters", "\320\241\321\205\320\265\320\274\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Filters", "\320\223\321\200\320\260\321\204\320\270\320\272", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Filters", "\320\222\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \321\204\320\270\320\273\321\214\321\202\321\200\320\260:", nullptr));
        Label_Type->setText(QCoreApplication::translate("Filters", "\320\242\320\270\320\277 \321\204\320\270\320\273\321\214\321\202\321\200\320\260:", nullptr));
        Label_View->setText(QCoreApplication::translate("Filters", "\320\222\320\270\320\264 \321\204\320\270\320\273\321\214\321\202\321\200\320\260:", nullptr));
        Label_InPut1->setText(QCoreApplication::translate("Filters", "TextLabel", nullptr));
        Label_InPut2->setText(QCoreApplication::translate("Filters", "TextLabel", nullptr));
        Label_InPut3->setText(QCoreApplication::translate("Filters", "TextLabel", nullptr));
        Label_InPut4->setText(QCoreApplication::translate("Filters", "TextLabel", nullptr));
        Label_InPut5->setText(QCoreApplication::translate("Filters", "TextLabel", nullptr));
        Label_InPut6->setText(QCoreApplication::translate("Filters", "TextLabel", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Filters", "\320\222\321\213\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265:", nullptr));
        Label_Output8->setText(QCoreApplication::translate("Filters", "TextLabel", nullptr));
        Label_Output7->setText(QCoreApplication::translate("Filters", "TextLabel", nullptr));
        PushButton_Calculate->setText(QCoreApplication::translate("Filters", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \321\200\320\260\321\201\321\207\321\221\321\202", nullptr));
        Label_OutPut1->setText(QCoreApplication::translate("Filters", "TextLabel", nullptr));
        Label_OutPut2->setText(QCoreApplication::translate("Filters", "TextLabel", nullptr));
        Label_OutPut3->setText(QCoreApplication::translate("Filters", "TextLabel", nullptr));
        Label_OutPut4->setText(QCoreApplication::translate("Filters", "TextLabel", nullptr));
        Label_OutPut5->setText(QCoreApplication::translate("Filters", "TextLabel", nullptr));
        Label_OutPut6->setText(QCoreApplication::translate("Filters", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Filters: public Ui_Filters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERS_H
