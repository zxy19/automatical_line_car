/****************************************************************************
** Meta object code from reading C++ file 'usermanage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/usermanage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usermanage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserManage_t {
    QByteArrayData data[11];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserManage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserManage_t qt_meta_stringdata_UserManage = {
    {
QT_MOC_LITERAL(0, 0, 10), // "UserManage"
QT_MOC_LITERAL(1, 11, 21), // "on_btn_commit_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 23), // "on_btn_rollback_clicked"
QT_MOC_LITERAL(4, 58, 21), // "on_btn_addrow_clicked"
QT_MOC_LITERAL(5, 80, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(6, 104, 13), // "onDataChanged"
QT_MOC_LITERAL(7, 118, 5), // "index"
QT_MOC_LITERAL(8, 124, 11), // "bottomRight"
QT_MOC_LITERAL(9, 136, 12), // "QVector<int>"
QT_MOC_LITERAL(10, 149, 5) // "roles"

    },
    "UserManage\0on_btn_commit_clicked\0\0"
    "on_btn_rollback_clicked\0on_btn_addrow_clicked\0"
    "on_pushButton_2_clicked\0onDataChanged\0"
    "index\0bottomRight\0QVector<int>\0roles"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserManage[] = {

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
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    3,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex, 0x80000000 | 9,    7,    8,   10,

       0        // eod
};

void UserManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserManage *_t = static_cast<UserManage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_commit_clicked(); break;
        case 1: _t->on_btn_rollback_clicked(); break;
        case 2: _t->on_btn_addrow_clicked(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->onDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2])),(*reinterpret_cast< const QVector<int>(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    }
}

const QMetaObject UserManage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UserManage.data,
      qt_meta_data_UserManage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UserManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserManage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UserManage.stringdata0))
        return static_cast<void*>(const_cast< UserManage*>(this));
    return QWidget::qt_metacast(_clname);
}

int UserManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
