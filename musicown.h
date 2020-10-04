#ifndef MUSICOWN_H
#define MUSICOWN_H

#include <QObject>
#include <QWidget>
#include<QMediaPlayer>
#include <QFile>
#include<QTime>

class Musicown : public QWidget
{
    Q_OBJECT
public:
    explicit Musicown(QWidget *parent = nullptr);
    int sencond;
    ~Musicown();
    int n=0;
    QList<int> sump;
    QFile *f=0;
    QMediaPlayer*player=0;
    int cha(int );
    void start();
signals:

public slots:
};

#endif // MUSICOWN_H
