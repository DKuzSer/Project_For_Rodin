QT       += core gui
QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Filters.cpp \
    MyCharts.cpp \
    Rectifiers.cpp \
    RectifiersAbstract.cpp \
    RectifiersOnePeriodCircuit.cpp \
    RectifiersTwoPeriodCircuit.cpp \
    main.cpp \
    mainpowersources.cpp

HEADERS += \
    Filters.h \
    MyCharts.h \
    Rectifiers.h \
    RectifiersAbstract.h \
    RectifiersOnePeriodCircuit.h \
    RectifiersTwoPeriodCircuit.h \
    constans.h \
    mainpowersources.h

FORMS += \
    Filters.ui \
    Rectifiers.ui \
    mainpowersources.ui

TRANSLATIONS += \
    PowerSources_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
