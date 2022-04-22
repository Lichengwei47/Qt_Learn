#include "mypushbutton.h"
#include<QPushButton>
#include<QDebug>
mypushbutton::mypushbutton(QPushButton *parent) : QPushButton(parent)
{
      qDebug()<<"创建按钮";
}
mypushbutton::~mypushbutton()
{
      qDebug()<<"按钮析构";
}
