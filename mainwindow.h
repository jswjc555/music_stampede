#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"musicown.h"
#include <QMainWindow>
#include <QKeyEvent>
#include <QDebug>
#include <QResizeEvent>
#include <QDateTime>
#include "mylabel.h"
#include<QPointer>
//#include <QQueue>
#include<QMessageBox>
#include <QMediaPlayer>
#include <QMovie>

enum result{bad,good,perfect};
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    int rand(int a=4, int b=0);
    result check(MyLabel*);
    bool israng(int, int, int);
    ~MainWindow();
protected:
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void QResizeEvent(QResizeEvent *event);
    void waits(int);
private slots:
    void on_start_game_clicked();

public slots:
    void deleteit();
private:
    Musicown *music;
    Ui::MainWindow *ui;
    int score=0;
    int tm_lcd;
    int nn=1;
    int already=0;
    int speed;
    int tm_label;
    int min,sec;
    QTimer sumtime;
    QList<MyLabel*>lnum;
};

#endif // MAINWINDOW_H
