/****************************************************************************
** Meta object code from reading C++ file 'outputhandle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../outputhandle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'outputhandle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OutputHandle_t {
    QByteArrayData data[16];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OutputHandle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OutputHandle_t qt_meta_stringdata_OutputHandle = {
    {
QT_MOC_LITERAL(0, 0, 12), // "OutputHandle"
QT_MOC_LITERAL(1, 13, 6), // "stdOut"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 3), // "msg"
QT_MOC_LITERAL(4, 25, 19), // "receiveQuestionList"
QT_MOC_LITERAL(5, 45, 20), // "QList<QuestionBrief>"
QT_MOC_LITERAL(6, 66, 9), // "questions"
QT_MOC_LITERAL(7, 76, 22), // "receiveQuestionContent"
QT_MOC_LITERAL(8, 99, 8), // "Question"
QT_MOC_LITERAL(9, 108, 8), // "question"
QT_MOC_LITERAL(10, 117, 12), // "receiveJudge"
QT_MOC_LITERAL(11, 130, 11), // "JudgeResult"
QT_MOC_LITERAL(12, 142, 5), // "judge"
QT_MOC_LITERAL(13, 148, 22), // "receiveUserInformation"
QT_MOC_LITERAL(14, 171, 4), // "User"
QT_MOC_LITERAL(15, 176, 4) // "user"

    },
    "OutputHandle\0stdOut\0\0msg\0receiveQuestionList\0"
    "QList<QuestionBrief>\0questions\0"
    "receiveQuestionContent\0Question\0"
    "question\0receiveJudge\0JudgeResult\0"
    "judge\0receiveUserInformation\0User\0"
    "user"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OutputHandle[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,
      10,    1,   48,    2, 0x0a /* Public */,
      13,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void OutputHandle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OutputHandle *_t = static_cast<OutputHandle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stdOut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->receiveQuestionList((*reinterpret_cast< QList<QuestionBrief>(*)>(_a[1]))); break;
        case 2: _t->receiveQuestionContent((*reinterpret_cast< Question(*)>(_a[1]))); break;
        case 3: _t->receiveJudge((*reinterpret_cast< JudgeResult(*)>(_a[1]))); break;
        case 4: _t->receiveUserInformation((*reinterpret_cast< User(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OutputHandle::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OutputHandle::stdOut)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject OutputHandle::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_OutputHandle.data,
      qt_meta_data_OutputHandle,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OutputHandle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OutputHandle::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OutputHandle.stringdata0))
        return static_cast<void*>(const_cast< OutputHandle*>(this));
    return QObject::qt_metacast(_clname);
}

int OutputHandle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void OutputHandle::stdOut(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
