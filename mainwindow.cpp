#include "mainwindow.h"
#include "ui_mainwindow.h"
#define cout qDebug() << "{" << __FILE__ << ":" << __LINE__ << "}"
#define width 800
#define high  1000
#define margin 100
#define jiange 1000
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    music=new Musicown(this);
    ui->perfect_lable->setText(QString::number(0));
    sumtime.setInterval(music->sencond*1000);


//    connect(&sumtime,&QTimer::timeout,this,[&](){
//        QMessageBox::information(NULL,"游戏结束","时间到");
//        ui->stackedWidget->setCurrentWidget(ui->start_page);
//        this->deleteLater();
//    });
    ui->start_game->raise();
    ui->movie_lable->setScaledContents(true);//封面背景自适应
    QMovie *background = new QMovie(":/background.gif");//添加背景
    ui->movie_lable->setMovie(background);
    background->start();
    ui->start_game->setStyleSheet("QPushButton{border-image: url(:/start.png)}"
                                 "QPushButton:hover{border-image: url(:/start_on.png)}");
    ui->exit_game->setStyleSheet("QPushButton{border-image: url(:/exit.png)}"
                                 "QPushButton:hover{border-image: url(:/exit_on.png)}");



    this->resize(width,high+100);
    ui->centralWidget->resize(width,high);
    ui->stackedWidget->resize(width,high);
    ui->stackedWidget->setCurrentWidget(ui->start_page);
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
    this->grabKeyboard();
    min=music->sencond/60;
    sec=music->sencond%60;
    already=music->cha(1);
}

int MainWindow::rand(int a,int b)
{
    RAND
    return qrand()%a+b;
}

result MainWindow::check(MyLabel *y)
{
    if(israng(y->gety()+y->height()/2,950,y->height()/2))
        return perfect;
    if(israng(y->gety(),900,y->height()))
        return good;
    return bad;
}

bool MainWindow::israng(int n,int a, int b)
{
    return n>=(a-b)&&n<=(a+b);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_game_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_page);
    ui->lcdNumber->setVisible(true);
    tm_lcd = this->startTimer(1000);
    tm_label = this->startTimer(5);
    ui->lcdNumber->display(QDateTime::currentDateTime().toString(QString::number(min)+":"+QString::number(sec)));//设置LCD
    sumtime.start();
    music->player->play();
}

void MainWindow::deleteit()
{
    for(int i=0;i<lnum.size();i++){
        if(lnum.at(i)->isHidden()){
            lnum.removeAt(i);
            return;
        }
    }
}



void MainWindow::timerEvent(QTimerEvent *event)
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
        if(r<(music->sencond-already)*1000+5&&r>(music->sencond-already)*1000-5)
        {
            int y=rand(15,1);//获得一个1-15的随机数
            nn++;
            already+=music->cha(nn);
            if(nn>music->n) return;
            int k=music->cha(nn);
            if(k>=5){
                MyLabel *p=new MyLabel(this,rand(),islong);
                lnum.append(p);
                if(nn>music->n) return;
            }
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

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    result r=bad;
    if(event->key() == Qt::Key_Left){
        ui->check_label_left->setStyleSheet("QLabel{background-color:rgb(183,210,215);}");
        if(lnum.isEmpty()) return;
        if(lnum.constFirst()->position==0)
         r=check(lnum.constFirst());
    }
    else if (event->key() == Qt::Key_Up) {
        ui->check_label_up->setStyleSheet("QLabel{background-color:rgb(183,210,215);}");
            if(lnum.isEmpty()) return;
        if(lnum.constFirst()->position==1)
         r=check(lnum.constFirst());
    }
    else if (event->key() == Qt::Key_Down) {
        ui->check_label_down->setStyleSheet("QLabel{background-color:rgb(183,210,215);}");
            if(lnum.isEmpty()) return;
        if(lnum.constFirst()->position==2)
         r=check(lnum.constFirst());
    }
    else if (event->key() == Qt::Key_Right) {
        ui->check_label_right->setStyleSheet("QLabel{background-color:rgb(183,210,215);}");
            if(lnum.isEmpty()) return;
        if(lnum.constFirst()->position==3)
         r=check(lnum.constFirst());
    }
    score+=int(r)*100;
    ui->perfect_lable->setText(QString::number(score));
}
void MainWindow::keyReleaseEvent(QKeyEvent *event)
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

//void MainWindow::QResizeEvent(MainWindow::QResizeEvent *event)
//{
//    ui->stackedWidget->resize(this->size());
//}

void MainWindow::waits(int n)
{
    QEventLoop loop;
    QTimer::singleShot(n,&loop,SLOT(quit()));
    loop.exec();
}
