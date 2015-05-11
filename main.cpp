#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "analyzesignal.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;


    //
    AnalyzeSignal analyzeSignal;
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("analyzeSignal", &analyzeSignal);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    // Registering slot onto a signal
    QObject *win = engine.rootObjects()[0];
    QObject *item = win->findChild<QObject*>("myButton");
    QObject::connect(item, SIGNAL(doAnalyzeSignal(QString,QString,QString)), &analyzeSignal, SLOT(cppSlot(QString,QString,QString)));



    return app.exec();
}
