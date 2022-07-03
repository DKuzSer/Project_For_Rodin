QT       += core gui
QT       += core gui charts
QT       += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Filters/FiltersCHEBISHEV.cpp \
    Filters\Filters.cpp \
    Filters\FiltersAbstract.cpp \
    Filters\FiltersButterworth.cpp \
    MainpowerSourcesAbstract.cpp \
    Matching\Matching.cpp \
    Matching\MatchingAbstract.cpp \
    Matching\MatchingOneCircuit.cpp \
    Matching\MatchingTwoCircuit.cpp \
    MyCharts.cpp \
    MyChartsView.cpp \
    Rectifiers\Rectifiers.cpp \
    Rectifiers\RectifiersAbstract.cpp \
    Rectifiers\RectifiersOnePeriodCircuit.cpp \
    Rectifiers\RectifiersTwoPeriodCircuit.cpp \
    diod_base.cpp \
    main.cpp \
    mainpowersources.cpp \
    stylehelper.cpp \
    svgview.cpp

HEADERS += \
    Filters/FiltersCHEBISHEV.h \
    Filters\Filters.h \
    Filters\FiltersAbstract.h \
    Filters\FiltersButterworth.h \
    MainpowerSourcesAbstract.h \
    Matching\Matching.h \
    Matching\MatchingAbstract.h \
    Matching\MatchingOneCircuit.h \
    Matching\MatchingTwoCircuit.h \
    MyCharts.h \
    MyChartsView.h \
    Rectifiers\Rectifiers.h \
    Rectifiers\RectifiersAbstract.h \
    Rectifiers\RectifiersOnePeriodCircuit.h \
    Rectifiers\RectifiersTwoPeriodCircuit.h \
    constans.h \
    diod_base.h \
    mainpowersources.h \
    stylehelper.h \
    svgview.h

FORMS += \
    Filters\Filters.ui \
    Matching\Matching.ui \
    Rectifiers\Rectifiers.ui \
    diod_base.ui \
    mainpowersources.ui

win32:RC_FILE = file.rc

TRANSLATIONS += \
    PowerSources_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES +=
