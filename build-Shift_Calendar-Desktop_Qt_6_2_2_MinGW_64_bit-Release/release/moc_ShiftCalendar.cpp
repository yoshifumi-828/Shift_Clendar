/****************************************************************************
** Meta object code from reading C++ file 'ShiftCalendar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Shift_Calendar/ShiftCalendar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ShiftCalendar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Shift_Calendar_t {
    const uint offsetsAndSize[28];
    char stringdata0[277];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Shift_Calendar_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Shift_Calendar_t qt_meta_stringdata_Shift_Calendar = {
    {
QT_MOC_LITERAL(0, 14), // "Shift_Calendar"
QT_MOC_LITERAL(15, 24), // "on_year_Box_valueChanged"
QT_MOC_LITERAL(40, 0), // ""
QT_MOC_LITERAL(41, 4), // "arg1"
QT_MOC_LITERAL(46, 32), // "on_month_Box_currentIndexChanged"
QT_MOC_LITERAL(79, 5), // "index"
QT_MOC_LITERAL(85, 40), // "on_display_month_Box_currentI..."
QT_MOC_LITERAL(126, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(148, 25), // "on_propertyButton_clicked"
QT_MOC_LITERAL(174, 28), // "on_auto_input_Button_clicked"
QT_MOC_LITERAL(203, 24), // "on_update_button_clicked"
QT_MOC_LITERAL(228, 22), // "on_save_Button_clicked"
QT_MOC_LITERAL(251, 11), // "delete_line"
QT_MOC_LITERAL(263, 13) // "return_dialog"

    },
    "Shift_Calendar\0on_year_Box_valueChanged\0"
    "\0arg1\0on_month_Box_currentIndexChanged\0"
    "index\0on_display_month_Box_currentIndexChanged\0"
    "on_pushButton_clicked\0on_propertyButton_clicked\0"
    "on_auto_input_Button_clicked\0"
    "on_update_button_clicked\0"
    "on_save_Button_clicked\0delete_line\0"
    "return_dialog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Shift_Calendar[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x08,    1 /* Private */,
       4,    1,   77,    2, 0x08,    3 /* Private */,
       6,    1,   80,    2, 0x08,    5 /* Private */,
       7,    0,   83,    2, 0x08,    7 /* Private */,
       8,    0,   84,    2, 0x08,    8 /* Private */,
       9,    0,   85,    2, 0x08,    9 /* Private */,
      10,    0,   86,    2, 0x08,   10 /* Private */,
      11,    0,   87,    2, 0x08,   11 /* Private */,
      12,    0,   88,    2, 0x08,   12 /* Private */,
      13,    0,   89,    2, 0x08,   13 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Shift_Calendar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Shift_Calendar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_year_Box_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_month_Box_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_display_month_Box_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_propertyButton_clicked(); break;
        case 5: _t->on_auto_input_Button_clicked(); break;
        case 6: _t->on_update_button_clicked(); break;
        case 7: _t->on_save_Button_clicked(); break;
        case 8: _t->delete_line(); break;
        case 9: _t->return_dialog(); break;
        default: ;
        }
    }
}

const QMetaObject Shift_Calendar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Shift_Calendar.offsetsAndSize,
    qt_meta_data_Shift_Calendar,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Shift_Calendar_t
, QtPrivate::TypeAndForceComplete<Shift_Calendar, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Shift_Calendar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Shift_Calendar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Shift_Calendar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Shift_Calendar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
