#include "image-loader.h"
#include "QString"
#include "QDir"
#include "QDebug"


namespace gallery {
namespace controllers {

    ImageLoader::ImageLoader(const QString &path) : dir(path)
    {        
    }

    QVector<ImageModel>* ImageLoader::loadImages()
    {
        QVector<ImageModel> *dataset = new QVector<ImageModel>;        
        QDir directory(ImageLoader::dir);
        QStringList images = directory.entryList(QStringList() << "*.png" << "*.PNG",QDir::Files);
        foreach(QString filename, images) {
            ImageModel *img = new ImageModel(dir + filename);
            dataset->append(*img);
        }        
        return dataset;
    }
}
}


