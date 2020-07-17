#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <gallery-lib_global.h>

#include <QString>
#include <QVector>
#include "models/image-model.h"


namespace gallery {
namespace controllers {

    const QString DIR_PATH = "/Users/krasimir/Desktop/example/qt-gallery/imgs/";

    class GALLERYLIB_EXPORT ImageLoader
    {

    public:
        ImageLoader(const QString &path = DIR_PATH);

        QVector<ImageModel>* loadImages();

    private:
        QString dir;
    };
}
}



#endif // IMAGELOADER_H
