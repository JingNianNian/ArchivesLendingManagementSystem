/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[405];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 7), // "exitWin"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 18), // "onTabWidgetChanged"
QT_MOC_LITERAL(4, 39, 3), // "cur"
QT_MOC_LITERAL(5, 43, 20), // "onFileContentChanged"
QT_MOC_LITERAL(6, 64, 18), // "onFileTitleChanged"
QT_MOC_LITERAL(7, 83, 17), // "onSaveTimeChanged"
QT_MOC_LITERAL(8, 101, 17), // "onLoadTimeChanged"
QT_MOC_LITERAL(9, 119, 19), // "onSaveButtonClicked"
QT_MOC_LITERAL(10, 139, 21), // "onCancelButtonClicked"
QT_MOC_LITERAL(11, 161, 20), // "onControlPageChanged"
QT_MOC_LITERAL(12, 182, 26), // "onRefreshFileButtonClicked"
QT_MOC_LITERAL(13, 209, 31), // "onCheckOverdueFileButtonClicked"
QT_MOC_LITERAL(14, 241, 33), // "onDeleteSelectedFileButtonCli..."
QT_MOC_LITERAL(15, 275, 22), // "onUpLevelButtonClicked"
QT_MOC_LITERAL(16, 298, 25), // "onDeleteUserButtonClicked"
QT_MOC_LITERAL(17, 324, 27), // "onAcceptRecordButtonClicked"
QT_MOC_LITERAL(18, 352, 27), // "onRefuseRecordButtonClicked"
QT_MOC_LITERAL(19, 380, 24) // "onDownLevelButtonClicked"

    },
    "MainWindow\0exitWin\0\0onTabWidgetChanged\0"
    "cur\0onFileContentChanged\0onFileTitleChanged\0"
    "onSaveTimeChanged\0onLoadTimeChanged\0"
    "onSaveButtonClicked\0onCancelButtonClicked\0"
    "onControlPageChanged\0onRefreshFileButtonClicked\0"
    "onCheckOverdueFileButtonClicked\0"
    "onDeleteSelectedFileButtonClicked\0"
    "onUpLevelButtonClicked\0onDeleteUserButtonClicked\0"
    "onAcceptRecordButtonClicked\0"
    "onRefuseRecordButtonClicked\0"
    "onDownLevelButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,  100,    2, 0x08 /* Private */,
       5,    0,  103,    2, 0x08 /* Private */,
       6,    1,  104,    2, 0x08 /* Private */,
       7,    0,  107,    2, 0x08 /* Private */,
       8,    0,  108,    2, 0x08 /* Private */,
       9,    0,  109,    2, 0x08 /* Private */,
      10,    0,  110,    2, 0x08 /* Private */,
      11,    1,  111,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->exitWin(); break;
        case 1: _t->onTabWidgetChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onFileContentChanged(); break;
        case 3: _t->onFileTitleChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->onSaveTimeChanged(); break;
        case 5: _t->onLoadTimeChanged(); break;
        case 6: _t->onSaveButtonClicked(); break;
        case 7: _t->onCancelButtonClicked(); break;
        case 8: _t->onControlPageChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->onRefreshFileButtonClicked(); break;
        case 10: _t->onCheckOverdueFileButtonClicked(); break;
        case 11: _t->onDeleteSelectedFileButtonClicked(); break;
        case 12: _t->onUpLevelButtonClicked(); break;
        case 13: _t->onDeleteUserButtonClicked(); break;
        case 14: _t->onAcceptRecordButtonClicked(); break;
        case 15: _t->onRefuseRecordButtonClicked(); break;
        case 16: _t->onDownLevelButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::exitWin)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::exitWin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
