#include "mainwindow.h"
#include "ui_mainwindow.h"
#define cout qDebug() << "{" << __FILE__ << ":" << __LINE__ << "}"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(main_WIDTH,main_HIGH);
    ui->stackedWidget->setFixedSize(main_WIDTH,main_HIGH);
    ui->movie_label->setFixedSize(main_WIDTH,main_HIGH);
    ui->background_mode->setFixedSize(main_WIDTH,main_HIGH);
    ui->start_game->raise();
    ui->movie_label->setScaledContents(true);//封面背景自适应
    ui->background_mode->setScaledContents(true);
    QMovie *background = new QMovie(":/image/background.gif");//添加背景
    ui->movie_label->setMovie(background);
    background->start();
    music_no =0;
    ui->music_choose->setText("TheCrave.mp3");

    ui->mode_normal_button->setStyleSheet("QPushButton{border-image: url(:/image/normal_mode.png)}"
                                          "QPushButton:hover{border-image: url(:/image/normal_mode.png)}");
    ui->mode_hard_button->setStyleSheet("QPushButton{border-image: url(:/image/hard_mode.png)}"
                                        "QPushButton:hover{border-image: url(:/image/hard_mode.png)}");
    ui->start_game->setStyleSheet("QPushButton{border-image: url(:/image/start.png)}"
                                 "QPushButton:hover{border-image: url(:/image/start_on.png)}");
    ui->exit_game->setStyleSheet("QPushButton{border-image: url(:/image/exit.png)}"
                                 "QPushButton:hover{border-image: url(:/image/exit_on.png)}");
    ui->stackedWidget->setCurrentWidget(ui->start_page);

}

MainWindow::~MainWindow()
{
    if(music!=0) delete music;
    delete ui;
}

void MainWindow::on_start_game_clicked()
{
    QMovie *background = new QMovie(":/image/background.gif");//添加背景
    ui->background_mode->setMovie(background);
    background->start();
    ui->stackedWidget->setCurrentWidget(ui->mode_page);

}

void MainWindow::GameOver(int n)
{
    if(music==0)
    {
        QMessageBox::information(NULL,"游戏结束","时间为"+QString::number(n/60)+"分"+QString::number(n%60)+"秒");
//        delete dmusic;
//        dmusic=0;
    }


}

void MainWindow::on_challenge_clicked()
{

    this->close();
}

void MainWindow::on_exit_game_clicked()
{
    this->close();
}

void MainWindow::on_mode_back_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->start_page);
}

void MainWindow::on_mode_normal_button_clicked()
{
    music=new MyMusic(0,this,music_no,easy);
           music->show();
           music->start();
           this->close();
}

void MainWindow::on_mode_hard_button_clicked()
{
    music=new MyMusic(0,this,music_no,diff);
           music->show();
           music->start();
           this->close();
}

void MainWindow::on_roll_music_button_clicked()
{
    music_no++;
    music_no %=2;
    switch (music_no) {
    case 0:
    {
        ui->music_choose->setText("TheCrave.mp3");
        break;
    }
    case 1:{
        ui->music_choose->setText("ori_01.mp3");
        break;
    }
    }

}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_mode_hp_button_clicked()
{
    music=new MyMusic(0,this,music_no,hp);
           music->show();
           music->start();
           this->close();
}
