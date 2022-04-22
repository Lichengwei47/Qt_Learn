#include "mylabel.h"
#include<QDebug>
#include<QMouseEvent>
mylabel::mylabel(QWidget *parent) : QLabel(parent)//QLabel是父类
{
    setMouseTracking(true);//设置鼠标追踪状态
}
//鼠标进入事件
void mylabel::enterEvent(QEvent *event){//Mouse enters widget's boundaries (QEnterEvent).
    qDebug()<<"鼠标进入标签";
}
//鼠标离开事件
void mylabel::leaveEvent(QEvent *event){
    qDebug()<<"鼠标离开标签";

}
void mylabel::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons() & Qt::RightButton)//鼠标右键点击,位运算符,ev->buttons()包含多种状态
    {
        qDebug()<<"鼠标移动";
    }

}
void mylabel::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::RightButton)//鼠标右键点击
    {
        QString qs=QString("x=%1,y=%2,Globalx=%3,Globaly=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug()<<"鼠标点击"<<qs;
    }
}
void mylabel::mouseReleaseEvent(QMouseEvent *ev)
{
    qDebug()<<"鼠标释放";
}
bool mylabel::event(QEvent *e){
    if(e->type()==QEvent::MouseButtonPress){
        QMouseEvent * ev=static_cast<QMouseEvent *>(e);
        QString qs=QString("Event函数鼠标按下x=%1,y=%2,Globalx=%3,Globaly=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug()<<"鼠标点击"<<qs;
        return true;//代表用户自己处理这个事件，不向下分发
    };
    //其他事情交给父类处理
    return QLabel::event(e);//[virtual protected] bool QLabel::event(QEvent *e) 作用：Reimplemented from QObject::event().

}
