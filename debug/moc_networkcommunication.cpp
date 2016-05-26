/****************************************************************************
** Meta object code from reading C++ file 'networkcommunication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../com/networkcommunication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networkcommunication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NetworkCommunication_t {
    QByteArrayData data[26];
    char stringdata0[320];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetworkCommunication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetworkCommunication_t qt_meta_stringdata_NetworkCommunication = {
    {
QT_MOC_LITERAL(0, 0, 20), // "NetworkCommunication"
QT_MOC_LITERAL(1, 21, 6), // "stdOut"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 3), // "msg"
QT_MOC_LITERAL(4, 33, 20), // "responseQuestionList"
QT_MOC_LITERAL(5, 54, 20), // "QList<QuestionBrief>"
QT_MOC_LITERAL(6, 75, 12), // "questionList"
QT_MOC_LITERAL(7, 88, 23), // "responseQuestionContent"
QT_MOC_LITERAL(8, 112, 8), // "Question"
QT_MOC_LITERAL(9, 121, 8), // "question"
QT_MOC_LITERAL(10, 130, 13), // "responseJudge"
QT_MOC_LITERAL(11, 144, 11), // "JudgeResult"
QT_MOC_LITERAL(12, 156, 6), // "result"
QT_MOC_LITERAL(13, 163, 23), // "responseUserInformation"
QT_MOC_LITERAL(14, 187, 4), // "User"
QT_MOC_LITERAL(15, 192, 4), // "user"
QT_MOC_LITERAL(16, 197, 19), // "requestQuestionList"
QT_MOC_LITERAL(17, 217, 22), // "requestQuestionContent"
QT_MOC_LITERAL(18, 240, 10), // "questionId"
QT_MOC_LITERAL(19, 251, 12), // "requestJudge"
QT_MOC_LITERAL(20, 264, 5), // "Judge"
QT_MOC_LITERAL(21, 270, 5), // "judge"
QT_MOC_LITERAL(22, 276, 22), // "requestUserInformation"
QT_MOC_LITERAL(23, 299, 5), // "token"
QT_MOC_LITERAL(24, 305, 10), // "msgReceive"
QT_MOC_LITERAL(25, 316, 3) // "doc"

    },
    "NetworkCommunication\0stdOut\0\0msg\0"
    "responseQuestionList\0QList<QuestionBrief>\0"
    "questionList\0responseQuestionContent\0"
    "Question\0question\0responseJudge\0"
    "JudgeResult\0result\0responseUserInformation\0"
    "User\0user\0requestQuestionList\0"
    "requestQuestionContent\0questionId\0"
    "requestJudge\0Judge\0judge\0"
    "requestUserInformation\0token\0msgReceive\0"
    "doc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetworkCommunication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       7,    1,   70,    2, 0x06 /* Public */,
      10,    1,   73,    2, 0x06 /* Public */,
      13,    1,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,   79,    2, 0x0a /* Public */,
      17,    1,   80,    2, 0x0a /* Public */,
      19,    1,   83,    2, 0x0a /* Public */,
      22,    2,   86,    2, 0x0a /* Public */,
      24,    1,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   15,   23,
    QMetaType::Void, QMetaType::QJsonDocument,   25,

       0        // eod
};

void NetworkCommunication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetworkCommunication *_t = static_cast<NetworkCommunication *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stdOut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->responseQuestionList((*reinterpret_cast< QList<QuestionBrief>(*)>(_a[1]))); break;
        case 2: _t->responseQuestionContent((*reinterpret_cast< Question(*)>(_a[1]))); break;
        case 3: _t->responseJudge((*reinterpret_cast< JudgeResult(*)>(_a[1]))); break;
        case 4: _t->responseUserInformation((*reinterpret_cast< User(*)>(_a[1]))); break;
        case 5: _t->requestQuestionList(); break;
        case 6: _t->requestQuestionContent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->requestJudge((*reinterpret_cast< Judge(*)>(_a[1]))); break;
        case 8: _t->requestUserInformation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->msgReceive((*reinterpret_cast< QJsonDocument(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NetworkCommunication::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkCommunication::stdOut)) {
                *result = 0;
            }
        }
        {
            typedef void (NetworkCommunication::*_t)(QList<QuestionBrief> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkCommunication::responseQuestionList)) {
                *result = 1;
            }
        }
        {
            typedef void (NetworkCommunication::*_t)(Question );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkCommunication::responseQuestionContent)) {
                *result = 2;
            }
        }
        {
            typedef void (NetworkCommunication::*_t)(JudgeResult );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkCommunication::responseJudge)) {
                *result = 3;
            }
        }
        {
            typedef void (NetworkCommunication::*_t)(User );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkCommunication::responseUserInformation)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject NetworkCommunication::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NetworkCommunication.data,
      qt_meta_data_NetworkCommunication,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NetworkCommunication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetworkCommunication::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkCommunication.stringdata0))
        return static_cast<void*>(const_cast< NetworkCommunication*>(this));
    return QObject::qt_metacast(_clname);
}

int NetworkCommunication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void NetworkCommunication::stdOut(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetworkCommunication::responseQuestionList(QList<QuestionBrief> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NetworkCommunication::responseQuestionContent(Question _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NetworkCommunication::responseJudge(JudgeResult _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void NetworkCommunication::responseUserInformation(User _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
