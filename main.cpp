#include <QApplication>
#include <QQmlApplicationEngine>
#include "analysissignal.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    AnalysisSignal analysisSignal;
    QObject *win = engine.rootObjects()[0];
    QObject *item = win->findChild<QObject*>("myButton");
    QObject::connect(item, SIGNAL(doAnalyseSignal(QString,QString,QString)), &analysisSignal, SLOT(cppSlot(QString,QString,QString)));

    return app.exec();
}
