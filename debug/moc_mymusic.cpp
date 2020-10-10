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
    QByteArrayData data[9];
    char stringdata0[93];
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
QT_MOC_LITERAL(4, 27, 8), // "up_quiet"
QT_MOC_LITERAL(5, 36, 10), // "left_quiet"
QT_MOC_LITERAL(6, 47, 10), // "down_quiet"
QT_MOC_LITERAL(7, 58, 11), // "right_quiet"
QT_MOC_LITERAL(8, 70, 22) // "on_stop_button_clicked"

    },
    "MyMusic\0gameover\0\0deleteit\0up_quiet\0"
    "left_quiet\0down_quiet\0right_quiet\0"
    "on_stop_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyMusic[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   52,    2, 0x0a /* Public */,
       4,    0,   53,    2, 0x0a /* Public */,
       5,    0,   54,    2, 0x0a /* Public */,
       6,    0,   55,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x0a /* Public */,
       8,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
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
        case 2: _t->up_quiet(); break;
        case 3: _t->left_quiet(); break;
        case 4: _t->down_quiet(); break;
        case 5: _t->right_quiet(); break;
        case 6: _t->on_stop_button_clicked(); break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
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
