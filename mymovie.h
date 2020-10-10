#ifndef MYMOVIE_H
#define MYMOVIE_H

#include <QMovie>
#include<QTimer>
class MyMovie:public QMovie
{
    Q_OBJECT
public:
    QTimer time;
    MyMovie(const QString &fileName, const QByteArray &format = QByteArray(), QObject *parent = Q_NULLPTR);
signals:
    void isfinished(MyMovie*);
};

#endif // MYMOVIE_H
