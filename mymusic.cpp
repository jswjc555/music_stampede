#include "mymusic.h"
#include "ui_mymusic.h"
#define cout qDebug() << "{" << __FILE__ << ":" << __LINE__ << "}"


MyMusic::MyMusic(QWidget *parent, QWidget *w, int music_no,gametype type) :
    QWidget(parent),w(w),type(type),
    ui(new Ui::MyMusic)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->play_page);
    musicpath<<":/TheCrave.txt"<<"qrc:/TheCrave.mp3"<<":/ori_01.txt"<<"qrc:/ori_01.mp3"<<":/lianaixunhuan.txt"<<"qrc:/lianaixunhuan.mp3";
    for(int i=0;i<50;i++)
    player=new QMediaPlayer(this);
    ui->HP->hide();
    setWindowTitle("Click track");
    if(type==hp){
        f=new QFile(musicpath[index*2],this);
        player->setMedia(QUrl(musicpath[index*2+1]));
        connect(&sumtime,&QTimer::timeout,this,&MyMusic::restart);
    }
    else
    {
        f=new QFile(musicpath[music_no*2],this);
        player->setMedia(QUrl(musicpath[music_no*2+1]));
        connect(&sumtime,&QTimer::timeout,this,[&](){
            emit gameover(score);//音乐结束时触发
        });
    }
    if(!f->open(QIODevice::ReadOnly)){return;}
    int i=0;
    QString file=QString(f->readAll().data());
    while (1) {
        QString s=file.section("\n",i,i);
        if(s=="") {n=i-1;break;}
        sump.append(s.toInt());
        i++;
    }
    sencond=sump[n]/200;
    player->setVolume(100);
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
    ui->down_cover->setScaledContents(true);
    ui->up_dis->setScaledContents(true);
    ui->left_dis->setScaledContents(true);
    ui->right_dis->setScaledContents(true);
    ui->down_dis->setScaledContents(true);
    ui->check_label_left->setScaledContents(true);
    ui->check_label_up->setScaledContents(true);
    ui->check_label_down->setScaledContents(true);
    ui->check_label_right->setScaledContents(true);

    num = new QImage;
    ui->cheng_label->setScaledContents(true);
    ui->combo_left->setScaledContents(true);
    ui->combo_right->setScaledContents(true);
    num->load(":/image/cheng.png");
    ui->cheng_label->setPixmap(QPixmap::fromImage(*num));
    num->load(":/image/0.png");
    ui->combo_left->setPixmap(QPixmap::fromImage(*num));
    ui->combo_right->setPixmap(QPixmap::fromImage(*num));



    ui->menlian_label->setScaledContents(true);
    menlian = new QMovie(":/image/menlian.gif");
    ui->menlian_label->setMovie(menlian);
    menlian->start();
    gif_quiet =new QImage;
    gif_quiet->load(":/image/none.png");
    ui->left_gif->setPixmap(QPixmap::fromImage(*gif_quiet));
    ui->up_gif->setPixmap(QPixmap::fromImage(*gif_quiet));
    ui->down_gif->setPixmap(QPixmap::fromImage(*gif_quiet));
    ui->right_gif->setPixmap(QPixmap::fromImage(*gif_quiet));
    up = new QImage;
    up->load(":/image/an_up.png");
    left = new QImage;
    left->load(":/image/an_left.png");
    right = new QImage;
    right->load(":/image/an_right.png");
    down = new QImage;
    down->load(":/image/an_down.png");


    long_key = new QImage;
    long_key->load(":/image/long_key.png");
    ui->down_cover->setPixmap(QPixmap::fromImage(*long_key));
    ui->down_cover->raise();
    ui->check_label_right->raise();
    ui->check_label_down->raise();
    ui->check_label_left->raise();
    ui->check_label_up->raise();

    short_key = new QImage;
    short_key->load(":/image/short_key.png");
    ui->check_label_left->setPixmap(QPixmap::fromImage(*short_key));
    ui->check_label_up->setPixmap(QPixmap::fromImage(*short_key));
    ui->check_label_down->setPixmap(QPixmap::fromImage(*short_key));
    ui->check_label_right->setPixmap(QPixmap::fromImage(*short_key));
    ui->check_label_left->setVisible(false);
    ui->check_label_up->setVisible(false);
    ui->check_label_down->setVisible(false);
    ui->check_label_right->setVisible(false);
    ui->stop_button->setStyleSheet("QPushButton{border-image: url(:/image/stop.png)}");

    main_back=new QImage; //新建一个image对象
    ui->main_back->setScaledContents(true);
    main_back->load(":/image/main_back.png");
    ui->main_back->setPixmap(QPixmap::fromImage(*main_back));
    bar=new QImage;
    ui->bar_label->setScaledContents(true);
    bar->load(":/image/check_bar.png");
    ui->bar_label->setPixmap(QPixmap::fromImage(*bar));
    mode = new QImage;
    ui->pattern_label->setScaledContents(true);
    ui->right_right_label->setScaledContents(true);
    right_right = new QImage;
    if(type == diff)
    {
        right_right->load(":/image/right_right.png");
        mode->load(":/image/hard_mode.png");
        min=sencond/60;
        sec=sencond%60;
    }
    else if(type == easy)
    {
        right_right->load(":/image/right_right.png");
         mode->load(":/image/normal_mode.png");
         min=sencond/60;
         sec=sencond%60;
    }
    else if (type == hp) {
        mode->load(":/image/hp_mode.png");
        right_right->load(":/image/right_right_hp.png");
       ui->HP->show();
       ui->perfect_lable->setVisible(false);
       ui->HP->raise();
    }
    ui->lcdNumber->raise();
    ui->cheng_label->raise();
    ui->combo_left->raise();
    ui->combo_right->raise();
    ui->perfect_lable->raise();
    ui->pattern_label->raise();
    ui->stop_button->raise();

    ui->right_right_label->setPixmap(QPixmap::fromImage(*right_right));
    ui->pattern_label->setPixmap(QPixmap::fromImage(*mode));
    connect(this,SIGNAL(back_to()),w,SLOT(to_me()));
    this->grabKeyboard();
    already=cha(1);
    connect(this,SIGNAL(gameover(int)),w,SLOT(GameOver(int)));
    f->close();
}

