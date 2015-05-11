#include "analyzesignal.h"
#include <QDebug>
#include <QFile>
#include <stdio.h>

AnalyzeSignal::AnalyzeSignal(QObject *parent) : QObject(parent) {}

void AnalyzeSignal::cppSlot(const QString &filter_cmd, const QString &worker_cmd, const QString &filter_output){
    qDebug() << "Filter CMD:"  << filter_cmd ;
    qDebug() << "Worker CMD:"  << worker_cmd ;
    qDebug() << "Filter output:"  << filter_output ;


    // Run filter if filter has not been run
    QFile file(filter_output);
    if( !file.exists() ){
        run_cmd(filter_cmd);
    }

    // Run savesip analyzer
    run_cmd(worker_cmd);


}

void AnalyzeSignal::run_cmd(const QString &cmd){
    FILE *in;
    char buff[512];
    if( (in = popen(cmd.toStdString().c_str(), "r")) ){
        while(fgets(buff, sizeof(buff), in)!=NULL){
            qDebug() << buff;
            writeToLogOutput(buff);
        }
        pclose(in);
    }
}
