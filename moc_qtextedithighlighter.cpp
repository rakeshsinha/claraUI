/****************************************************************************
** Meta object code from reading C++ file 'qtextedithighlighter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qtextedithighlighter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtextedithighlighter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QTextEditHighlighter_t {
    QByteArrayData data[8];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTextEditHighlighter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTextEditHighlighter_t qt_meta_stringdata_QTextEditHighlighter = {
    {
QT_MOC_LITERAL(0, 0, 20), // "QTextEditHighlighter"
QT_MOC_LITERAL(1, 21, 11), // "resizeEvent"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 13), // "QResizeEvent*"
QT_MOC_LITERAL(4, 48, 1), // "e"
QT_MOC_LITERAL(5, 50, 25), // "updateLineNumberAreaWidth"
QT_MOC_LITERAL(6, 76, 13), // "newBlockCount"
QT_MOC_LITERAL(7, 90, 20) // "updateLineNumberArea"

    },
    "QTextEditHighlighter\0resizeEvent\0\0"
    "QResizeEvent*\0e\0updateLineNumberAreaWidth\0"
    "newBlockCount\0updateLineNumberArea"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTextEditHighlighter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,
       7,    1,   48,    2, 0x08 /* Private */,
       7,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QRectF,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void QTextEditHighlighter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QTextEditHighlighter *_t = static_cast<QTextEditHighlighter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 1: _t->updateLineNumberAreaWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->updateLineNumberArea((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 3: _t->updateLineNumberArea((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->updateLineNumberArea(); break;
        default: ;
        }
    }
}

const QMetaObject QTextEditHighlighter::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_QTextEditHighlighter.data,
      qt_meta_data_QTextEditHighlighter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QTextEditHighlighter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTextEditHighlighter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QTextEditHighlighter.stringdata0))
        return static_cast<void*>(const_cast< QTextEditHighlighter*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int QTextEditHighlighter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