MyMusic::~MyMusic()
{
    if(f->isOpen())
        f->close();
    if(num!=nullptr) delete num;
    if(numm!=nullptr) delete numm;
    if(gif_quiet!=nullptr) delete gif_quiet;
    if(left!=nullptr) delete left;
    if(up!=nullptr) delete up;
    if(down!=nullptr) delete down;
    if(right!=nullptr) delete right;
    if(long_key!=0) delete long_key;
    if(short_key!=0) delete short_key;
    if(main_back!=0) delete main_back;
    if(bar!=0) delete bar;
    if(mode!=0) delete mode;
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
    if(israng(y->gety()+y->height()/2,h+lable_width/2,y->height()/4))
        return perfect;
    if(israng(y->gety(),h,y->height()/2))
        return good;
    return bad;
}

bool MyMusic::israng(int n,int a, int b)
{
    return n>=(a-b)&&n<=(a+b);
}

int MyMusic::stop_MessageBox(QString title, QString message)
{
    QMessageBox mymessage(QMessageBox::Information, title, message);
    QPushButton *btnYes = mymessage.addButton(("继续"), QMessageBox::YesRole);
    mymessage.resize(400,500);
    mymessage.exec();
    if ((QPushButton*)mymessage.clickedButton() == btnYes)
            return 0;
    return 0;
}

