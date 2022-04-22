#include "mypushbutton.h"
#include<QPushButton>
#include<QDebug>
#include<QPropertyAnimation>//设置动画特效
/*myPushButton::myPushButton(QWidget *parent) : QPushButton(parent)
{

}*/
myPushButton::myPushButton(QString normlImage,QString pressImage){//pressImage再.h和.cpp只能在一个地方赋值
    this->normImgPath =normlImage;
    this->preeImgPath =pressImage;
    QPixmap pix;
    bool ret = pix.load(normlImage);
    if(!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }
    //设置图片固定大小
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则样式
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

}
void myPushButton::zoom1(){
    //创建动态对象
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);//设置动画时间间隔200毫秒
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置弹跳属性
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();//执行动画
}
void myPushButton::zoom2(){

    //创建动态对象
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);//设置动画时间间隔200毫秒
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置弹跳属性
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();//执行动画
}
void myPushButton::mousePressEvent(QMouseEvent *e){
    if(this->preeImgPath!=""){//传入图片不为空，则有按下事件，说明需要有按下状态
        QPixmap pix;
        bool ret = pix.load(this->preeImgPath);
        if(!ret)
        {
            qDebug()<<"图片加载失败";
            return;
        }
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则样式
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    //让父类执行其他内容
    return QPushButton::mousePressEvent(e);
}

void myPushButton::mouseReleaseEvent(QMouseEvent *e){
    if(this->preeImgPath!=""){//传入图片不为空，则有释放，说明需要有鼠标释放状态
        QPixmap pix;
        bool ret = pix.load(this->normImgPath);
        if(!ret)
        {
            qDebug()<<"图片加载失败";
            return;
        }
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则样式
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    //让父类执行其他内容
    return QPushButton::mouseReleaseEvent(e);

}
