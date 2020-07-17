#include "image-model.h"

ImageModel::ImageModel(const QString &name) : mName(name)
{
}

QString ImageModel::name() const
{
    return mName;
}

void ImageModel::setName(const QString &name)
{
    mName = name;
}
