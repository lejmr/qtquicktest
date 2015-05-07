#include "analyzesignal.h"
#include <QDebug>
#include <stdio.h>

AnalyzeSignal::AnalyzeSignal(QObject *parent) : QObject(parent) {}

void AnalyzeSignal::cppSlot(const QString &filter_cmd, const QString &worker_cmd, const QString &filter_output){
    qDebug() << "Filter CMD:"  << filter_cmd ;
    qDebug() << "Worker CMD:"  << worker_cmd ;
    qDebug() << "Filter output:"  << filter_output ;



    emit writeToLogOutput("test");



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
