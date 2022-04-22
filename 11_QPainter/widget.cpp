#include "widget.h"
#include "ui_widget.h"
#include<QPainter>//画家类
#include<QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget())
{
    ui->setupUi(this);
    //点击按钮，移动图片
    posX=0;
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        //如果要手动调用绘图事件
        //this->repaint();
        //setUpdatesEnabled(true);
        QWidget::update();
        //QWidget::repaint();
        //QWidget::showNormal();
        //this->resize(this->size());
        //QWidget::adjustSize();
    });
}

Widget::~Widget()
{
    delete ui;


}
void Widget::paintEvent(QPaintEvent *)
{
    /*QPainter painter(this);
    QPen pen(QColor(255,0,0));
    //设置画笔宽度
    pen.setWidth(2);
    pen.setStyle(Qt::DotLine);//设置画笔风格
    painter.setPen(pen);

    //设置画刷
    QBrush brush(Qt::cyan);//类似填充
    brush.setStyle(Qt::Dense7Pattern);//设置画刷风格
    painter.setBrush(brush);
    //画线
    painter.drawLine(QPoint(0,0),QPoint(50,50));
    //画圆
    painter.drawEllipse(QPoint(100,100),50,50);
    //画矩形
    painter.drawRect(QRect(QPoint(150,150),QPoint(200,200)));
    painter.drawText(QRect(QPoint(150,150),QPoint(200,200)),"无名之辈");*/

    //////////////////高级设置/////////////////
    /*QPainter painter(this);
    //painter.drawEllipse(QPoint(100,100),100,100);
    //painter.setRenderHint(QPainter::Antialiasing);//设置抗锯齿，效率低
    //painter.drawEllipse(QPoint(200,200),100,100);
    painter.drawRect(QRect(QPoint(150,150),QPoint(200,200)));
    painter.translate(100,0);//让画家移动位置
    painter.drawRect(QRect(QPoint(150,150),QPoint(200,200)));
    painter.save();//保存状态
    painter.translate(200,0);//让画家移动位置
    painter.restore();//还原到42行的状态
    painter.drawRect(QRect(QPoint(150,150),QPoint(200,200)));*/
    //////////////////画图片/////////////////
    QPainter painter(this);
    posX+=20;
    if(posX>this->width())
        posX=0;
    painter.drawPixmap(posX,100,QPixmap(":/open.png"));
    qDebug()<<"当前pos="<<posX;
}
