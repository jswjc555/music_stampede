#include "mainwindow.h"
#include "ui_mainwindow.h"
#define cout qDebug() << "{" << __FILE__ << ":" << __LINE__ << "}"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(main_WIDTH,main_HIGH);
    ui->movie_label->setFixedSize(main_WIDTH,main_HIGH);
    ui->start_game->raise();
    ui->movie_label->setScaledContents(true);//封面背景自适应
    QMovie *background = new QMovie(":/image/background.gif");//添加背景
    ui->movie_label->setMovie(background);
    background->start();
    ui->start_game->setStyleSheet("QPushButton{border-image: url(:/image/start.png)}"
                                 "QPushButton:hover{border-image: url(:/image/start_on.png)}");
    ui->exit_game->setStyleSheet("QPushButton{border-image: url(:/image/exit.png)}"
                                 "QPushButton:hover{border-image: url(:/image/exit_on.png)}");

}

MainWindow::~MainWindow()
{
    if(music!=0) delete music;
    delete ui;
}

void MainWindow::on_start_game_clicked()
{
//    dmusic=new DiffMusic(0,this);
//    dmusic->show();
//    dmusic->start();
        music=new MyMusic(0,this);
        music->show();
        music->start();
        this->close();
}

void MainWindow::GameOver(int n)
{
    if(music==0)
    {
        QMessageBox::information(NULL,"游戏结束","时间为"+QString::number(n/60)+"分"+QString::number(n%60)+"秒");
        delete dmusic;
        dmusic=0;
    }
    if(dmusic==0)
    {
        QMessageBox::information(NULL,"游戏结束","分数为"+QString::number(n));
        delete music;
        music=0;
    }

}

void MainWindow::on_challenge_clicked()
{
    dmusic=new DiffMusic(0,this);
    dmusic->show();
    dmusic->start();
    this->close();
}

void MainWindow::on_exit_game_clicked()
{
    this->close();
}
