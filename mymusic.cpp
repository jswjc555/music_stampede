#include "mymusic.h"
#include "ui_mymusic.h"
#define cout qDebug() << "{" << __FILE__ << ":" << __LINE__ << "}"


MyMusic::MyMusic(QWidget *parent, QWidget *w) :
    QWidget(parent),w(w),
    ui(new Ui::MyMusic)
{
    ui->setupUi(this);
    for(int i=0;i<50;i++)
    global_i[i][0] = 0;//1代表被消除
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


    ui->perfect_lable->setText(QString::number(0));
    setFixedSize(play_WIDTH,play_HIGH);
    ui->stackedWidget->setFixedSize(play_WIDTH,play_HIGH);
    sumtime.setInterval(sencond*1000);
    ui->lcdNumber->setDigitCount(5);
    ui->lcdNumber->setVisible(false);

    ui->left_gif->setScaledContents(true);
    ui->up_gif->setScaledContents(true);
    ui->down_gif->setScaledContents(true);
    ui->right_gif->setScaledContents(true);
    gif_quiet =new QImage;
    gif_quiet->load(":/image/none.png");
    ui->left_gif->setPixmap(QPixmap::fromImage(*gif_quiet));
    ui->up_gif->setPixmap(QPixmap::fromImage(*gif_quiet));
    ui->down_gif->setPixmap(QPixmap::fromImage(*gif_quiet));
    ui->right_gif->setPixmap(QPixmap::fromImage(*gif_quiet));

    ui->check_label_left->setText("left");
    ui->check_label_left->setStyleSheet("QLabel{background-color:rgb(92,141,128);}");
    ui->check_label_up->setText("up");
    ui->check_label_up->setStyleSheet("QLabel{background-color:rgb(92,141,128);}");
    ui->check_label_down->setText("down");
    ui->check_label_down->setStyleSheet("QLabel{background-color:rgb(92,141,128);}");
    ui->check_label_right->setText("right");
    ui->check_label_right->setStyleSheet("QLabel{background-color:rgb(92,141,128);}");
    QImage *main_back=new QImage; //新建一个image对象
    ui->main_back->setScaledContents(true);//自适应大小
    main_back->load(":/image/main_back.png"); //将图像资源载入对象img，注意路径，可点进图片右键复制路径
    ui->main_back->setPixmap(QPixmap::fromImage(*main_back)); //将图片放入label，使用setPixmap,注意指针*img
    QImage *bar=new QImage;
    ui->bar_label->setScaledContents(true);
    bar->load(":/image/check_bar.png");
    ui->bar_label->setPixmap(QPixmap::fromImage(*bar));





    this->grabKeyboard();
    min=sencond/60;
    sec=sencond%60;
    already=cha(1);
    connect(this,SIGNAL(gameover(int)),w,SLOT(GameOver(int)));
    connect(&sumtime,&QTimer::timeout,this,[&](){
        emit gameover(score);//音乐结束时触发
    });
    connect(this,&MyMusic::destroyed,this,[&](){
        if((min*60+sec)==0) return;
        emit gameover(score);//玩家强行关闭时触发
    });
}

MyMusic::~MyMusic()
{
    if(f->isOpen())
        f->close();
    delete ui;
}

int MyMusic::rand(int a,int b)
{
    RAND
    return qrand()%a+b;
}

result MyMusic::check(MyLabel *y)
{
    int h=ui->bar_label->geometry().y();//槽的顶部y坐标
    if(israng(y->gety()+y->height()/2,h+lable_width/2,y->height()/2))
        return perfect;
    if(israng(y->gety(),h,y->height()))
        return good;
    return bad;
}

bool MyMusic::israng(int n,int a, int b)
{
    return n>=(a-b)&&n<=(a+b);
}

void MyMusic::deleteit()
{
        for(int i=0;i<lnum.size();i++){
            if(lnum.at(i)->isHidden()){
                if(!lnum.at(i)->isclicked)
                    combo=0;//连击清零
                lnum.removeAt(i);
                return;
            }
        }
}

void MyMusic::deletegif_left()
{
    for(int i=0;i<lnum.size();i++)
        if(global_i[i][0] == 1){
            lnum.at(i)->hide();
            lnum.removeAt(i);//消除方块
            global_i[i][0] = 0;
            cout;
        }
    ui->left_gif->setPixmap(QPixmap::fromImage(*gif_quiet));

}

void MyMusic::deletegif_up()
{
    for(int i=0;i<lnum.size();i++)
        if(global_i[i][0] == 1){
            lnum.at(i)->hide();
            lnum.removeAt(i);//消除方块
            global_i[i][0] = 0;
            cout;
        }
    ui->up_gif->setPixmap(QPixmap::fromImage(*gif_quiet));
}

