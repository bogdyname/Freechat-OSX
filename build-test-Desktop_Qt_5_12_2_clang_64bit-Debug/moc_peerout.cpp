/****************************************************************************
** Meta object code from reading C++ file 'peerout.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../test/Network/peerout.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'peerout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Peerout_t {
    QByteArrayData data[9];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Peerout_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Peerout_t qt_meta_stringdata_Peerout = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Peerout"
QT_MOC_LITERAL(1, 8, 13), // "SlotReadyRead"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 13), // "SlotConnected"
QT_MOC_LITERAL(4, 37, 8), // "QString&"
QT_MOC_LITERAL(5, 46, 6), // "ipHost"
QT_MOC_LITERAL(6, 53, 16), // "SlotSendToServer"
QT_MOC_LITERAL(7, 70, 9), // "SlotError"
QT_MOC_LITERAL(8, 80, 28) // "QAbstractSocket::SocketError"

    },
    "Peerout\0SlotReadyRead\0\0SlotConnected\0"
    "QString&\0ipHost\0SlotSendToServer\0"
    "SlotError\0QAbstractSocket::SocketError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Peerout[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       6,    0,   38,    2, 0x0a /* Public */,
       7,    1,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,

       0        // eod
};

void Peerout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Peerout *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SlotReadyRead(); break;
        case 1: _t->SlotConnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->SlotSendToServer(); break;
        case 3: _t->SlotError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Peerout::staticMetaObject = { {
    &QTcpSocket::staticMetaObject,
    qt_meta_stringdata_Peerout.data,
    qt_meta_data_Peerout,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Peerout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Peerout::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Peerout.stringdata0))
        return static_cast<void*>(this);
    return QTcpSocket::qt_metacast(_clname);
}

int Peerout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE