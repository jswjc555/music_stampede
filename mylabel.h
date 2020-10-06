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
#define DEEP 900
#define SPEED 3
#define lable_width   125
#define  lable_high  125
#define RAND QTime time1= QTime::currentTime();\
qsrand(time1.msec()*90000000000+time1.second());
enum type{disappear,canmove,islong,normal};
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
    void moveEvent(QMoveEvent*);
signals:
     void deletethis();
};

#endif // MYLABEL_H
