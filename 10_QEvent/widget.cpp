#include "widget.h"
#include "ui_widget.h"
#include<QTimer>
#include<QMouseEvent>
#include<QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    id1 =startTimer(1000);//启动计时器事件，每两秒运行一次timerEvent函数
    id2 =startTimer(2000);//单位毫秒
    QTimer *timer=new QTimer(this);
    timer->start(500);//0.5秒执行一次
    connect(timer,&QTimer::timeout,this,[=](){
        static int  num =1;
        ui->label_4->setText(QString::number(num++));});
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        timer->stop();
    });
    //事件过滤
    //1、给label安装事件过滤器
    ui->label->installEventFilter(this);//给label1安装事件过滤器
    //重写事件过滤，bool Widget::eventFilter(QObject *obj,QEvent *e)
}

Widget::~Widget()
{
    delete ui;

}
void Widget::timerEvent(QTimerEvent *ev)
{
    static  int num1=1;//只初始化一次内存，再运行这个函数时不再重新设置num
    static int num2=1;
    if(ev->timerId()==id1)
    {
        ui->label_2->setText(QString::number(num1++));
    }
    if(ev->timerId()==id2)
    {
        ui->label_3->setText(QString::number(num2++));
    }
}
bool Widget::eventFilter(QObject *obj,QEvent *e){
    if(obj==ui->label)
    {
        if(e->type()==QEvent::MouseButtonPress){
            QMouseEvent * ev=static_cast<QMouseEvent *>(e);
            QString qs=QString("事件过滤器中函数鼠标按下x=%1,y=%2,Globalx=%3,Globaly=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
            qDebug()<<"鼠标点击"<<qs;
            return true;//代表用户自己处理这个事件，不向下分发
        };
    }
    return QWidget::eventFilter(obj,e);
}
