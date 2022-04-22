#include "studen.h"
#include<QDebug>
Studen::Studen(QObject *parent) : QObject(parent)
{

}
void Studen::Student_eat()
{
    qDebug()<<"下课了，去食堂吃饭！";
}
void Studen::Student_eat(QString foodname)
{
    qDebug()<<"下课了，去食堂吃饭吃"<<foodname.toUtf8().data();
}
