#ifndef DIFFMUSIC_H
#define DIFFMUSIC_H

#include"mylabel.h"
#include <QObject>
#include <QWidget>
#include<QMediaPlayer>
#include <QFile>
#include<QTime>
#include <QKeyEvent>
#include <QDateTime>
#include<QPointer>
#include<QMessageBox>

#define play_WIDTH 850
#define play_HIGH  800



namespace Ui {
class DiffMusic;
}

class DiffMusic : public QWidget
{
    Q_OBJECT
public:
    QWidget *w=0;
    QList<int> sump;//卡点存储
    QFile *f=0;
    QMediaPlayer*player=0;
    QStringList path;
    int score=0;//分数
    int nn=1;//已经卡点数
    int already=0;//已经过时长
    int tm_label;
    int tm_lcd;
    int min=0,sec=0;
    int combo=0;//连击
    int sencond;//总时长
    int n=0;//总卡点数
    int m=0;//音乐代号
    QTimer sumtime;
    QTimer alltime;//总时长
//    QTimer showtime;//perfect good bad 弹窗展示时间
    QList<MyLabel*>lnum;

    explicit DiffMusic(QWidget *parent,QWidget *w);
    ~DiffMusic();
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
    Ui::DiffMusic *ui;
public slots:
    void deleteit();
signals:
    void gameover(int);
private slots:

    void on_HD_valueChanged(int value);
};


#endif // DIFFMUSIC_H
