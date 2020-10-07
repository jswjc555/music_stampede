#include "diffmusic.h"
#include "ui_diffmusic.h"


DiffMusic::DiffMusic(QWidget *parent, QWidget *w) :
    QWidget(parent),w(w),
    ui(new Ui::DiffMusic)
{
    ui->setupUi(this);
    path<<":/test.txt"<<"qrc:/lion.mp3";//持续添加
    ui->perfect_lable->setText(QString::number(0));
    setFixedSize(play_WIDTH,play_HIGH);
    ui->stackedWidget->setFixedSize(play_WIDTH,play_HIGH);
    ui->lcdNumber->setDigitCount(5);
    ui->lcdNumber->setVisible(false);
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
    this->grabKeyboard();

    alltime.start(60*60*1000);//一个小时
    connect(this,SIGNAL(gameover(int)),w,SLOT(GameOver(int)));
    connect(&sumtime,&QTimer::timeout,this,[&](){
        start();//切歌
    });
    connect(this,&DiffMusic::destroyed,this,[&](){
        if(ui->HD->value()==0) return;
        emit gameover(min*60+sec);//玩家强行关闭时触发
    });
}

DiffMusic::~DiffMusic()
{
    if(f->isOpen())
        f->close();
    delete ui;
}

int DiffMusic::rand(int a,int b)
{
    RAND
    return qrand()%a+b;
}

result DiffMusic::check(MyLabel *y)
{
    int h=ui->check_label_down->geometry().y();//槽的顶部y坐标
    if(israng(y->gety()+y->height()/2,h+lable_width/2,y->height()/2))
        return perfect;
    if(israng(y->gety(),h,y->height()))
        return good;
    return bad;
}

bool DiffMusic::israng(int n,int a, int b)
{
    return n>=(a-b)&&n<=(a+b);
}

void DiffMusic::deleteit()
{
        for(int i=0;i<lnum.size();i++){
            if(lnum.at(i)->isHidden()){
                if(!lnum.at(i)->isclicked)
                {
                    combo=0;
                    ui->HD->setValue(ui->HD->value()-10);
                }
                lnum.removeAt(i);
                return;
            }
        }
}

int DiffMusic::cha(int i)
{
    return sump[i]-sump[i-1];
}

void DiffMusic::start()
{
    f=new QFile(path[m++],this);
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
    player->setMedia(QUrl(path[m++]));
    player->setVolume(100);
    sencond=sump[n];
    already=cha(1);
    sumtime.setInterval(sencond*1000);

    ui->lcdNumber->setVisible(true);
    tm_lcd = this->startTimer(1000);
    tm_label = this->startTimer(5);
    ui->lcdNumber->display(QDateTime::currentDateTime().toString(QString::number(min)+":"+QString::number(sec)));//设置LCD
    sumtime.start();
    player->play();
}


void DiffMusic::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == tm_lcd){
         ui->lcdNumber->display(QDateTime::currentDateTime().toString(QString::number(min)+":"+QString::number(sec)));
         sec++;
         if(sec > 59){
             sec =0;
             min++;
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
            else{
                for(int j=0;j<4;j++){
                    if(y&(1<<j)){//二进制的方法判断哪些位置应该出现方块
                        MyLabel *p=0;
                        if(y==1||y==2||y==8||y==4)
                            p=new MyLabel(this,j,canmove);
                        else
                            p=new MyLabel(this,j,disappear);
                        lnum.append(p);
                    }
                }
            }
        }
        for(int i=0;i<lnum.size();i++){
            lnum.at(i)->move(lnum.at(i)->position*lable_width,lnum.at(i)->gety()+SPEED);
        }
    }
}

void DiffMusic::keyPressEvent(QKeyEvent *event)
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
                    //增加连击次数
                    if(r==good)
                        ui->HD->setValue(ui->HD->value()+5);
                    else
                        ui->HD->setValue(ui->HD->value()+2);
                }
                else
                {
                    combo=0;
                    ui->HD->setValue(ui->HD->value()-10);
                }
                    lnum.at(i)->hide();
                    lnum.removeAt(i);//消除方块
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
                    //增加连击次数
                    if(r==good)
                        ui->HD->setValue(ui->HD->value()+5);
                    else
                        ui->HD->setValue(ui->HD->value()+2);
                }
                else
                {
                    combo=0;
                    ui->HD->setValue(ui->HD->value()-10);
                }
                    lnum.at(i)->hide();
                    lnum.removeAt(i);//消除方块
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
                    //增加连击次数
                    if(r==good)
                        ui->HD->setValue(ui->HD->value()+5);
                    else
                        ui->HD->setValue(ui->HD->value()+2);
                }
                else
                {
                    combo=0;
                    ui->HD->setValue(ui->HD->value()-10);
                }
                    lnum.at(i)->hide();
                    lnum.removeAt(i);//消除方块
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
                    //增加连击次数
                    if(r==good)
                        ui->HD->setValue(ui->HD->value()+5);
                    else
                        ui->HD->setValue(ui->HD->value()+2);
                }
                else
                {
                    combo=0;
                    ui->HD->setValue(ui->HD->value()-10);
                }
                    lnum.at(i)->hide();
                    lnum.removeAt(i);//消除方块
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
void DiffMusic::keyReleaseEvent(QKeyEvent *event)
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



void DiffMusic::on_HD_valueChanged(int value)
{
    if(value<=0){
        value=0;
        emit gameover(min*60+sec);
    }
}
