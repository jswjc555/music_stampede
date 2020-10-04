#ifndef HELP_H
#define HELP_H

#include <QObject>
#include<QThread>
#include<QLabel>
#include<QMovie>
class Help:public QThread
{
    Q_OBJECT
public:
    Help(QObject *parent=nullptr);
};

#endif // HELP_H
