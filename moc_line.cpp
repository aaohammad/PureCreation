/****************************************************************************
** Meta object code from reading C++ file 'line.h'
**
** Created: Thu Jun 2 19:00:19 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Model-Headers/line.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'line.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Line[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x0a,
      25,    5,    5,    5, 0x0a,
      41,    5,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Line[] = {
    "Line\0\0changeAttributes()\0changeColorAE()\0"
    "vertexComboBoxChanged()\0"
};

const QMetaObject Line::staticMetaObject = {
    { &Model::staticMetaObject, qt_meta_stringdata_Line,
      qt_meta_data_Line, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Line::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Line::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Line::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Line))
        return static_cast<void*>(const_cast< Line*>(this));
    return Model::qt_metacast(_clname);
}

int Line::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Model::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: changeAttributes(); break;
        case 1: changeColorAE(); break;
        case 2: vertexComboBoxChanged(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE