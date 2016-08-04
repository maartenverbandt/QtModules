/****************************************************************************
** Meta object code from reading C++ file 'qmavlinkconnection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/qmavlinkconnection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmavlinkconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QMavlinkConnection_t {
    QByteArrayData data[16];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMavlinkConnection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMavlinkConnection_t qt_meta_stringdata_QMavlinkConnection = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QMavlinkConnection"
QT_MOC_LITERAL(1, 19, 16), // "mavlinkConnected"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 1), // "c"
QT_MOC_LITERAL(4, 39, 18), // "mavlinkMsgReceived"
QT_MOC_LITERAL(5, 58, 17), // "mavlink_message_t"
QT_MOC_LITERAL(6, 76, 3), // "msg"
QT_MOC_LITERAL(7, 80, 8), // "closeLog"
QT_MOC_LITERAL(8, 89, 14), // "mavlinkMsgSend"
QT_MOC_LITERAL(9, 104, 16), // "mavlinkParseData"
QT_MOC_LITERAL(10, 121, 12), // "checkTimeout"
QT_MOC_LITERAL(11, 134, 15), // "checkConnection"
QT_MOC_LITERAL(12, 150, 20), // "connectionInfoDialog"
QT_MOC_LITERAL(13, 171, 17), // "logActionCallback"
QT_MOC_LITERAL(14, 189, 7), // "checked"
QT_MOC_LITERAL(15, 197, 22) // "quicklogActionCallback"

    },
    "QMavlinkConnection\0mavlinkConnected\0"
    "\0c\0mavlinkMsgReceived\0mavlink_message_t\0"
    "msg\0closeLog\0mavlinkMsgSend\0"
    "mavlinkParseData\0checkTimeout\0"
    "checkConnection\0connectionInfoDialog\0"
    "logActionCallback\0checked\0"
    "quicklogActionCallback"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMavlinkConnection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       7,    0,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   71,    2, 0x0a /* Public */,
       9,    0,   74,    2, 0x0a /* Public */,
      10,    0,   75,    2, 0x0a /* Public */,
      11,    0,   76,    2, 0x0a /* Public */,
      12,    0,   77,    2, 0x0a /* Public */,
      13,    1,   78,    2, 0x0a /* Public */,
      15,    1,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Bool,   14,

       0        // eod
};

void QMavlinkConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QMavlinkConnection *_t = static_cast<QMavlinkConnection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mavlinkConnected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->mavlinkMsgReceived((*reinterpret_cast< mavlink_message_t(*)>(_a[1]))); break;
        case 2: _t->closeLog(); break;
        case 3: _t->mavlinkMsgSend((*reinterpret_cast< mavlink_message_t(*)>(_a[1]))); break;
        case 4: _t->mavlinkParseData(); break;
        case 5: _t->checkTimeout(); break;
        case 6: _t->checkConnection(); break;
        case 7: _t->connectionInfoDialog(); break;
        case 8: _t->logActionCallback((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->quicklogActionCallback((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QMavlinkConnection::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMavlinkConnection::mavlinkConnected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QMavlinkConnection::*_t)(mavlink_message_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMavlinkConnection::mavlinkMsgReceived)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QMavlinkConnection::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMavlinkConnection::closeLog)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject QMavlinkConnection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QMavlinkConnection.data,
      qt_meta_data_QMavlinkConnection,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QMavlinkConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMavlinkConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QMavlinkConnection.stringdata0))
        return static_cast<void*>(const_cast< QMavlinkConnection*>(this));
    return QObject::qt_metacast(_clname);
}

int QMavlinkConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void QMavlinkConnection::mavlinkConnected(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QMavlinkConnection::mavlinkMsgReceived(mavlink_message_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QMavlinkConnection::closeLog()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