void MyMusic::deletegif_right()
{
    for(int i=0;i<lnum.size();i++)
        if(global_i[i][0] == 1){
            lnum.at(i)->hide();
            lnum.removeAt(i);//消除方块
            global_i[i][0] = 0;
            cout;
        }
     ui->right_gif->setPixmap(QPixmap::fromImage(*gif_quiet));
}

void MyMusic::deletegif_down()
{
    for(int i=0;i<lnum.size();i++)
        if(global_i[i][0] == 1){
            lnum.at(i)->hide();
            lnum.removeAt(i);//消除方块
            global_i[i][0] = 0;
            cout;
        }
    ui->down_gif->setPixmap(QPixmap::fromImage(*gif_quiet));
}

int MyMusic::cha(int i)
{
    return sump[i]-sump[i-1];
}

void MyMusic::start()
{
    ui->lcdNumber->setVisible(true);
    tm_lcd = this->startTimer(1000);
    tm_label = this->startTimer(5);
    ui->lcdNumber->display(QDateTime::currentDateTime().toString(QString::number(min)+":"+QString::number(sec)));//设置LCD
    sumtime.start();
    player->play();
}


void MyMusic::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == tm_lcd){
         ui->lcdNumber->display(QDateTime::currentDateTime().toString(QString::number(min)+":"+QString::number(sec)));
         sec--;
         if(sec < 0){
             sec =59;
             min--;
             if(min < 0)
                 killTimer(tm_lcd);
         }
    }
    else if (event->timerId() == tm_label) {
        int r=sumtime.remainingTime();
        if(r<(sencond-already)*1000+5&&r>(sencond-already)*1000-5)
        {
            int y=rand(15,1);//获得一个1-15的随机数
            nn++;
            already+=cha(nn);
            if(nn>n) return;
            int k= cha(nn);
            if(k>=5){
                MyLabel *p=new MyLabel(this,rand(),normal);//islong
                lnum.append(p);
                if(nn>n) return;
            }
            else{
                for(int j=0;j<4;j++){
                    if(y&(1<<j)){//二进制的方法判断哪些位置应该出现方块
                        MyLabel *p = 0;
                        if(y==1||y==2||y==8||y==4){
                            p=new MyLabel(this,j,normal);//canmove
                        }
                        else
                            if(combo>=10){
                                p=new MyLabel(this,j,normal);//disappear
                            }//连击超过10次生成可消失方块

                            else{
                                  p=new MyLabel(this,j,normal);
                            }
                        lnum.append(p);
                    }
                }
            }
        }
        for(int i=0;i<lnum.size();i++){
            if(global_i[i][0] == 1)
                continue;
            lnum.at(i)->move(lnum.at(i)->position*lable_width,lnum.at(i)->gety()+SPEED);
        }
    }
}

