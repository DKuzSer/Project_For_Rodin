/****************************************************************************
** Meta object code from reading C++ file 'Rectifiers.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../PowerSources/Rectifiers/Rectifiers.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Rectifiers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Rectifiers_t {
    const uint offsetsAndSize[28];
    char stringdata0[265];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Rectifiers_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Rectifiers_t qt_meta_stringdata_Rectifiers = {
    {
QT_MOC_LITERAL(0, 10), // "Rectifiers"
QT_MOC_LITERAL(11, 40), // "on_ComboBox_DevicesR_currentI..."
QT_MOC_LITERAL(52, 0), // ""
QT_MOC_LITERAL(53, 5), // "index"
QT_MOC_LITERAL(59, 39), // "on_ComboBox_OutPutF_currentIn..."
QT_MOC_LITERAL(99, 31), // "on_PushButton_Calculate_clicked"
QT_MOC_LITERAL(131, 16), // "CoordinateCursor"
QT_MOC_LITERAL(148, 5), // "point"
QT_MOC_LITERAL(154, 3), // "ind"
QT_MOC_LITERAL(158, 33), // "on_PushButton_Interactive_cli..."
QT_MOC_LITERAL(192, 7), // "checked"
QT_MOC_LITERAL(200, 27), // "on_PushButton_Hands_clicked"
QT_MOC_LITERAL(228, 31), // "on_DoubleSpinBoxOX_valueChanged"
QT_MOC_LITERAL(260, 4) // "arg1"

    },
    "Rectifiers\0on_ComboBox_DevicesR_currentIndexChanged\0"
    "\0index\0on_ComboBox_OutPutF_currentIndexChanged\0"
    "on_PushButton_Calculate_clicked\0"
    "CoordinateCursor\0point\0ind\0"
    "on_PushButton_Interactive_clicked\0"
    "checked\0on_PushButton_Hands_clicked\0"
    "on_DoubleSpinBoxOX_valueChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Rectifiers[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x08,    1 /* Private */,
       4,    1,   59,    2, 0x08,    3 /* Private */,
       5,    0,   62,    2, 0x08,    5 /* Private */,
       6,    2,   63,    2, 0x08,    6 /* Private */,
       9,    1,   68,    2, 0x08,    9 /* Private */,
      11,    1,   71,    2, 0x08,   11 /* Private */,
      12,    1,   74,    2, 0x08,   13 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Double,   13,

       0        // eod
};

void Rectifiers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Rectifiers *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_ComboBox_DevicesR_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_ComboBox_OutPutF_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_PushButton_Calculate_clicked(); break;
        case 3: _t->CoordinateCursor((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_PushButton_Interactive_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_PushButton_Hands_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_DoubleSpinBoxOX_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Rectifiers::staticMetaObject = { {
    QMetaObject::SuperData::link<MainpowerSourcesAbstract::staticMetaObject>(),
    qt_meta_stringdata_Rectifiers.offsetsAndSize,
    qt_meta_data_Rectifiers,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Rectifiers_t
, QtPrivate::TypeAndForceComplete<Rectifiers, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPointF, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>


>,
    nullptr
} };


const QMetaObject *Rectifiers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Rectifiers::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Rectifiers.stringdata0))
        return static_cast<void*>(this);
    return MainpowerSourcesAbstract::qt_metacast(_clname);
}

int Rectifiers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MainpowerSourcesAbstract::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
