/****************************************************************************
** Meta object code from reading C++ file 'ratio_layouted_frame.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/rqt_common_plugins/rqt_image_view/include/rqt_image_view/ratio_layouted_frame.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ratio_layouted_frame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rqt_image_view__RatioLayoutedFrame[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      36,   35,   35,   35, 0x05,
      57,   53,   35,   35, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_rqt_image_view__RatioLayoutedFrame[] = {
    "rqt_image_view::RatioLayoutedFrame\0\0"
    "delayed_update()\0x,y\0mouseLeft(int,int)\0"
};

void rqt_image_view::RatioLayoutedFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RatioLayoutedFrame *_t = static_cast<RatioLayoutedFrame *>(_o);
        switch (_id) {
        case 0: _t->delayed_update(); break;
        case 1: _t->mouseLeft((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rqt_image_view::RatioLayoutedFrame::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rqt_image_view::RatioLayoutedFrame::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_rqt_image_view__RatioLayoutedFrame,
      qt_meta_data_rqt_image_view__RatioLayoutedFrame, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rqt_image_view::RatioLayoutedFrame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rqt_image_view::RatioLayoutedFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rqt_image_view::RatioLayoutedFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_image_view__RatioLayoutedFrame))
        return static_cast<void*>(const_cast< RatioLayoutedFrame*>(this));
    return QFrame::qt_metacast(_clname);
}

int rqt_image_view::RatioLayoutedFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void rqt_image_view::RatioLayoutedFrame::delayed_update()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void rqt_image_view::RatioLayoutedFrame::mouseLeft(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
