/****************************************************************************
** Meta object code from reading C++ file 'network.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../com/network.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'network.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Network_t {
    QByteArrayData data[12];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Network_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Network_t qt_meta_stringdata_Network = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Network"
QT_MOC_LITERAL(1, 8, 9), // "connected"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 12), // "disconnected"
QT_MOC_LITERAL(4, 32, 11), // "msgReceived"
QT_MOC_LITERAL(5, 44, 3), // "doc"
QT_MOC_LITERAL(6, 48, 6), // "stdOut"
QT_MOC_LITERAL(7, 55, 3), // "msg"
QT_MOC_LITERAL(8, 59, 13), // "clientStarted"
QT_MOC_LITERAL(9, 73, 13), // "clientStopped"
QT_MOC_LITERAL(10, 87, 7), // "msgSend"
QT_MOC_LITERAL(11, 95, 7) // "receive"

    },
    "Network\0connected\0\0disconnected\0"
    "msgReceived\0doc\0stdOut\0msg\0clientStarted\0"
    "clientStopped\0msgSend\0receive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Network[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    1,   56,    2, 0x06 /* Public */,
       6,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   62,    2, 0x08 /* Private */,
       9,    0,   63,    2, 0x08 /* Private */,
      10,    1,   64,    2, 0x0a /* Public */,
      11,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonDocument,    5,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonDocument,    5,
    QMetaType::Void,

       0        // eod
};

void Network::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Network *_t = static_cast<Network *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->msgReceived((*reinterpret_cast< QJsonDocument(*)>(_a[1]))); break;
        case 3: _t->stdOut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->clientStarted(); break;
        case 5: _t->clientStopped(); break;
        case 6: _t->msgSend((*reinterpret_cast< QJsonDocument(*)>(_a[1]))); break;
        case 7: _t->receive(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Network::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Network::connected)) {
                *result = 0;
            }
        }
        {
            typedef void (Network::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Network::disconnected)) {
                *result = 1;
            }
        }
        {
            typedef void (Network::*_t)(QJsonDocument );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Network::msgReceived)) {
                *result = 2;
            }
        }
        {
            typedef void (Network::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Network::stdOut)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Network::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Network.data,
      qt_meta_data_Network,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Network::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Network::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Network.stringdata0))
        return static_cast<void*>(const_cast< Network*>(this));
    return QObject::qt_metacast(_clname);
}

int Network::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Network::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Network::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Network::msgReceived(QJsonDocument _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Network::stdOut(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
