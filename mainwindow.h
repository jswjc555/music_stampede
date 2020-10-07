#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"mymusic.h"
#include"diffmusic.h"
#include <QMainWindow>
#include <QDebug>
#include <QMovie>
#define main_WIDTH 560
#define main_HIGH 800
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:

private slots:

    void on_start_game_clicked();

    void on_challenge_clicked();

    void on_exit_game_clicked();

public slots:
    void GameOver(int);
private:
    MyMusic *music=0;
    DiffMusic *dmusic=0;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
