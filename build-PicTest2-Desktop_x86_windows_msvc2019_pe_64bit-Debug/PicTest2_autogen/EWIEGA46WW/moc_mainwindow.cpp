/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PicTest2/mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "Update",
    "",
    "on_Normal_clicked",
    "on_Open_Image_clicked",
    "on_Grayscale_clicked",
    "on_Binary_clicked",
    "on_Blur_clicked",
    "on_GaussianBlur_clicked",
    "on_Canny_clicked",
    "on_HSV_clicked",
    "on_Draw_stateChanged",
    "arg1",
    "on_Open_Camera_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[11];
    char stringdata1[7];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[22];
    char stringdata5[21];
    char stringdata6[18];
    char stringdata7[16];
    char stringdata8[24];
    char stringdata9[17];
    char stringdata10[15];
    char stringdata11[21];
    char stringdata12[5];
    char stringdata13[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 6),  // "Update"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 17),  // "on_Normal_clicked"
        QT_MOC_LITERAL(37, 21),  // "on_Open_Image_clicked"
        QT_MOC_LITERAL(59, 20),  // "on_Grayscale_clicked"
        QT_MOC_LITERAL(80, 17),  // "on_Binary_clicked"
        QT_MOC_LITERAL(98, 15),  // "on_Blur_clicked"
        QT_MOC_LITERAL(114, 23),  // "on_GaussianBlur_clicked"
        QT_MOC_LITERAL(138, 16),  // "on_Canny_clicked"
        QT_MOC_LITERAL(155, 14),  // "on_HSV_clicked"
        QT_MOC_LITERAL(170, 20),  // "on_Draw_stateChanged"
        QT_MOC_LITERAL(191, 4),  // "arg1"
        QT_MOC_LITERAL(196, 22)   // "on_Open_Camera_clicked"
    },
    "MainWindow",
    "Update",
    "",
    "on_Normal_clicked",
    "on_Open_Image_clicked",
    "on_Grayscale_clicked",
    "on_Binary_clicked",
    "on_Blur_clicked",
    "on_GaussianBlur_clicked",
    "on_Canny_clicked",
    "on_HSV_clicked",
    "on_Draw_stateChanged",
    "arg1",
    "on_Open_Camera_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x0a,    1 /* Public */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    0,   83,    2, 0x08,    4 /* Private */,
       6,    0,   84,    2, 0x08,    5 /* Private */,
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    0,   86,    2, 0x08,    7 /* Private */,
       9,    0,   87,    2, 0x08,    8 /* Private */,
      10,    0,   88,    2, 0x08,    9 /* Private */,
      11,    1,   89,    2, 0x08,   10 /* Private */,
      13,    0,   92,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'Update'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Normal_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Open_Image_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Grayscale_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Binary_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Blur_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_GaussianBlur_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Canny_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_HSV_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Draw_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_Open_Camera_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Update(); break;
        case 1: _t->on_Normal_clicked(); break;
        case 2: _t->on_Open_Image_clicked(); break;
        case 3: _t->on_Grayscale_clicked(); break;
        case 4: _t->on_Binary_clicked(); break;
        case 5: _t->on_Blur_clicked(); break;
        case 6: _t->on_GaussianBlur_clicked(); break;
        case 7: _t->on_Canny_clicked(); break;
        case 8: _t->on_HSV_clicked(); break;
        case 9: _t->on_Draw_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->on_Open_Camera_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
