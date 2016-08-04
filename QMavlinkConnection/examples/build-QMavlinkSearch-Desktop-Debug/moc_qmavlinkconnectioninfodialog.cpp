/****************************************************************************
** Meta object code from reading C++ file 'qmavlinkconnectioninfodialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/qmavlinkconnectioninfodialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmavlinkconnectioninfodialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QMavlinkConnectionInfoDialog_t {
    QByteArrayData data[6];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMavlinkConnectionInfoDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMavlinkConnectionInfoDialog_t qt_meta_stringdata_QMavlinkConnectionInfoDialog = {
    {
QT_MOC_LITERAL(0, 0, 28), // "QMavlinkConnectionInfoDialog"
QT_MOC_LITERAL(1, 29, 18), // "mavlinkMsgReceived"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 17), // "mavlink_message_t"
QT_MOC_LITERAL(4, 67, 3), // "msg"
QT_MOC_LITERAL(5, 71, 5) // "reset"

    },
    "QMavlinkConnectionInfoDialog\0"
    "mavlinkMsgReceived\0\0mavlink_message_t\0"
    "msg\0reset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMavlinkConnectionInfoDialog[] = {

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
       1,    1,   24,    2, 0x0a /* Public */,
       5,    0,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void QMavlinkConnectionInfoDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QMavlinkConnectionInfoDialog *_t = static_cast<QMavlinkConnectionInfoDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mavlinkMsgReceived((*reinterpret_cast< mavlink_message_t(*)>(_a[1]))); break;
        case 1: _t->reset(); break;
        default: ;
        }
    }
}

const QMetaObject QMavlinkConnectionInfoDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QMavlinkConnectionInfoDialog.data,
      qt_meta_data_QMavlinkConnectionInfoDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QMavlinkConnectionInfoDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMavlinkConnectionInfoDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QMavlinkConnectionInfoDialog.stringdata0))
        return static_cast<void*>(const_cast< QMavlinkConnectionInfoDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int QMavlinkConnectionInfoDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
