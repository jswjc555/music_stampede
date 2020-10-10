#include "mymovie.h"
#include<QDebug>
MyMovie::MyMovie(const QString &fileName, const QByteArray &format, QObject *parent):QMovie(fileName,format,parent)
{
    connect(this,SIGNAL(isfinished(MyMovie*)),this->parent(),SLOT(deletemovie(MyMovie*)),Qt::DirectConnection);
    time.setInterval(200);
    connect(&time,&QTimer::timeout,this,[&](){
            emit this->isfinished(this);
    });
    time.start();
}
