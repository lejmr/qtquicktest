#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "analyzesignal.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //
    AnalyzeSignal analyzeSignal;
    QQmlContext *context = new QQmlContext(engine.rootContext());
    context->setContextProperty("analyzeSignal", &analyzeSignal);


    // Registering slot onto a signal
    QObject *win = engine.rootObjects()[0];
    QObject *item = win->findChild<QObject*>("myButton");
    QObject::connect(item, SIGNAL(doAnalyzeSignal(QString,QString,QString)), &analyzeSignal, SLOT(cppSlot(QString,QString,QString)));



    return app.exec();
}