void MyMusic::closeEvent(QCloseEvent *event)
{
    if(ui->stackedWidget->currentIndex()==1){
        exit(0);
    }
    else
    {
        player->stop();
        killTimer(tm_label);
        killTimer(tm_lcd);
        while(lnum.size()){
            lnum.at(0)->hide();
            delete lnum[0];
            lnum[0]=nullptr;
            lnum.removeAt(0);
        }
        while(flnum.size()){
            flnum.at(0)->hide();
            delete flnum[0];
            flnum[0]=nullptr;
            flnum.removeAt(0);
        }
        ui->stackedWidget->setCurrentWidget(ui->end_page);
        if(type==hp)
            ui->end_label->setText("时长：\n"+QString("%1:%2").arg(min,2,10,QLatin1Char( '0' )).arg(sec,2,10,QLatin1Char( '0' )));
        else
            ui->end_label->setText("分数：\n"+QString::number(score));
        event->ignore();
    }
}

void MyMusic::deleteit()
{
        for(int i=0;i<lnum.size();i++){
            if(lnum.at(i)->isHidden()){
                if(!lnum.at(i)->isclicked)
                    combo=0;//连击清零
                delete lnum[i];
                lnum[i]=nullptr;
                lnum.removeAt(i);
                hpvalue-=10;
                break;
            }
        }
//        ui->HP->setValue(ui->HP->value()-10);
}

void MyMusic::up_quiet()
{
    ui->up_dis->setPixmap(QPixmap::fromImage(*gif_quiet));
}

void MyMusic::left_quiet()
{
    ui->left_dis->setPixmap(QPixmap::fromImage(*gif_quiet));
}

void MyMusic::down_quiet()
{
    ui->down_dis->setPixmap(QPixmap::fromImage(*gif_quiet));
}

void MyMusic::right_quiet()
{
    ui->right_dis->setPixmap(QPixmap::fromImage(*gif_quiet));
}

