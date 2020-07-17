#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <controllers/image-loader.h>
#include <models/image-list-model.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<gallery::models::ImageListModel>("GALLERY",1,0,"ImageListModel");
    //qmlRegisterUncreatableType<gallery::models::ImageListModel>("GALLERY",1,0,"ImageListModel",QStringLiteral(""));
    QQmlApplicationEngine engine;

    gallery::models::ImageListModel imageList;

    engine.rootContext()->setContextProperty("imageListModel", &imageList);

    const QUrl url(QStringLiteral("qrc:/views/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
