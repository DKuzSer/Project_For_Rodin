/********************************************************************************
** Form generated from reading UI file 'mainpowersources.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPOWERSOURCES_H
#define UI_MAINPOWERSOURCES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPowerSources
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QFrame *Frame;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *label1_NameProject;
    QLabel *label2_NameProject;
    QToolButton *PushButton_Calculate;
    QToolButton *PushButton_Reference;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *StackedWidget_Main;
    QWidget *Page_SettingCalculate;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QFrame *Frame_SettingCalculate;
    QVBoxLayout *verticalLayout_4;
    QPushButton *PushButton_Data;
    QPushButton *PushButton_Tables;
    QSpacerItem *verticalSpacer_3;
    QFrame *horizontalFrame_2;
    QHBoxLayout *horizontalLayout_5;
    QWidget *Page_UsingData;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QFrame *Frame_UsingData;
    QVBoxLayout *verticalLayout_3;
    QToolButton *PushButton_Rectifiers;
    QToolButton *PushButton_Filters;
    QSpacerItem *verticalSpacer;
    QFrame *horizontalFrame_page1;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainPowerSources)
    {
        if (MainPowerSources->objectName().isEmpty())
            MainPowerSources->setObjectName(QString::fromUtf8("MainPowerSources"));
        MainPowerSources->setWindowModality(Qt::WindowModal);
        MainPowerSources->resize(1400, 950);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainPowerSources->sizePolicy().hasHeightForWidth());
        MainPowerSources->setSizePolicy(sizePolicy);
        MainPowerSources->setMinimumSize(QSize(1400, 950));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(64, 65, 66, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(206, 206, 206, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(167, 167, 167, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(204, 204, 204, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush5(QColor(88, 109, 127, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush5);
        QBrush brush6(QColor(51, 75, 90, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(223, 223, 223, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(0, 0, 0, 128));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        MainPowerSources->setPalette(palette);
        MainPowerSources->setLayoutDirection(Qt::LeftToRight);
        MainPowerSources->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        centralwidget = new QWidget(MainPowerSources);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMaximumSize(QSize(16777215, 150));
        frame->setFrameShape(QFrame::Box);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(1, 1, -1, 1);
        splitter = new QSplitter(frame);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy2);
        splitter->setFrameShape(QFrame::NoFrame);
        splitter->setOrientation(Qt::Horizontal);
        Frame = new QFrame(splitter);
        Frame->setObjectName(QString::fromUtf8("Frame"));
        Frame->setFrameShape(QFrame::NoFrame);
        gridLayout_4 = new QGridLayout(Frame);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label = new QLabel(Frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(110, 0));
        label->setMaximumSize(QSize(110, 16777215));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/img/DopLogo.png")));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label1_NameProject = new QLabel(Frame);
        label1_NameProject->setObjectName(QString::fromUtf8("label1_NameProject"));
        label1_NameProject->setMinimumSize(QSize(86, 0));
        label1_NameProject->setMaximumSize(QSize(86, 16777215));
        QFont font;
        font.setPointSize(14);
        label1_NameProject->setFont(font);

        verticalLayout->addWidget(label1_NameProject);

        label2_NameProject = new QLabel(Frame);
        label2_NameProject->setObjectName(QString::fromUtf8("label2_NameProject"));
        label2_NameProject->setMinimumSize(QSize(86, 0));
        label2_NameProject->setMaximumSize(QSize(86, 16777215));
        label2_NameProject->setFont(font);

        verticalLayout->addWidget(label2_NameProject);


        gridLayout_4->addLayout(verticalLayout, 0, 1, 1, 1);

        PushButton_Calculate = new QToolButton(Frame);
        PushButton_Calculate->setObjectName(QString::fromUtf8("PushButton_Calculate"));
        sizePolicy.setHeightForWidth(PushButton_Calculate->sizePolicy().hasHeightForWidth());
        PushButton_Calculate->setSizePolicy(sizePolicy);
        PushButton_Calculate->setMinimumSize(QSize(110, 74));
        PushButton_Calculate->setMaximumSize(QSize(110, 74));
        QFont font1;
        font1.setPointSize(12);
        PushButton_Calculate->setFont(font1);
        PushButton_Calculate->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 144, 156)"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/img/ButtonCalculate.png"), QSize(), QIcon::Normal, QIcon::Off);
        PushButton_Calculate->setIcon(icon);
        PushButton_Calculate->setIconSize(QSize(48, 48));
        PushButton_Calculate->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_4->addWidget(PushButton_Calculate, 0, 2, 1, 1);

        PushButton_Reference = new QToolButton(Frame);
        PushButton_Reference->setObjectName(QString::fromUtf8("PushButton_Reference"));
        sizePolicy.setHeightForWidth(PushButton_Reference->sizePolicy().hasHeightForWidth());
        PushButton_Reference->setSizePolicy(sizePolicy);
        PushButton_Reference->setMinimumSize(QSize(110, 74));
        PushButton_Reference->setMaximumSize(QSize(110, 74));
        PushButton_Reference->setFont(font1);
        PushButton_Reference->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 144, 156)"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/img/ButtonData.png"), QSize(), QIcon::Normal, QIcon::Off);
        PushButton_Reference->setIcon(icon1);
        PushButton_Reference->setIconSize(QSize(48, 48));
        PushButton_Reference->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_4->addWidget(PushButton_Reference, 0, 3, 1, 1);

        splitter->addWidget(Frame);

        horizontalLayout->addWidget(splitter);

        horizontalSpacer = new QSpacerItem(300, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(frame);

        StackedWidget_Main = new QStackedWidget(centralwidget);
        StackedWidget_Main->setObjectName(QString::fromUtf8("StackedWidget_Main"));
        sizePolicy1.setHeightForWidth(StackedWidget_Main->sizePolicy().hasHeightForWidth());
        StackedWidget_Main->setSizePolicy(sizePolicy1);
        StackedWidget_Main->setMinimumSize(QSize(0, 400));
        StackedWidget_Main->setLayoutDirection(Qt::LeftToRight);
        StackedWidget_Main->setAutoFillBackground(false);
        StackedWidget_Main->setFrameShape(QFrame::Panel);
        StackedWidget_Main->setMidLineWidth(0);
        Page_SettingCalculate = new QWidget();
        Page_SettingCalculate->setObjectName(QString::fromUtf8("Page_SettingCalculate"));
        gridLayout_3 = new QGridLayout(Page_SettingCalculate);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        Frame_SettingCalculate = new QFrame(Page_SettingCalculate);
        Frame_SettingCalculate->setObjectName(QString::fromUtf8("Frame_SettingCalculate"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Frame_SettingCalculate->sizePolicy().hasHeightForWidth());
        Frame_SettingCalculate->setSizePolicy(sizePolicy3);
        Frame_SettingCalculate->setMinimumSize(QSize(100, 0));
        Frame_SettingCalculate->setMaximumSize(QSize(100, 16777215));
        Frame_SettingCalculate->setFrameShape(QFrame::Panel);
        verticalLayout_4 = new QVBoxLayout(Frame_SettingCalculate);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(6, -1, -1, -1);
        PushButton_Data = new QPushButton(Frame_SettingCalculate);
        PushButton_Data->setObjectName(QString::fromUtf8("PushButton_Data"));
        PushButton_Data->setMinimumSize(QSize(86, 74));
        PushButton_Data->setMaximumSize(QSize(86, 74));
        PushButton_Data->setFont(font1);
        PushButton_Data->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 144, 156)"));

        verticalLayout_4->addWidget(PushButton_Data);

        PushButton_Tables = new QPushButton(Frame_SettingCalculate);
        PushButton_Tables->setObjectName(QString::fromUtf8("PushButton_Tables"));
        PushButton_Tables->setMinimumSize(QSize(86, 74));
        PushButton_Tables->setMaximumSize(QSize(86, 74));
        PushButton_Tables->setFont(font1);
        PushButton_Tables->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 144, 156)"));

        verticalLayout_4->addWidget(PushButton_Tables);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);


        horizontalLayout_4->addWidget(Frame_SettingCalculate);

        horizontalFrame_2 = new QFrame(Page_SettingCalculate);
        horizontalFrame_2->setObjectName(QString::fromUtf8("horizontalFrame_2"));
        horizontalFrame_2->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_5 = new QHBoxLayout(horizontalFrame_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));

        horizontalLayout_4->addWidget(horizontalFrame_2);


        gridLayout_3->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        StackedWidget_Main->addWidget(Page_SettingCalculate);
        Page_UsingData = new QWidget();
        Page_UsingData->setObjectName(QString::fromUtf8("Page_UsingData"));
        gridLayout_2 = new QGridLayout(Page_UsingData);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Frame_UsingData = new QFrame(Page_UsingData);
        Frame_UsingData->setObjectName(QString::fromUtf8("Frame_UsingData"));
        sizePolicy2.setHeightForWidth(Frame_UsingData->sizePolicy().hasHeightForWidth());
        Frame_UsingData->setSizePolicy(sizePolicy2);
        Frame_UsingData->setMinimumSize(QSize(110, 0));
        Frame_UsingData->setMaximumSize(QSize(110, 16777215));
        Frame_UsingData->setFrameShape(QFrame::Panel);
        verticalLayout_3 = new QVBoxLayout(Frame_UsingData);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(6, -1, -1, -1);
        PushButton_Rectifiers = new QToolButton(Frame_UsingData);
        PushButton_Rectifiers->setObjectName(QString::fromUtf8("PushButton_Rectifiers"));
        sizePolicy.setHeightForWidth(PushButton_Rectifiers->sizePolicy().hasHeightForWidth());
        PushButton_Rectifiers->setSizePolicy(sizePolicy);
        PushButton_Rectifiers->setMinimumSize(QSize(95, 74));
        PushButton_Rectifiers->setMaximumSize(QSize(95, 74));
        QFont font2;
        font2.setPointSize(10);
        PushButton_Rectifiers->setFont(font2);
        PushButton_Rectifiers->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 144, 156)"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/img/ButtonRectifiers.png"), QSize(), QIcon::Normal, QIcon::Off);
        PushButton_Rectifiers->setIcon(icon2);
        PushButton_Rectifiers->setIconSize(QSize(50, 50));
        PushButton_Rectifiers->setAutoRepeat(false);
        PushButton_Rectifiers->setAutoExclusive(false);
        PushButton_Rectifiers->setPopupMode(QToolButton::DelayedPopup);
        PushButton_Rectifiers->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        PushButton_Rectifiers->setArrowType(Qt::NoArrow);

        verticalLayout_3->addWidget(PushButton_Rectifiers);

        PushButton_Filters = new QToolButton(Frame_UsingData);
        PushButton_Filters->setObjectName(QString::fromUtf8("PushButton_Filters"));
        sizePolicy.setHeightForWidth(PushButton_Filters->sizePolicy().hasHeightForWidth());
        PushButton_Filters->setSizePolicy(sizePolicy);
        PushButton_Filters->setMinimumSize(QSize(95, 74));
        PushButton_Filters->setMaximumSize(QSize(95, 74));
        PushButton_Filters->setFont(font1);
        PushButton_Filters->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 144, 156)"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/img/ButtonFilters.png"), QSize(), QIcon::Normal, QIcon::Off);
        PushButton_Filters->setIcon(icon3);
        PushButton_Filters->setIconSize(QSize(50, 50));
        PushButton_Filters->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_3->addWidget(PushButton_Filters);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_3->addWidget(Frame_UsingData);

        horizontalFrame_page1 = new QFrame(Page_UsingData);
        horizontalFrame_page1->setObjectName(QString::fromUtf8("horizontalFrame_page1"));
        horizontalFrame_page1->setStyleSheet(QString::fromUtf8(""));
        horizontalFrame_page1->setFrameShape(QFrame::NoFrame);
        horizontalLayout_2 = new QHBoxLayout(horizontalFrame_page1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

        horizontalLayout_3->addWidget(horizontalFrame_page1);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        StackedWidget_Main->addWidget(Page_UsingData);

        verticalLayout_2->addWidget(StackedWidget_Main);

        verticalSpacer_2 = new QSpacerItem(683, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        MainPowerSources->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainPowerSources);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1400, 26));
        MainPowerSources->setMenuBar(menubar);
        statusbar = new QStatusBar(MainPowerSources);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainPowerSources->setStatusBar(statusbar);

        retranslateUi(MainPowerSources);

        StackedWidget_Main->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainPowerSources);
    } // setupUi

    void retranslateUi(QMainWindow *MainPowerSources)
    {
        MainPowerSources->setWindowTitle(QCoreApplication::translate("MainPowerSources", "Calculation of power supply devices", nullptr));
        label->setText(QString());
        label1_NameProject->setText(QCoreApplication::translate("MainPowerSources", "Power", nullptr));
        label2_NameProject->setText(QCoreApplication::translate("MainPowerSources", "Sources", nullptr));
        PushButton_Calculate->setText(QCoreApplication::translate("MainPowerSources", "\320\222\321\213\321\207\320\270\321\201\320\273\320\265\320\275\320\270\320\265", nullptr));
        PushButton_Reference->setText(QCoreApplication::translate("MainPowerSources", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        PushButton_Data->setText(QCoreApplication::translate("MainPowerSources", "\320\242\320\265\320\276\321\200\320\270\321\217", nullptr));
        PushButton_Tables->setText(QCoreApplication::translate("MainPowerSources", "\320\242\320\260\320\261\320\273\320\270\321\206\321\213", nullptr));
        PushButton_Rectifiers->setText(QCoreApplication::translate("MainPowerSources", "\320\222\321\213\320\277\321\200\321\217\320\274\320\270\321\202\320\265\320\273\320\270", nullptr));
        PushButton_Filters->setText(QCoreApplication::translate("MainPowerSources", "\320\244\320\270\320\273\321\214\321\202\321\200\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainPowerSources: public Ui_MainPowerSources {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPOWERSOURCES_H
