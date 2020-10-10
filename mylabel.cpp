#include "mylabel.h"
QStringList MyLabel::path(":/image/zhuan.png");
MyLabel::MyLabel(QWidget *parent, int position, type mytype):QLabel(parent),position(position),mytype(mytype)
{
        resize(lable_width,lable_high);
        pix.load(path[0]);
        setPixmap(pix);
    //200-height()+100
    move(position*lable_width,0);
    show();
    setScaledContents(true);
    connect(this,SIGNAL(deletethis()),this->parent(),SLOT(deleteit()));
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
            return;
        }
        if(this->mytype==disappear){
            if(gety()>=490-150) {
               setPixmap(pix);
                return;
            }
            int i=rand(1,0);
            if(gety()>50+50*i) {setPixmap(QPixmap(":/imagene.png"));}
        }
        else if(mytype==canmove){
            if(gety()>=490-200) return;
            int i=position;
            while (1) {
                position=rand(4,0);
                if(position!=i) break;
            }
        }
        else if(mytype==isfalse){
            if(gety()>=100*rand(2,3)){
                if(speed>0)speed=-2;
                if(gety()<0){
                    hide();
                }
            }
        }
}
