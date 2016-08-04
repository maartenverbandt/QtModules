/****************************************************************************
** Meta object code from reading C++ file 'qconnectioncoordinator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/qconnectioncoordinator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qconnectioncoordinator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QConnectionCoordinator_t {
    QByteArrayData data[16];
    char stringdata0[227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QConnectionCoordinator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QConnectionCoordinator_t qt_meta_stringdata_QConnectionCoordinator = {
    {
QT_MOC_LITERAL(0, 0, 22), // "QConnectionCoordinator"
QT_MOC_LITERAL(1, 23, 22), // "mavlinkConnectionFound"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 19), // "QMavlinkConnection*"
QT_MOC_LITERAL(4, 67, 18), // "mavlink_connection"
QT_MOC_LITERAL(5, 86, 5), // "query"
QT_MOC_LITERAL(6, 92, 16), // "mavlinkConnected"
QT_MOC_LITERAL(7, 109, 1), // "c"
QT_MOC_LITERAL(8, 111, 20), // "mavlinkConnectionUSB"
QT_MOC_LITERAL(9, 132, 15), // "QSerialPortInfo"
QT_MOC_LITERAL(10, 148, 4), // "info"
QT_MOC_LITERAL(11, 153, 19), // "mavlinkConnectionBT"
QT_MOC_LITERAL(12, 173, 20), // "QBluetoothDeviceInfo"
QT_MOC_LITERAL(13, 194, 20), // "mavlinkConnectionUDP"
QT_MOC_LITERAL(14, 215, 6), // "server"
QT_MOC_LITERAL(15, 222, 4) // "port"

    },
    "QConnectionCoordinator\0mavlinkConnectionFound\0"
    "\0QMavlinkConnection*\0mavlink_connection\0"
    "query\0mavlinkConnected\0c\0mavlinkConnectionUSB\0"
    "QSerialPortInfo\0info\0mavlinkConnectionBT\0"
    "QBluetoothDeviceInfo\0mavlinkConnectionUDP\0"
    "server\0port"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QConnectionCoordinator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x0a /* Public */,
       6,    1,   48,    2, 0x0a /* Public */,
       8,    1,   51,    2, 0x0a /* Public */,
      11,    1,   54,    2, 0x0a /* Public */,
      13,    2,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   14,   15,

       0        // eod
};

void QConnectionCoordinator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QConnectionCoordinator *_t = static_cast<QConnectionCoordinator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mavlinkConnectionFound((*reinterpret_cast< QMavlinkConnection*(*)>(_a[1]))); break;
        case 1: _t->query(); break;
        case 2: _t->mavlinkConnected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->mavlinkConnectionUSB((*reinterpret_cast< QSerialPortInfo(*)>(_a[1]))); break;
        case 4: _t->mavlinkConnectionBT((*reinterpret_cast< QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 5: _t->mavlinkConnectionUDP((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMavlinkConnection* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QConnectionCoordinator::*_t)(QMavlinkConnection * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QConnectionCoordinator::mavlinkConnectionFound)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QConnectionCoordinator::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QConnectionCoordinator.data,
      qt_meta_data_QConnectionCoordinator,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QConnectionCoordinator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QConnectionCoordinator::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QConnectionCoordinator.stringdata0))
        return static_cast<void*>(const_cast< QConnectionCoordinator*>(this));
    return QObject::qt_metacast(_clname);
}

int QConnectionCoordinator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QConnectionCoordinator::mavlinkConnectionFound(QMavlinkConnection * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
