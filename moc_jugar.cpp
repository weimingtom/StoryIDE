/****************************************************************************
** Meta object code from reading C++ file 'jugar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/jugar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jugar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Jugar_t {
    QByteArrayData data[4];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Jugar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Jugar_t qt_meta_stringdata_Jugar = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Jugar"
QT_MOC_LITERAL(1, 6, 8), // "compilar"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 11) // "onIrAEscena"

    },
    "Jugar\0compilar\0\0onIrAEscena"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Jugar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    0,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Jugar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Jugar *_t = static_cast<Jugar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->compilar(); break;
        case 1: _t->onIrAEscena(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Jugar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Jugar.data,
      qt_meta_data_Jugar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Jugar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Jugar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Jugar.stringdata0))
        return static_cast<void*>(const_cast< Jugar*>(this));
    return QWidget::qt_metacast(_clname);
}

int Jugar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_BotonJuego_t {
    QByteArrayData data[3];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BotonJuego_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BotonJuego_t qt_meta_stringdata_BotonJuego = {
    {
QT_MOC_LITERAL(0, 0, 10), // "BotonJuego"
QT_MOC_LITERAL(1, 11, 7), // "clicado"
QT_MOC_LITERAL(2, 19, 0) // ""

    },
    "BotonJuego\0clicado\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BotonJuego[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void BotonJuego::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BotonJuego *_t = static_cast<BotonJuego *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicado((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject BotonJuego::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_BotonJuego.data,
      qt_meta_data_BotonJuego,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BotonJuego::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BotonJuego::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BotonJuego.stringdata0))
        return static_cast<void*>(const_cast< BotonJuego*>(this));
    return QPushButton::qt_metacast(_clname);
}

int BotonJuego::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
