#include "stylehelper.h"

QString StyleHelper::getMainWidgetStyle()
{
    return "MainWindow{"
           "background-color: rgb(0, 0, 0 );"
           "}";
}

QString StyleHelper::getButtonsStyle()
{
    return "QPushButton{"
           "    color:rgb(255, 255, 255);"
           "    border:1px solid rgb(255, 255, 255);"
           "    border-radius:5px;"
           "}"
           "QPushButton::hover{"
           "background-color:rgb(80, 255, 163);"
           "color:rgb(0, 0, 0);"
           "}"
           "QPushButton::pressed{"
           "background-color:rgb(42, 121, 76);"
           "color:rgb(0, 0, 0);"
           "}";
}

QString StyleHelper::getLabelStyle()
{
    return "QLabel{"
           "    border:none;"
           "    color:rgb(255, 255, 255);"
           "    background-color: none;"
           "}"
;
}

QString StyleHelper::getFrameStyle()
{
    return "QFrame{"
           "border:0.5px solid rgb(255, 255, 255);"
           "background-color: rgba(36, 41, 67,100);"
           "}"
;
}

QString StyleHelper::getToolButtonsStyle()
{
    return "QToolButton{"
           "    color:rgb(255, 255, 255);"
           "    border:1px solid rgb(255, 255, 255);"
           "    border-radius:5px;"
           "}"
           "QToolButton::hover{"
           "background-color:rgb(80, 255, 163);"
           "color:rgb(0, 0, 0);"
           "}"
           "QToolButton::pressed{"
           "background-color:rgb(42, 121, 76);"
           "color:rgb(0, 0, 0);"
           "}";
}

QString StyleHelper::getTabWidgetStyle()
{
    return "QTabWidget::pane{"
           "    border-radius:10px;"
           "    background:rgb(24,39,46);"
           "    top:-50px;"
           "}"
           "QTabBar::tab:selected{"
           "    border-bottom:2px solid rgb(255, 234, 89);"
           "    background:rgb(255, 234, 89);"
           "}"
           "QTabBar::tab:top:first{"
           "}"
           "QTabBar::tab{"
           "    border-radius:30px;"
           "    font: italic 13pt Calibri;"
           "    background:rgb(24,39,46);"
           "    color:rgb(255, 234, 89);"
           "    left:10px;"
           "    width:15ex;"
           "    height:15ex;"
           "}"
           "QTabBar::tab:selected{"
           "    margin-top:+50px;"
           "}"
           "QTabWidget::tab-bar{"
           "    width:60ex;"
           "    height:20ex;"
           "}"
           "QTabBar::tab:hover{"
           "    background:rgb(255, 234, 89);"
           "    color:rgb(24,39,46);"
           "}"
            ;
}

QString StyleHelper::getComboBoxStyle()
{
    return "QComboBox{"
           "    color:rgb(255,255,255);"
           "    min-width:20ex;"
           "    min-height:8ex;"
           "    border:none;"
           "    border-top-left-radius:5px;"
           "    border-bottom:2px solid rgb(255, 234, 89);"
           "    background:rgb(24,39,46);"
           "    font: italic 13pt Calibri;"
           "}"
           "QComboBox::down-arrow{"
           "    image:url(:/img/img/Без_названия-removebg-preview.png);"
           "    color:rgb(255, 234, 89);"
           "    background:none;"
           "    border:none;"
           "    min-width: 20ex;"
           "    min-height: 8ex;"
           "}"
           "QComboBox::hover{"
           "    background: rgb(54,87,103);"
           "}"
           "QComboBox::drop-down{"
           "    subcontrol-origin:padding;"
           "}"
            ;
}

QString StyleHelper::getMainButtonsStyle()
{
    return "QPushButton{"
           "    border:none;"
           "    border-radius:none;"
           "    border-top-left-radius:5px;"
           "    border-bottom-left-radius:5px;"
           "    background:rgb(73,88,95);"
           "    color:rgb(255,255,255);"
           "    font: italic 15pt Calibri;"
           "    border-right: 5px solid rgb(255, 234, 89);"
           "    width:20ex;"
           "    height:8ex;"
           "}"
           "QPushButton::hover{"
           "    background:rgb(87, 134, 158);"
           "}"
            ;
}

QString StyleHelper::getTestComboBoxStyle()
{
    return "QComboBox {"
           "border: 1px solid gray;"
           "border-radius: 3px;"
           "padding: 1px 18px 1px 3px;"
           "min-width: 6em;"
           "}"

    "QComboBox:editable {"
        "background:black;"
    "}"

    "QComboBox:!editable, QComboBox::drop-down:editable {"
    "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                 "stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,"
                                 "stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);"
    "}"

    "QComboBox:!editable:on, QComboBox::drop-down:editable:on {"
    "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                "stop: 0 #D3D3D3, stop: 0.4 #D8D8D8,"
                                "stop: 0.5 #DDDDDD, stop: 1.0 #E1E1E1);"
    "}"

    "QComboBox:on {"
    "padding-top: 3px;"
    "padding-left: 4px;"
    "}"

    "QComboBox::drop-down {"
    "subcontrol-origin: padding;"
    "subcontrol-position: top right;"
    "width: 15px;"
    "border-left-width: 1px;"
    "border-left-color: darkgray;"
    "border-left-style: solid;"
    "border-top-right-radius: 3px;"
    "border-bottom-right-radius: 3px;"
    "}"

    "QComboBox::down-arrow:on {"
    "top: 1px;"
    "left: 1px;"
    "}"
     ;
}

QString StyleHelper::getGroupBoxStyle()
{
    return "QGroupBox{"
           "color:rgb(255,255,255);"
           "}"
            ;
}



