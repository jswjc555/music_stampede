/****************************************************************************
** Meta object code from reading C++ file 'mymusic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mymusic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mymusic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyMusic_t {
    QByteArrayData data[12];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyMusic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyMusic_t qt_meta_stringdata_MyMusic = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MyMusic"
QT_MOC_LITERAL(1, 8, 8), // "gameover"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 8), // "deleteit"
QT_MOC_LITERAL(4, 27, 14), // "deletegif_left"
QT_MOC_LITERAL(5, 42, 12), // "deletegif_up"
QT_MOC_LITERAL(6, 55, 15), // "deletegif_right"
QT_MOC_LITERAL(7, 71, 14), // "deletegif_down"
QT_MOC_LITERAL(8, 86, 8), // "up_quiet"
QT_MOC_LITERAL(9, 95, 10), // "left_quiet"
QT_MOC_LITERAL(10, 106, 10), // "down_quiet"
QT_MOC_LITERAL(11, 117, 11) // "right_quiet"

    },
    "MyMusic\0gameover\0\0deleteit\0deletegif_left\0"
    "deletegif_up\0deletegif_right\0"
    "deletegif_down\0up_quiet\0left_quiet\0"
    "down_quiet\0right_quiet"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyMusic[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   67,    2, 0x0a /* Public */,
       4,    0,   68,    2, 0x0a /* Public */,
       5,    0,   69,    2, 0x0a /* Public */,
       6,    0,   70,    2, 0x0a /* Public */,
       7,    0,   71,    2, 0x0a /* Public */,
       8,    0,   72,    2, 0x0a /* Public */,
       9,    0,   73,    2, 0x0a /* Public */,
      10,    0,   74,    2, 0x0a /* Public */,
      11,    0,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyMusic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyMusic *_t = static_cast<MyMusic *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gameover((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->deleteit(); break;
        case 2: _t->deletegif_left(); break;
        case 3: _t->deletegif_up(); break;
        case 4: _t->deletegif_right(); break;
        case 5: _t->deletegif_down(); break;
        case 6: _t->up_quiet(); break;
        case 7: _t->left_quiet(); break;
        case 8: _t->down_quiet(); break;
        case 9: _t->right_quiet(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyMusic::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyMusic::gameover)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MyMusic::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyMusic.data,
      qt_meta_data_MyMusic,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyMusic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyMusic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyMusic.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MyMusic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MyMusic::gameover(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
