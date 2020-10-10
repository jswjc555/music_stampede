#ifndef MYMUSIC_H
#define MYMUSIC_H

#include"mymovie.h"
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
enum gametype{easy,diff,hp};
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
    bool ispause=0;//判断游戏是否暂停
    gametype type;
    QList<int> sump;//卡点存储
    QFile *f=0;
    QMediaPlayer *player=0;
    int score=0;//分数
    int nn=1;//已经卡点数
    int already=0;//已经过时长
    int tm_label;
    int tm_lcd;
    int tm_left,tm_up,tm_down,tm_right;
    int min,sec;
    int combo=0;//连击
    QTimer sumtime;
    QTimer *dis_gif;
    QTimer left_time;
    QTimer up_time;
    QTimer right_time;
    QTimer down_time;
    QList<MyLabel*>lnum;
    QList<MyLabel*>flnum;

    explicit MyMusic(QWidget *parent,QWidget *w,int music_no,gametype type=easy );
    ~MyMusic();
    int cha(int);
    void start();
    int rand(int a=4, int b=0);
    result check(MyLabel*);
    bool israng(int, int, int);
    int stop_MessageBox(QString title, QString message);
protected:
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
private:
    Ui::MyMusic *ui;
    MyMovie *dis;
    MyMovie *pingjia;
    QMovie *up_dis,*left_dis,*down_dis,*right_dis;
    QImage *gif_quiet=nullptr;
    QImage *left=nullptr,*up=nullptr,*down=nullptr,*right=nullptr;
    QImage *long_key=0 ,*short_key=0,* main_back=0,* bar=0,* mode=0;
    QImage *numm=nullptr,*num=nullptr;
public slots:
    void deleteit();
    void up_quiet();
    void left_quiet();
    void down_quiet();
    void right_quiet();
    void deletemovie(MyMovie*);
signals:
    void gameover(int);
private slots:

    void on_stop_button_clicked();
};



#endif // MYMUSIC_H
