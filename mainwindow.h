#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"mymusic.h"
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

    void on_mode_back_button_clicked();

    void on_mode_normal_button_clicked();

    void on_mode_hard_button_clicked();

    void on_roll_music_button_clicked();

public slots:
    void GameOver(int);
private:
    MyMusic *music=0;
    Ui::MainWindow *ui;
    int music_no;

};

#endif // MAINWINDOW_H
