#include "mycoin.h"
#include<QDebug>
#include<QTimer>
#include<QPushButton>
/*myCoin::myCoin(QWidget *parent) : QPushButton(parent)
{

}*/
myCoin::myCoin(QString btnImg){
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret){
        qDebug()<<"图片加载失败";
        return;
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{boder::0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

    //初始化定时器对象
    timer1=new QTimer(this);
    timer2=new QTimer(this);

    //监听正面翻反面的信号，并翻转
    connect(timer1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str=QString(":/res/Coin000%1.png").arg(this->min++);
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{boder::0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));

        //判断如果 翻完了，将min重置为1
        if(this->min>this->max)
        {
            this->min=1;
            timer1->stop();//停止定时器
            this->isAnimation=false;//不做动画
        }

    });
    //监听反面翻转正面的信号，并翻转
    connect(timer2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str=QString(":/res/Coin000%8.png").arg(this->max--);
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{boder::0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));

        //判断如果 翻完了，将min重置为1
        if(this->min>this->max)
        {
            this->max=8;
            timer2->stop();//停止定时器
            this->isAnimation=false;//不做动画
        }

    });

}
void myCoin::changeFlag(){//改变正反面标识的方法
    if(this->flag)//如果是正面翻转为反面
    {
        timer1->start(30);//正面翻转为反面的定时器
        this->isAnimation=true;//开始做动画
        this->flag=false;
    }
    else
    {
        timer2->start(30);//反面翻转正面的计时器
        this->isAnimation=true;//开始做动画
        this->flag=true;
    }
}
void myCoin::mousePressEvent(QMouseEvent *e){
    if(this->isAnimation||this->isWin)
    {
        return;
    }
    else
    {
        QPushButton::mousePressEvent(e);
    }
}
