#include "mylabel.h"
QStringList MyLabel::path(":/zhuan.png");
MyLabel::MyLabel(QWidget *parent, int position, type mytype):QLabel(parent),position(position),mytype(mytype)
{
    if(mytype==islong)
        resize(lable_width,lable_high*8);
    else
        resize(lable_width,lable_high);
    pix.load(path[0]);
    setPixmap(pix);
    move(position*lable_width,200-height()+100);
    show();
    setScaledContents(true);
    connect(this,SIGNAL(deletethis()),parent,SLOT(deleteit()));
}
int MyLabel::rand(int a,int b)
{
    RAND
    return qrand()%a+b;
}
int MyLabel::getx()
{
    p=this->pos();
    return p.x();
}

int MyLabel::gety()
{
    p=this->pos();
    return p.y();
}

void MyLabel::moveEvent(QMoveEvent *)
{
    if(gety()>=DEEP){
        hide();
        emit deletethis();
    }
    if(this->mytype==disappear){
        if(gety()>=DEEP-300) {
           setPixmap(pix);
            return;
        }
        int i=rand(1,0);
        if(gety()>300+50*i) {setPixmap(QPixmap(":/none.png"));}
    }
    else if(mytype==canmove){
        if(gety()>=DEEP-300) return;
        int i=position;
        while (1) {
            position=rand(4,0);
            if(position!=i) break;
        }
    }
}
