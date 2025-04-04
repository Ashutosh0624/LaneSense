#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "adasmanager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    ADASManager adasManager;
    engine.rootContext()->setContextProperty("manager", &adasManager);


    const QUrl url = QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/../main.qml");


    qDebug() << "QML Path:" << url.toString();


    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
