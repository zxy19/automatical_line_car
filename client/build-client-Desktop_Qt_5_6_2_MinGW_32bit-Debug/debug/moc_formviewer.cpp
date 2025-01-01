/****************************************************************************
** Meta object code from reading C++ file 'formviewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/formviewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FormViewer_t {
    QByteArrayData data[11];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormViewer_t qt_meta_stringdata_FormViewer = {
    {
QT_MOC_LITERAL(0, 0, 10), // "FormViewer"
QT_MOC_LITERAL(1, 11, 16), // "sig_set_progress"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 1), // "p"
QT_MOC_LITERAL(4, 31, 14), // "sig_set_finish"
QT_MOC_LITERAL(5, 46, 19), // "sig_error_fail_open"
QT_MOC_LITERAL(6, 66, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 88, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(8, 112, 12), // "set_progress"
QT_MOC_LITERAL(9, 125, 10), // "set_finish"
QT_MOC_LITERAL(10, 136, 15) // "error_fail_open"

    },
    "FormViewer\0sig_set_progress\0\0p\0"
    "sig_set_finish\0sig_error_fail_open\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "set_progress\0set_finish\0error_fail_open"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    0,   57,    2, 0x06 /* Public */,
       5,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    1,   61,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FormViewer *_t = static_cast<FormViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_set_progress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sig_set_finish(); break;
        case 2: _t->sig_error_fail_open(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        case 5: _t->set_progress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->set_finish(); break;
        case 7: _t->error_fail_open(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FormViewer::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FormViewer::sig_set_progress)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FormViewer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FormViewer::sig_set_finish)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FormViewer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FormViewer::sig_error_fail_open)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject FormViewer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FormViewer.data,
      qt_meta_data_FormViewer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FormViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FormViewer.stringdata0))
        return static_cast<void*>(const_cast< FormViewer*>(this));
    return QWidget::qt_metacast(_clname);
}

int FormViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void FormViewer::sig_set_progress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FormViewer::sig_set_finish()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void FormViewer::sig_error_fail_open()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
