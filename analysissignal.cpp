#include "analysissignal.h"
#include <QDebug>
#include <stdio.h>

AnalysisSignal::AnalysisSignal(QObject *parent) : QObject(parent) {}

void AnalysisSignal::cppSlot(const QString &filter_cmd, const QString &worker_cmd, const QString &filter_output){
    qDebug() << "Filter CMD:"  << filter_cmd ;
    qDebug() << "Worker CMD:"  << worker_cmd ;
    qDebug() << "Filter output:"  << filter_output ;



    emit showOutput("test");



    /*
    FILE *in;
    char buff[512];

    if( (in = popen("ls -sail", "r")) ){

        while(fgets(buff, sizeof(buff), in)!=NULL){
            qDebug() << buff;
        }
        pclose(in);

    }

    */


}
