#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QDebug>
#include <QDateTime>
#include <QLabel>
#include <QFile>
#include <QQueue>
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
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private slots:
    void on_start_game_clicked();

    void on_test_button_clicked();

private:
    Ui::MainWindow *ui;
    int tm_lcd;
    int tm_label;
    int location;
    QImage *image;
    int min,sec;//歌曲的时长
    QQueue<int> q;//方块生成的队列
    int creat_falg;
    QLabel *b[50];
    int x[50],y[50];

};

#endif // MAINWINDOW_H
