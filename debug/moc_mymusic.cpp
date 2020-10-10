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
    QByteArrayData data[15];
    char stringdata0[170];
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
QT_MOC_LITERAL(3, 18, 7), // "back_to"
QT_MOC_LITERAL(4, 26, 8), // "deleteit"
QT_MOC_LITERAL(5, 35, 8), // "up_quiet"
QT_MOC_LITERAL(6, 44, 10), // "left_quiet"
QT_MOC_LITERAL(7, 55, 10), // "down_quiet"
QT_MOC_LITERAL(8, 66, 11), // "right_quiet"
QT_MOC_LITERAL(9, 78, 11), // "deletemovie"
QT_MOC_LITERAL(10, 90, 8), // "MyMovie*"
QT_MOC_LITERAL(11, 99, 7), // "restart"
QT_MOC_LITERAL(12, 107, 22), // "on_stop_button_clicked"
QT_MOC_LITERAL(13, 130, 20), // "on_end_close_clicked"
QT_MOC_LITERAL(14, 151, 18) // "on_to_main_clicked"

    },
    "MyMusic\0gameover\0\0back_to\0deleteit\0"
    "up_quiet\0left_quiet\0down_quiet\0"
    "right_quiet\0deletemovie\0MyMovie*\0"
    "restart\0on_stop_button_clicked\0"
    "on_end_close_clicked\0on_to_main_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyMusic[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       3,    0,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   78,    2, 0x0a /* Public */,
       5,    0,   79,    2, 0x0a /* Public */,
       6,    0,   80,    2, 0x0a /* Public */,
       7,    0,   81,    2, 0x0a /* Public */,
       8,    0,   82,    2, 0x0a /* Public */,
       9,    1,   83,    2, 0x0a /* Public */,
      11,    0,   86,    2, 0x0a /* Public */,
      12,    0,   87,    2, 0x08 /* Private */,
      13,    0,   88,    2, 0x08 /* Private */,
      14,    0,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,    2,
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
        case 1: _t->back_to(); break;
        case 2: _t->deleteit(); break;
        case 3: _t->up_quiet(); break;
        case 4: _t->left_quiet(); break;
        case 5: _t->down_quiet(); break;
        case 6: _t->right_quiet(); break;
        case 7: _t->deletemovie((*reinterpret_cast< MyMovie*(*)>(_a[1]))); break;
        case 8: _t->restart(); break;
        case 9: _t->on_stop_button_clicked(); break;
        case 10: _t->on_end_close_clicked(); break;
        case 11: _t->on_to_main_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyMovie* >(); break;
            }
            break;
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
        {
            typedef void (MyMusic::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyMusic::back_to)) {
                *result = 1;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MyMusic::gameover(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyMusic::back_to()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
