#ifndef ANALYSISSIGNAL_H
#define ANALYSISSIGNAL_H

#include <QObject>

class AnalysisSignal : public QObject
{
    Q_OBJECT
public:
    explicit AnalysisSignal(QObject *parent = 0);

public slots:
    void cppSlot(const QString &filter_cmd, const QString &worker_cmd, const QString &filter_output);

};

#endif // ANALYSISSIGNAL_H
