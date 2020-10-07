#ifndef MYMUSIC_H
#define MYMUSIC_H

#include"mylabel.h"
#include <QObject>
#include <QWidget>
#include<QMediaPlayer>
#include <QFile>
#include<QTime>
#include <QTimer>
#include <QKeyEvent>
#include <QDateTime>
#include<QPointer>
#include<QMessageBox>
#include <QMovie>


#define play_WIDTH 850
#define play_HIGH  800

namespace Ui {
class MyMusic;
}

class MyMusic : public QWidget
{
    Q_OBJECT
public:
    QWidget *w=0;
    int sencond;//总时长
    int n=0;//总卡点数
    QList<int> sump;//卡点存储
    QFile *f=0;
    QMediaPlayer *player=0;
    int score=0;//分数
    int nn=1;//已经卡点数
    int already=0;//已经过时长
    int tm_label;
    int tm_lcd;
    int min,sec;
    int combo=0;//连击
    QTimer sumtime;
    QTimer *dis_gif;
//    QTimer showtime;//perfect good bad 弹窗展示时间
    QList<MyLabel*>lnum;
    int global_i[50][1];//全局i，用于判断消失的砖块的传参

    explicit MyMusic(QWidget *parent,QWidget *w);
    ~MyMusic();
    int cha(int);
    void start();
    int rand(int a=4, int b=0);
    result check(MyLabel*);
    bool israng(int, int, int);
protected:
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
private:
    Ui::MyMusic *ui;
    QMovie *dis;
    QMovie *pingjia;
    QMovie *up_dis,*left_dis,*down_dis,*right_dis;
    QImage *gif_quiet;
public slots:
    void deleteit();
    void deletegif_left();
    void deletegif_up();
    void deletegif_right();
    void deletegif_down();
    void up_quiet();
    void left_quiet();
    void down_quiet();
    void right_quiet();

signals:
    void gameover(int);
private slots:

};



#endif // MYMUSIC_H
