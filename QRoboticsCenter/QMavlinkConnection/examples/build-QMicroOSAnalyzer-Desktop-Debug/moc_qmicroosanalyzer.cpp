/****************************************************************************
** Meta object code from reading C++ file 'qmicroosanalyzer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../QRoboticsCenter/qmicroosanalyzer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmicroosanalyzer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QMicroOSAnalyzer_t {
    QByteArrayData data[10];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMicroOSAnalyzer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMicroOSAnalyzer_t qt_meta_stringdata_QMicroOSAnalyzer = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QMicroOSAnalyzer"
QT_MOC_LITERAL(1, 17, 28), // "handleMavlinkConnectionFound"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 19), // "QMavlinkConnection*"
QT_MOC_LITERAL(4, 67, 18), // "mavlink_connection"
QT_MOC_LITERAL(5, 86, 6), // "search"
QT_MOC_LITERAL(6, 93, 19), // "launchThreadsDialog"
QT_MOC_LITERAL(7, 113, 17), // "launchDebugDialog"
QT_MOC_LITERAL(8, 131, 20), // "launchMessagesDialog"
QT_MOC_LITERAL(9, 152, 18) // "launchLoggerDialog"

    },
    "QMicroOSAnalyzer\0handleMavlinkConnectionFound\0"
    "\0QMavlinkConnection*\0mavlink_connection\0"
    "search\0launchThreadsDialog\0launchDebugDialog\0"
    "launchMessagesDialog\0launchLoggerDialog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMicroOSAnalyzer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QMicroOSAnalyzer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QMicroOSAnalyzer *_t = static_cast<QMicroOSAnalyzer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleMavlinkConnectionFound((*reinterpret_cast< QMavlinkConnection*(*)>(_a[1]))); break;
        case 1: _t->search(); break;
        case 2: _t->launchThreadsDialog(); break;
        case 3: _t->launchDebugDialog(); break;
        case 4: _t->launchMessagesDialog(); break;
        case 5: _t->launchLoggerDialog(); break;
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
        }
    }
}

const QMetaObject QMicroOSAnalyzer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QMicroOSAnalyzer.data,
      qt_meta_data_QMicroOSAnalyzer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QMicroOSAnalyzer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMicroOSAnalyzer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QMicroOSAnalyzer.stringdata0))
        return static_cast<void*>(const_cast< QMicroOSAnalyzer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QMicroOSAnalyzer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