void MyMusic::keyPressEvent(QKeyEvent *event)
{

    result r=bad;
    if(event->key() == Qt::Key_Left){
        ui->check_label_left->setStyleSheet("QLabel{background-color:rgb(183,210,215);}");
        for(int i=0;i<lnum.size();i++){
            if(lnum.at(i)->position==0){
                r=check(lnum.at(i));
                if(r!=bad)
                {
                    combo++;
                    lnum.at(i)->isclicked=1;
                }//增加连击次数
                else combo=0;
                if(lnum.at(i)->mytype!=islong&&(r == perfect||r == good) )
                {
                    if(r == perfect){
                        pingjia = new QMovie(":/image/perfect.gif");
                        ui->left_gif->setMovie(pingjia);
                        pingjia->start();
                    }
                    else if (r == good) {
                        pingjia = new QMovie(":/image/good.gif");
                        ui->left_gif->setMovie(pingjia);
                        pingjia->start();
                    }
                    dis = new QMovie(":/image/dis.gif");
                    lnum.at(i)->setMovie(dis);
                    ui->disappear_gif->setMovie(dis);
                    dis->start();
                    QTimer *pTimer = new QTimer(this);
                    global_i[i][0] = 1;
                    connect(pTimer,SIGNAL(timeout()),this,SLOT(deletegif_left()));
                    pTimer->setSingleShot(true);
                    pTimer->start(600);
//                    lnum.at(i)->hide();
//                    lnum.removeAt(i);//消除方块
                }
                break;
            }
        }
    }
    else if (event->key() == Qt::Key_Up) {
        ui->check_label_up->setStyleSheet("QLabel{background-color:rgb(183,210,215);}");
        for(int i=0;i<lnum.size();i++){
            if(lnum.at(i)->position==1){
                r=check(lnum.at(i));
                if(r!=bad)
                {
                    combo++;
                    lnum.at(i)->isclicked=1;
                }
                else combo=0;
                if(lnum.at(i)->mytype!=islong&&(r == perfect||r == good) )
                {
                    if(r == perfect){
                        pingjia = new QMovie(":/image/perfect.gif");
                        ui->up_gif->setMovie(pingjia);
                        pingjia->start();
                    }
                    else if (r == good) {
                        pingjia = new QMovie(":/image/good.gif");
                        ui->up_gif->setMovie(pingjia);
                        pingjia->start();
                    }
                    dis = new QMovie(":/image/dis.gif");
                    lnum.at(i)->setMovie(dis);
                    ui->disappear_gif->setMovie(dis);
                    dis->start();
                    QTimer *pTimer = new QTimer(this);
                    global_i[i][0] = 1;
                    connect(pTimer,SIGNAL(timeout()),this,SLOT(deletegif_up()));
                    pTimer->setSingleShot(true);
                    pTimer->start(600);
//                    lnum.at(i)->hide();
//                    lnum.removeAt(i);//消除方块
                }
                break;
            }
        }
    }
    else if (event->key() == Qt::Key_Down) {
        ui->check_label_down->setStyleSheet("QLabel{background-color:rgb(183,210,215);}");
        for(int i=0;i<lnum.size();i++){
            if(lnum.at(i)->position==2){
                r=check(lnum.at(i));
                if(r!=bad)
                {
                    combo++;
                    lnum.at(i)->isclicked=1;
                }
                else combo=0;
                if(lnum.at(i)->mytype!=islong&&(r == perfect||r == good) )
                {
                    if(r == perfect){
                        pingjia = new QMovie(":/image/perfect.gif");
                        ui->down_gif->setMovie(pingjia);
                        pingjia->start();
                    }
                    else if (r == good) {
                        pingjia = new QMovie(":/image/good.gif");
                        ui->down_gif->setMovie(pingjia);
                        pingjia->start();
                    }
                    dis = new QMovie(":/image/dis.gif");
                    lnum.at(i)->setMovie(dis);
                    ui->disappear_gif->setMovie(dis);
                    dis->start();
                    QTimer *pTimer = new QTimer(this);
                    global_i[i][0] = 1;
                    connect(pTimer,SIGNAL(timeout()),this,SLOT(deletegif_down()));
                    pTimer->setSingleShot(true);
                    pTimer->start(600);
//                    lnum.at(i)->hide();
//                    lnum.removeAt(i);//消除方块
                }
                break;
            }
        }
    }
    else if (event->key() == Qt::Key_Right) {
        ui->check_label_right->setStyleSheet("QLabel{background-color:rgb(183,210,215);}");
        for(int i=0;i<lnum.size();i++){
            if(lnum.at(i)->position==3){
                r=check(lnum.at(i));
                if(r!=bad)
                {
                    combo++;
                    lnum.at(i)->isclicked=1;
                }
                else combo=0;
                if(lnum.at(i)->mytype!=islong&&(r == perfect||r == good) )
                {
                    if(r == perfect){
                        pingjia = new QMovie(":/image/perfect.gif");
                        ui->right_gif->setMovie(pingjia);
                        pingjia->start();
                    }
                    else if (r == good) {
                        pingjia = new QMovie(":/image/good.gif");
                        ui->right_gif->setMovie(pingjia);
                        pingjia->start();
                    }

                    dis = new QMovie(":/image/dis.gif");
                    lnum.at(i)->setMovie(dis);
                    ui->disappear_gif->setMovie(dis);
                    dis->start();
                    QTimer *pTimer = new QTimer(this);
                    global_i[i][0] = 1;
                    connect(pTimer,SIGNAL(timeout()),this,SLOT(deletegif_right()));
                    pTimer->setSingleShot(true);
                    pTimer->start(600);
//                    lnum.at(i)->hide();
//                    lnum.removeAt(i);//消除方块
                }
                break;
            }
        }
    }
    else return;
    score+=int(r)*100;
    ui->perfect_lable->setText(QString::number(score));
    //Perfect Good Bad 弹出代码
//    QString re;
//    switch (int(r)) {
//    case 0:
//        re="Bad!!!";
//        break;
//    case 1:
//        re="Good!!!";
//        break;
//    default:
//        re="Perfect!!!";
//        break;
//    }
//    if(r==bad)
//    ui->showre->setText(re);
//    else
//        ui->showre->setText(re+QString::number(combo));
//    showtime.start(700);
//    connect(&showtime,&QTimer::timeout,this,[&](){
//        ui->showre->setText("");
//    });
}
void MyMusic::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
         ui->check_label_left->setStyleSheet("QLabel{background-color:rgb(92,141,128);}");
    }
    else if (event->key() == Qt::Key_Up) {
        ui->check_label_up->setStyleSheet("QLabel{background-color:rgb(92,141,128);}");
    }
    else if (event->key() == Qt::Key_Down) {
        ui->check_label_down->setStyleSheet("QLabel{background-color:rgb(92,141,128);}");
    }
    else if (event->key() == Qt::Key_Right) {
        ui->check_label_right->setStyleSheet("QLabel{background-color:rgb(92,141,128);}");
    }
}


