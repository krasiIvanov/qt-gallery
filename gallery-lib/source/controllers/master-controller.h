#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>

#include <gallery-lib_global.h>

namespace gallery {

namespace controllers {

    class GALLERYLIB_EXPORT MasterController : public QObject
    {
        Q_OBJECT

        public:
            explicit MasterController(QObject* parent = nullptr);
    };
}
}

#endif // MASTERCONTROLLER_H
