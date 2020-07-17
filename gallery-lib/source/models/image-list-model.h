#ifndef IMAGELISTMODEL_H
#define IMAGELISTMODEL_H

#include <QVector>

#include "gallery-lib_global.h"
#include "QAbstractListModel"
#include "image-model.h"
#include "controllers/image-loader.h"

namespace gallery {
namespace models {
class GALLERYLIB_EXPORT ImageListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QVector<ImageModel> *list READ list WRITE setList)
public:

    enum{
        name
    };

    ImageListModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;
    bool removeRows(int row, int count, const QModelIndex& parent)override;
    QHash<int, QByteArray> roleNames() const override;

    QVector<ImageModel> *list() const;
    void setList(QVector<ImageModel> *list);

private:
    gallery::controllers::ImageLoader mLoader;
    QVector<ImageModel> *mImages;
};

#endif // IMAGELISTMODEL_H

}
}

