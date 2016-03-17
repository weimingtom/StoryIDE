/****************************************************************************
** Meta object code from reading C++ file 'texteditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/texteditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'texteditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TextEditor_t {
    QByteArrayData data[7];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TextEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TextEditor_t qt_meta_stringdata_TextEditor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TextEditor"
QT_MOC_LITERAL(1, 11, 26), // "updateAreaNumeroLineaWidth"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 13), // "newBlockCount"
QT_MOC_LITERAL(4, 53, 20), // "highlightCurrentLine"
QT_MOC_LITERAL(5, 74, 21), // "updateAreaNumeroLinea"
QT_MOC_LITERAL(6, 96, 15) // "actualizarLinks"

    },
    "TextEditor\0updateAreaNumeroLineaWidth\0"
    "\0newBlockCount\0highlightCurrentLine\0"
    "updateAreaNumeroLinea\0actualizarLinks"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    0,   37,    2, 0x08 /* Private */,
       5,    2,   38,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRect, QMetaType::Int,    2,    2,
    QMetaType::Void,

       0        // eod
};

void TextEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TextEditor *_t = static_cast<TextEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateAreaNumeroLineaWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->highlightCurrentLine(); break;
        case 2: _t->updateAreaNumeroLinea((*reinterpret_cast< const QRect(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->actualizarLinks(); break;
        default: ;
        }
    }
}

const QMetaObject TextEditor::staticMetaObject = {
    { &QPlainTextEdit::staticMetaObject, qt_meta_stringdata_TextEditor.data,
      qt_meta_data_TextEditor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TextEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TextEditor.stringdata0))
        return static_cast<void*>(const_cast< TextEditor*>(this));
    return QPlainTextEdit::qt_metacast(_clname);
}

int TextEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
struct qt_meta_stringdata_AreaNumeroLinea_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AreaNumeroLinea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AreaNumeroLinea_t qt_meta_stringdata_AreaNumeroLinea = {
    {
QT_MOC_LITERAL(0, 0, 15) // "AreaNumeroLinea"

    },
    "AreaNumeroLinea"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AreaNumeroLinea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void AreaNumeroLinea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject AreaNumeroLinea::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AreaNumeroLinea.data,
      qt_meta_data_AreaNumeroLinea,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AreaNumeroLinea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AreaNumeroLinea::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AreaNumeroLinea.stringdata0))
        return static_cast<void*>(const_cast< AreaNumeroLinea*>(this));
    return QWidget::qt_metacast(_clname);
}

int AreaNumeroLinea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
