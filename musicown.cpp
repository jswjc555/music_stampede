#include "musicown.h"

Musicown::Musicown(QWidget *parent) : QWidget(parent)
{
    f=new QFile(":/test.txt",this);
    if(!f->open(QIODevice::ReadOnly)){return;}
    int i=0;
    QString file=QString(f->readAll().data());
    while (1) {
        QString s=file.section("\n",i,i);
        if(s=="") {n=i-1;break;}
        sump.append(s.toInt());
        i++;
    }
    player=new QMediaPlayer(this);
    player->setMedia(QUrl("qrc:/lion.mp3"));
    player->setVolume(100);
    sencond=sump[n];
}

Musicown::~Musicown()
{
    if(f->isOpen())
        f->close();
}

int Musicown::cha(int i)
{
    return sump[i]-sump[i-1];
}

void Musicown::start()
{
    QTime time= QTime::currentTime();
    qsrand(time.msec()+time.second()*3000);  //设置随机种子

}