void MyMusic::deletemovie(MyMovie *m)
{
    delete m;
    m=nullptr;
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
    if(ispause) return;
    if(isrestart){
        sumtime.start(sencond*1000);
        player->play();
        isrestart=0;
    }
    if(event->timerId() == tm_lcd){
        if(type==hp){
            ui->lcdNumber->display(QString("%1:%2").arg(min,2,10,QLatin1Char( '0' )).arg(sec,2,10,QLatin1Char( '0' )));
            sec++;
            if(sec > 59){
                sec =0;
                min++;
            }
        }
        else{
            ui->lcdNumber->display(QString("%1:%2").arg(min,2,10,QLatin1Char( '0' )).arg(sec,2,10,QLatin1Char( '0' )));
            sec--;
            if(sec < 0){
                sec =59;
                min--;
                if(min < 0)
                {
                    killTimer(tm_lcd);
                    ui->stackedWidget->setCurrentWidget(ui->end_page);
                }

            }
        }
    }
    else if (event->timerId() == tm_label) {
        if(type==hp)
               {
                   if(hpvalue<0) ui->HP->setValue(0);
                   else if(hpvalue>100) ui->HP->setValue(100);
                   else ui->HP->setValue(hpvalue);
               }
        if(type==hp&&ui->HP->value()<=0)
        {
            player->stop();
            killTimer(tm_label);
            killTimer(tm_lcd);
            while(lnum.size()){
                lnum.at(0)->hide();
                delete lnum[0];
                lnum[0]=nullptr;
                lnum.removeAt(0);
            }
            while(flnum.size()){
                flnum.at(0)->hide();
                delete flnum[0];
                flnum[0]=nullptr;
                flnum.removeAt(0);
            }
            QMessageBox::information(NULL,"游戏结束","血量为零！！！");
            ui->stackedWidget->setCurrentWidget(ui->end_page);
            if(type==hp)
                ui->end_label->setText("时长：\n"+QString("%1:%2").arg(min,2,10,QLatin1Char( '0' )).arg(sec,2,10,QLatin1Char( '0' )));
            else
                ui->end_label->setText("分数：\n"+QString::number(score));
            return;
        }
        int r=sumtime.remainingTime();
        if(r<(sump[n]-sump[nn])*5+5&&r>(sump[n]-sump[nn])*5-5)
        {
            int y=rand(24,1);//获得一个1-15的随机数
            nn++;
            already+=cha(nn);
            if(nn>n) return;
            else{
                if(type==easy)
                {
                    for(int j=0;j<4;j++){
                        if(y&(1<<j)){//二进制的方法判断哪些位置应该出现方块
                            MyLabel *p =new MyLabel(this,j,normal);
                            lnum.append(p);
                        }
                    }
                }
                else
                {
                    MyLabel *p=0;
                    if(y>=1 && y<=3){    //0
                        if(combo>=10)//连击超过10次生成可消失方块
                            p=new MyLabel(this,0,disappear);
                        else
                            p=new MyLabel(this,0,normal);
                        lnum.append(p);
                    }
                    if(y>=4 && y<=6){    //1
                        if(combo>=10)//连击超过10次生成可消失方块
                            p=new MyLabel(this,1,disappear);
                        else
                            p=new MyLabel(this,1,normal);
                        lnum.append(p);
                    }
                    if(y>=7 && y<=9){    //2
                        if(combo>=10)//连击超过10次生成可消失方块
                            p=new MyLabel(this,2,disappear);
                        else
                            p=new MyLabel(this,2,normal);
                        lnum.append(p);
                    }
                    if(y>=10 && y<=12){  //3
                        if(combo>=10)//连击超过10次生成可消失方块
                            p=new MyLabel(this,3,disappear);
                        else
                            p=new MyLabel(this,3,normal);
                        lnum.append(p);
                    }
                    if(y>=13 && y<=14){  //0.1
                        if(combo>=10)//连击超过10次生成可消失方块
                        {p=new MyLabel(this,0,disappear);
                            lnum.append(p);
                            p=new MyLabel(this,1,disappear);}
                        else
                        {p=new MyLabel(this,0,normal);
                            lnum.append(p);
                            p=new MyLabel(this,1,normal);}
                        lnum.append(p);
                    }
                    if(y>=15 && y<=16){  //0.2
                        if(combo>=10)//连击超过10次生成可消失方块
                        {p=new MyLabel(this,0,disappear);
                            lnum.append(p);
                            p=new MyLabel(this,2,disappear);}
                        else
                        {p=new MyLabel(this,0,normal);
                            lnum.append(p);
                            p=new MyLabel(this,2,normal);}
                        lnum.append(p);
                    }
                    if(y>=17 && y<=18){  //0.3
                        if(combo>=10)//连击超过10次生成可消失方块
                        {p=new MyLabel(this,0,disappear);
                            lnum.append(p);
                            p=new MyLabel(this,3,disappear);}
                        else
                        {p=new MyLabel(this,0,normal);
                            lnum.append(p);
                            p=new MyLabel(this,3,normal);}
                        lnum.append(p);
                    }
                    if(y>=19 && y<=20){  //1.2
                        if(combo>=10)//连击超过10次生成可消失方块
                        {p=new MyLabel(this,2,disappear);
                            lnum.append(p);
                            p=new MyLabel(this,1,disappear);}
                        else
                        {p=new MyLabel(this,2,normal);
                            lnum.append(p);
                            p=new MyLabel(this,1,normal);}
                        lnum.append(p);
                    }
                    if(y>=21 && y<=22){  //1.3
                        if(combo>=10)//连击超过10次生成可消失方块
                        {p=new MyLabel(this,3,disappear);
                            lnum.append(p);
                            p=new MyLabel(this,1,disappear);}
                        else
                        {p=new MyLabel(this,1,normal);
                            lnum.append(p);
                            p=new MyLabel(this,3,normal);}
                        lnum.append(p);
                    }
                    if(y>=23 && y<=24){  //2.3
                        if(combo>=10)//连击超过10次生成可消失方块
                        {p=new MyLabel(this,2,disappear);
                            lnum.append(p);
                            p=new MyLabel(this,3,disappear);}
                        else
                        {p=new MyLabel(this,2,normal);
                            lnum.append(p);
                            p=new MyLabel(this,3,normal);}
                        lnum.append(p);
                    }
                }
            }
            }
        else if((r%5000)<=5){
        if(type!=easy)
        {
            if(combo>=5)
            {
                int nnn=0;
                int y=rand(15,1);//获得一个1-15的随机数
                for(int j=0;j<4;j++){
                    if(y&(1<<j)){//二进制的方法判断哪些位置应该出现方块
                        nnn++;
                        if(nnn>2) break;
                        MyLabel*p=new MyLabel(this,j,isfalse);
                        flnum.append(p);
                    }
                }
            }
        }
    }
    for(int i=0;i<lnum.size();i++){
        if(!lnum.at(i)->isclicked)
        lnum.at(i)->move(lnum.at(i)->position*lable_width,lnum.at(i)->gety()+lnum.at(i)->speed);
    }
    for(int i=0;i<flnum.size();i++){
        if(!flnum.at(i)->isclicked)
        flnum.at(i)->move(flnum.at(i)->position*lable_width,flnum.at(i)->gety()+flnum.at(i)->speed);
    }

    }

}

