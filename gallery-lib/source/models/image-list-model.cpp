#include "image-list-model.h"

namespace gallery {
namespace models {

    ImageListModel::ImageListModel(QObject* parent) : QAbstractListModel(parent),
        mLoader(),
        mImages(mLoader.loadImages())
    {
    }

    int ImageListModel::rowCount(const QModelIndex &parent) const
    {
        if (parent.isValid() || !mImages){
           return 0;
       }
        return mImages->size();
    }

    QVariant ImageListModel::data(const QModelIndex &index, int role) const
    {
        if (!index.isValid()) {
           return QVariant();
       }

       const ImageModel& image = mImages->at(index.row());
       return image.name();

    }

    bool ImageListModel::setData(const QModelIndex &index, const QVariant &value, int role)
    {
        if(!mImages){
            return false;
        }
        ImageModel image = mImages->at(index.row());
        image.setName(value.toString());
        emit dataChanged(index,index);
        return true;

    }

    bool ImageListModel::removeRows(int row, int count, const QModelIndex &parent)
    {
        //TODO
        return false;
    }

    QHash<int, QByteArray> ImageListModel::roleNames() const
    {
        QHash<int, QByteArray> names;
        names[name] = "name";

        return names;
    }

    QVector<ImageModel> *ImageListModel::list() const
    {
        return mImages;
    }

    void ImageListModel::setList(QVector<ImageModel> *list)
    {
        //TODO
    }

}
}
