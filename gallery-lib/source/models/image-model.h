#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H

#include "gallery-lib_global.h"

#include <QString>

class GALLERYLIB_EXPORT ImageModel
{
public:
    explicit ImageModel(const QString &name ="");

    QString name() const;
    void setName(const QString &name);
private:

    QString mName;
};

#endif // IMAGEMODEL_H