void MyMusic::keyPressEvent(QKeyEvent *event)
{

    result r=bad;
    if(event->key()==Qt::Key_Escape){
        on_stop_button_clicked();
    }
    else if(event->key() == Qt::Key_Left){
        ui->check_label_left->setVisible(true);
        ui->left_dis->setPixmap(QPixmap::fromImage(*left));
        for(int i=0;i<lnum.size();i++){
            if(lnum.at(i)->position==0){
                if(lnum.at(i)->isclicked) return;
                r=check(lnum.at(i));
                if(r!=bad)
                {
                    combo++;
                    lnum.at(i)->isclicked=1;
                }//增加连击次数
                else combo=0;
                if(r!=bad )
                {
                    if(r == perfect){
                        pingjia = new MyMovie(":/image/perfect.gif",QByteArray(),this);
                        ui->left_gif->setMovie(pingjia);
                        pingjia->start();
                    }
                    else if (r == good) {
                        pingjia = new MyMovie(":/image/good.gif",QByteArray(),this);
                        ui->left_gif->setMovie(pingjia);
                        pingjia->start();
                    }
                    dis = new MyMovie(":/image/dis.gif",QByteArray(),this);
                    lnum.at(i)->setMovie(dis);
                    dis->start();
                    left_time.start(200);
                    connect(&left_time,&QTimer::timeout,this,[&](){
                        for(int i=0;i<lnum.size();i++)
                            if(lnum.at(i)->position==0)
                            {
                                if(lnum.at(i)->isclicked){
                                    lnum.at(i)->hide();
                                    delete lnum[i];
                                    lnum[i]=nullptr;
                                    lnum.removeAt(i);//消除方块
                                    ui->left_gif->setPixmap(QPixmap::fromImage(*gif_quiet));
                                    break;
                                }
                            }
                    });
                }
                break;
            }
        }
    }
    else if (event->key() == Qt::Key_Up) {
        ui->check_label_up->setVisible(true);
        ui->up_dis->setPixmap(QPixmap::fromImage(*up));
        for(int i=0;i<lnum.size();i++){
            if(lnum.at(i)->position==1){
                if(lnum.at(i)->isclicked) return;
                r=check(lnum.at(i));
                if(r!=bad)
                {
                    combo++;
                    lnum.at(i)->isclicked=1;
                }
                else combo=0;
                if(r!=bad )
                {

                    if(r == perfect){
                        pingjia = new MyMovie(":/image/perfect.gif",QByteArray(),this);
                        ui->up_gif->setMovie(pingjia);
                        pingjia->start();
                    }
                    else if (r == good) {
                        pingjia = new MyMovie(":/image/good.gif",QByteArray(),this);
                        ui->up_gif->setMovie(pingjia);
                        pingjia->start();
                    }
                    dis = new MyMovie(":/image/dis.gif",QByteArray(),this);
                    lnum.at(i)->setMovie(dis);
                    dis->start();
                    up_time.start(200);
                    connect(&up_time,&QTimer::timeout,this,[&](){
                        for(int i=0;i<lnum.size();i++)
                        {
                            if(lnum.at(i)->position==1)
                            {
                                if(lnum.at(i)->isclicked){
                                    lnum.at(i)->hide();
                                    delete lnum[i];
                                    lnum[i]=nullptr;
                                    lnum.removeAt(i);//消除方块
                                    ui->up_gif->setPixmap(QPixmap::fromImage(*gif_quiet));
                                    break;
                                }
                            }
                        }
                    });
                }
                break;
            }
        }
    }
    else if (event->key() == Qt::Key_Down) {
        ui->check_label_down->setVisible(true);
        ui->down_dis->setPixmap(QPixmap::fromImage(*down));
        for(int i=0;i<lnum.size();i++){
            if(lnum.at(i)->position==2){
                if(lnum.at(i)->isclicked) return;
                r=check(lnum.at(i));
                if(r!=bad)
                {
                    combo++;
                    lnum.at(i)->isclicked=1;
                }
                else combo=0;
                if(r!=bad )
                {
                    if(r == perfect){
                        pingjia = new MyMovie(":/image/perfect.gif",QByteArray(),this);
                        ui->down_gif->setMovie(pingjia);
                        pingjia->start();
                    }
                    else if (r == good) {
                        pingjia = new MyMovie(":/image/good.gif",QByteArray(),this);
                        ui->down_gif->setMovie(pingjia);
                        pingjia->start();
                    }
                    dis = new MyMovie(":/image/dis.gif",QByteArray(),this);
                    lnum.at(i)->setMovie(dis);
                    dis->start();
                    down_time.start(200);
                    connect(&down_time,&QTimer::timeout,this,[&](){
                        for(int i=0;i<lnum.size();i++)
                            if(lnum.at(i)->position==2)
                            {
                                if(lnum.at(i)->isclicked){
                                    lnum.at(i)->hide();
                                    delete lnum[i];
                                    lnum[i]=nullptr;
                                    lnum.removeAt(i);//消除方块
                                    ui->down_gif->setPixmap(QPixmap::fromImage(*gif_quiet));
                                    break;
                                }
                            }
                    });
                }
                break;
            }
        }
    }
    else if (event->key() == Qt::Key_Right) {
       ui->check_label_right->setVisible(true);
       ui->right_dis->setPixmap(QPixmap::fromImage(*right));
        for(int i=0;i<lnum.size();i++){
            if(lnum.at(i)->position==3){
                if(lnum.at(i)->isclicked) return;
                r=check(lnum.at(i));
                if(r!=bad)
                {
                    combo++;
                    lnum.at(i)->isclicked=1;
                }
                else combo=0;
                if(r!=bad )
                {
                    if(r == perfect){
                        pingjia = new MyMovie(":/image/perfect.gif",QByteArray(),this);
                        ui->right_gif->setMovie(pingjia);
                        pingjia->start();
                    }
                    else if (r == good) {
                        pingjia = new MyMovie(":/image/good.gif",QByteArray(),this);
                        ui->right_gif->setMovie(pingjia);
                        pingjia->start();
                    }

                    dis = new MyMovie(":/image/dis.gif",QByteArray(),this);
                    lnum.at(i)->setMovie(dis);
                    dis->start();
                    right_time.start(200);
                    connect(&right_time,&QTimer::timeout,this,[&](){
                        for(int i=0;i<lnum.size();i++)
                            if(lnum.at(i)->position==3)
                            {
                                if(lnum.at(i)->isclicked){
                                    lnum.at(i)->hide();
                                    delete lnum[i];
                                    lnum[i]=nullptr;
                                    lnum.removeAt(i);//消除方块
                                    ui->right_gif->setPixmap(QPixmap::fromImage(*gif_quiet));
                                    break;
                                }
                            }
                    });
                }
                break;
            }
        }
    }
    else return;
    score+=int(r)*100;
    if(type==hp){
            if(r==bad){
                hpvalue-=10;
                if(hpvalue<0) hpvalue=0;
            }
            else if(r==good){
                hpvalue+=2;
                if(hpvalue>100) hpvalue=100;
            }
            else if(r==perfect){
                hpvalue+=5;
                if(hpvalue>100) hpvalue=100;
            }
        }
    ui->perfect_lable->setText(QString::number(score));
    numm = new QImage;
    if (combo == 0){
        numm->load(":/image/0.png");
        ui->combo_left->setPixmap(QPixmap::fromImage(*numm));;
        ui->combo_right->setPixmap(QPixmap::fromImage(*numm));
    }
   else{
        int right = combo%10;
        int left  = (combo-(combo%10))/10;
        switch (right) {
        case 0:{
            numm->load(":/image/0.png");
            ui->combo_right->setPixmap(QPixmap::fromImage(*numm));
            break;
        }
            case 1:{
                numm->load(":/image/1.png");
                ui->combo_right->setPixmap(QPixmap::fromImage(*numm));
                break;
            }
        case 2:{
            numm->load(":/image/2.png");
            ui->combo_right->setPixmap(QPixmap::fromImage(*numm));
            break;
        }
        case 3:{
            numm->load(":/image/3.png");
            ui->combo_right->setPixmap(QPixmap::fromImage(*numm));
            break;
        }
        case 4:{
            numm->load(":/image/4.png");
            ui->combo_right->setPixmap(QPixmap::fromImage(*numm));
            break;
        }
        case 5:{
            numm->load(":/image/5.png");
            ui->combo_right->setPixmap(QPixmap::fromImage(*numm));
            break;
        }
        case 6:{
            numm->load(":/image/6.png");
            ui->combo_right->setPixmap(QPixmap::fromImage(*numm));
            break;
        }
        case 7:{
            numm->load(":/image/7.png");
            ui->combo_right->setPixmap(QPixmap::fromImage(*numm));
            break;
        }
        case 8:{
            numm->load(":/image/8.png");
            ui->combo_right->setPixmap(QPixmap::fromImage(*numm));
            break;
        }
        case 9:{
            numm->load(":/image/9.png");
            ui->combo_right->setPixmap(QPixmap::fromImage(*numm));
            break;
        }
        }
        switch (left) {
            case 1:{
                numm->load(":/image/1.png");
                ui->combo_left->setPixmap(QPixmap::fromImage(*numm));
                break;
            }
        case 2:{
            numm->load(":/image/2.png");
            ui->combo_left->setPixmap(QPixmap::fromImage(*numm));
            break;
        }
        case 3:{
            numm->load(":/image/3.png");
            ui->combo_left->setPixmap(QPixmap::fromImage(*numm));
            break;
        }
        case 4:{
            numm->load(":/image/4.png");
            ui->combo_left->setPixmap(QPixmap::fromImage(*numm));
            break;
        }
        case 5:{
            numm->load(":/image/5.png");
            ui->combo_left->setPixmap(QPixmap::fromImage(*numm));
            break;
        }
        case 6:{
            numm->load(":/image/6.png");
            ui->combo_left->setPixmap(QPixmap::fromImage(*numm));
            break;
        }
        case 7:{
            numm->load(":/image/7.png");
            ui->combo_left->setPixmap(QPixmap::fromImage(*numm));
            break;
        }
        case 8:{
            numm->load(":/image/8.png");
            ui->combo_left->setPixmap(QPixmap::fromImage(*numm));
            break;
        }
        case 9:{
            numm->load(":/image/9.png");
            ui->combo_left->setPixmap(QPixmap::fromImage(*numm));
            break;
        }
        }
    }



}
void MyMusic::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        ui->check_label_left->setVisible(false);
        ui->left_dis->setPixmap(QPixmap::fromImage(*gif_quiet));

    }
    else if (event->key() == Qt::Key_Up) {
        ui->check_label_up->setVisible(false);
        ui->up_dis->setPixmap(QPixmap::fromImage(*gif_quiet));

    }
    else if (event->key() == Qt::Key_Down) {
        ui->check_label_down->setVisible(false);
        ui->down_dis->setPixmap(QPixmap::fromImage(*gif_quiet));
    }
    else if (event->key() == Qt::Key_Right) {
        ui->check_label_right->setVisible(false);
        ui->right_dis->setPixmap(QPixmap::fromImage(*gif_quiet));
    }
}


