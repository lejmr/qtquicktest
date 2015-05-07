#ifndef ANALYZESIGNAL_H
#define ANALYZESIGNAL_H

#include <QObject>

class AnalyzeSignal : public QObject
{
    Q_OBJECT
    Q_PROPERTY(NOTIFY writeToLogOutput)
public:
    explicit AnalyzeSignal(QObject *parent = 0);

public slots:
    void cppSlot(const QString &filter_cmd, const QString &worker_cmd, const QString &filter_output);

signals:
    void writeToLogOutput(const QString &line);

};

#endif // ANALYZESIGNAL_H
