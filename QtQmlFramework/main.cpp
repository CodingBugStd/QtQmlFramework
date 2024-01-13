#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "BackendThread.h"
#include "elog.h"

#include <string.h>

void log_module_init(void)
{
    elog_init();

    elog_set_text_color_enabled(0);

    elog_set_fmt( ELOG_LVL_VERBOSE , ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME );
    elog_set_fmt( ELOG_LVL_DEBUG , ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt( ELOG_LVL_INFO , ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt( ELOG_LVL_WARN , ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME );
    elog_set_fmt( ELOG_LVL_ERROR , ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME );

    elog_start();
}

int main(int argc, char *argv[])
{
    log_module_init();

    QGuiApplication app(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);

    QQmlApplicationEngine engine;

    BackendThread* backend = new BackendThread;

    //将封装了业务逻辑的backend实例添加到UI引擎中，方便qml直接调用后台
    engine.rootContext()->setContextProperty( "backend" , backend );

    //将qml UI文件载入邀请
    QUrl url("./UI/main.qml");
    if( !url.isEmpty() )
    {
        elog_w("main","Can`t find qml file in file system.");
        elog_w("main","Use internal default UI.");
        url = QUrl(QStringLiteral("qrc:/default_ui.qml"));
    }

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    //获取UI对象，方便c/c++控制UI
    QObject* qmlObj = engine.rootObjects().at(0);
    backend->setBackendQmlObj(qmlObj);
    backend->backendStart();

    elog_v("test","verbose log");
    elog_d("test","debug log");
    elog_i("test","info log");
    elog_w("test","warn log");
    elog_e("test","err log");

    return app.exec();
}
