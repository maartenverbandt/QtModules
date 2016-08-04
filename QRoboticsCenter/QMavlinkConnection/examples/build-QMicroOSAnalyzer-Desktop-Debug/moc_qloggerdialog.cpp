/****************************************************************************
** Meta object code from reading C++ file 'qloggerdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../QRoboticsCenter/qloggerdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qloggerdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QLoggerDialog_t {
    QByteArrayData data[7];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QLoggerDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QLoggerDialog_t qt_meta_stringdata_QLoggerDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QLoggerDialog"
QT_MOC_LITERAL(1, 14, 18), // "mavlinkMsgReceived"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 17), // "mavlink_message_t"
QT_MOC_LITERAL(4, 52, 3), // "msg"
QT_MOC_LITERAL(5, 56, 23), // "on_recordButton_clicked"
QT_MOC_LITERAL(6, 80, 7) // "checked"

    },
    "QLoggerDialog\0mavlinkMsgReceived\0\0"
    "mavlink_message_t\0msg\0on_recordButton_clicked\0"
    "checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QLoggerDialog[] = {

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
       5,    1,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    6,

       0        // eod
};

void QLoggerDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QLoggerDialog *_t = static_cast<QLoggerDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mavlinkMsgReceived((*reinterpret_cast< mavlink_message_t(*)>(_a[1]))); break;
        case 1: _t->on_recordButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject QLoggerDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QLoggerDialog.data,
      qt_meta_data_QLoggerDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QLoggerDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QLoggerDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QLoggerDialog.stringdata0))
        return static_cast<void*>(const_cast< QLoggerDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int QLoggerDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
