#include "mainwindow.h"
#include "ui_mainwindow.h"
#define cout qDebug() << "{" << __FILE__ << ":" << __LINE__ << "}"//方便debug
#define width 800//窗口宽度x
#define high  1000//窗口长度y
#define lable_width   200//方块的宽
#define  lable_high  100//方块的长
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i = 0;i<50;i++){
        b[i] = NULL;
        x[i] = 1;//初识x都置1，表示无方块，这个比较反直觉，可以弄别的
        y[i] = 0;
    }
    image = NULL;
    location = 0;


    this->resize(width,high);
    ui->centralWidget->resize(width,high);
    ui->stackedWidget->resize(width,high);
    ui->stackedWidget->setCurrentWidget(ui->start_page);
    ui->lcdNumber->setDigitCount(5);
    ui->lcdNumber->setVisible(false);
    ui->check_label_left->setText("←👈");
    ui->check_label_left->setStyleSheet("QLabel{background-color:rgb(92,141,128);}");
    ui->check_label_up->setText("↑\n👆");
    ui->check_label_up->setStyleSheet("QLabel{background-color:rgb(92,141,128);}");
    ui->check_label_down->setText("👇\n↓");
    ui->check_label_down->setStyleSheet("QLabel{background-color:rgb(92,141,128);}");
    ui->check_label_right->setText("👉→");
    ui->check_label_right->setStyleSheet("QLabel{background-color:rgb(92,141,128);}");
    this->grabKeyboard();

    min=3;
    sec=25;
    creat_falg = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_game_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}

void MainWindow::on_test_button_clicked()
{
    ui->lcdNumber->setVisible(true);
    tm_lcd = this->startTimer(1000);
    tm_label = this->startTimer(5);
    ui->lcdNumber->display(QDateTime::currentDateTime().toString(QString::number(min)+":"+QString::number(sec)));
    QFile f("S:\\qt\\Examples\\xiaobaichengxu\\music_stampede\\test.txt");
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
       {
            qDebug() << ("打开文件失败");
       }
    QTextStream txtInput(&f);
    QString lineStr;
    while(!txtInput.atEnd()){//用队列存储所有的数据
        lineStr = txtInput.readLine();
        q.enqueue(lineStr.toInt()) ;
    }
    f.close();

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
        creat_falg += 1;//每200为一秒
        if(q.isEmpty() != true){
            if (creat_falg == q.head()){
                cout << creat_falg;
                image = new QImage;
                image->load(":/test.png");
                for(int i =0;i<50;i++){
                    if(b[i] == NULL){
                        b[i] = new QLabel;
                        b[i]->setScaledContents(true);
                        b[i]->setPixmap(QPixmap::fromImage(*image));
                        x[i] = location*200;
                        y[i] = 72;//初始值，可更改
                        b[i]->setParent(ui->main_page);
                        b[i]->resize(lable_width,lable_high);
                        b[i]->move(x[i],y[i]);
                        b[i]->show();
                        location = (location+1)%4;
                        break;
                    }
                }
                q.dequeue();
           }
        }
       for(int i =0;i<50;i++)
           if(x[i] != 1){//不是1，代表有方块
               y[i] += 2;
               if(y[i]> 1000){
                   delete b[i];
                   b[i] = NULL;
                   x[i] = 1;
                   y[i] = 0;
                   ui->perfect_lable->setText("Miss!!");
                   continue;
               }
               b[i]->move(x[i],y[i]);
               b[i]->show();
           }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        ui->check_label_left->setStyleSheet("QLabel{background-color:rgb(183,210,215);}");
        for(int i =0;i<50;i++){
            if(x[i] == 0 && y[i]>850 && y[i]<920){
                delete b[i];
                b[i] = NULL;
                x[i] = 1;
                y[i] = 0;
                ui->perfect_lable->setText("Perfect!!!");
            }
            else if (x[i] == 0 && y[i]>920 ) {
                delete b[i];
                b[i] = NULL;
                x[i] = 1;
                y[i] = 0;
                ui->perfect_lable->setText("Good!!");
            }
            else if (x[i] == 0 && y[i]<850) {
                ui->perfect_lable->setText("Bad!!");
            }
        }
    }
    else if (event->key() == Qt::Key_Up) {
        ui->check_label_up->setStyleSheet("QLabel{background-color:rgb(183,210,215);}");
        for(int i =0;i<50;i++){
            if(x[i] == 200 && y[i]>850 && y[i]<920){
                delete b[i];
                b[i] = NULL;
                x[i] = 1;
                y[i] = 0;
                ui->perfect_lable->setText("Perfect!!!");
            }
            else if (x[i] == 200 && y[i]>920 ) {
                delete b[i];
                b[i] = NULL;
                x[i] = 1;
                y[i] = 0;
                ui->perfect_lable->setText("Good!!");
            }
            else if (x[i] == 200 && y[i]<850) {
                ui->perfect_lable->setText("Bad!!");
            }
        }
    }
    else if (event->key() == Qt::Key_Down) {
        ui->check_label_down->setStyleSheet("QLabel{background-color:rgb(183,210,215);}");
        for(int i =0;i<50;i++){
            if(x[i] == 400 && y[i]>850 && y[i]<920){
                delete b[i];
                b[i] = NULL;
                x[i] = 1;
                y[i] = 0;
                ui->perfect_lable->setText("Perfect!!!");
            }
            else if (x[i] == 400 && y[i]>920 ) {
                delete b[i];
                b[i] = NULL;
                x[i] = 1;
                y[i] = 0;
                ui->perfect_lable->setText("Good!!");
            }
            else if (x[i] == 400 && y[i]<850) {
                ui->perfect_lable->setText("Bad!!");
            }
        }
    }
    else if (event->key() == Qt::Key_Right) {
        ui->check_label_right->setStyleSheet("QLabel{background-color:rgb(183,210,215);}");
        for(int i =0;i<50;i++){
            if(x[i] == 600 && y[i]>850 && y[i]<920){
                delete b[i];
                b[i] = NULL;
                x[i] = 1;
                y[i] = 0;
                ui->perfect_lable->setText("Perfect!!!");
            }
            else if (x[i] == 600 && y[i]>920 ) {
                delete b[i];
                b[i] = NULL;
                x[i] = 1;
                y[i] = 0;
                ui->perfect_lable->setText("Good!!");
            }
            else if (x[i] == 600 && y[i]<850) {
                ui->perfect_lable->setText("Bad!!");
            }
        }
    }

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
