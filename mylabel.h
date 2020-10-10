#ifndef MYLABEL_H
#define MYLABEL_H

#include<QLabel>
#include<QPixmap>
#include<QPoint>
#include<QMoveEvent>
#include<QStringList>
#include<QTimer>
#include<QTime>
#include <QtGlobal>//包含随机函数
#define DEEP 650
#define SPEED 2
#define lable_width   140
#define  lable_high  140
#define RAND QTime time1= QTime::currentTime();\
qsrand(time1.msec()*90000000000+time1.second());
enum type{disappear,canmove,isfalse,normal};
enum result{bad,good,perfect};
class MyLabel : public QLabel
{
    Q_OBJECT
private:
    QPoint p;
    QPixmap pix;

public:
    static QStringList path;
    MyLabel(QWidget *parent=nullptr,int position=-1,type mytype=normal);
    int getx();
    int gety();
    int rand(int a,int b);
    int position;
    type mytype;
    bool isclicked=0;
    int speed=2;
    void moveEvent(QMoveEvent*);
signals:
     void deletethis();
};

#endif // MYLABEL_H