void MyMusic::on_stop_button_clicked()
{
    player->stop();
    ispause=1;
    qDebug()<<this->children().size();
    int re=sumtime.remainingTime();
    sumtime.stop();
    QString str;
    str += "当前连击数combo: " + QString::number(combo) + "\n" + "当前分数: " + QString::number(score) +"\n休息一下，再接再厉吧！";
    int a =stop_MessageBox("暂停",str);
    if(a == 0){
        player->play();
        sumtime.start(re);
        ispause=0;
    }
}

void MyMusic::on_end_close_clicked()
{
    exit(0);
}

void MyMusic::on_to_main_clicked()
{
    emit back_to();
}
void MyMusic::restart()
{
                index++;
                nn=0;combo=0;
                if(index>3){
                ispause=1;
                    while(lnum.size()){
                        lnum.at(0)->hide();
                        delete lnum[0];
                        lnum[0]=nullptr;
                        lnum.removeAt(0);
                    }
                    while(flnum.size()){
                        flnum.at(0)->hide();
                        delete flnum[0];
                        flnum[0]=nullptr;
                        flnum.removeAt(0);
                    }
                    ui->stackedWidget->setCurrentWidget(ui->end_page);
                }
                else
                {
                    ispause=1;
                    while(lnum.size()){
                        lnum.at(0)->hide();
                        delete lnum[0];
                        lnum[0]=nullptr;
                        lnum.removeAt(0);
                    }
                    while(flnum.size()){
                        flnum.at(0)->hide();
                        delete flnum[0];
                        flnum[0]=nullptr;
                        flnum.removeAt(0);
                    }
                    sump.clear();
                    ui->stackedWidget->setCurrentWidget(ui->qiege_page);
                    dianbo=new QMovie(":/image/qg.gif",QByteArray(),this);
                    ui->dianbo->setScaledContents(true);
                    ui->dianbo->setMovie(dianbo);
                    delete f;
                    f=new QFile(musicpath[index*2],this);
                    player->setMedia(QUrl(musicpath[index*2+1]));
                    if(!f->open(QIODevice::ReadOnly)){return;}
                    int i=0;
                    QString file=QString(f->readAll().data());
                    while (1) {
                        QString s=file.section("\n",i,i);
                        if(s=="") {n=i-1;qDebug()<<n;break;}
                        sump.append(s.toInt());
                        i++;
                    }
                    sencond=sump[n]/200;
                    qDebug()<<sencond;
                    f->close();
                    j.start(2000);
                    connect(&j,&QTimer::timeout,this,[&](){
                        ispause=0;
                        j.stop();
                        ui->stackedWidget->setCurrentWidget(ui->play_page);
                        isrestart=1;
                    });
                    dianbo->start();
                }
}



