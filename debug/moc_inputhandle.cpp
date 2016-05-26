/****************************************************************************
** Meta object code from reading C++ file 'inputhandle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inputhandle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inputhandle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_InputHandle_t {
    QByteArrayData data[13];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InputHandle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InputHandle_t qt_meta_stringdata_InputHandle = {
    {
QT_MOC_LITERAL(0, 0, 11), // "InputHandle"
QT_MOC_LITERAL(1, 12, 6), // "stdOut"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 3), // "msg"
QT_MOC_LITERAL(4, 24, 16), // "sendQuestionList"
QT_MOC_LITERAL(5, 41, 19), // "sendQuestionContent"
QT_MOC_LITERAL(6, 61, 10), // "questionId"
QT_MOC_LITERAL(7, 72, 9), // "sendJudge"
QT_MOC_LITERAL(8, 82, 5), // "Judge"
QT_MOC_LITERAL(9, 88, 5), // "judge"
QT_MOC_LITERAL(10, 94, 19), // "sendUserInformation"
QT_MOC_LITERAL(11, 114, 4), // "user"
QT_MOC_LITERAL(12, 119, 5) // "token"

    },
    "InputHandle\0stdOut\0\0msg\0sendQuestionList\0"
    "sendQuestionContent\0questionId\0sendJudge\0"
    "Judge\0judge\0sendUserInformation\0user\0"
    "token"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InputHandle[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,
       5,    1,   43,    2, 0x06 /* Public */,
       7,    1,   46,    2, 0x06 /* Public */,
      10,    2,   49,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,

       0        // eod
};

void InputHandle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InputHandle *_t = static_cast<InputHandle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stdOut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendQuestionList(); break;
        case 2: _t->sendQuestionContent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sendJudge((*reinterpret_cast< Judge(*)>(_a[1]))); break;
        case 4: _t->sendUserInformation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (InputHandle::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InputHandle::stdOut)) {
                *result = 0;
            }
        }
        {
            typedef void (InputHandle::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InputHandle::sendQuestionList)) {
                *result = 1;
            }
        }
        {
            typedef void (InputHandle::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InputHandle::sendQuestionContent)) {
                *result = 2;
            }
        }
        {
            typedef void (InputHandle::*_t)(Judge );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InputHandle::sendJudge)) {
                *result = 3;
            }
        }
        {
            typedef void (InputHandle::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InputHandle::sendUserInformation)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject InputHandle::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_InputHandle.data,
      qt_meta_data_InputHandle,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *InputHandle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InputHandle::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_InputHandle.stringdata0))
        return static_cast<void*>(const_cast< InputHandle*>(this));
    return QObject::qt_metacast(_clname);
}

int InputHandle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void InputHandle::stdOut(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void InputHandle::sendQuestionList()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void InputHandle::sendQuestionContent(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void InputHandle::sendJudge(Judge _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void InputHandle::sendUserInformation(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
