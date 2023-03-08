#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "BackendThread.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    //将封装了业务逻辑的backend实例添加到UI引擎中，方便qml直接调用后台
    engine.rootContext()->setContextProperty( "backend" , &BackendThread::backendThread );

    const QUrl url("./UI/main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
